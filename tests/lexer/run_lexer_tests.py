#!/usr/bin/env python3
import argparse
import csv
import glob
import html
import os
import re
import subprocess

TOKEN_RE = re.compile(r'^(\S+)\s+(\S+)\s+\(line\s+(\d+),\s+col\s+(\d+)\)$')

def run_test(executable_path, source):
    proc = subprocess.run(
        [executable_path],
        input=source,
        text=True,
        capture_output=True
    )

    tokens = []
    for line in proc.stdout.splitlines():
        m = TOKEN_RE.match(line)
        if not m:
            continue
        tok_type, lexeme, line_no, col_no = m.groups()
        tokens.append((tok_type, lexeme, int(line_no), int(col_no)))
    return tokens


def write_markdown_report(tests, report_md_path):
    with open(report_md_path, 'w') as f:
        f.write('# Lexer Test Report\n\n')
        for test_file, data in sorted(tests.items()):
            f.write(f'## Test: {test_file}\n\n')
            # include source code
            f.write('```\n')
            f.write(data['source'])
            if not data['source'].endswith('\n'):
                f.write('\n')
            f.write('```\n\n')
            # table
            f.write('| Token Type | Lexeme | Line | Column |\n')
            f.write('|------------|--------|------|--------|\n')
            for token in data['tokens']:
                f.write(f"| {token['token_type']} | `{token['lexeme']}` | {token['line']} | {token['col']} |\n")
            f.write('\n')
    print(f"Generated Markdown report at {report_md_path}")


def write_html_report(tests, report_html_path):
    with open(report_html_path, 'w') as f:
        f.write('<!DOCTYPE html>\n<html lang="en">\n<head>\n')
        f.write('  <meta charset="UTF-8">\n')
        f.write('  <meta name="viewport" content="width=device-width, initial-scale=1.0">\n')
        f.write('  <title>Lexer Test Report</title>\n')
        f.write('  <style>')
        f.write('table { border-collapse: collapse; width: 100%; }')
        f.write('th, td { border: 1px solid #ccc; padding: 8px; text-align: left; }')
        f.write('th { background-color: #f4f4f4; }')
        f.write('pre { background: #f8f8f8; padding: 10px; border: 1px solid #ddd; }')
        f.write('</style>\n</head>\n<body>\n')
        f.write('<h1>Lexer Test Report</h1>\n')
        for test_file, data in sorted(tests.items()):
            f.write(f'<h2>Test: {test_file}</h2>\n')
            # include source code
            f.write('<pre><code>')
            f.write(html.escape(data['source']))
            f.write('</code></pre>\n')
            # table
            f.write('<table>\n')
            f.write('  <thead><tr><th>Token Type</th><th>Lexeme</th><th>Line</th><th>Column</th></tr></thead>\n')
            f.write('  <tbody>\n')
            for token in data['tokens']:
                f.write(
                    '    <tr>' + \
                        f'<td>{token['token_type']}</td>' + \
                        f'<td>{html.escape(token['lexeme'])}</td>' + \
                        f'<td>{token['line']}</td>' + \
                        f'<td>{token['col']}</td>' + \
                    '</tr>\n'
                )
            f.write('  </tbody>\n</table>\n')
        f.write('</body>\n</html>')
    print(f"Generated HTML report at {report_html_path}")


def test_report(csv_path):
    """Generate Markdown and HTML test reports from lexer test results CSV."""
    base = os.path.splitext(csv_path)[0]
    md_path = base + '.md'
    html_path = base + '.html'

    # Read CSV data
    with open(csv_path) as f:
        reader = csv.DictReader(f)
        records = list(reader)

    # Group by test file and read sources
    tests = {}
    for rec in records:
        name = os.path.basename(rec['test_file'])
        entry = tests.setdefault(name, {'source': None, 'tokens': []})
        entry['tokens'].append({
            'token_type': rec['token_type'],
            'lexeme': rec['lexeme'],
            'line': rec['line'],
            'col': rec['col']
        })
        if entry['source'] is None:
            # load source from first occurrence
            with open(rec['test_file']) as sf:
                entry['source'] = sf.read()

    # Write both formats
    write_markdown_report(tests, md_path)
    write_html_report(tests, html_path)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--test-lexer-executable-path', required=True)
    parser.add_argument('-t', '--tests-dir', required=True)
    parser.add_argument('-o', '--output-path', required=True)
    args = parser.parse_args()

    if not args.output_path.endswith('.csv'):
        args.output_path = args.output_path + '.csv'

    test_files = sorted(glob.glob(os.path.join(args.tests_dir, '*.ctl')))

    with open(args.output_path, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['test_file','token_type','lexeme','line','col'])
        for tf in test_files:
            with open(tf) as f:
                src = f.read()
            tokens = run_test(args.test_lexer_executable_path, src)
            for tok in tokens:
                writer.writerow([tf, *tok])
    print(f"Wrote results to {args.output_path}")

    test_report(args.output_path)

if __name__ == '__main__':
    main()
