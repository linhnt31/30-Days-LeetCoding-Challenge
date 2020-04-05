""" 
-Python lambda: -anonymous function-
-syntax:  lambda arguments: expression ( we can have any number of argument but only one expression)
-Pros: we can put a lambda definition anywhere
"""

def cube(x):
    return x*x*x

f = lambda y : y *y * y
#print("Normal func: ", cube(3))
#print("Lambda func: ", f(3))
#print(type(f))

""" Lambda functions can be used along with built-in functions like filter(), map() and reduce(). """
# 1. filter(func[*] or None, iterable) ---> filter object: filter() iterate entire elements of list/dict,.. and return values for which the func[*] returns True.
lst = [5, 7, 22, 97, 54, 62, 77, 23, 73, 61] 
final_lst_filter = list(filter(lambda x: x % 2 == 0, lst))
print(final_lst_filter)

# 2. map(func[*], iterable) ---> map object: map() also iterate entire elements of list/dict,.. and computes and modified follow func[*]
final_lst_map = list(map(lambda  x: x * x, lst))
print(final_lst_map, " ", "type: ", final_lst_map)

# 3. from functools import reduce  : reduce(func, sequence) 
from functools import reduce
final_lst_reduce = reduce(lambda x, y: x +y, lst)
print(final_lst_reduce)

#Ref: https://www.geeksforgeeks.org/python-lambda-anonymous-functions-filter-map-reduce/