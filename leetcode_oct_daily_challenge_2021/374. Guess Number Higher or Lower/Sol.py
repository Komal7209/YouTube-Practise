class Solution:
    def guessNumber(self, n: int) -> int:
        minn, maxx = 0, n
        while(minn<=maxx):
            mid = minn + (maxx-minn)//2
            if guess(mid) == 0 : return mid
            elif guess(mid) == 1: minn = mid+1
            else: maxx = mid-1
            
        return -1
        