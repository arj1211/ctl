#!/usr/bin/env python3
import argparse
import csv
import glob
import os
import re
import subprocess

# regex to match lines like:
# T_IDENT  input      (line 1, col 1)
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

def test_report(csv_path):
    """Generate a Markdown test report from lexer test results CSV."""
    report_path = os.path.splitext(csv_path)[0] + '.md'
    
    # Read and parse CSV
    with open(csv_path) as f:
        reader = csv.DictReader(f)
        records = list(reader)
    
    # Group records by test file
    tests = {}
    for record in records:
        test_file = os.path.basename(record['test_file'])
        if test_file not in tests:
            tests[test_file] = []
        tests[test_file].append(record)
    
    # Generate report
    with open(report_path, 'w') as f:
        f.write('# Lexer Test Report\n\n')
        
        for test_file, tokens in sorted(tests.items()):
            f.write(f'## Test: {test_file}\n\n')
            
            # Table header
            f.write('| Token Type | Lexeme | Line | Column |\n')
            f.write('|------------|---------|------|--------|\n')
            
            # Table rows
            for token in tokens:
                f.write(f"| {token['token_type']} | `{token['lexeme']}` | {token['line']} | {token['col']} |\n")
            
            f.write('\n')

    print(f"Generated test report at {report_path}")

def main():
    _parser = argparse.ArgumentParser()
    _parser.add_argument('-p', '--test-lexer-executable-path', required=True)
    _parser.add_argument('-t', '--tests-dir', required=True)
    _parser.add_argument('-o', '--output-path', required=True)
    args = _parser.parse_args()
    if not args.output_path.endswith('.csv'):
        args.output_path = args.output_path.strip()+'.csv'
    test_files = sorted(glob.glob(glob._join(args.tests_dir, '*.ctl')))
    with open(f'{args.output_path}', 'w', newline='') as csvfile:
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
