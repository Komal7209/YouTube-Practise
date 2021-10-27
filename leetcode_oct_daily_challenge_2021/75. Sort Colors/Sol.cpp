/*

// two pass solution:

// Tc: O(n)
// Sc: O(1)

class Solution {
public:
        void sortColors(vector<int>& nums) {
            
            int cnt0=0, cnt1=0,cnt2=0;
            for(int i=0;i<size(nums); i++){
                
                  nums[i]==0 ? cnt0++:(nums[i]==1 ? cnt1++:cnt2++);

                }
                for(int i=0;i<size(nums);i++){
                    if (cnt0!=0){
                        nums[i] =0;
                        cnt0--;
                    }
                 else if (cnt1!=0){
                        nums[i] = 1; 
                        cnt1--;
                    }
                  else if (cnt2!= 0){
                        nums[i] =2;
                        cnt2--;
                    }
                }

           }
    };
*/




    // Tc: O(n)
   // SC: O(1)
  // dutch national flag algo
 // using quicksort with 1 pass n O(n)

class Solution {
public:

    void sortColors(vector<int>& nums) {
        int p0 = 0, p = 0, p2 = nums.size() -1;
        while(p <= p2){
            if(nums[p] == 0 ){
                nums[p] = nums[p0];           // swapping
                nums[p0]= 0;                 // asssiging 0 value to p0
                p0++;
                p++;
            }else if (nums[p] == 2){ 
                nums[p]= nums[p2];        // swapping
                nums[p2] = 2;            // assigning
                p2--;                   // decrement last pointer bcoz we want last pointer elements as 2               
            }else                      // nums[p]==1
                p++;                  // for reaching p ->p2
        }
    }
};

