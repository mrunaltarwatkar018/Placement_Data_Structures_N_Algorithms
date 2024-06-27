/* Leetcode Problem No.: 54. Spiral Matrix  */


/*
    Company Tags                 :  Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal, 
                                    D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack
    Frequency                    : 80%
    Leetcode Qn Link             : https://leetcode.com/problems/spiral-matrix/
    Similar GfG Link             : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();    // row
        int n = matrix[0].size(); // colums

        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        int dir = 0;

        /*
            dir = 0   -> left  to right
            dir = 1   -> top   to down
            dir = 2   -> right to left
            dir = 3   -> down  to top
        */

        vector<int> result;

        while(top <= down && left <= right) {
            if (dir == 0) {
                // left to right
                // constant : row (top)
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            if (dir == 1) {
                // top to down
                // constant : colums (right)
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if (dir == 2) {
                // right to left
                // constant : row (down)
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            if (dir == 3) {
                // down to top
                // constant : colums (left)
                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;

            if (dir == 4)
                dir = 0;
        }
        return result;
    }
};

















// another way

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        
        int id = 0;
        //id
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top

        while(top <= down && left <= right) {
            //left to right
            if(id == 0) {
                for(int i = left; i<=right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            
            //top to down
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            
            //right to left
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            
            //down to top
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return result;
    }
};



/*
    YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=73j2ipxR958
*/