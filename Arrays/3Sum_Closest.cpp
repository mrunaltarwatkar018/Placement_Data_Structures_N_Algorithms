/* Leetcode Problem No.: 16. 3Sum Closest  */


/*
    Company Tags                 : Facebook, Amazon, Microsoft, Oracle
    Leetcode Link                : https://leetcode.com/problems/3sum-closest/
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(),
             nums.end()); // sorting input for applying two pointer technique

        int closestSum = 100000;

        for (int k = 0; k <= n - 3; k++) {
            int i = k + 1;
            int j = n - 1;

            // two pointer logic
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum < target)
                    i++;
                else
                    j--;
            }
        }

        return closestSum;
    }
};



// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         // sorting input for applying two pointer technique
//         sort(nums.begin(), nums.end());
        
//         int closestSum = 100000;
        
//         for(int i = 0; i<n-2; i++) {
            
//             int l = i+1, r = n-1;
//             while(l < r) {
//                 int sum = nums[i] + nums[l] + nums[r];
                
//                 if(abs(target-sum) < abs(target-closestSum)) {
//                     closestSum = sum;
//                 }
                
//                 if(sum > target)
//                     r--;
//                 else
//                     l++;
//             }
//         }
//         return closestSum;
//     }
};


/*
    YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=hGLjwiPRh0U&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=6
*/