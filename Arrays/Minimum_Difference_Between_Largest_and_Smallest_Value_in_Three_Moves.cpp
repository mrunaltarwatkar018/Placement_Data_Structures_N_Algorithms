/* Leetcode Problem No.: 1509.  Minimum Difference Between Largest and Smallest Value in Three Moves   */

/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
*/



/************************************************************** C++ **************************************************************/

/*
        Approach:

            T.C :  O(n log n)
            S.P : O(1)

                    Step 1: Get the length of the nums/array

                    Step 2: If the nums/array has 4 or fewer elements, return 0
                    
                    Step 3: Sort the array/nums

                    Step 4: Initialize the answer with the maximum possible difference

                    Step 5: Check the difference for different scenarios:
                    Scenario 1: Change 3 smallest elements.
                    Scenario 2: Change 2 smallest elements and 1 largest element.
                    Scenario 3: Change 1 smallest element and 2 largest elements.
                    Scenario 4: Change 3 largest elements.
*/

// T.C = O(nlogn)
// S.C = O(1)



class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Step 1: Get the length of the nums/array
        int n = nums.size();

        // Step 2: If the nums/array has 4 or fewer elements, return 0
        if (n <= 4) 
            return 0;

        
        // Step 3: Sort the array/nums
        sort(begin(nums), end(nums));

        // Step 4: Initialize the answer with the maximum possible difference
        int result = INT_MAX;


        // Step 5: Check the difference for different scenarios:
        // Scenario 1: Change 3 smallest elements.
        // Scenario 2: Change 2 smallest elements and 1 largest element.
        // Scenario 3: Change 1 smallest element and 2 largest elements.
        // Scenario 4: Change 3 largest elements.

        // case 1
        result = std::min( result, nums[n - 4] - nums[0] );
        // case 2
        result = std::min( result, nums[n - 3] - nums[1] );
        // case 3
        result = std::min( result, nums[n - 2] - nums[2] );
        // case 4
        result = std::min( result, nums[n - 1] - nums[3] );

        return result;
    }
};















































/************************************************************** JAVA **************************************************************/



class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;  // Step 1: Get the length of the array.
        
        if (n <= 4) return 0;  // Step 2: If the array has 4 or fewer elements, return 0.
        
        Arrays.sort(nums);  // Step 3: Sort the array.
        
        int ans = nums[n-1] - nums[0];  // Step 4: Initialize the answer with the maximum possible difference.
        
        // Step 5: Check the difference for different scenarios:
        // Scenario 1: Change 3 smallest elements.
        // Scenario 2: Change 2 smallest elements and 1 largest element.
        // Scenario 3: Change 1 smallest element and 2 largest elements.
        // Scenario 4: Change 3 largest elements.
        for (int i = 0; i <= 3; i++) {
            ans = Math.min(ans, nums[n-(3-i)-1] - nums[i]);
        }
        
        return ans;  // Step 6: Return the minimum difference found.
    }
}









/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=3ggt-iX4cyM
*/