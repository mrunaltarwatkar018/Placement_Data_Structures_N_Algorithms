/*    Leetcode Problem No.: 142. Binary Tree Postorder Traversal    */

/*
    Company Tags                : A lot of companies have asked this.
    Leetcode Link               : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*/
// more on: https://leetcodethehardway.com/tutorials/graph-theory/binary-tree


/****************************************************** C++ ******************************************************/

// Approach 1: Basic Approach: Recursive Approach
class Solution {
public:

    void postorder(TreeNode* root, vector <int> & result) {
        if (root == NULL) {
            return;
        }

        postorder(root -> left, result); // left
        postorder(root -> right, result); // right
        result.push_back(root -> val); // visit
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;

        postorder(root, result);

        return result;
    }
};




// Approach 2: Morris Approach
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (curr!= NULL) {
            if (curr -> right == NULL) {
                result.push_back(curr -> val);
                curr = curr -> left;
            } else {
                prev = curr -> right;
                while (prev -> left!= NULL && prev -> left!= curr) {
                    prev = prev -> left;
                }

                if (prev -> left == NULL) {
                    result.push_back(curr -> val);
                    prev -> left = curr;
                    curr = curr -> right;
                } else {
                    prev -> left = NULL;
                    curr = curr -> left;
                }
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};