/* Leetcode Problem No.: 959. Regions Cut By Slashes  */

/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/regions-cut-by-slashes/?envType=daily-question&envId=2024-08-10
*/

/************************************************************ C++ ************************************************/
//Simple Approach - Counting left and right values
//T.C : O(rows*cols)
//S.C : O(rows*cols)

/*
    Summary :

        The approach in this solution aims to count the number of distinct regions formed by slashes 
        ('/' and '\') in a grid. 
        
        The strategy involves:

            Grid Expansion: 
                Each cell in the original grid is expanded into a 3x3 sub-grid to handle the slashes 
                more easily. A slash '/' is represented by marking a diagonal from the top-right to the 
                bottom-left in the sub-grid, and a backslash '\' is represented by marking a diagonal 
                from the top-left to the bottom-right.

            Depth-First Search (DFS): 
                The algorithm uses DFS to explore and mark connected regions of unmarked cells (0s) in 
                the expanded grid. This is done by checking each cell, and if it is unmarked, the DFS 
                marks it and recursively explores its neighboring cells in four possible directions 
                (up, down, left, right).

            Counting Regions: 
                For every unmarked cell found in the expanded grid, the algorithm initiates a DFS to 
                mark the entire connected region, and increments the region count.

            Final Output: 
                The total count of DFS operations corresponds to the number of distinct regions formed 
                by the slashes in the original grid.

        This approach effectively breaks down the problem into manageable components by expanding the 
        grid and using DFS to explore and count regions.
*/

class Solution {
public:

    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j) {
        // out of bound
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1) {
            return;
        }

        matrix[i][j] = 1; //mark visited

        numberOfIslandsDFS(matrix, i+1, j);
        numberOfIslandsDFS(matrix, i-1, j);
        numberOfIslandsDFS(matrix, i, j+1);
        numberOfIslandsDFS(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0)); //M * N

        //Populate the matrix using the mapping of '/', '\'

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        //Apply concept of "Number of Islands"

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) { //DFS
                    numberOfIslandsDFS(matrix, i, j);
                    regions += 1;
                }
            }
        }

        return regions;
    }
};


// another way
class Solution {
public:

    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1)
            return;
        
        matrix[i][j] = 1; //mark visited

        for(const auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            numberOfIslandsDFS(matrix, new_i, new_j);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0)); //M * N

        //Populate the matrix using the mapping of '/', '\'

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }


        //Apply concept of "Number of Islands"
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) { //DFS
                    numberOfIslandsDFS(matrix, i, j);
                    regions += 1;
                }
            }
        }

        return regions;

    }
};






/************************************************************ PYTHON ************************************************/
class Solution(object):
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def numberOfIslandsDFS(matrix, i, j):
            if i < 0 or i >= len(matrix) or j < 0 or j >= len(matrix[0]) or matrix[i][j] == 1:
                return
            matrix[i][j] = 1  # mark visited
            for dir in directions:
                new_i = i + dir[0]
                new_j = j + dir[1]
                numberOfIslandsDFS(matrix, new_i, new_j)

        rows = len(grid)
        cols = len(grid[0])
        regions = 0

        matrix = [[0] * (cols * 3) for _ in range(rows * 3)]  # M * N

        # Populate the matrix using the mapping of '/', '\'
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '/':
                    matrix[i * 3][j * 3 + 2] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    matrix[i * 3][j * 3] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3 + 2] = 1

        # Apply concept of "Number of Islands"
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:  # DFS
                    numberOfIslandsDFS(matrix, i, j)
                    regions += 1

        return regions


// another way
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def numberOfIslandsDFS(matrix, i, j):
            if i < 0 or i >= len(matrix) or j < 0 or j >= len(matrix[0]) or matrix[i][j] == 1:
                return
            matrix[i][j] = 1  # mark visited
            for dir in directions:
                new_i = i + dir[0]
                new_j = j + dir[1]
                numberOfIslandsDFS(matrix, new_i, new_j)

        rows = len(grid)
        cols = len(grid[0])
        regions = 0

        matrix = [[0] * (cols * 3) for _ in range(rows * 3)]  # M * N

        # Populate the matrix using the mapping of '/', '\'
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '/':
                    matrix[i * 3][j * 3 + 2] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    matrix[i * 3][j * 3] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3 + 2] = 1

        # Apply concept of "Number of Islands"
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:  # DFS
                    numberOfIslandsDFS(matrix, i, j)
                    regions += 1

        return regions



/************************************************************ PYTHON 3 ************************************************/
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def numberOfIslandsDFS(matrix, i, j):
            if i < 0 or i >= len(matrix) or j < 0 or j >= len(matrix[0]) or matrix[i][j] == 1:
                return
            matrix[i][j] = 1  # mark visited
            for dir in directions:
                new_i = i + dir[0]
                new_j = j + dir[1]
                numberOfIslandsDFS(matrix, new_i, new_j)

        rows = len(grid)
        cols = len(grid[0])
        regions = 0

        matrix = [[0] * (cols * 3) for _ in range(rows * 3)]  # M * N

        # Populate the matrix using the mapping of '/', '\'
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '/':
                    matrix[i * 3][j * 3 + 2] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    matrix[i * 3][j * 3] = 1
                    matrix[i * 3 + 1][j * 3 + 1] = 1
                    matrix[i * 3 + 2][j * 3 + 2] = 1

        # Apply concept of "Number of Islands"
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:  # DFS
                    numberOfIslandsDFS(matrix, i, j)
                    regions += 1

        return regions


// another way
from typing import List

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        rows, cols = len(grid), len(grid[0])
        matrix = [[0] * (cols * 3) for _ in range(rows * 3)]

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '/':
                    matrix[i*3][j*3+2] = 1
                    matrix[i*3+1][j*3+1] = 1
                    matrix[i*3+2][j*3] = 1
                elif grid[i][j] == '\\':
                    matrix[i*3][j*3] = 1
                    matrix[i*3+1][j*3+1] = 1
                    matrix[i*3+2][j*3+2] = 1

        def dfs(i, j):
            if i < 0 or i >= len(matrix) or j < 0 or j >= len(matrix[0]) or matrix[i][j] == 1:
                return
            matrix[i][j] = 1
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

        regions = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    dfs(i, j)
                    regions += 1

        return regions








/************************************************************ JAVA ************************************************/
//Simple Approach - Counting left and right values
//T.C : O(rows*cols)
//S.C : O(rows*cols)
class Solution {
    // Directions array for moving up, down, left, and right
    private int[][] directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // DFS method to explore the grid and mark visited cells
    private void numberOfIslandsDFS(int[][] matrix, int i, int j) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == 1) {
            return;
        }

        matrix[i][j] = 1; // mark visited

        // Explore all four directions
        for (int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            numberOfIslandsDFS(matrix, new_i, new_j);
        }
    }

    public int regionsBySlashes(String[] grid) {
        int rows = grid.length;
        int cols = grid[0].length();

        int regions = 0;

        // Create a 3x3 expanded grid to handle slashes
        int[][] matrix = new int[rows * 3][cols * 3];

        // Populate the matrix based on '/' and '\\' in the original grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i].charAt(j) == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i].charAt(j) == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        // Apply DFS to count the regions
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    numberOfIslandsDFS(matrix, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
}



























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zMqgIbLLsc4
*/