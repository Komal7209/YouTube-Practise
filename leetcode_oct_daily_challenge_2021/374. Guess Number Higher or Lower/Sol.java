public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int min = 1, max = n;
        while(min<=max){
            int mid = min + (max-min)/2; // (min+max)/2
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1) min = mid+1; // you need to search number in higher range, bcoz number u need to find is greater than what u picked presently 
            else max = mid-1;            
        }
        return -1;
    }
}