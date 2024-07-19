/* Leetcode Problem No.: 1380. Lucky Numbers in a Matrix  */

/*
    Company Tags                : Cisco
    Leetcode Link               : https://leetcode.com/problems/lucky-numbers-in-a-matrix
*/


/********************************************************************* C++ ****************************************************************************/
// Approach-1 (Using Simple Traversal and extra space)
// T.C : O(m*n)
// S.C : O(m+n)


/*
    Summary :
        Approach 1: Using Simple Traversal and Extra Space

            Time Complexity (T.C): O(m*n)
            Space Complexity (S.C): O(m+n)

            Summary: 
                This approach involves two main steps:

                Finding Row Minimums: 
                    Traverse each row to find the minimum element in each row and 
                    store these minimums in a list (rowMin).

                Finding Column Maximums: 
                    Traverse each column to find the maximum element in each column 
                    and store these maximums in a list (colMax).

                Finally, it checks for each element in the matrix if it is both the 
                minimum in its row and the maximum in its column. If so, it adds 
                this element to the result list.

*/


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

                vector<int> rowMin;
        for (int row = 0; row < m; row++) {

            int rMin = INT_MAX;
            for (int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }
            rowMin.push_back(rMin);
        }

        vector<int> colMax;
        for (int col = 0; col < n; col++) {

            int cMax = INT_MIN;
            for (int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }
            colMax.push_back(cMax);
        }

        vector<int> result;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]) {
                    result.push_back(matrix[row][col]);
                }
            }
        }

        return result;
    }
};



// Approach-2 (Only one Lucky Number is possible) - Find it Greedily
// T.C : O(m*n)
// S.C : O(1)

/*
    Summary :

        Approach 2: 
        
            Finding the Lucky Number Greedily

            Time Complexity (T.C): O(m*n)
            Space Complexity (S.C): O(1)

            Summary: 
                This approach aims to find a single lucky number using a greedy 
                strategy:

                Finding Maximum of Row Minimums: 
                    Traverse each row to find the minimum element, and track the 
                    maximum of these row minimums (rMinMax).

                Finding Minimum of Column Maximums: 
                    Traverse each column to find the maximum element, and track the 
                    minimum of these column maximums (cMaxMin).

            If the maximum of the row minimums (rMinMax) is equal to the minimum of 
            the column maximums (cMaxMin), this value is the lucky number and is 
            returned as the result. If no such value exists, an empty list is 
            returned.
*/


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //columns

        int rMinMax = INT_MIN;
        
        for(int row = 0; row < m; row++) {

            int rMin = INT_MAX;
            for(int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }

            rMinMax = max(rMinMax, rMin);

        }

        int cMaxMin = INT_MAX;
        for(int col = 0; col < n; col++) {

            int cMax = INT_MIN;
            for(int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }

            cMaxMin = min(cMaxMin, cMax);

        }


        if(rMinMax == cMaxMin) {
            return {rMinMax}; //{cMaxMin}
        }

        return {};
    }
};


// aother way
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        int row_Min_Max = INT_MIN;
        for ( int row = 0; row < m; row++ ) {
            int row_Min = INT_MAX;

            for ( int col = 0; col < n; col++ ) {
                row_Min = min( row_Min, matrix[row][col]);
            }

            row_Min_Max = max(row_Min_Max, row_Min);
        }
        
        int col_Max_Min = INT_MAX;
        for ( int col = 0; col < n; col++ ) {
            int col_Max = INT_MIN;

            for ( int row = 0; row < m; row++ ) {
                col_Max = max( col_Max, matrix[row][col]);
            }

            col_Max_Min = min(col_Max_Min, col_Max);
        }


        if ( row_Min_Max == col_Max_Min ) {
            return {row_Min_Max}; // {col_Max_Min}
        }

        return {};
    }
};













/********************************************************************* JAVA ****************************************************************************/
//Approach-1 (Using Simple Traversal and extra space)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        List<Integer> rowMin = new ArrayList<>();
        for (int row = 0; row < m; row++) {
            int rMin = Integer.MAX_VALUE;
            for (int col = 0; col < n; col++) {
                rMin = Math.min(rMin, matrix[row][col]);
            }
            rowMin.add(rMin);
        }

        List<Integer> colMax = new ArrayList<>();
        for (int col = 0; col < n; col++) {
            int cMax = Integer.MIN_VALUE;
            for (int row = 0; row < m; row++) {
                cMax = Math.max(cMax, matrix[row][col]);
            }
            colMax.add(cMax);
        }

        List<Integer> result = new ArrayList<>();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == rowMin.get(row) && matrix[row][col] == colMax.get(col)) {
                    result.add(matrix[row][col]);
                }
            }
        }

        return result;
    }
}


//Approach-2 (Only one Lucky Number is possible) - Find it Greedily
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length; // rows
        int n = matrix[0].length; // columns

        int rMinMax = Integer.MIN_VALUE;

        for (int row = 0; row < m; row++) {
            int rMin = Integer.MAX_VALUE;
            for (int col = 0; col < n; col++) {
                rMin = Math.min(rMin, matrix[row][col]);
            }
            rMinMax = Math.max(rMinMax, rMin);
        }

        int cMaxMin = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            int cMax = Integer.MIN_VALUE;
            for (int row = 0; row < m; row++) {
                cMax = Math.max(cMax, matrix[row][col]);
            }
            cMaxMin = Math.min(cMaxMin, cMax);
        }

        List<Integer> result = new ArrayList<>();
        if (rMinMax == cMaxMin) {
            result.add(rMinMax); // {cMaxMin}
        }

        return result;
    }
}































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iUM2dOAOA9s
*/