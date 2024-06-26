/*    Leetcode Problem No.: 1382. Balance a Binary Search Tree    */

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wHzpM_u7p0s
    Company Tags                : Paytm
    Leetcode Link               : https://leetcode.com/problems/balance-a-binary-search-tree/description
*/


/************************************************************************ C++ ********************************************************/

/*
    Approach Summary :
        In-Order Traversal:

        Perform an in-order traversal of the given binary search tree (BST).
        Store the values in a list to get a sorted sequence of elements.
        
        Construct Balanced BST:
        Use the sorted list to construct a balanced BST.
        Recursively choose the middle element of the current subarray as the root 
        to ensure the tree remains balanced.
        Assign the left half of the list to the left subtree and the right half to 
        the right subtree.

        Rebuild the Tree:

        Start the process from the entire range of the list (from 0 to the size of 
        the list minus one).
        The recursive construction ensures that the resulting tree is 
        height-balanced.
        Benefits:

        The in-order traversal ensures that the elements are sorted, leveraging the 
        properties of a BST.
        Recursively choosing the middle element ensures the tree is as balanced as 
        possible, minimizing the height.
*/


//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);

    }

    TreeNode* construct(int l, int r, vector<int>& vec) {
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left  = construct(l, mid-1, vec);
        root->right = construct(mid+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int l = 0, r = vec.size()-1;

        return construct(l, r, vec);
    }
};


/************************************************************************ JAVA ********************************************************/
//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution {
    private void inOrder(TreeNode root, List<Integer> vec) {
        if (root == null) {
            return;
        }
        inOrder(root.left, vec);
        vec.add(root.val);
        inOrder(root.right, vec);
    }

    private TreeNode construct(int l, int r, List<Integer> vec) {
        if (l > r) {
            return null;
        }
        int mid = l + (r - l) / 2;
        TreeNode root = new TreeNode(vec.get(mid));
        root.left = construct(l, mid - 1, vec);
        root.right = construct(mid + 1, r, vec);
        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> vec = new ArrayList<>();
        inOrder(root, vec);
        return construct(0, vec.size() - 1, vec);
    }
}