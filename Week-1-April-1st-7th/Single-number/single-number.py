class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        #Method 1: Using O(n) space, O(1) time complexity 
        if len(nums) == 1:
            return nums[0]
        tmp = {}
        for v in nums:
            if tmp.get(v) == None:
                tmp[v] = 1
            else:
                tmp[v] += 1
        for key, value in tmp.items():
            if value == 1:
                return key 
        
        #Method 1: O(1) space and O(n) time complexity
        if len(nums) == 1:
            return nums[0]
        tmp = nums[0]
        for i in range(1, len(nums)):
            tmp ^= nums[i] #XOR
        return tmp

        #Method 3: using reduce and lambda func
        from functools import reduce
        def singleNumber(self, nums: List[int]) -> int:
            res =  reduce(lambda x, y : x ^ y, nums)
            return res