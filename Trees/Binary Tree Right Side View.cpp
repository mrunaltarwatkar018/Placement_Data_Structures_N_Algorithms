/*    Leetcode Problem No.: 199. Binary Tree Right Side View    */

/*
    Company Tags          : Accolite, Amazon, Flipkart, Knowlarity, MakeMyTrip, Ola Cabs, Open Solutions, OYO ROoms, Paytm, Qualcomm, Samsung,
                            Snapdeal, Twitter
    Leetcode Qn Link      : https://leetcode.com/problems/binary-tree-right-side-view/
    Approach              : Use DFS or Level Order Traversal
    Time Complexity       : O(n)
*/

// Approach-1 : Level Order Traversal i.e., BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(!root)
            return {};
        
        queue<TreeNode*> que;
        vector<int> result;
        
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            TreeNode * node = NULL;

            while(n--) {
                node = que.front();
                que.front();
                que.pop();
                
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
            result.push_back(node->val);
        }
        return result;
    }
};





// Approach-2 : Pre Order Traversal i.e., DFS


class Solution {
public:

    void preOrder(TreeNode* root, int level, vector<int> & result) {
        if (root == NULL) 
            return;

        if (result.size() < level) 
            result.push_back(root -> val);

        preOrder(root -> right, level + 1, result);
        preOrder(root -> left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) 
            return {};
        vector <int> result;

        preOrder(root, 1, result);

        return result;
    }
};














































/*
    YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=-Qs1T_xfzLo&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=1
 */