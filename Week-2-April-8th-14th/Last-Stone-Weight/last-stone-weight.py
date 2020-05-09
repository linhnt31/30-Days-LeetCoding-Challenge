# Time complexityL O(n^2) ... Space complexity: O(1)
class Solution:
    def getMax(self, stones):
        self.firstMax = self.secMax = -float("inf")
        self.firstInd = -1
        
        for i in range(len(stones)):
            if stones[i] > self.firstMax:
                self.firstMax = stones[i]
                self.firstInd = i
        for i in range(len(stones)):
            if stones[i] > self.secMax and i != self.firstInd:
                self.secMax = stones[i]
        return [self.firstMax,self.secMax]
    
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1: # O(n/2)
            maxVals = self.getMax(stones)
            tmp = abs(maxVals[0] - maxVals[1])
            stones.remove(maxVals[0]) #O(n)
            stones.remove(maxVals[1])
            if tmp != 0:
                stones.append(tmp)
        if len(stones) == 1:
            return stones[0]
        return 0
