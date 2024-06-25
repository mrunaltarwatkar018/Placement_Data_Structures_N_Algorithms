/*    Leetcode Problem No.: 938. Range Sum of BST    */

/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=qIFhQ2m6i64
    Company Tags                : Google, Amazon, D.E. Shaw, Meta
    Leetcode Link               : https://leetcode.com/problems/range-sum-of-bst/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
*/


/*
        Approach Summary : 
        
            The function uses a recursive approach to traverse the BST. If the 
            current node's value is within the range, it adds the node's value to 
            the sum and continues the traversal to both the left and right 
            subtrees. If the node's value is less than low, the function 
            recursively moves to the right subtree, as values to the left would be 
            smaller. Conversely, if the node's value is greater than high, the 
            function recursively moves to the left subtree, as values to the right 
            would be larger. The base case for the recursion is when the current 
            node is null, at which point the function returns 0. The sum of the 
            values within the specified range is accumulated and returned as the 
            final result.
*/

/****************************************************************** C++ ******************************************************************/
//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        if (!root)
            return 0;

        // within range, SO add it
            if (root -> val >= low && root -> val <= high) {
            return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        }

        // root -> val < low (waste to go to left. So, we go right)
        if (root -> val < low ) {
            return rangeSumBST(root -> right, low, high);
        }

        // root -> val > high (waste to go to right. So, we go left)
        return rangeSumBST(root -> left, low, high);
    }
};




/****************************************************************** JAVA ******************************************************************/
//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)
public class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }

        // Within Range
        if (root.val >= low && root.val <= high) {
            return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
        }

        // When outside the range (Less than low) - Go right
        if (root.val < low) {
            return rangeSumBST(root.right, low, high);
        }

        // When outside the range (Greater than high) - Go left
        return rangeSumBST(root.left, low, high);
    }
}