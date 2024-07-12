/* Leetcode Problem No.: 766. Toeplitz Matrix  */


/*
    Company Tags                : Facebook(Meta), Apple, Google
    Leetcode Link               : https://leetcode.com/problems/toeplitz-matrix/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/toeplitz-matrix/1
*/

/*
    A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();  // row
        int n = matrix[0].size();  // col

        for ( int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};






















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=q-WIid5qu-I
*/