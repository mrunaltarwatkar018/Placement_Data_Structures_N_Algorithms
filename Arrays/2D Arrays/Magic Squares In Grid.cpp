/* Leetcode Problem No.: 840. Magic Squares In Grid  */

/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/magic-squares-in-grid
*/

/******************************************** C++ ********************************************/
// Approach-1 (Brute Force)
// T.C : O(m*n)
// S.C : O(1)

/*
    Summary :

        Just simple iterate and check all possible 3*3 Grids.
            1)  Check uniqueness of elements in 3x3 Grid and if it contains elements from 1 to 9 only
            2)  Check If row sums and column sums are all equal
            3)  Check if diagonal and anti-diagonal sums are all equal
*/



class Solution {
public:

    bool isMagicSquare( vector<vector<int>>& grid, int r, int c ) {
        // Unique numbers between 1 and 9
        unordered_set<int> st;

        for ( int  i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.count(num)) {
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }

        // check Sum - Rows and Columns
        int SUM = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for ( int  i = 0; i < 3; i++ ) {
            if ( grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != SUM ) { //Row sum
                return false;
            }


            if ( grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != SUM ) { //Col sum
                return false;
            }
        }

        // check Sum - Diagonal and Anti-Diagonal
        if ( grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != SUM ) { // Diagonal Sum
            return false;
        }

        if ( grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != SUM ) { // Anti-Diagonal Sum
            return false;
        }

        return true;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.size();

        int count = 0;

        for ( int i = 0; i <= rows - 3; i++ ) {
            for ( int j = 0; j <= cols - 3; j++ ) {
                if ( isMagicSquare(grid, i, j) ) {
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
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        // Must have Unique numbers between 1 and 9
        unordered_set<int> nums;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || nums.count(num)) {
                    return false;
                } else {
                    nums.insert(num);
                }
            }
        }

        // Check sums
        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        for (int i = 0; i < 3; ++i) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum || //Row sum
                grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum) { //Col sum
                return false;
            }
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum || // Diagonal
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) { // Anti Diagonal
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};



//Approach-2 (Using Maths and Observation) - 
//T.C : O(m*n)
//S.C : O(1)




/******************************************** JAVA ********************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    
    private boolean isMagicGrid(int[][] grid, int r, int c) {
        // Uniqueness check for numbers 1 to 9
        Set<Integer> st = new HashSet<>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.contains(num)) {
                    return false;
                } else {
                    st.add(num);
                }
            }
        }

        // Check the sum for rows and columns
        int SUM = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != SUM) {
                return false;
            }
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != SUM) {
                return false;
            }
        }

        // Check the diagonal and anti-diagonal
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != SUM) {
            return false;
        }
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != SUM) {
            return false;
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicGrid(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
}


//Approach-2 (Using Maths and Observation) - 
//T.C : O(m*n)
//S.C : O(1)








































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KgiW_AtaBPo
*/