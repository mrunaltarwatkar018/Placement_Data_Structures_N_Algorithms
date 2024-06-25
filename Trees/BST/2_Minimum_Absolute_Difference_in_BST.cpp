/*    Leetcode Problem No.: 530. Minimum Absolute Difference in BST    */

/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=yNvt9ejf9Ec
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-absolute-difference-in-bst
*/

//SAMEW PROBLEM (Leetcode - 783) "Minimum Distance Between BST Nodes"
// LeetCOde Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

//Using Simple InOrder traversal - T.C : O(n)



// Approach 1: prev as a by reference
class Solution {
public:
    int minDiff = INT_MAX;

    // prev as a by reference
    void inOrder(TreeNode* root, TreeNode*& prev) {

        if (root == NULL)
            return;

        inOrder(root->left, prev);  // L

        if (prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }

        prev = root;

        inOrder(root->right, prev);
    }

    int getMinimumDifference(TreeNode* root) {
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

    int getMinimumDifference(TreeNode* root) {
        prev = NULL;
        inOrder(root);
        return minDiff;
    }
};