/* Leetcode Problem No.: 1022. Sum of Root To Leaf Binary Numbers */

/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
*/


/**************************************************************** C++ *************************************************************/
//Approach - Recursion
//T.C : O(n)
//S.C : O(1) Auxiliary space (But O(n) system recursion stack space)
class Solution {
public:
    int solve(TreeNode* root, int val) {
        if(!root) { //root == NULL
            return 0;
        }

        val = (2*val) + root->val;

        if(root->left == NULL && root->right == NULL)
            return val;
        
        return solve(root->left, val) + solve(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};



/**************************************************************** JAVA *************************************************************/
//Approach - Recursion
//T.C : O(n)
//S.C : O(1) Auxiliary space (But O(n) system recursion stack space)
class Solution {

    int solve(TreeNode root, int val) {

        if (root == null) {
            return 0;
        }

        val = (2 * val) + root.val;

        // If leaf node
        if (root.left == null && root.right == null) {
            return val;
        }

        return solve(root.left, val) + solve(root.right, val);
    }

    public int sumRootToLeaf(TreeNode root) {
        return solve(root, 0);
    }
}