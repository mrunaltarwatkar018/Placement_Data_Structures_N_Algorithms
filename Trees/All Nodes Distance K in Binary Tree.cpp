/*    Leetcode Problem No.: 863. All Nodes Distance K in Binary Tree    */


/*
    Company Tags                : Amazon, Citicorp, Flipkart, Goldman Sachs, Hike, Ola Cabs, Samsung, Walmart
    Leetcode Link               : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/

//Approach-1  (Using Parent Pointers)


class Solution {
public:

    unordered_map<TreeNode *, TreeNode *> parent;

    void inOrder(TreeNode * root) {
        if (root == NULL)
            return;

        if (root -> left != NULL)
            parent[root -> left] = root;

        inOrder(root -> left);

        if (root -> right != NULL)
            parent[root -> right] = root;

        inOrder(root -> right);
    }

    void BFS(TreeNode* target, int k,  vector<int>&result) {
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<int> visited;
        visited.insert(target -> val);

        while(!que.empty()) {
            int n = que.size();

            if ( k == 0)
                break;

            while (n--) {
                TreeNode * curr = que.front();
                que.pop();

                // current ka left child     
                if (curr->left != NULL && !visited.count(curr->left->val)) {
                    que.push(curr -> left);
                    visited.insert(curr -> left -> val);
                }

                // current ka right child                    
                if(curr->right != NULL && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }

                // current ka parent 
                // parent[curr] = parent of curr
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        inOrder(root);

        BFS(target, k, result);

        return result;
    }
};






















class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void addParent(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
            parent[root->left] = root;
        
        addParent(root->left);
        
        if(root->right)
            parent[root->right] = root;
        
        addParent(root->right);
    }
    
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParent(root);
        
        collectKDistanceNodes(target, k, result);
        return result;
    }
};


//Approach-2 (Without Using Parent Pointers)























































class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        dfs(root, target, k, result);
        return result;
    }

    int dfs(TreeNode* node, TreeNode* target, int k, vector<int>& result) {
        if (!node) return -1;
        if (node == target) {
            collectKDistanceNodes(node, k, result);
            return 0;
        }
        int left = dfs(node->left, target, k, result);
        if (left != -1) {
            if (left + 1 == k) result.push_back(node->val);
            else collectKDistanceNodes(node->right, k - left - 2, result);
            return left + 1;
        }
        int right = dfs(node->right, target, k, result);
        if (right != -1) {
            if (right + 1 == k) result.push_back(node->val);
            else collectKDistanceNodes(node->left, k - right - 2, result);
            return right + 1;
        }
        return -1;
    }

    void collectKDistanceNodes(TreeNode* node, int k, vector<int>& result) {
        if (!node) return;
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        collectKDistanceNodes(node->left, k - 1, result);
        collectKDistanceNodes(node->right, k - 1, result);
    }
};


















/*
    YOUTUBE VIDEO ON THIS Qn : (Approach-1) - https://www.youtube.com/watch?v=1PMjfQl_UVQ 
*/