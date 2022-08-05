// combs(target)=∑i=0,n combs(target−nums[i]) if target≥nums[i]

//============================
// recursive
//============================

// class Solution {
// private:
    
//    int combs(vector<int>nums, int remain) {
//         if (remain == 0)
//             return 1;

//         int result = 0;
//         for (int num : nums) {
//             if (remain - num >= 0)
//                 result += combs(nums, remain - num);
//             // minor optimizaton, early stopping
//             // else
//             //     break;
//         }

//         return result;
//     }
// public:
//   int combinationSum4(vector<int>& nums, int target) {
//          // minor optimization
//         // Arrays.sort(nums);
//         return combs(nums, target);      
//   }
// };


//===========================
// memoisation
//============================


// class Solution {
// private:
//     unordered_map<int, int>memo;
    
//    int combs(vector<int>nums, int remain) {
//         if (remain == 0)
//             return 1;
//         if (memo.count(remain))
//             return memo[remain];

//         int result = 0;
//         for (int num : nums) {
//             if (remain - num >= 0)
//                 result += combs(nums, remain - num);
//             // minor optimizaton, early stopping
//             // else
//             //     break;
//         }
//         memo.insert({remain, result});
//         return result;
//     }
// public:
//   int combinationSum4(vector<int>& nums, int target) {
//          // minor optimization
//         // Arrays.sort(nums);
//         return combs(nums, target);      
//   }
// };


//=============================
// bottom up
//=============================


class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> result(target + 1);
        result[0] = 1; // because not choosing is also onr of the ans
        for (int combSum = 1; combSum <= target; ++combSum) {
            for (int x : nums) {
                if (combSum >= x) result[combSum] += result[combSum - x];
            }
        }
      
        return result[target];
    }
};


// TC: O(T*N)
// SC: O(T)



