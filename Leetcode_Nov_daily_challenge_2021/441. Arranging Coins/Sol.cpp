/*
// brute force
// Tc: O(k)
// SC: O(1)

class Solution {
public:
    int arrangeCoins(int totalNumberOfCoins) {
        
        int rowCount =0;
        
        while(totalNumberOfCoins>0){
            
            rowCount++;
            totalNumberOfCoins-=rowCount;
        }
        return totalNumberOfCoins == 0 ? rowCount : rowCount-1;
        
    }
};

*/

// for binary search approach

//TC: O(logn)
// SC: O(1)

/*
class Solution {
    public int arrangeCoins(int n) {
        long left = 0; // we use "long" because we may get an integer overflow
		long right = n;
		while(left <= right){
			long pivot = left + (right - left) / 2;  // finding mid
			long coinsUsed = pivot * (pivot + 1)/2;  // exact area of triangle using mid
			if(coinsUsed == n){
				return (int)pivot;
			}
			if(n < coinsUsed){
				right = pivot-1;
			}
			else{
				left = pivot + 1;
			}
		}
		return (int)right; // cast as an "int" because it was initiliazed as a "long" // we are returning right because when left and right cross each other then left right has all filled rows with it but left dont have
    }
};

*/

// Maths formula
// TC: O(1)
// SC: O(1)
// As per above intuition
// If we simply consider it as area of triangle then k-> no. of rows
// k+1 -> no. of columns // it is greater bcoz we want to equate it equal to n but area of triangle is more as compared to coins available with us thus we are required to find actual number of rows which were completely filled with those number of coins
// thus we are required to find value of k

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)floor(sqrt(2 * double(n + 0.25)) - 0.5);
    }
};
