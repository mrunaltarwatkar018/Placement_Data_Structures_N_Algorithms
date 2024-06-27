/* Leetcode Problem No.: 48. Rotate Image  */

/*
    Company Tags                : Amazon, DE-Shaw, Microsoft, Morgan Stanley, Paytm, Samsung, Snapdeal, Zoho
    Similar GfG Link            : https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1
    Leetcode Link               : https://leetcode.com/problems/rotate-image/
*/

// one way
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size(); // m = row
        int n = m;             // n = coloum

        // Transpose
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //  reverse the rows of this transpose matrix

        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// another way

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        //find transpose
        for(int i = 0; i<N; i++) {
            for(int j = i; j<N; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //flip horizontally - For clock wise rotation
        for(int i = 0; i<N; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        /*
        //flip vertically - For anticlock wise rotation
        for(int col = 0; col<N; col++) {
            int row = 0;
            int mid = n/2;
            while(row < mid) {
                swap(matrix[row][col], matrix[n-row-1][col]);
                row++;
            }
        }
        */
    }
};



/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=I48Z8QlQH8c&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=8
*/