/*    Leetcode Problem No.: 124. Binary Tree Maximum Path Sum    */


/*
    Company Tags                : Google, Amazon, Meta, Flipkart
    Leetcode Link               : https://leetcode.com/problems/binary-tree-maximum-path-sum/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
*/

class Solution {
public:

    int maxSum;

    int solve(TreeNode* root) {
        if (root == NULL){
            return 0;
        }

        int leftSide = solve(root -> left);
        int rightSide = solve(root -> right);

        // case 1
        int neeche_hi_milgaya_answer = leftSide + rightSide + root -> val;

        // case 2
        int koi_ek_acha = max(leftSide, rightSide) + root -> val;

        // case 3
        int only_root_acha = root -> val;

        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        //most important part
        return max(koi_ek_acha, only_root_acha);
        
    }

    int maxPathSum(TreeNode* root) {

        maxSum = INT_MIN;

        solve(root);

        return maxSum;
        
    }
};




/*
    Let's break down the approach used in this solution:

    Problem Statement: 
        Find the maximum path sum in a binary tree, 
        where the path can include any node in the tree.

    Approach:

        The solution uses a recursive approach to traverse the binary tree. 
        The key idea is to consider four cases for each node:

        Case 1: neeche_hi_milgaya_answer: The maximum path sum that includes 
        the current node and its left and right subtrees.

        Case 2: koi_ek_acha: The maximum path sum that includes the current 
        node and either its left or right subtree (but not both).

        Case 3: only_root_acha: The maximum path sum that includes only the 
        current node.

        For each node, the solution recursively calculates the maximum path 
        sum for its left and right subtrees (leftSide and rightSide). Then, 
        it considers the four cases mentioned above and updates the maxSum 
        variable accordingly.

        The solve function returns the maximum path sum that includes the 
        current node and either its left or right subtree (but not both), 
        which is used to calculate the maximum path sum for the parent node.

    Key Insights:

        The solution uses a recursive approach to traverse the binary tree, which 
        allows it to consider all possible paths in the tree.

        The maxSum variable is used to keep track of the maximum path sum found 
        so far, which is updated recursively as the solution traverses the tree.

        The solve function returns the maximum path sum that includes the current 
        node and either its left or right subtree, which is used to calculate the 
        maximum path sum for the parent node.
    
    Time Complexity: 
        The time complexity of this solution is O(n), where n is 
        the number of nodes in the binary tree, since each node is 
        visited once.

    Space Complexity: 
        The space complexity of this solution is O(h), where h is the 
        height of the binary tree, since the recursive call stack can 
        grow up to the height of the tree.
*/













/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Op6YFcs8R9M
*/