"""Tuple
- is immutable.
- syntax: ()

*** Note:
- When a tuple containing a single value ---> we have to include a comma

"""
tup1 = ('1', 'a')
tup2 = '1', '2'
tup3 = (50, )
lst = [1,2,3,4,5]
print(tuple(lst).append('hello'))
print(tup1, type(tup1))
print(tup2, type(tup2))
print(tup3, type(tup3))