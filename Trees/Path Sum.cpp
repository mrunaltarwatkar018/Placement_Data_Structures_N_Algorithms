/*    Leetcode Problem No.: 112. Path Sum    */



/*
    Company Tags                : Amazon, Microsoft, Accolite, Adobe, CouponDunia, FactSet, Goldman Sachs, Housing.com, Oracle, Samsung, Atlassian
    Leetcode Qn Link            : https://leetcode.com/problems/path-sum/
*/


// one way
class Solution {
public:

    bool inOrder(TreeNode* root, int sum, int targetSum) {
        if (root == NULL)
            return false;

        sum += root -> val;

        // if we reached leaf node
        if (root -> left == NULL && root -> right == NULL) {
            if (sum == targetSum) 
                return true;

            return false;
        }

        bool leftSide = inOrder(root -> left, sum, targetSum);
        bool rightSide = inOrder(root -> right, sum, targetSum);

        return leftSide || rightSide;
        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        bool result = inOrder(root, sum, targetSum);

        return result;
    }
};



// amnother way
class Solution {
public:
    bool pathSum(TreeNode* root, int sum, int curr) {
        if(!root)
            return false;
        
        if(!root->left && !root->right)
            return ((curr+root->val) == sum);
        
        bool l = pathSum(root->left,  sum, curr+root->val);
        bool r = pathSum(root->right, sum, curr+root->val);
        return l||r;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return pathSum(root, sum, 0);
    }
};
















































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7jIWcMDxT28&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=12
*/