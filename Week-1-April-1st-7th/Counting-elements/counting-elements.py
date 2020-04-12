# Time complexity: O(n^2).... Space complexity: O(1)
class Solution:
    def countElements(self, arr: List[int]) -> int:
        ans = 0
        for x in arr:
            if (x + 1) in arr:
                ans += 1
        return ans

# Time complexity: O(n)... Space complexity: O(n)
#Note: "in" operator in Python has time complexity is: O(1)
class Solution:
    def countElements(self, arr: List[int]) -> int:
        tmp = set() # set
        for a in arr:
            tmp.add(a)
        return sum([1 if (a + 1) in tmp else 0 for a in arr])