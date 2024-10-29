/* Leetcode Problem No.: 2684. Maximum Number of Moves in a Grid */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
*/


// TIme limit Exceed


class Solution {
public:
    int m; // rows
    int n; // cols

    vector<int> directions = { -1, 0, 1 };

    int DFS(int row, int col, vector<vector<int>> &grid ) {
        int moves = 0;

        for ( int &dir : directions ) {
            int newRow = row + dir;
            int newCol = col + 1;

            if ( newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + DFS(newRow, newCol, grid));
            }
        }

        return moves;
    }


    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;

        for ( int row = 0; row < m; row++ ) {
            result = max(result, DFS(row, 0, grid));
        }

        return result;
    }
};













// optimized way


class Solution {
public:
    int m; // rows
    int n; // cols

    vector<int> directions = { -1, 0, 1 };

    int DFS(int row, int col, vector<vector<int>> &grid, vector<vector<int>> & t) {

        if ( t[row] [col] != -1 ) {
            return t[row][col];
        }

        int moves = 0;

        for ( int &dir : directions ) {
            int newRow = row + dir;
            int newCol = col + 1;

            if ( newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + DFS(newRow, newCol, grid, t));
            }
        }

        return t[row][col] = moves;
    }


    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;

        vector<vector<int>> t(m, vector<int>(n, -1));

        for ( int row = 0; row < m; row++ ) {
            result = max(result, DFS(row, 0, grid, t));
        }

        return result;
    }
};