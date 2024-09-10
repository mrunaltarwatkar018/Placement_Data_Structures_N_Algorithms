/*    Leetcode Problem No.: 2326. Spiral Matrix IV    */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/spiral-matrix-iv/description
*/




/************************************************ C++ ************************************************/
//Simple SImulation
//T.C : O(m*n)
//S.C : O(1) (I am not considering the result matrix we have to return as result)



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*

    Summary :

        The approach converts a linked list into a matrix filled in a spiral order. The 
        matrix is initially filled with -1, representing empty cells. The spiral filling 
        process starts from the top-left corner and follows four directions cyclically: 
        left-to-right, top-to-down, right-to-left, and down-to-top. The boundaries (top, 
        down, left, and right) are updated after each traversal to shrink the matrix region, 
        ensuring that the spiral continues inward.

        At each step, the current value of the linked list node is placed into the matrix, 
        and the linked list pointer moves to the next node. The loop continues until the 
        entire matrix is filled or the linked list is exhausted.

    Simple SImulation
    T.C : O(m*n)
    S.C : O(1) (I am not considering the result matrix we have to return as result)
        
*/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id    = 0; //0, 1, 2, 3
        int top   = 0; // represent first row
        int down  = m-1; // represent last row
        int left  = 0; // represent first column
        int right = n-1; // represent last column

        while(top <= down && left <= right) {
            
            if(id == 0) { //left to right
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }
        return matrix;
    }
};


/************************************************ JAVA ************************************************/
//Simple SImulation
//T.C : O(m*n)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        
        // Initialize the matrix with -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = -1;
            }
        }

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        int id = 0; // Direction identifier (0: left->right, 1: top->down, 2: right->left, 3: down->top)

        while (top <= down && left <= right && head != null) {
            if (id == 0) { // left to right
                for (int i = left; i <= right && head != null; i++) {
                    matrix[top][i] = head.val;
                    head = head.next;
                }
                top++;
            } 
            else if (id == 1) { // top to down
                for (int i = top; i <= down && head != null; i++) {
                    matrix[i][right] = head.val;
                    head = head.next;
                }
                right--;
            } 
            else if (id == 2) { // right to left
                for (int i = right; i >= left && head != null; i--) {
                    matrix[down][i] = head.val;
                    head = head.next;
                }
                down--;
            } 
            else if (id == 3) { // down to top
                for (int i = down; i >= top && head != null; i--) {
                    matrix[i][left] = head.val;
                    head = head.next;
                }
                left++;
            }

            id = (id + 1) % 4; // Cycle through directions
        }

        return matrix;
    }
}



/// another way
class Solution
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    static ArrayList<Integer> spirallyTraverse(int matrix[][], int r, int c)
    {
    //   Declaraing an arrayList for storing the results
    ArrayList<Integer> spiralMat = new ArrayList<Integer>();
    // Declaring 4 pointers
    int startRow=0;
    int endRow=r-1;
    int startColumn=0;
    int endColumn=c-1;
    
    // Logic goes here
    
    while(startRow<=endRow && startColumn<=endColumn)
    {
            //from the starting row
        for(int i=startColumn;i<=endColumn;i++)
        {
            spiralMat.add(matrix[startRow][i]);
        }
        startRow++;
        
           //from the ending column
        for(int i=startRow;i<=endRow;i++)
        {
            spiralMat.add(matrix[i][endColumn]);
        }
        endColumn--;
        
        if(startRow<=endRow)
        {
               //from the ending row
        for(int i=endColumn;i>=startColumn;i--)
        {
            spiralMat.add(matrix[endRow][i]);
        }
        endRow--;
        }
        
        if(startColumn<=endColumn)
        {
               //from the starting Column
        for(int i=endRow;i>=startRow;i--)
        {
            spiralMat.add(matrix[i][startColumn]);
        }
        startColumn++;
        }
    }
    return spiralMat;
    }
}