/*    Leetcode Problem No.: 2583. Kth Largest Sum in a Binary Tree    */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
*/








class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq; //Min Heap

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n    = que.size();
            long levelSum = 0;
            while (n--) {
                TreeNode* poppedNode = que.front();
                que.pop();
                levelSum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    que.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    que.push(poppedNode->right);
                }
            }

            pq.push(levelSum);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};