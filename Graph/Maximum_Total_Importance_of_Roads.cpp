/* Leetcode Problem No.: 2285. Maximum Total Importance of Roads  */

/*
    Company Tags                : ADOBE
    Leetcode Link               : https://leetcode.com/problems/maximum-total-importance-of-roads
*/


/***************************************************************************** C++ *****************************************************************************/

/*

Approach Summary :

            The approach to solving the problem of calculating the maximum 
            importance of nodes in a graph involves the following steps:

        Degree Calculation:

            Initialize an array to store the degree (number of edges connected) of 
            each node.
            Traverse the list of roads (edges) to update the degree of each node.

        Sorting:

            Sort the degree array in ascending order. This allows assigning higher 
            values to nodes with higher degrees in the subsequent step.

        Calculating Maximum Importance:

            Initialize variables to track the current value and the total sum.
            Iterate over the sorted degree array, multiplying each degree by an 
            incrementing value, and add the result to the sum.

        Result:

            The final sum represents the maximum importance, calculated by 
            strategically assigning higher values to nodes with higher degrees.
        
            By sorting the degrees and assigning incremental values, the approach 
            ensures that nodes with higher connectivity contribute more to the      
            overall importance, thus maximizing the total importance.
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // n = total number of nodes numbered from 0 to n-1
        vector<int> degree(n, 0);  // SC: O(n)

        for (auto& vec : roads) { // T.C: O(E)
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree), end(degree)); // asecending order // T.C: O(nlogn)

        long long value = 1;
        long long sum = 0;

        for(int i = 0; i < n; i++) { // O(n)
            sum += (degree[i] * value);
            value++;
        }

        return sum;
    }
};


//Approach (using degree and assiging value greedily)
//T.C : O(E + nlogn)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //n = total number of nodes numbered from 0 to n-1

        vector<int> degree(n, 0);

        // Calculate the degree of each node
        for(auto &vec : roads) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        // Sort the degrees in ascending order
        sort(begin(degree), end(degree)); //ascedning order

        long long value = 1;
        long long sum   = 0;

        // Calculate the sum of degrees multiplied by their corresponding values
        for(int i = 0; i < n; i++) {
            sum += (degree[i] * value);
            value++;
        }

        return sum;
    }
};


/***************************************************************************** JAVA *****************************************************************************/
//Approach (using degree and assiging value greedily)
//T.C : O(E + nlogn)
//S.C : O(n)
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        // n = total number of nodes numbered from 0 to n-1

        int[] degree = new int[n];

        // Calculate the degree of each node
        for (int[] road : roads) {
            int u = road[0];
            int v = road[1];

            degree[u]++;
            degree[v]++;
        }

        // Sort the degrees in ascending order
        Arrays.sort(degree);

        long value = 1;
        long sum = 0;

        // Calculate the sum of degrees multiplied by their corresponding values
        for (int i = 0; i < n; i++) {
            sum += (degree[i] * value);
            value++;
        }

        return sum;
    }
}















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=p4y_rQeB2mg
*/