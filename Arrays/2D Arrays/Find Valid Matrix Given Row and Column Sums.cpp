/* Leetcode Problem No.: 1605. Find Valid Matrix Given Row and Column Sums  */

/*
    Company Tags                : Facebook, Uber, Google, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
*/

/************************************************************ C++ ********************************************************************************/
// Approach (Using simple Greedy)
// T.C : O(m+n)
// S.C : O(m*n) //You can exclude this because it is what is expected to return from the function

/*
    Summary :
        
        The provided solution constructs a 2D matrix based on the given rowSum and 
        colSum arrays by following these steps:

        Initialize Matrix: 
            Create a 2D matrix vec of size m x n, where m is the 
            length of rowSum and n is the length of colSum.

        Iterate Through Rows and Columns: 
            Use two pointers, i for rows and j for columns, both starting at 0.

        Assign Minimum Values: 
            At each step, set vec[i][j] to the minimum of rowSum
            [i] and colSum[j]. This ensures that the value assigned is within the 
            constraints of the remaining sums for the current row and column.

        Update Sums: 
            Subtract the assigned value from both rowSum[i] and colSum[j].

        Move Pointers: 
            If rowSum[i] becomes 0, increment i to move to the next row. If colSum
            [j] becomes 0, increment j to move to the next column.

        Repeat Until Complete: 
            Continue this process until all elements of rowSum and colSum are 
            reduced to 0, ensuring the matrix satisfies the required row and column 
            sums.

        The algorithm ensures that the matrix will always fulfill the given 
        requirements, as it greedily assigns the minimum possible value to each 
        matrix cell while maintaining the constraints of rowSum and colSum.
*/


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> vec(m, vector<int>(n));
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            vec[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= vec[i][j];
            colSum[j] -= vec[i][j];

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
            
        }
        return vec;
    }
};






























/************************************************************ JAVA ********************************************************************************/
//Approach (Using simple Greedy)
//T.C : O(m+n)
//S.C : O(m*n) //You can exclude this because it is what is expected to return from the function
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.length;
        int n = colSum.length;
        int[][] matrix = new int[m][n];
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            matrix[i][j] = Math.min(rowSum[i], colSum[j]);

            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];

            if (rowSum[i] == 0) i++;
            if (colSum[j] == 0) j++;
        }
        
        return matrix;
    }
}


































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9dKdLNlmxco
*/