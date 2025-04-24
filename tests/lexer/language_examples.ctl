@ 1. Single numeric literal
42:

@ 2. Single symbol
x:

@ 3. Simple arithmetic
x + 5:

@ 4. Simple comparison
y >= 10:

@ 5. Bare vector literal
1,2,3:

@ 6. Bracketed vector literal
[4,5,6]:

@ 7. Arithmetic on literals and symbols
[1,2] : a * 3:

@ 8. Comparison between an expr and literal
(x - 2) == 7:

@ 9. Mixed ops with precedence via grouping
(3 + x) * (y - 4):

@ 10. Nested parentheses
((x + 1) * (x - 1)) / (x ^ 2):

@ 11. Modulo and shift
x % 4 : x << 2:

@ 12. Vector plus comparison
[0,1,2] : z != 0:

@ 13. Combined arithmetic and comparison
(x * 2 + 1) / (x - 1) >= 5:

@ 14. Deeply nested with multiple ops
((a << 3) - (b % 5)) ^ (c + (d / 2)):

@ 15. Full program chaining everything
[1,2,3] : p + q * r : (p % 2) == 0 : (q >> 1) <= (r ^ 2) : z - (x + y):
