/*    Leetcode Problem No.: 1001. Symmetric Tree    */

/*
    Company Tags                : Amazon, Microsoft, Mentor (Siemens)
    Leetcode Link               : https://leetcode.com/problems/symmetric-tree/
*/

class Solution {
public:

    bool check(TreeNode* leftSide, TreeNode* rightSide) {
        if ( leftSide == NULL && rightSide == NULL) {
            return true;
        }

        if (leftSide == NULL || rightSide == NULL) {
            return false;
        }

        if((leftSide -> val, rightSide -> val) 
            && check(leftSide -> left, rightSide -> right)
            && check(leftSide -> right, rightSide -> left)
        ) {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if ( root == NULL)
            return false;

        return check(root -> left, root -> right);
    }
};

















// 
class Solution {
public:
    
    bool check(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL)
            return true;
        if(l == NULL || r == NULL)
            return false;
        
        if(l->val == r->val && check(l->left, r->right) && check(l->right, r->left))
            return true;
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return check(root->left, root->right);
    }
};































/*
    YOUTUBE VIDEO ON THIS Qn : <soon>
*/