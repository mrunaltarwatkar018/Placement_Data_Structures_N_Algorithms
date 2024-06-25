/*    Leetcode Problem No.: 783. Minimum Distance Between BST Nodes    */

/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=yNvt9ejf9Ec
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
*/

//SAMEW PROBLEM (Leetcode - 530) "Minimum Absolute Difference in BST"
// LeetCOde Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst

//Using Simple InOrder traversal - T.C : O(n)
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

// Approach 1: prev as a by reference
class Solution {
public:

    int minDiff = INT_MAX;
    // Approach 1: prev as a by reference
    void inOrder(TreeNode* root, TreeNode* &prev) {
        
        if(root == NULL)
            return;
        
        inOrder(root->left, prev);
        
        if(prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        
        prev = root;
        
        inOrder(root->right, prev);
        
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        inOrder(root, prev);
        return minDiff;
    }
};



// Approach 2:prev as a global variable

class Solution {
public:

    int minDiff = INT_MAX;

    // prev as a global variable
    TreeNode * prev;
    void inOrder(TreeNode* root) {

        if (root == NULL)
            return;

        inOrder(root->left);  // L

        if (prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }

        prev = root;

        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        inOrder(root);
        return minDiff;
    }
};