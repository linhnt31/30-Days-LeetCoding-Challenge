"""
- A python dictionary throws a KeyError if we try to get an item with a key that is not currently in the dictionary
---> Solution: collections.defaultdict will create any items that we are trying to access
For example: default values are created collections.defaultdict(int/list) are 0/[] (empty list) 
"""
import collections
d = collections.defaultdict(int)

print((d.items()))