/*    Leetcode Problem No.: 1339. Maximum Product of Splitted Binary Tree    */


/*
    Company Tags                : Google, Facebok, Amazon(Phone Interview)
    Leetcode Link               : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/

// one way
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    long SUM = 0; // total sum of the tree
    long MaxProduct = 0;

    int totalSum(TreeNode * root) {
        if (root == NULL)
            return 0;

        int leftSubtreeSum = totalSum(root -> left);
        int rightSubtreeSum = totalSum(root -> right);

        int sum = root -> val + leftSubtreeSum + rightSubtreeSum;

        return sum;
    }

    int findMaxProduct(TreeNode * root) {
        if (root == NULL)
            return 0;

        int leftSum = findMaxProduct(root -> left);
        int rightSum = findMaxProduct(root -> right);

        long subTreeSum = root -> val + leftSum + rightSum; // S1

        long remainingSubTreeSum = SUM - subTreeSum; // s2

        MaxProduct = max(MaxProduct, subTreeSum * remainingSubTreeSum );

        return subTreeSum;
        
    }

    int maxProduct(TreeNode* root) {

        if (root == NULL)
            return 0;

        MaxProduct = 0;
        SUM = totalSum(root);

        findMaxProduct(root);

        return MaxProduct % (1000000007);
        
    }
};


// above code in optimize previous solution way

// above code in optimize previous solution way as same function ko hi thoda update kiya
class Solution {
public:

    long SUM = 0; // total sum of the tree
    long MaxProduct = 0;

    int totalSum(TreeNode * root) {
        if (root == NULL)
            return 0;

        int leftSubtreeSum = totalSum(root -> left);
        int rightSubtreeSum = totalSum(root -> right);

        long subTreeSum = root -> val + leftSubtreeSum + rightSubtreeSum;

        long remainingSubTreeSum = SUM - subTreeSum; // s2

        MaxProduct = max(MaxProduct, subTreeSum * remainingSubTreeSum );

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {

        if (root == NULL)
            return 0;

        MaxProduct = 0;
        SUM = totalSum(root);

        totalSum(root);

        return MaxProduct % (1000000007);
        
    }
};





////////////////////////////////////



class Solution {
public:
    
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum             = root->val + leftSubtreeSum + rightSubtreeSum;
        
        maxP = max(maxP, (totalSum - sum) * sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        totalSum = findTotalSum(root);
        
        
        findTotalSum(root);
        
        return maxP%M;
    }
};



/*
    The time complexity of this one is a little straight forward.
    If you notice, we are visiting each node of the Tree just Once.
    So Time complexity will be : O(n)
    Where n = number of nodes in the tree. 

    You can say we have called the function twice , 
    - one for calculating totalSum
    - And another for calculating maximum product. 

    So to be precise , Time complexity will be O(n +n) = O(2*n) which is effectively O(n) only. (Ignoring the constant 2).

*/

























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ITySQXe9Ybg
*/