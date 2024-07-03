/*    Leetcode Problem No.: 94. Binary Tree Inorder Traversal    */

/*
    Company Tags                : A lot of companies have asked this.
    Leetcode Link               : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/
// more on: https://leetcodethehardway.com/tutorials/graph-theory/binary-tree


/****************************************************** C++ ******************************************************/

// Approach 1: Basic Approach: Recursive Approach

class Solution {
public:

    void inorder(TreeNode* root, vector <int> & result) {
        if (root == NULL) {
            return;
        }

        inorder(root -> left, result); // left
        result.push_back(root -> val); // visit
        inorder(root -> right, result); // right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> result;

        inorder(root, result);

        return result;
    }
};


























































/****************************************************** JAVA ******************************************************/
//T.C : O(n)
//S.C : O(1) - Not including result array
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;

        while (curr != null) {
            if (curr.left == null) {
                result.add(curr.val);
                curr = curr.right;
            } else {
                pre = curr.left;

                while (pre.right != null) {
                    pre = pre.right;
                }

                pre.right = curr;
                TreeNode temp = curr;
                curr = curr.left;
                temp.left = null;
            }
        }

        return result;
    }
}
































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Wq3ibaP4dJY
*/