/* Leetcode Problem No.: 1020. Number of Enclaves  */

/*
        Company Tags                : AMAZON
        Leetcode Link               : https://leetcode.com/problems/number-of-enclaves/
*/

//Approach-1 (DFS)

class Solution {
public:

    int m, n;

    void dfs( vector<vector<int>>& grid, int i, int j ) {
        // check boundary conditions
        if( i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 ) {
            return;
        }

        // mark as visited
        grid[i][j] = 0;

        // move left, right, up and down
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // step 1: First column and last column par DFS lagaoo
        for ( int row = 0; row < m; row++ ) {
            // First Column
            if ( grid[row][0] == 1 ) {
                dfs( grid, row, 0 );
            }

            // Last Column

            if ( grid[row][n - 1] == 1) {
                dfs( grid, row, n - 1);
            }
        }

        // step 2: First row and last row par DFS lagaoo
        for ( int column = 0; column < n - 1; column++ ) {
            // First Row
            if ( grid[0][column] == 1 ) {
                dfs( grid, 0, column );
            }

            // Last Row
            if ( grid[m - 1][column] == 1 ) {
                dfs( grid, m - 1, column);
            }
        }

        int count = 0;
        // step 3: count 1s because ye visited nhi hue

        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( grid[i][j] == 1 ) {
                    count++;
                }
            }
        }

        return count;

    }
};

// another way
class Solution {
public:
    
    int m, n;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;

        
        grid[r][c] = 0;
        
        
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            // Last column.
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
            // Last row.
            if (grid[m - 1][i] == 1) {
                dfs(grid, m - 1, i);
            }
        }
        
        
        
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    count += 1;
                }
                
            }
        }
        
        return count;
    }
};


//Approach-2 (Using BFS)
//will soon share here

























/*
        YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dYOm367BdbM
*/