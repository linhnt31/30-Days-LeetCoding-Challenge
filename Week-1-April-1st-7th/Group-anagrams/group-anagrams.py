# Time complexity: O(k*nlogn)
"""
import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for s in strs:
            tmp = sorted(s)
            d[tuple(tmp)].append(s)
        ans = []
        for v in d.values():
            ans.append(v)
        return ans
"""

# Time complexity: O(n*k) : k is length of strs and n is a maximum length of a elements of strs
import collections
class Solution:
    def groupAnagrams(self, strs):
        d = collections.defaultdict(list)
        for s in strs:
            check = [0]*26
            for c in s:
                check[ord(c) - ord('a')] += 1
            d[tuple(check)].append(s)
        
        return d.values()

strs = ['ate', 'eat', 'tae', 'uefg','geuf', 'abc']
a = Solution()
ans = a.groupAnagrams(strs)
print(ans)