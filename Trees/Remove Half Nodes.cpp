/*    GFG Problem No.: Remove Half Nodes  */

/*
    Company Tags    : Amazon
    GFG Link        : https://www.geeksforgeeks.org/problems/remove-half-nodes/1
*/















// Return the root of the modified tree after removing all the half nodes.
class Solution {
    public:
    Node *RemoveHalfNodes(Node *root) {
        // base case
        if ( root == NULL) {
            return NULL;
        }
        
        // recursive case
        
        root -> left = RemoveHalfNodes(root -> left);
        root -> right = RemoveHalfNodes(root -> right);
        
        if ( root -> left == NULL && root -> right != NULL ) {
            return root -> right;
        }
        
        if ( root -> left != NULL && root -> right == NULL ) {
            return root -> left;
        }
        
        return root;
    }
};























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=e932p97MVbk
*/