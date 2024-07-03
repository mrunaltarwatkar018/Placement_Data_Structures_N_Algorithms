/*    Leetcode Problem No.: 144. Binary Tree Preorder Traversal    */

/*
    Company Tags          : Microsoft, Walmart, Flipkart, Amazon
    Leetcode Qn Link      : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    
    Time Complexity       :
*/



// approach 1
class Solution {
public:

    void preorder(TreeNode* root, vector <int> & result) {
        if (root == NULL) {
            return;
        }

        result.push_back(root -> val); // visit
        preorder(root -> left, result); // left
        preorder(root -> right, result); // right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> result;

        preorder(root, result);

        return result;
    }
};




// approach 2
class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* node) {
        if (node == NULL) return;
        // do something with node value here
        ans.push_back(node->val);
        // traverse the left node
        preorder(node->left);
        // traverse the right node
        preorder(node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};





// more on: https://leetcodethehardway.com/tutorials/graph-theory/binary-tree