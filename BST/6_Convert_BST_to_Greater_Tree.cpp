/*    Leetcode Problem No.: 538. Convert BST to Greater Tree    */
/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=8YuKhynQaqA
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/convert-bst-to-greater-tree/description/
*/

//SAMEW PROBLEM (Leetcode - 1038) "Binary Search Tree to Greater Sum Tree"
// LeetCOde Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree




//NOTE - You can do it in many ways, Brute Force , Better Brute Force, Iterative Inorder, Morris Traversal etc - You can give them a try for your practice.

/********************************************************************** C++ **********************************************************************/

/*
    Approach Summary :

    The approach involves converting a Binary Search Tree (BST) into a 
    Greater Sum Tree (GST) where each node's value is updated to the 
    sum of all values greater than or equal to it. This is achieved 
    through a reverse in-order traversal (right-root-left) of the tree. 
    Here's a step-by-step explanation:


    * Traversal Method (solve):

    1.  Base Case: If the current node is null, simply return.
    2.  Right Subtree Processing: Recursively process the right subtree 
        to ensure all nodes with greater values are updated first.
    3.  Update Current Node: Add the current node's value to the cumulative 
        sum and update the current node's value to this sum.
    4.  Left Subtree Processing: Recursively process the left subtree to 
        update nodes with lesser values.


    * Main Function (bstToGst):

    1.  Initialize the cumulative sum to 0.
    2.  Call the solve method starting with the root node to transform the 
        BST into a GST.
    3.  Return the modified tree's root.
    4.  This approach ensures that by the time a node is processed, all nodes 
        with greater values have already been updated, thus maintaining the 
        properties required for the Greater Sum Tree.

*/


// optimal Solution
class Solution {
public:

    void solve (TreeNode * root, int &sum) {
        if (!root) {
            return;
        }

        solve(root -> right, sum); // Process right subtree
        sum += root -> val; // Update the sum with the value of the current node
        root -> val = sum; // Update the current node value with the sum
        solve(root -> left, sum); // Process left subtree
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0; // Use an array to hold the sum because C++ passes by value
        solve(root, sum); // Start the conversion
        return root; // Return the modified tree
    }
};

//  Approach Summary : Right -> visit -> left
