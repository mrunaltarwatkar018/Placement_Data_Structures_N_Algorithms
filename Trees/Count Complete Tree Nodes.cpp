/*    Leetcode Problem No.: 222. Count Complete Tree Nodes    */


/*
    Company Tags               : Amazon, Microsoft, Salesforce, Facebook
    Leetcode Link              : https://leetcode.com/problems/count-complete-tree-nodes/
*/

//Time Complexity : O(log(n) * log(n))


//Time Complexity : O(log(n) * log(n))
class Solution {
public:

    int getLeftHeight(TreeNode * root) {
        TreeNode * temp = root;
        int leftHeight = 0;

        while (temp != NULL) {
            temp = temp -> left;
            leftHeight++;
        }
        return leftHeight;
    }

    int getRightHeight(TreeNode * root) {
        TreeNode * temp = root;
        int rightHeight = 0;

        while (temp != NULL) {
            temp = temp -> right;
            rightHeight++;
        }
        return rightHeight;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        //if perfect binary tree hai
        if (leftHeight == rightHeight) {
            return (pow(2, leftHeight) - 1);
        }

        //if perfect binary tree nhi hai
        return countNodes(root -> left) + countNodes(root -> right) +1;
        
    }
};





// another way

//Time Complexity : O(log(n) * log(n))
class Solution {
public:

    int getLeftHeight(TreeNode * root) {
        TreeNode * temp = root;
        int leftHeight = 0;

        while (temp) {
            temp = temp -> left;
            leftHeight++;
        }
        return leftHeight;
    }

    int getRightHeight(TreeNode * root) {
        TreeNode * temp = root;
        int rightHeight = 0;

        while (temp) {
            temp = temp -> right;
            rightHeight++;
        }
        return rightHeight;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        //if perfect binary tree hai
        if (leftHeight == rightHeight) {
            return (pow(2, leftHeight) - 1);
        }

        //if perfect binary tree nhi hai
        return countNodes(root -> left) + countNodes(root -> right) +1;
        
    }
};






















/*
    YOUTUBE VIDE ON THIS Qn : https://www.youtube.com/watch?v=2XTXL7a6ItI
*/