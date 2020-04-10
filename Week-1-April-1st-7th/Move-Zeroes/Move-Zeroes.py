# Method 1: Time complexity=O(n^2), Space complexity: O(1)
class Solution:
    def moveZeroes(self, a: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(a)-1):
            if a[i] != 0:
                continue
            for j in range(i + 1, len(a)):
                if a[j] == 0:
                    continue
                else:
                    a[i], a[j] = a[j], a[i]
                    break

# Method 2: Time complexity=O(n), Space complexity: O(n)
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        tmp = []
        for v in nums:
            if v != 0:
                tmp.append(v)
        for i in range(len(nums)):
            if i < len(tmp):
                nums[i] = tmp[i]
            else:
                nums[i] = 0

# Method 3: Time complexity=O(n), Space complexity: O(1)
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        # the number of non-zero elements 
        non = 0
        for v in nums:
            if v != 0:
                nums[non] = v
                non += 1
        for i in range(non, len(nums)):
            nums[i] = 0
        
        