class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i : int = 0
        j : int = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i >= len(s) 
        