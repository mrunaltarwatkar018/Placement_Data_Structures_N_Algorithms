/* Leetcode Problem No.: 1991: Find the Middle Index In Array: */
/*
    Company Tags                : Amazon, Adobe, Coupang, Radius
    Leetcode Link               : https://leetcode.com/problems/find-the-middle-index-in-array/description/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?page=1&curated[]=1&sortBy=submissions#
*/


// similar problem at Leetcode: 724. Find Pivot Index  https://leetcode.com/problems/find-pivot-index/description/

//Approach-1 (Using O(n) space)

    // Function to find pivot index  in the array.
    // a: input array
    // n: size of array


        /*
            Example :
            A[]      = {1, 3, 5,  2, 2 }
            cumu_sum = {1, 4, 9, 11, 13}
            TotalSum = 13
            
            For i = 1, cumu_sum = 4
            sum at the left of i = 1 : cumu_sum[i] - a[i] = 4-3 = 1.   (i.e. 1)
            
            sum at the right of i = 1 : TotalSum - left_sum - a[i] = 13 - 1 - 3 = 9. (i.e. 5 + 2 + 2)
            
        */


// Approach 2:  Space Complexity: O(1)


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
                int n = nums.size();

        int total_sum = 0;
        for (int &x : nums) {
            total_sum += x;
        }

        int cumulative_sum = 0;

        for (int i = 0; i < n; i++) {
            int left_sum = cumulative_sum;
            int right_sum = total_sum - cumulative_sum - nums[i];
            if (left_sum == right_sum) {
                return i;
            }
            cumulative_sum += nums[i];
        }
        return -1;
    }
};

