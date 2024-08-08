/* Leetcode Problem No.: 885. Spiral Matrix III  */

/*
    Company Tags                : Google, Meta
    Leetcode Link               : https://leetcode.com/problems/spiral-matrix-iii/
*/

/************************************************ C++ ************************************************/
// Simple SImulation
// T.C : O(max(rows,cols)^2)
// S.C : O(1) (I am not considering the result matrix we have to return as result)

/*
    Summary :

        The provided Java code implements a solution to traverse a matrix in a spiral order 
        starting from a given cell (rStart, cStart). The algorithm uses an array of direction 
        vectors to navigate east, south, west, and north cyclically. It dynamically adjusts the 
        number of steps taken in each direction, increasing the step count after completing 
        movements in the east or west directions.

        Key points of the solution include:

            Initialization: 
                Set up direction vectors, a result array to store coordinates, and initial 
                values for steps and direction.

            Traversal Loop: 
                Continue until all cells are visited, adjusting the direction and step count as 
                needed.

            Boundary Checks: 
                Ensure that only valid grid positions are added to the result.

        The time complexity is O(max(rows,cols)^2) due to the quadratic growth of steps needed 
        to cover the grid and potential movements outside the grid boundaries.
*/


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions =  {
                                            {0, 1},  //EAST
                                            {1, 0},  //SOUTH
                                            {0, -1}, //WEST
                                            {-1, 0}  //NORTH
                                        };
        
        vector<vector<int>> result;  
        int step = 0; //how much steps to move
        int dir  = 0; //Which direction

        result.push_back({rStart, cStart});

        while (result.size() < rows * cols) {
            //When we move EAST or WEST, we need to increase our steps by 1
            if (dir == 0 || dir == 2) step++;

            for (int i = 0; i < step; i++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) // check valid
                    result.push_back({rStart, cStart});
            }

            dir = (dir + 1) % 4; // turn to next direction
        }
        return result;
    }
};


/************************************************ PYTHON ************************************************/
class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        """
        :type rows: int
        :type cols: int
        :type rStart: int
        :type cStart: int
        :rtype: List[List[int]]
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # EAST, SOUTH, WEST, NORTH
        result = [[rStart, cStart]]
        step = 0
        dir_idx = 0

        while len(result) < rows * cols:
            if dir_idx == 0 or dir_idx == 2:
                step += 1

            for _ in range(step):
                rStart += directions[dir_idx][0]
                cStart += directions[dir_idx][1]

                if 0 <= rStart < rows and 0 <= cStart < cols:
                    result.append([rStart, cStart])

            dir_idx = (dir_idx + 1) % 4

        return result


/************************************************ PYTHON 3 ************************************************/

from typing import List

class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # EAST, SOUTH, WEST, NORTH
        result = [[rStart, cStart]]
        step = 0
        dir_idx = 0

        while len(result) < rows * cols:
            if dir_idx == 0 or dir_idx == 2:
                step += 1

            for _ in range(step):
                rStart += directions[dir_idx][0]
                cStart += directions[dir_idx][1]

                if 0 <= rStart < rows and 0 <= cStart < cols:
                    result.append([rStart, cStart])

            dir_idx = (dir_idx + 1) % 4

        return result


/************************************************ JAVA ************************************************/
//Simple SImulation
//T.C : O(max(rows,cols)^2)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int[][] directions = {
            {0, 1},  // EAST
            {1, 0},  // SOUTH
            {0, -1}, // WEST
            {-1, 0}  // NORTH
        };
        
        int[][] result = new int[rows * cols][2];  
        int step = 0; // how many steps to move
        int dir  = 0; // which direction

        result[0] = new int[]{rStart, cStart};
        int count = 1;

        while (count < rows * cols) {
            // When we move EAST or WEST, we need to increase our steps by 1
            if (dir == 0 || dir == 2) step++;

            for (int i = 0; i < step; i++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) { // check valid
                    result[count++] = new int[]{rStart, cStart};
                }
            }

            dir = (dir + 1) % 4; // turn to next direction
        }
        
        return result;
    }
}














/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dt0UzAz7SPg
*/