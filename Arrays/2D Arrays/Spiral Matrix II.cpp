/* Leetcode Problem No.: 54.  Spiral Matrix II  */

/*
    Company Tags                : Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal, D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack
    Frequency                   : 64%
    Leetcode Qn Link            : https://leetcode.com/problems/spiral-matrix-ii/
*/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // base case
        if ( n == 0 ) {
            return {};
        }

        int m = n; // we have to create n * n matrix & n is simalar or same as n

        vector<vector<int>> matrix(m, vector<int> (n));

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        int dir = 0;

        /*
            dir = 0   -> left  to right
            dir = 1   -> top   to down
            dir = 2   -> right to left
            dir = 3   -> down  to top
        */

        int counter = 1;

        while( top <= down && left <= right ) {
            if ( dir == 0 ) {
                // left to right
                // constant : row (top)
                for ( int  i = left; i <= right; i++ ) {
                    matrix[top][i] = counter++;
                }
                top++;
            }

            if ( dir == 1 ) {
                // top to down
                // constant : colums (right)
                for ( int i = top; i <= down; i++ ) {
                    matrix[i][right] = counter++;
                }
                right--;
            }

            if ( dir == 2 ) {
                // right to left
                // constant : row (down)
                for ( int i = right; i >= left; i-- ) {
                    matrix[down][i] = counter++;
                }
                down--;
            }

            if ( dir == 3 ) {
                // down to top
                // constant : colums (left)
                for ( int i = down; i >= top; i-- ) {
                    matrix[i][left] = counter++;
                }
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return matrix;

    }
};






/******************************************************************** Python **************************************************************************/

class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        if n == 0:
            return []
        
        matrix = [[0]*n for _ in range(n)]
        top, down, left, right = 0, n-1, 0, n-1
        id = 0  # 0: left to right, 1: top to down, 2: right to left, 3: down to top
        counter = 1
        
        while top <= down and left <= right:
            # left to right
            if id == 0:
                for i in range(left, right+1):
                    matrix[top][i] = counter
                    counter += 1
                top += 1
            
            # top to down
            elif id == 1:
                for i in range(top, down+1):
                    matrix[i][right] = counter
                    counter += 1
                right -= 1
            
            # right to left
            elif id == 2:
                for i in range(right, left-1, -1):
                    matrix[down][i] = counter
                    counter += 1
                down -= 1
            
            # down to top
            elif id == 3:
                for i in range(down, top-1, -1):
                    matrix[i][left] = counter
                    counter += 1
                left += 1
            
            id = (id+1)%4
        
        return matrix














/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HXdCemhtrNA
*/