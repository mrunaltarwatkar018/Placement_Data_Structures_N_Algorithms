/*    Leetcode Problem No.: 951. Flip Equivalent Binary Trees    */

/*
    Company Tags                : Microsoft
    Leetcode Premium Qn         : https://leetcode.com/problems/flip-equivalent-binary-trees 
*/






/****************************************************** C++ *********************************************/
//Approach - Simple Recursion
//T.C : ~O(4*n)
//S.C : O(n) system stack space because of Recursion
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL) {
            return false;
        }

        if(root1 -> val == root2->val) {
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
                    flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }

        return false;
    }
};


/****************************************************** JAVA *********************************************/
//Approach - Simple Recursion
//T.C : ~O(4*n)
//S.C : O(n) system stack space because of Recursion
class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }
        
        if (root1 == null || root2 == null) {
            return false;
        }

        if (root1.val == root2.val) {
            return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) ||
                    (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
        }

        return false;
    }
}