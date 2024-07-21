/* Leetcode Problem No.: 1526. Minimum Number of Increments on Subarrays to Form a Target Array */

/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
    Harder Version of this Qn   : https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/
*/


/************************************************************ C++ ************************************************/
//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)

//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)

/*
    Summary :
        The approach involves the following steps:

        Initialization: 
            Set up the necessary variables: result to store the total number of operations, and 
            prev to track the previous value of the difference between corresponding elements in 
            target and nums.

        Iterate through arrays: For each element in the arrays:

            Calculate the difference (curr) between the current elements of target and nums.
            
            Check for a sign change between curr and prev. If a sign change occurs, add the 
            absolute value of curr to result.

            If there's no sign change, but the absolute value of curr is greater than that of 
            prev, add the absolute difference between curr and prev to result.

            Update prev to the current value of curr.

            Return the result: After processing all elements, return the total number of 
            operations stored in result. This ensures the transformation from nums to target with 
            the minimum operations.
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i];

            if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};























/************************************************************ JAVA ************************************************/
//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minNumberOperations(int[] target) {
        int n = target.length;
        int result = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int curr = target[i];
            if (curr > prev) {
                result += (curr - prev);
            }
            prev = curr;
        }

        return result;
    }
}

























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yX6NHGF_YQ4
*/