/*    Leetcode Problem No.: 513. Find Bottom Left Tree Value   */


/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-bottom-left-tree-value/
*/
/*
    Approach Summary : 

        Approach-1 (Using DFS)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(max depth of tree)

            The depth-first search (DFS) approach uses recursion to 
            traverse the tree and find the bottom-left value. It maintains 
            the maximum depth encountered and updates the bottom-left 
            value accordingly.
        
        Approach-2 (Using BFS)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(n) for the queue

            The breadth-first search (BFS) approach uses a queue to 
            traverse the tree level by level. It updates the bottom-left 
            value during the traversal, ensuring that the last processed 
            node on the bottom-left is returned as the result.

        Approach-3 (Using BFS with inner while loop)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(n) for the queue

            This variation of the BFS approach uses an inner while loop to 
            process nodes level by level. It ensures that only the 
            leftmost node at each level is considered for updating the 
            bottom-left value, providing an alternative implementation to 
            the basic BFS approach.
*/



/********************************************************** C++ **********************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(max depth of tree)

/*
        Approach-1 (Using DFS)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(max depth of tree)

            The depth-first search (DFS) approach uses recursion to 
            traverse the tree and find the bottom-left value. It maintains 
            the maximum depth encountered and updates the bottom-left 
            value accordingly.
*/

class Solution {
public:
    int maxDepth;
    int bottomLeft; // result
    
    void solve(TreeNode* root, int currDepth) {
        if(!root) {
            return;
        }
        
        if(currDepth > maxDepth) {
            maxDepth   = currDepth;
            bottomLeft = root->val;
        }
        
        solve(root->left, currDepth+1);
        solve(root->right, currDepth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        
        solve(root, 0);
        return bottomLeft;
        
    }
};


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n) for queue

/*
        Approach-2 (Using BFS)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(n) for the queue

            The breadth-first search (BFS) approach uses a queue to 
            traverse the tree level by level. It updates the bottom-left 
            value during the traversal, ensuring that the last processed 
            node on the bottom-left is returned as the result.
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            bottomLeft = node->val;
            
            if(node->right) {
                que.push(node->right);
            }
            if(node->left) {
                que.push(node->left);
            }
        }
        
        return bottomLeft;
    }
};


//Approach-3 (Using BFS with inner while loop)
//T.C : O(n)
//S.C : O(n) for queue

/*
        Approach-3 (Using BFS with inner while loop)

            Time Complexity (T.C): O(n)
            Space Complexity (S.C): O(n) for the queue

            This variation of the BFS approach uses an inner while loop to 
            process nodes level by level. It ensures that only the 
            leftmost node at each level is considered for updating the 
            bottom-left value, providing an alternative implementation to 
            the basic BFS approach.
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> que;
        int bottomLeft;
        que.push(root);

        // level by level processing BFS
        while(!que.empty()) {
            int n = que.size(); // current level has n nodes

            while(n--) { // process all those nodes at once
                TreeNode * node = que.front();
                que.pop();

                bottomLeft = node -> val;

                if (node -> right)
                    que.push(node -> right);

                if (node -> left)
                    que.push(node -> left);
            }
        }
        return bottomLeft;
    }
};



















/********************************************************** JAVA **********************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(max depth of tree)
class Solution {
    private int maxDepth;
    private int bottomLeft;
    
    public int findBottomLeftValue(TreeNode root) {
        maxDepth = -1;
        
        solve(root, 0);
        return bottomLeft;
    }
    
    private void solve(TreeNode root, int currDepth) {
        if (root == null) {
            return;
        }
        
        if (currDepth > maxDepth) {
            maxDepth = currDepth;
            bottomLeft = root.val;
        }
        
        solve(root.left, currDepth + 1);
        solve(root.right, currDepth + 1);
    }
}


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n) for queue
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        
        int bottomLeft = 0;
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            
            bottomLeft = node.val;
            
            if (node.right != null) {
                queue.offer(node.right);
            }
            if (node.left != null) {
                queue.offer(node.left);
            }
        }
        
        return bottomLeft;
    }
}


//Approach-3 (Using BFS with inner while loop)
//T.C : O(n)
//S.C : O(n) for queue
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            
            bool firstElementTaken = false;
            
            while(n--) {
                TreeNode* node = que.front();
                que.pop();
                
                bottomLeft = node->val;
                
                if(node->right) {
                    que.push(node->right);
                }
                if(node->left) {
                    que.push(node->left);
                }
            }
            
        }
        
        return bottomLeft;
    }
};


















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YnabMptoE0I
*/