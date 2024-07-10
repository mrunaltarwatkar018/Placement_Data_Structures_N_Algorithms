/*    Leetcode Problem No.: 988. Smallest String Starting From Leaf   */

/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/smallest-string-starting-from-leaf/
    Similar Qn                  : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
*/




/***************************************************************** C++ *****************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(n) space taken for resurion system stack

/*
        Approach 1: Depth-First Search (DFS)

            -   Time Complexity (T.C): O(n) - 
                    where n is the number of nodes in the tree. This is 
                    because each node is visited exactly once.
            
            -   Space Complexity (S.C): O(n) - 
                    space taken for recursion system stack. In the 
                    worst-case scenario, the recursion stack could go as 
                    deep as the number of nodes in the tree.

            -   Description:
                -   The algorithm performs a depth-first traversal of the 
                    tree, starting from the root.

                -   At each node, it appends the character corresponding 
                    to the current node's value to the string `curr`.

                -   If the current node is a leaf node (i.e., it has no 
                    children), it compares the resulting string `curr` 
                    with the current `result`, updating `result` if 
                    necessary.

                -   Recursively explores the left and right subtrees.
*/


class Solution {
public:
    string result = "";

    void dfs(TreeNode * root, string curr) {
        if (root == NULL)
            return;

        curr = char(root->val + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
        if(!root->left && !root->right) {
            if(result == "" || result > curr) {
                result = curr;
            }
            return;
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");

        return result;
    }
};


// another way
class Solution {
public:
    string result = "";
    
    
    void solve(TreeNode* root, string curr) {
        if(root == NULL) {
            return;
        }
        
        curr = char(root->val + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
        if(root->left == NULL && root->right == NULL) {
            if(result == "" || result > curr) {
                result = curr;
            }
            return;
        }
        
        solve(root->left, curr);
        solve(root->right, curr);
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        
        return result;
    }
};


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)

/*
        Approach 2: Breadth-First Search (BFS)

            -   Time Complexity (T.C): O(n) - 
                    where n is the number of nodes in the tree. Each node 
                    is visited once in the worst-case scenario.

            -   Space Complexity (S.C): O(n) - 
                    space used by the queue to store nodes and strings.

            -   Description:

                -   The algorithm performs a breadth-first traversal of 
                    the tree, starting from the root.

                -   It uses a queue to keep track of nodes and their 
                    corresponding strings.

                -   At each step, it dequeues a node and its associated 
                    string from the queue.

                -   If the dequeued node is a leaf node, it compares the 
                    resulting string with the current `result`, updating 
                    `result` if necessary.

                -   Enqueues the left and right children of the dequeued 
                    node along with their corresponding strings, obtained 
                    by appending the character corresponding to the child 
                    node's value to the current string.

        Both approaches achieve the same goal of finding the 
        lexicographically smallest string formed by traversing from the 
        root to a leaf node in the binary tree. The choice between the two 
        approaches may depend on factors such as memory constraints or the 
        specific characteristics of the tree.
*/

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> que;
        
        string result = "";
        que.push({root, string(1, root->val + 'a')});
        
        while(!que.empty()) {
            
            auto[node, curr] = que.front();
            que.pop();
            
            if(node->left == NULL && node->right == NULL) {
                if(result == "" || result > curr) {
                    result = curr;
                }
            }
            
            if(node->left) {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }
            
            if(node->right) {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
            
        }
        
        return result;
    }
};






















/***************************************************************** JAVA *****************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(n) space taken for resurion system stack
class Solution {
    String result = "";

    void solve(TreeNode root, String curr) {
        if (root == null) {
            return;
        }

        curr = (char) (root.val + 'a') + curr; // This will take O(length of curr) but I have ignored this. You can consider this as well in calculating T.C

        if (root.left == null && root.right == null) {
            if (result.equals("") || result.compareTo(curr) > 0) {
                result = curr;
            }
            return;
        }

        solve(root.left, curr);
        solve(root.right, curr);
    }

    public String smallestFromLeaf(TreeNode root) {
        solve(root, "");
        return result;
    }
}



//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String smallestFromLeaf(TreeNode root) {
        Queue<Pair<TreeNode, String>> queue = new LinkedList<>();
        
        String result = "";
        queue.add(new Pair<>(root, String.valueOf((char)(root.val + 'a'))));
        
        while (!queue.isEmpty()) {
            Pair<TreeNode, String> pair = queue.poll();
            TreeNode node = pair.getKey();
            String curr = pair.getValue();
            
            if (node.left == null && node.right == null) {
                if (result.equals("") || result.compareTo(curr) > 0) {
                    result = curr;
                }
            }
            
            if (node.left != null) {
                queue.add(new Pair<>(node.left, (char)(node.left.val + 'a') + curr));
            }
            
            if (node.right != null) {
                queue.add(new Pair<>(node.right, (char)(node.right.val + 'a') + curr));
            }
        }
        
        return result;
    }
}
























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SX7dC8htok0
*/