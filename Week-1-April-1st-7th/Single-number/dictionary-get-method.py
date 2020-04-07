"""
+ dict = {key : value}
- key in dict can be any immutable type(int, string,...)
"""

""" dict
- If we use: key in dict ----> Time complexity: O(n)
- ELse, we use: dict.get(key) -----> TIme complexity: O(1) (hash-table)
+ dict.get(key) ---> return the value of that key. It key is not existing in dict --> return None

"""

d = {1 : 2, 3 : 4, 5 : 6, 8 : 10}
greet1 = dict(map(lambda kv : (kv[0], kv[1] ** 2), d.items()))
greet2 = dict(filter(lambda kv : (kv[0] % 2 != 0), d.items()))
print(greet1)
print(greet2)


# Link: 
# https://stackoverflow.com/questions/5904969/how-to-print-a-dictionarys-key
# https://stackoverflow.com/questions/44814719/can-both-the-values-and-keys-of-a-dictionary-be-integers/44814737
# https://www.quora.com/What-is-the-time-complexity-of-checking-if-a-key-is-in-a-dictionary-in-Python