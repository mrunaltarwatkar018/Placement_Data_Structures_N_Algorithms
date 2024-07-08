/*    Leetcode Problem No.: 1372. Longest ZigZag Path in a Binary Tree    */

/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
*/


//Approach-1 (Basic Code - Trying left and right direction and call them)
class Solution {
public:
    int pathLength = 0;
    void dfs(TreeNode* node, bool goLeft, int steps) {
        if (node == nullptr) {
            return;
        }
        pathLength = max(pathLength, steps);
        if (goLeft) {
            dfs(node->left, false, steps + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->left, false, 1);
            dfs(node->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, false, 0);
        dfs(root, true, 0);
        return pathLength;
    }
};

//Approach-1 (Basic Code - Trying left and right direction and call them)

class Solution {
public:

    int maxPath = 0;

    void solve(TreeNode * root, int steps, bool goLeft) {
        if (root == NULL)
            return;

        maxPath = max(maxPath, steps);

        if (goLeft == true) {
            solve(root -> left, steps + 1, false);
            solve(root -> right, 1, true);
        } 
        else {
            solve(root -> right, steps + 1, true);
            solve(root -> left, 1, false);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root, 0, true);
        solve(root, 0, false);
        return maxPath;
    }
};

//Approach-2 (Keeping track of left and right count)
class Solution {
public:

    int maxPath = 0;

    void solve(TreeNode * root, int leftSide, int rightSide) {
        if (root == NULL)
            return;

        maxPath = max({maxPath, leftSide, rightSide});

        solve(root->left, rightSide + 1, 0);
        solve(root->right, 0, leftSide + 1);
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        return maxPath;
    }
};


//Approach-3 (Returning pair of left and right length)
class Solution {
public:
    
    int maxPath = 0;
    
    vector<int> solve(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        
        vector<int> reL = solve(root->left);
        vector<int> reR = solve(root->right);
        
        int L = reL[0];
        int R = reR[1];
        
        maxPath = max({maxPath, L, R});
        
        return {R+1, L+1};
    
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root);
        return maxPath;
    }
};














/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bAO794rh_4M
*/