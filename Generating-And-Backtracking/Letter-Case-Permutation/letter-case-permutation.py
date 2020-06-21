class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        def backtrack(ind=0, sub=""):
            if ind == len(S):
                res.append(sub)
                return 
            
            backtrack(ind+1, sub + S[ind])
            if S[ind].isalpha():
                backtrack(ind+1, sub + S[ind].swapcase())
        
        res = []
        backtrack()
        return res
