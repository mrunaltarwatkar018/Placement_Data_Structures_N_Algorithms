/* Leetcode Problem No.: 63. Unique Paths II  */

/*
    Company Tags                : Amazon, Cisco, Paytm, OLA Cabs, Walmart, LinkedIn
    Letcode Link                : https://leetcode.com/problems/unique-paths-ii/
*/


/************************************************************ C++ ************************************************************/

/*
    Approach-1 (Recursion) - TLE - 31 / 42 testcases passed
        Description:
        The idea is to use recursion to solve this problem. We start from the source cell and try
        to explore all possible paths to reach the destination cell. If we encounter an obstacle
        (represented by 1), we return 0 as we cannot move further from that cell.
        If we reach the destination cell, we return 1 to indicate that we have found a valid path.
        The total number of unique paths is the sum of the number of paths from the right cell and
        the number of paths from the down cell.
        (The final answer is the sum of the number of paths from the right cell and the number of paths
        from the down cell.)
        Time complexity: O(2^(m*n)) - Exponential
        Space complexity: O(m*n) - Due to recursion stack space
*/

// Approach-1 (Recursion) - TLE - 31 / 42 testcases passed
// T.C : O(2^(m*n))
// S.C : O(m*n) due to recursion stack space
class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }

        if(i == m-1 && j == n-1) {
            return 1;
        }

        int right = solve(obstacleGrid, i, j + 1);
        int down = solve(obstacleGrid, i + 1, j);

        return right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return solve(obstacleGrid, 0, 0);
    }
};

/*
Approach 2: Recursion + Memoization

    Description:
        This approach uses recursion to explore all possible paths from the top-left to 
        the bottom-right corner.
        To avoid redundant calculations, a memoization table (t[i][j]) is used to store 
        the number of unique paths from cell (i,j) to the destination.
        The recursive function stops when it encounters an obstacle or goes out of bounds, 
        and it returns 1 when the bottom-right corner is reached.
        (The final answer is stored in the top-left corner of the memoization table.)
    Time complexity: O(m*n) - Each cell is visited at most once.
    Space complexity: O(m*n) - Due to the memoization table.
*/

// Approach-2: (Recursion + Memo)
// Recursion T.C : O(m*n)
// Memo T.C      : O(m*n)
// S.C           : O(m*n)

class Solution {
public:
    int m, n;
    int t[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if(i == m-1 && j == n-1) {
            return 1;
        }

        int right = solve(obstacleGrid, i, j + 1);
        int down = solve(obstacleGrid, i + 1, j);

        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        return solve(obstacleGrid, 0, 0);
    }
};

// or
class Solution {
public:
    int m, n;
    int t[101][101];
    
    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(i == m-1 && j == n-1)
            return 1;
        
        // Why we are not making [i][j] visited ?
        // Because robot can only move down or right so it will never visit any visited cell again
        // int temp = obstacleGrid[i][j];
        // obstacleGrid[i][j] = -1;
        
        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);
        
        // obstacleGrid[i][j] = temp;
        
        return t[i][j] = right + down;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        memset(t, -1, sizeof(t));
        
        return solve(obstacleGrid, 0, 0);
    }
};





/*
    Approach 3: Bottom-Up Dynamic Programming

        Description:
            This approach uses a tabular (iterative) method to build a DP table (t[i][j]) from the top-left 
            corner to the bottom-right corner.
            The first row and column are initialized based on whether obstacles block the path.
            For each cell (i,j), if it's not an obstacle, the number of paths is the sum of paths from 
            the top (t[i-1][j]) and left (t[i][j-1]) cells.
            (The final answer is stored in the bottom-right corner of the DP table.)
        Time complexity: O(m*n) - Each cell is visited once.
        Space complexity: O(m*n) - Due to the DP table.
*/

// Approach-3 (Bottom Up). 
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int> (n, 0));

        // Fill the first Row
        for (int col = 0; col < n; col++) {
            if (col >= 1 && grid[0][col - 1] == 1) {
                t[0][col] = 0;
                grid[0][col] = 1;
            } else if (grid[0][col] == 1) {
                t[0][col] = 0;
            } else {
                t[0][col] = 1;
            }
        }

        // Fill the first column
        for(int row = 0; row<m; row++) {
            if(row > 0 && grid[row-1][0] == 1) {
                t[row][0] = 0;
                grid[row][0] = 1; 
            }
            else if (grid[row][0] == 1) {
                t[row][0] = 0;
            }
            else {
                t[row][0] = 1;
            }
        }

        // rest cells are filling
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(grid[i][j] == 1) {
                    t[i][j] = 0;
                }
                else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }

        return t[m-1][n-1];
    }
};

// or
class Solution {
public:
    int m, n;

    //Tabular approach
    int solve(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> t(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        for(int col = 0; col<n; col++) {
            if(col > 0 && obstacleGrid[0][col-1] == 1) {
                t[0][col] = 0;
                obstacleGrid[0][col] = 1; //Bcz now it's not possible to reach any cell in first row from this cell onwards
            }
            else if(obstacleGrid[0][col] == 1)
                t[0][col] = 0;
            else
                t[0][col] = 1;
        }
        
        for(int row = 0; row<m; row++) {
            if(row > 0 && obstacleGrid[row-1][0] == 1) {
                t[row][0] = 0;
                obstacleGrid[row][0] = 1; //Bcz now it's not possible to reach any cell in first col from this cell onwards
            }
            else if(obstacleGrid[row][0] == 1)
                t[row][0] = 0;
            else
                t[row][0] = 1;
        }
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(obstacleGrid[i][j] == 1)
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        return solve(obstacleGrid);
        
    }
};





************************************************************ JAVA ************************************************************
//Approach-1 (Recursion + Memo)
//Recursion T.C : O(m*n)
//Memo T.C      : O(m*n)
class Solution {
    Integer t[][]=new Integer[101][101];
    int m, n;
    
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
        
        return solve(obstacleGrid, 0, 0);
    }
    int solve(int[][]obstacleGrid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        
        if(t[i][j] != null)
            return t[i][j];
        
        if(i == m-1 && j == n-1)
            return 1;
        
        //Why we are not making [i][j] visited ?
        //Because robot can only move down or right so it will never visit any visited cell again
        //int temp = obstacleGrid[i][j];
        //obstacleGrid[i][j] = -1;
        
        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);
        
        //obstacleGrid[i][j] = temp;
        
        return t[i][j] = right + down;
    }
}