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




// Approach 2: Morris Traversal

//T.C : O(n)
//S.C : O(1) - Not including result array

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        TreeNode * curr = root;

        while(curr != NULL) {
            if (curr -> left == NULL) {
                // L, V, R
                result.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode * leftChild = curr-> left;

                while (leftChild -> right != NULL) {
                    leftChild = leftChild -> right;
                }

                leftChild -> right = curr;

                // curr -> left ko app NULL mark kar date hai, first store then mark it
                TreeNode * temp = curr;
                curr = curr -> left;
                temp -> left = NULL;
            }
        }
        return result;
    }
};

// another way
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};







/*
    The Inorder Traversal of a Binary Tree is a traversal technique where 
    the left subtree is visited first, then the root node, and finally 
    the right subtree.

    Here's a step-by-step explanation of the code:

        The function inorderTraversal takes the root of the binary tree as an 
        input and returns a vector of integers representing the inorder traversal 
        of the tree.

        The function initializes an empty vector result to store the traversal 
        result and a pointer curr to the root of the tree.

        The function then enters a while loop that continues until curr becomes 
        NULL.

        Inside the loop, it checks if the left child of the current node is NULL. 
        If it is, it means we have reached a leaf node or a node with no left child. 
        In this case, it adds the value of the current node to the result vector and
        moves the curr pointer to the right child of the current node.

        If the left child of the current node is not NULL, it means we need to traverse 
        the left subtree first. In this case, it finds the rightmost node in the left 
        subtree (i.e., the inorder predecessor of the current node) and temporarily 
        links it to the current node. This is done to keep track of the nodes to be 
        visited.

        After linking the rightmost node in the left subtree to the current node, 
        it moves the curr pointer to the left child of the current node and sets the 
        left child of the current node to NULL to avoid revisiting the same node.

        The loop continues until curr becomes NULL, at which point the function returns 
        the result vector containing the inorder traversal of the binary tree.

        This approach is known as Morris Traversal, which is an efficient way to perform 
        inorder traversal without using recursion or a stack. It has a time complexity of 
        O(n), where n is the number of nodes in the tree, and a space complexity of O(1), 
        as it only uses a constant amount of space to store the temporary links.
*/


/*
        The Morris Traversal is a method of traversing a binary tree without using recursion or a 
        stack. It uses a threaded binary tree, where the right child of a node is used to store the 
        inorder successor of the node. This allows us to traverse the tree in a single pass, without
        the need for recursion or a stack.

        Here's a step-by-step explanation of the code:

            1.  Initialize an empty vector result to store the inorder traversal of the binary tree.

            2.  Initialize a pointer curr to the root of the binary tree.

            3.  Start a while loop that continues until curr becomes NULL.

            4.  Inside the loop, check if the left child of curr is NULL. If it is, then:

                    Push the value of curr into the result vector.
                    Move curr to its right child.

            5.  If the left child of curr is not NULL, then:

                    Find the inorder predecessor of curr by traversing to the rightmost node 
                    of the left subtree of curr.

                    Link the right child of the inorder predecessor to curr (this is the threaded part).

                    Store the current node in a temporary variable temp.

                    Move curr to its left child.

                    Set the left child of temp to NULL to break the thread.

            6.  Repeat steps 4 and 5 until curr becomes NULL.

            7.  Return the result vector, which now contains the inorder traversal of the binary tree.
*/



















































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