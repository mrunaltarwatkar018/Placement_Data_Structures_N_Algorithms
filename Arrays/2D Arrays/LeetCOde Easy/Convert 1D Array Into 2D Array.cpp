/* Leetcode Problem No.: 2022. Convert 1D Array Into 2D Array  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/convert-1d-array-into-2d-array
*/





/************************************************************ C++ ************************************************************/
//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result


/*
    Summary :

        Both approaches convert a 1D array (original) into a 2D array (result) with m 
        rows and n columns. However, they differ in how they populate the 2D array.

        First Approach (Nested Loops):

            This method uses two nested loops: the outer loop iterates over the rows, 
            and the inner loop iterates over the columns.

            It keeps track of an index (idx) that is used to access elements in the 1D 
            array and place them in the 2D array sequentially.

            Simple and intuitive, especially when thinking about 2D arrays as rows and 
            columns.


        Second Approach (Single Loop with Division/Modulus):

            Instead of nested loops, this approach uses a single loop that iterates 
            over the entire length of the original array.

            It calculates the row index as i / n and the column index as i % n to 
            directly place elements into the 2D array.

            This approach is more compact, leveraging division and modulus operations 
            to map 1D indices to 2D indices.

        Both methods check if the total number of elements in the original array 
        matches m * n before proceeding. If not, they return an empty 2D array.

*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));

        if ( original.size() != m * n ) {
            return {};
        }

        int idx = 0;

        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                result[i][j] = original[idx];
                idx++;
            }
        }
        return result;
    }
};
// another way to do same 

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;
    }
};


//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result

/*
    Summary :

        Both approaches convert a 1D array (original) into a 2D array (result) with m 
        rows and n columns. However, they differ in how they populate the 2D array.

        First Approach (Nested Loops):

            This method uses two nested loops: the outer loop iterates over the rows, 
            and the inner loop iterates over the columns.

            It keeps track of an index (idx) that is used to access elements in the 1D 
            array and place them in the 2D array sequentially.

            Simple and intuitive, especially when thinking about 2D arrays as rows and 
            columns.


        Second Approach (Single Loop with Division/Modulus):

            Instead of nested loops, this approach uses a single loop that iterates 
            over the entire length of the original array.

            It calculates the row index as i / n and the column index as i % n to 
            directly place elements into the 2D array.

            This approach is more compact, leveraging division and modulus operations 
            to map 1D indices to 2D indices.

        Both methods check if the total number of elements in the original array 
        matches m * n before proceeding. If not, they return an empty 2D array.

*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));

        if ( original.size() != m * n ) {
            return {};
        }

        for ( int i = 0; i < original.size(); i++ ) {
            int row_idx = i / n;
            int col_idx = i % n;

            result[row_idx][col_idx] = original[i];
        }
        return result;
    }
};


// another way to do same 
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        for(int i = 0; i < l; i++) {
            result[i/n][i%n] = original[i];
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if the product of m and n is equal to the size of the original array
        if (m * n != original.length) {
            return new int[0][0];  // Return an empty 2D array if the sizes don't match
        }

        // Initialize the result 2D array
        int[][] result = new int[m][n];

        // Index for the original array
        int idx = 0;

        // Fill the 2D array row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;  // Return the constructed 2D array
    }
}



//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if the total number of elements matches
        if (m * n != original.length) {
            return new int[0][0];  // Return an empty 2D array if the sizes don't match
        }

        // Initialize the result 2D array
        int[][] result = new int[m][n];
        
        // Fill the 2D array using division and modulus to calculate row and column indices
        for (int i = 0; i < original.length; i++) {
            result[i / n][i % n] = original[i];
        }

        return result;  // Return the constructed 2D array
    }
}