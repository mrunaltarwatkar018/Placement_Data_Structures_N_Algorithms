/*    Leetcode Problem No.: 543. Diameter of Binary Tree   */

/*
    COmpany Tags                : Amazon, Cadence India, Directi, MakeMyTrip, Microsoft, Oracle, OYO Rooms, Philips, Salesforce, Snapdeal, VMWare
    Leetcode Link               : https://leetcode.com/problems/diameter-of-binary-tree/
*/

/************************************************ C++ ************************************************/
// T.C : O(n)
// S.C : O(depth of tree) - Recursion System Stack Space

/*
    Approach Summary : 

        The logic of the diameterOfBinaryTree method is based on a 
        recursive approach to find the diameter of a binary tree. It 
        utilizes the diameter private method to traverse the tree, 
        calculating the length of the longest path passing through each 
        node. Within the diameter method:

        If the current node is null, it returns 0.

        It recursively calculates the diameter of the left and right 
        subtrees.

        It updates the result variable with the maximum diameter 
        encountered so far, considering the path passing through the 
        current node.
        
        It returns the maximum length between the left and right subtrees 
        plus 1, representing the length of the path from the current node 
        to the deepest leaf.

        Finally, the diameterOfBinaryTree method initializes a variable 
        result with the smallest possible integer value, calls the 
        diameter method to compute the diameter, and returns the maximum 
        diameter found.

*/

class Solution {
public:

    int solve(TreeNode* root,int & result) {
        if (!root) 
            return 0;

        int leftSide = solve(root -> left, result);
        int rightSide = solve(root -> right, result);

        result = max(result, leftSide + rightSide);   //What if I longest diamenter passes through left -> me -> right

        return max(leftSide, rightSide) + 1;  //But I will return max I can afford if (left -> me -> right) was not answer
    } 
    int diameterOfBinaryTree(TreeNode* root) {

        if (!root) 
            return 0;

        int result = INT_MIN;

        solve(root, result);

        return result;
    }
};
















// another way
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root){
        return !root ? 0 : max(maxDepth(root->right), maxDepth(root->left))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int rootDiameter = maxDepth(root->left)+maxDepth(root->right);
        return max(rootDiameter,max(leftDiameter,rightDiameter));
    }
};



/************************************************ JAVA ************************************************/
//T.C : O(n)
//S.C : O(depth of tree) - Recursion System Stack Space
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;

        int[] result = { Integer.MIN_VALUE };
        diameter(root, result);

        return result[0];
    }

    private int diameter(TreeNode root, int[] result) {
        if (root == null)
            return 0;

        int left = diameter(root.left, result);
        int right = diameter(root.right, result);

        result[0] = Math.max(result[0], left + right);

        return Math.max(left, right) + 1;
    }
};





























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=15KwRECEXLU
*/