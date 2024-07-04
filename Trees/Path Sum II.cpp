/*    Leetcode Problem No.: 113. Path Sum II    */

/*
    Company Tags                : Bloomberg, LinkedIn, Amazon, Bloomberg, Quora
    Leetcode Link               : https://leetcode.com/problems/path-sum-ii/
*/


/************************************************************ C++ ************************************************************/

// one way

class Solution {
public:

    vector<vector<int>> result;

    void fill (TreeNode* root, int sum, vector<int> temp, int & targetSum) {
        // if (!root)
        if(root == NULL)
            return;

        sum += root -> val;
        temp.push_back(root -> val);

        // if leaf node hai
        if (root -> left == NULL && root -> right == NULL) {
            if (sum == targetSum) {
                result.push_back(temp);
            }
            return;
        }

        fill(root -> left, sum, temp, targetSum);
        fill(root -> right, sum, temp, targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        vector<int> temp;
        
        fill (root, sum, temp, targetSum);

        return result;
    }
};


/*
    T.C : 
        The time complexity of the code is O(N), where N is the number of nodes in 
        the binary tree. 

        This is because each node is visited exactly once during the recursive 
        traversal.

        Note that I am ignoring the time taken to move the temp values to result - result.push_back(temp);
    
    S.C :  
        The space complexity is O(H) in the worst case, where H is the height of 
        the binary tree. 

        This is due to the recursion stack during the depth-first search. 
        
        In the worst case, the recursion stack will have H function calls, 
        where H is the height of the tree.
*/





class Solution {
public:
    void collectPaths(TreeNode* root, int curr, vector<int>& temp, vector<vector<int>>& result) {
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == curr) {
            result.push_back(temp);
        }
        
        collectPaths(root->left, curr-root->val, temp, result);
        collectPaths(root->right, curr-root->val, temp, result);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        
        vector<int> temp;
        collectPaths(root, sum, temp, result);
        return result;
    }
};





































/************************************************************ JAVA ************************************************************/

/*
    T.C : 
        The time complexity of the code is O(N), where N is the number of nodes in 
        the binary tree. 

        This is because each node is visited exactly once during the recursive 
        traversal.

        Note that I am ignoring the time taken to move the temp values to result - result.push_back(temp);
    
    S.C :  
        The space complexity is O(H) in the worst case, where H is the height of 
        the binary tree. 

        This is due to the recursion stack during the depth-first search. 
        
        In the worst case, the recursion stack will have H function calls, 
        where H is the height of the tree.
*/
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        collectPaths(root, sum, temp, result);
        return result;
    }

    private void collectPaths(TreeNode root, int curr, List<Integer> temp, List<List<Integer>> result) {
        if (root == null)
            return;
        
        temp.add(root.val);

        if (root.left == null && root.right == null && root.val == curr) {
            result.add(new ArrayList<>(temp));
        }

        collectPaths(root.left, curr - root.val, temp, result);
        collectPaths(root.right, curr - root.val, temp, result);

        temp.remove(temp.size() - 1);
    }
}



// The approach used in this solution is a depth-first search (DFS) with backtracking. Here's a step-by-step explanation:

// The pathSum function is the main function that initiates the process. It takes a TreeNode* root and an int sum as input and returns a vector<vector<int>> containing all the paths in the binary tree that sum up to the given sum.

// The collectPaths function is a helper function that performs the DFS traversal. It takes four parameters:

// TreeNode* root: the current node in the traversal
// int curr: the current sum of the path from the root to the current node
// vector<int>& temp: a temporary vector to store the current path
// vector<vector<int>>& result: a reference to the result vector that stores all the paths that sum up to the given sum
// In the collectPaths function, if the current node is NULL, it returns immediately.

// If the current node is not NULL, it adds the node's value to the temp vector and updates the curr sum by subtracting the node's value.

// If the current node is a leaf node (i.e., both its left and right children are NULL) and the curr sum is equal to 0, it means that the current path sums up to the given sum. In this case, it adds the temp vector to the result vector.

// The function then recursively calls itself for the left and right children of the current node, passing the updated curr sum and the temp vector.

// After the recursive calls, it removes the current node's value from the temp vector (backtracking) to explore other paths.

// The pathSum function returns the result vector, which contains all the paths that sum up to the given sum.

// This approach ensures that all possible paths in the binary tree are explored, and the paths that sum up to the given sum are stored in the result vector.













/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eoyO8hOkPNs&t=3s
*/