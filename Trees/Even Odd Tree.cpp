/*    Leetcode Problem No.: 1609. Even Odd Tree    */

/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/even-odd-tree/
*/

/*************************************************************** C++ *****************************************************************/
//Approach-1 (When we deal with level, always first think of BFS)
//T.C : O(n)
//S.C : O(n)

/*
    Approach-1 (BFS)
    
        Algorithm:
            Uses Breadth-First Search (BFS) to traverse the tree level by level.

            Maintains a queue to keep track of nodes at each level.

            Uses a boolean flag (even_level) to alternate between even and odd 
            levels.

            Checks if values in even levels are strictly increasing and odd levels 
            are strictly decreasing.

            Complexity:

                Time Complexity: O(n) - where n is the number of nodes in the tree.
                Space Complexity: O(n) - in the worst case, when the queue stores 
                all nodes at the maximum level.
*/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        
        que.push(root);
        bool even_level = true;

        while(!que.empty()) {
            int n = que.size();
            int prev;

            if (even_level)
                prev = INT_MIN;
            else 
                prev = INT_MAX;

            while(n--) {
                TreeNode * curr = que.front();
                que.pop();

                if (even_level && (curr -> val % 2 == 0 || curr -> val <= prev)) {
                    return false;
                }

                if (!even_level && (curr -> val % 2 != 0 || curr -> val >= prev)) {
                    return false;
                }

                prev = curr -> val;

                if (curr -> left)
                    que.push(curr -> left);
                if (curr -> right)
                    que.push(curr -> right);
            }

            even_level = !even_level;
        }
        return true;
    }
};






//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)

/*
    Approach-2 (DFS)

        Algorithm:

            Uses Depth-First Search (DFS) with a recursive approach.

            Maintains a vector (levelPrev) to store the previous value at each level.

            Checks if values at even levels are strictly increasing and odd levels 
            are strictly decreasing.

            Complexity:
                Time Complexity: O(n) - where n is the number of nodes in the tree.
                
                Space Complexity: O(n) - uses additional space for the vector 
                levelPrev and recursion stack. The recursion depth is determined by 
                the height of the tree.

        These approaches aim to determine if a given binary tree is an Even-Odd Tree 
        based on specific rules about the values in even and odd levels. The BFS 
        approach uses a queue for level-order traversal, while the DFS approach 
        utilizes recursive calls and a vector to track previous values at each 
        level. Both approaches have a time complexity of O(n) but differ in their 
        space complexity.

*/

class Solution {
public:
    
    vector<int> levelPrev;
    
    bool solve(TreeNode* root, int level) {
        if(!root) {
            return true;
        }
        
        if((level%2 == 0 && root->val%2 == 0) || (level%2 != 0 && root->val%2 != 0)) {
            return false;
        }
        
        if(level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0) { //already there is a value at this level
            if((level%2 == 0 && root->val <= levelPrev[level]) ||
                (level%2 != 0 && root->val >= levelPrev[level]))
                return false;
        }
        
        levelPrev[level] = root->val;
        
        return solve(root->left, level+1) && solve(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};



//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)
class Solution {
public:
    vector<int> level_prev; // max size will be O(depth)

    bool solve(TreeNode * root, int level) {
        if (!root) return true;

        // if (level % 2 == 0 && root -> val % 2 == 0)
        //     return false;

        // if (level % 2 != 0 && root -> val % 2 != 0)
        //     return false;

        // above two if statements can be written as
        if (level % 2 == root -> val % 2)
            return false;

        if (level >= level_prev.size()) {
            level_prev.resize(level + 1);
        }

        if (level_prev[level] != 0) { // already there is a value at this level which I saw in past
            if((level%2 == 0 && root->val <= level_prev[level]) ||
                (level%2 != 0 && root->val >= level_prev[level]))
                return false;
        }
        level_prev[level] = root -> val;

        return solve(root->left, level+1) && solve(root->right, level+1);
    }

    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};


/*************************************************************** JAVA *****************************************************************/
//Approach-1 (When we deal with level, always first think of BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean evenLevel = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            int prev = evenLevel ? Integer.MIN_VALUE : Integer.MAX_VALUE;

            while (size-- > 0) {
                TreeNode node = queue.poll();

                if ((evenLevel && (node.val % 2 == 0 || node.val <= prev)) ||
                    (!evenLevel && (node.val % 2 == 1 || node.val >= prev))) {
                    return false;
                }

                prev = node.val;

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
}


//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)
class Solution {
    private List<Integer> levelPrev = new ArrayList<>();

    public boolean isEvenOddTree(TreeNode root) {
        return solve(root, 0);
    }

    private boolean solve(TreeNode root, int level) {
        if (root == null) {
            return true;
        }

        if ((level % 2 == 0 && root.val % 2 == 0) || (level % 2 != 0 && root.val % 2 != 0)) {
            return false;
        }

        if (level >= levelPrev.size()) {
            levelPrev.add(root.val);
        } else {
            if ((level % 2 == 0 && root.val <= levelPrev.get(level)) ||
                (level % 2 != 0 && root.val >= levelPrev.get(level))) {
                return false;
            }
            levelPrev.set(level, root.val);
        }

        return solve(root.left, level + 1) && solve(root.right, level + 1);
    }
}
















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ai7zemxYjz4
*/