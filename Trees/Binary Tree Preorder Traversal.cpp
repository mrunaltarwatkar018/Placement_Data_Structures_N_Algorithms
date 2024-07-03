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


// Approach 2: Morris approach

//T.C : O(n)
//S.C : O(1) - Not including result array
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        TreeNode* prev = NULL;

        while (current != NULL) {
            if (current->left == NULL) {
                result.push_back(current->val);
                current = current->right;
            } else {
                prev = current->left;
                while (prev->right != NULL && prev->right != current) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    result.push_back(current->val);
                    prev->right = current;
                    current = current->left;
                } else {
                    prev->right = NULL;
                    current = current->right;
                }
            }
        }

        return result;
    }
};


// more on: https://leetcodethehardway.com/tutorials/graph-theory/binary-tree