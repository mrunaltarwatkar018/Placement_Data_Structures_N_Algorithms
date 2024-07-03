/*    Leetcode Problem No.: 958. Check Completeness of a Binary Tree    */

/*
    Company Tags                 : Amazon, Meta
    Leetcode Link                : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

//Appraoch 1 : Using BFS

/*
        Approach:

            The approach is to perform a level-order traversal (BFS) of the binary tree 
            using a queue. We keep track of whether we've seen a NULL node in the past 
            using the past flag.

            Here's the logic:

                1.  Enqueue the root node.

                2.  While the queue is not empty, dequeue a node.

                3.  If the node is NULL, set the past flag to true.

                4.  If the node is not NULL, check if we've seen a NULL node in the past. 

                    If so, return false, as the tree is not complete.

                5.  Enqueue the left and right children of the node.

                6.  Repeat steps 2-5 until the queue is empty.

                7.  If we've reached this point, the tree is complete, so return true.
                
        The idea is that in a complete binary tree, all levels except the last level should 
        be fully filled, and the last level should be filled from left to right. If we encounter 
        a NULL node, we set the past flag to true. If we encounter a non-NULL node after setting 
        the past flag, it means the tree is not complete, so we return false.
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //Using BFS
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        bool past = false; //kya aapne past me NULL node dekha hai ?
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            if(node == NULL) {
                past = true;
            } else {
                if(past == true) {
                    return false;
                }
                
                que.push(node->left);
                que.push(node->right);
            }
        }
        
        return true;
    }
};



// in comments
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;  // Create a queue to store nodes
        que.push(root);  // Enqueue the root node

        bool past = false;  // Flag to indicate if we've seen a NULL node in the past

        while (!que.empty()) {
            TreeNode* node = que.front();  // Dequeue a node
            que.pop();

            if (node == NULL) {
                past = true;  // If the node is NULL, set the flag to true
            } else {
                if (past == true) {
                    return false;  // If we've seen a NULL node in the past, return false
                }
                que.push(node->left);  // Enqueue the left child
                que.push(node->right);  // Enqueue the right child
            }
        }
        return true;  // If we've reached this point, the tree is complete
    }
};













//Approach-2 : Using DFS


/*
Approach:

    The approach is to first count the total number of nodes in the 
    tree using a recursive function countNodes. Then, perform a 
    Depth-First Search (DFS) on the tree, keeping track of the 
    index of each node. If the tree is complete, the index of each 
    node should be within the range of 1 to totalNodes. If the index 
    of any node exceeds totalNodes, it means the tree is not complete, 
    and we return false. If the DFS completes successfully, we return 
    true, indicating that the tree is complete.
*/


class Solution {
public:

    // Function to count the total number of nodes in the tree
    int countNodes(TreeNode* root) {

        // Base case: If the tree is empty, return 0
        if(root == NULL)
            return 0;
        
        // Recursively count the nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Function to perform DFS and check if the tree is complete
    bool dfs(TreeNode* root, int i, int totalNodes) {

        // Base case: If the current node is NULL, return true
        if(root == NULL)
            return true;
        
        // If the current node's index is greater than the total number of nodes, return false
        if(i > totalNodes)
            return false;
        
        // Recursively perform DFS on the left and right subtrees
        return dfs(root->left, 2*i, totalNodes) && dfs(root->right, 2*i + 1, totalNodes);
    }
    
    // Main function to check if the tree is complete
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root); // Count the total number of nodes in the tree
        
        int i = 1; // Initialize the index for DFS
        return dfs(root, i, totalNodes); // Perform DFS to check if the tree is complete
    }
};























/*
    YOUTUBE VIDEO FOR THIS Qn :     BFS - https://youtu.be/08e5EBHoXxE
                                    DFS - https://youtu.be/5zyG8Nw9V78
*/