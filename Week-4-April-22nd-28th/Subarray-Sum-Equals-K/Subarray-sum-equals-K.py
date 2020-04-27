import collections as c
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = pref = 0
        count_pref = c.defaultdict(int) 
        count_pref[pref] += 1
        
        for val in nums:
            pref += val
            need = pref - k
            ans += count_pref[need]
            count_pref[pref] += 1
        return ans