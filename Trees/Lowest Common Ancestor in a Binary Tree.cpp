/*    Leetcode Problem No.: 236. Lowest Common Ancestor in a Binary Tree    */

/*
    Company Tags : Accolite, Amazon, American Express, Expedia, MakeMyTrip, Microsoft, Payu, Snapdeal, Times Internet, Twitter
    Link to Qn   : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/


/*
        The approach used here is a recursive depth-first search (DFS) to find the 
        lowest common ancestor (LCA) of two nodes p and q in a binary tree.

        Here's a step-by-step breakdown of the approach:

            Start at the root node of the tree.

            If the current node is NULL, return NULL.

            If the current node is either p or q, return the current node.

            Recursively search for p and q in the left and right subtrees.

            If both p and q are found in different subtrees, the current node is the LCA.

            If only one of p or q is found in the left subtree, return the left node.

            If only one of p or q is found in the right subtree, return the right node.

            Repeat steps 2-7 until the LCA is found.

    This approach has a time complexity of O(n), where n is the number of nodes in the tree, 
    since we visit each node at most once. The space complexity is O(h), where h is the height 
    of the tree, due to the recursive call stack.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is NULL, return NULL
        if (root == NULL)
            return NULL;
        
        // If the current node is either p or q, return the current node
        if (root == p || root == q)
            return root;

        // Recursively search for p and q in the left subtree
        TreeNode * leftN = lowestCommonAncestor(root -> left, p, q);
    
        // Recursively search for p and q in the right subtree
        TreeNode * rightN = lowestCommonAncestor(root -> right, p, q);

        // If both p and q are found in different subtrees, the current node is the LCA
        if (leftN != NULL && rightN != NULL)
            return root;

        // If only one of p or q is found in the left subtree, return the left node
        if (leftN != NULL)
            return leftN;

        // If only one of p or q is found in the right subtree, return the right node
        return rightN;
    }
};




















// another way of writing same approach, 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r)
            return root;
        
        return l?l:r;
    }
};









































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Oi3_06ultic&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=4
*/