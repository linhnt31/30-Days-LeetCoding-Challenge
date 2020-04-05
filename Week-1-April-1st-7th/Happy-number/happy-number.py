class Solution:
    #Time complexity: O(n)
    def isHappy(self, n: int) -> bool:
        #check infinite loop
        check = set()
        for i in range(19):
            if n == 1:
                return True
            n = sum(map(lambda x: int(x)**2, str(n)))
            if n in check:
                return False
            check.add(n)