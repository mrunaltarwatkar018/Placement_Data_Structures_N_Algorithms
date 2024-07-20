/* Leetcode Problem No.: 2256. Minimum Average Difference  */

/*
    Company Tags                : Amazon, Paytm
    Leetcode Link               : https://leetcode.com/problems/minimum-average-difference/
*/


/*
    NOTE : Please also try Brute Force approach on your own. It's always a good thing to start with Brute Force
*/



//Using Cumulative Sum Approach : O(n) Time, O(1) Space
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        // Find Total Sum
        long long total_Sum = 0;
        for ( int i = 0; i < n; i++ ) {  // O(n)
            total_Sum += nums[i];
        }

        long long left_Sum = 0;
        long long right_Sum = 0;

        int result = INT_MAX;
        int idx = -1;

        for ( int i = 0; i < n; i++ ) {  // O(n)
            left_Sum += nums[i];  // nikalte chalenge
            right_Sum = total_Sum - left_Sum; // left_Sum + right_Sum = total_Sum

            int n1 = i + 1;
            int n2 = n - n1; // n1 + n2 = n

            long long left_avg = left_Sum / n1;
            long long right_avg = ( i == n - 1) ? 0 : right_Sum / n2;

            /*
                above ternary oprator can be written as : 
                if ( i == n - 1)
                    right_avg = 0;
                else 
                    right_avg = right_Sum / n2;
            */

            int difference = abs ( left_avg - right_avg );

            if ( result > difference ) {
                result = difference;
                idx = i;
            }
        }

        return idx;
    }
};




















// Approach 1: Brute Force
// Time complexity of O(n^2)  because it uses two nested loops to calculate the left and right sums for each index
// Space complexity of O(1) because it only uses a constant amount of space to store variables, regardless of the size of the input array.

// class Solution {
// public:
//     int minimumAverageDifference(vector<int>& nums) {
//         int n = nums.size();
//         int result = INT_MAX;
//         int idx = -1;

//         for (int i = 0; i < n; i++) {
//             long long left_sum = 0;
//             long long right_sum = 0;

//             // Calculate left sum
//             for (int j = 0; j <= i; j++) {
//                 left_sum += nums[j];
//             }

//             // Calculate right sum
//             for (int j = i + 1; j < n; j++) {
//                 right_sum += nums[j];
//             }

//             int n1 = i + 1;
//             int n2 = n - n1;

//             long long left_avg = left_sum / n1;
//             long long right_avg = (i == n - 1) ? 0 : right_sum / n2;

//             int difference = abs(left_avg - right_avg);

//             if (result > difference) {
//                 result = difference;
//                 idx = i;
//             }
//         }

//         return idx;
//     }
// };

/*
    time limit exceeds in the brute force approach
*/

















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=odP1T58kNQY
*/