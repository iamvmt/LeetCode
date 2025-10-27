class Solution:
    def lengthOfLastWord(self, s: str) -> int:
       words = s.strip().split()
       if not words:
         return 0
       else:
        return len(words[-1]) 