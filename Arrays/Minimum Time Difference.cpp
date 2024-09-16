/* Leetcode Problem No.: 539. Minimum Time Difference  */


/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16
*/

/************************************************************ C++ ************************************************/
//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn)
//S.C : O(n)
//NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]



/*
    Summary :
        The given approach to solving the problem of finding the minimum time difference 
        between time points follows these steps:

        Convert Time to Minutes: 
            The input times are in HH:MM format. For each time string in the timePoints 
            vector, the algorithm extracts the hours and minutes, converts them to integers, 
            and then calculates the total minutes since midnight. These minute values are 
            stored in a separate vector, minutes.

        Sort the Minutes: 
            The minutes vector is sorted to facilitate easy comparison of adjacent time 
            points.

        Find Minimum Difference: 
            After sorting, the minimum time difference between consecutive times is 
            calculated. A loop runs through the sorted list, comparing the difference 
            between each pair of adjacent times.

        Handle Circular Time: 
            To account for the circular nature of the clock (e.g., the difference between 
            23:59 and 00:00), the algorithm also compares the difference between the last 
            and the first time point across midnight.

        Return the Result: 
            The smallest difference found is returned as the result.

        This approach ensures that the minimum time difference is efficiently found using 
        sorting and simple comparisons. The time complexity is dominated by the sorting 
        step, making it O(n log n).

*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);  // Space: O(n) because of sorting

        // Convert timePoints to minutes
        for ( int i = 0; i < n; i++ ) { // Time: O(nlogn)
            string time = timePoints[i];

            string hourSubstr = time.substr(0, 2); //"HH"
            string minSubstr = time.substr(3); //"MM"

            int hourInt = stoi(hourSubstr);
            int minInt  = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }

        // Sort the minutes array
        sort(begin(minutes), end(minutes));

        // Initialize result with the maximum possible value
        int result = INT_MAX;

        // Find the minimum difference between adjacent times
        for(int i = 1; i < n; i++) {
            result = min(result, minutes[i] - minutes[i-1]);
        }

        // Check the circular case (between the first and last times)
        return min(result, (24*60 - minutes[n-1]) + minutes[0]);
    }
};




// using bucket sort
//Bucket sort has a T.C : O(n + k) where n is the number of elements and k is the number of buckets. In this case, k is 1440, which is a constant.
// T.C :  O(n)
//S.C : O(n + k)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);  

        // Convert timePoints to minutes
        for (int i = 0; i < n; i++) { 
            string time = timePoints[i];

            string hourSubstr = time.substr(0, 2); //"HH"
            string minSubstr = time.substr(3); //"MM"

            int hourInt = stoi(hourSubstr);
            int minInt  = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }

        // Implement bucket sort
        vector<int> buckets[1440]; // 1440 possible minutes in a day
        for (int i = 0; i < n; i++) {
            buckets[minutes[i]].push_back(minutes[i]);
        }

        vector<int> sortedMinutes;
        for (int i = 0; i < 1440; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                sortedMinutes.push_back(buckets[i][j]);
            }
        }

        // Initialize result with the maximum possible value
        int result = INT_MAX;

        // Find the minimum difference between adjacent times
        for(int i = 1; i < n; i++) {
            result = min(result, sortedMinutes[i] - sortedMinutes[i-1]);
        }

        // Check the circular case (between the first and last times)
        return min(result, (24*60 - sortedMinutes[n-1]) + sortedMinutes[0]);
    }
};

/************************************************************ JAVA ************************************************/
//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn)
//S.C : O(n)
//NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        int[] minutes = new int[n];

        // Convert timePoints to minutes
        for (int i = 0; i < n; i++) {
            String time = timePoints.get(i);
            String[] parts = time.split(":");

            int hours = Integer.parseInt(parts[0]);
            int mins = Integer.parseInt(parts[1]);

            minutes[i] = hours * 60 + mins;
        }

        // Sort the minutes array
        Arrays.sort(minutes);

        // Initialize result with the maximum possible value
        int result = Integer.MAX_VALUE;

        // Find the minimum difference between adjacent times
        for (int i = 1; i < n; i++) {
            result = Math.min(result, minutes[i] - minutes[i - 1]);
        }

        // Check the circular case (between the first and last times)
        result = Math.min(result, (24 * 60 - minutes[n - 1]) + minutes[0]);

        return result;
    }
}