/* Leetcode Problem No.: 62. Unique Paths  */

/*
    Company Tags                : Amazon, Cisco, Paytm, OLA Cabs, Walmart, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/unique-paths/
*/

// ************************************************************ C++ ************************************************************

/*
    Approach 1: Recursion
        This approach solves the problem by recursively calculating the number of 
        unique paths to the bottom-right corner of the grid from the top-left corner. 
        Base cases handle out-of-bound conditions and the finish cell.
        Recursive calls sum up the ways from the cell below and the cell to the right.
        Time complexity: O(2^(m+n)), Space complexity: O(m+n)
*/


// Approach-1 - Recursion - TLE - 38 / 63 testcases passed.
// T.C : O(2^(m+n))
// S.C : O(m+n)
class Solution {
public:
    int solve(int i, int j, int m; int n) {
        if ( i == m - 1 && j == n - 1) {
            return 1; // we found 1 path to reach [m-1][n-1]
        }

        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return 0; // invalid path
        }

        int right = solve(i, j + 1, m, n);
        int down = solve(i + 1, j, m, n);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};


/*
    Approach 2: Recursion + Memoization
        This approach solves the problem by recursively calculating the number of 
        unique paths to the bottom-right corner of the grid from the top-left corner. 
        Memoization (a 2D array t) is used to store intermediate results to avoid 
        redundant computations.
        Base cases handle out-of-bound conditions and the finish cell.
        Recursive calls sum up the ways from the cell below and the cell to the right.
        Time complexity: O(m*n), Space complexity: O(m*n)
*/


// Approach-2 - Recursion + Memoization
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> & t) {
        if ( i == m - 1 && j == n - 1) {
            return 1; // we found 1 path to reach [m-1][n-1]
        }

        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return 0; // invalid path
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j + 1, m, n, t);
        int down = solve(i + 1, j, m, n, t);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int> (n+1, -1));
        return solve(0, 0, m, n, t);
    }
};

/*
    Approach 3: Bottom-Up Dynamic Programming
        This approach builds a 2D DP table iteratively, where t[i][j] represents 
        the number of ways to reach the cell [i][j]. The values are calculated based 
        on the sum of ways from the cell above [i−1][j] and the cell to the left [i][j−1]. 
        First row and column are initialized to 1, as there is only one way to move along 
        these edges. The value at [m−1][n−1] represents the total unique paths.
        Time complexity: O(m*n), Space complexity: O(m*n)
*/


// Approach-3 (using Bottom Up)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    //source = [0][0]
    //Dest = [0][0]
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));
        //t[i][j] = total no. of ways to reach [i][j] from [0][0]

        t[0][0] = 1; //total ways to reach 0,0 from 0,0

        //Fill 0th row
        for(int col = 1; col < n; col++) {
            t[0][col] = 1;
        }

        //Fill 0th col
        for(int row = 1; row < m; row++) {
            t[row][0] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];

    }
};



// ************************************************************ JAVA ************************************************************
//Approach-1 - Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public int solve(int i, int j, int m, int n, int[][] t) {
        // Base case: Reached the bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        // If already computed, return the stored result
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Calculate the number of paths by going right and down
        int right = solve(i, j + 1, m, n, t);
        int down = solve(i + 1, j, m, n, t);

        // Store the result in the memoization table
        return t[i][j] = right + down;
    }

    public int uniquePaths(int m, int n) {
        // Create a memoization table initialized with -1
        int[][] t = new int[m][n];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        // Start the recursive computation from the top-left cell
        return solve(0, 0, m, n, t);
    }
}
    
//Approach-2 (using Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
//Note : You can write C++ code above as simple as this one but I commented the code above for clarity and added some extra line of code for clarity
class Solution {
    public int uniquePaths(int m, int n) {
        // Create a 2D array for storing the number of ways to reach each cell
        int[][] t = new int[m][n];

        // Initialize the first row
        for (int col = 0; col < n; col++) {
            t[0][col] = 1; // Only one way to reach any cell in the first row
        }

        // Initialize the first column
        for (int row = 0; row < m; row++) {
            t[row][0] = 1; // Only one way to reach any cell in the first column
        }

        // Fill the rest of the table using the relation:
        // t[i][j] = t[i-1][j] + t[i][j-1]
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }

        // The bottom-right cell contains the total number of unique paths
        return t[m - 1][n - 1];
    }
}