# Time complexity: O(n)...Space complexity: O(n)
class Solution:
    def remove(self, s):
        tmp = '' # tmp is built from scratch, not reusing the memory of s ---> O(n) space
        for c in s:
            if c == '#':
                if tmp != '':
                    tmp = tmp[:-1]
            else:
                tmp += c
        return tmp
    
    def backspaceCompare(self, S: str, T: str) -> bool:
        return self.remove(S) == self.remove(T)