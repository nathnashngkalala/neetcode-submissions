class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter = [0] * 26
        if len(s) > len(t):
            temp = s
            s = t
            t = temp
        for c in s: 
            counter[ord(c) - ord('a')] += 1
        for c in t:
             counter[ord(c) - ord('a')] -= 1
             if counter[ord(c) - ord('a')] < 0:
                return False
        return True


        