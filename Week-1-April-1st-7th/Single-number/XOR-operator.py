"""
Operator: ^ (XOR)
- If 2 bits are the same ----> result = 0
example: 2 bits 1 or 2 bits 0 = 0
a = 20  <=> 0 0 0 1 0 1 0 0 
b = 15  <=> 0 0 0 0 1 1 1 1
-------------------------------
a ^ b =     0 0 0 1 1 0 1 1

- XOR is associative and commutative
r = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4
  = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)
  = 7 ^ 0
  = 7 
"""