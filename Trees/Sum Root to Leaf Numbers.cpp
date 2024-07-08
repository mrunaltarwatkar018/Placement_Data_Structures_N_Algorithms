/*    Leetcode Problem No.: 129. Sum Root to Leaf Numbers    */

/*
    Company Tags                :   Google, Meta, Accolite, Amazon, Microsoft, Samsung, FactSet, 
                                    Housing.com, Oracle, Goldman Sachs, Adobe, Coupon Dunia, Atlassian
    Leetcode Link               : https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/


/***************************************************** C++ *************************************/
//Recursion-1
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    
    int find(TreeNode* root, int curr) {
        
        if(!root)
            return 0;
        
        curr = curr*10 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            return curr;
        }
        
        int left_num  = find(root->left, curr);
        int right_num = find(root->right, curr);
        
        return left_num + right_num;
    }
    
    int sumNumbers(TreeNode* root) {
        return find(root, 0);
    }
};





class Solution {
public:

    int solve(TreeNode * root, int curr) {
        if (root == NULL)
            return 0;

        curr = (curr*10) + root->val;

        // leaf node (we found a root to leaf path)
        if (root -> left == NULL && root -> right == NULL)
            return curr;

        int leftSide = solve(root -> left, curr);
        int rightSide = solve(root -> right, curr);

        return leftSide + rightSide;
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};





//Recursion-2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return sum*10+root->val;
        
        int ls = sumNumbers(root->left, sum*10+root->val);
        int rs = sumNumbers(root->right, sum*10+root->val);
        
        return ls + rs;
    }
};






/***************************************************** JAVA *************************************/
//Recursion-1
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int find(TreeNode root, int curr) {
        if (root == null)
            return 0;

        curr = curr * 10 + root.val;

        if (root.left == null && root.right == null) {
            return curr;
        }

        int leftNum = find(root.left, curr);
        int rightNum = find(root.right, curr);

        return leftNum + rightNum;
    }

    public int sumNumbers(TreeNode root) {
        return find(root, 0);
    }
}






//Recursion-2
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int sumNumbers(TreeNode root) {
        return sumNumbers(root, 0);
    }
    
    private int sumNumbers(TreeNode root, int sum) {
        if (root == null)
            return 0;

        if (root.left == null && root.right == null)
            return sum * 10 + root.val;

        int leftSum = sumNumbers(root.left, sum * 10 + root.val);
        int rightSum = sumNumbers(root.right, sum * 10 + root.val);

        return leftSum + rightSum;
    }
}















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KTwkq-MsJDw
*/