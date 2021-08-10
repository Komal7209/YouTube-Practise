class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        
        counter_one , counter_flip = 0,0
        for i in range(len(s)):
            if s[i] == '1':
                counter_one = counter_one + 1
            else:
                counter_flip = counter_flip + 1
                
            counter_flip = min(counter_one, counter_flip)
        
        return counter_flip