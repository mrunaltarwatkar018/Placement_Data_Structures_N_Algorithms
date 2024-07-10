/*    Leetcode Problem No.: 979. Distribute Coins in Binary Tree    */
/*    GFG Problem : Distribute Candies in a Binary Tree    */

/*
        Company Tags                : Microsoft
        Leetcode Link               : Distribute Coins in Binary Tree: https://leetcode.com/problems/distribute-coins-in-binary-tree
        GfG Link                    : Distribute Candies in a Binary Tree: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
*/

/****************************************************************** C++ ****************************************************************************************/


/*
    Approach Summary : 
        A recursive approach is used to traverse the binary tree. For each 
        node, the function calculates the total number of extra candies/
        coins that can be distributed among its left and right subtrees, 
        along with the candies at the current node. The function also 
        updates the moves variable to keep track of the total number of 
        moves required to distribute candies/coins. The distributeCandy 
        function initializes the moves variable and checks if the tree has 
        only one node. If it does, the function returns 0. Otherwise, it 
        calls the solve function to perform the candy/coins distribution 
        and returns the total number of moves required. Overall, the code 
        implements a candy/coins distribution algorithm for a binary tree, 
        aiming to minimize the total number of moves while ensuring each 
        node receives an appropriate number of candies/coins.
*/



//T.C : O(n)
//S.C : O(height of tree due to recursion)
class Solution {
public:
    int solve(TreeNode* root, int &moves) {
        if(root == NULL) {
            return 0;
        }
        
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);
        
        int total_extra_candies = (l + r + root->val) - 1;
        
        moves += abs(l) + abs(r);
        
        return total_extra_candies;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        if(!root->left && !root->right) {
            return 0;
        }
        solve(root, moves);
        
        return moves;
    }
};



/*
        GfG Link: Distribute Candies in a Binary Tree: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
*/
class Solution
{
    public:
    
    int solve(Node * root, int& moves) {
        if  (!root) 
            return 0;
            
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);
        
        // int total_extra_candies = (l + r + root->val) - 1;
        
        moves += abs(l) + abs(r);
        
        return (l + r + root->key) - 1;

        // return total_extra_candies;

    }
    
    int distributeCandy(Node* root)
    {
        //code here
        
        int moves = 0;

        solve(root, moves);
        
        return moves;
    }
};

/****************************************************************** JAVA ****************************************************************************************/
//T.C : O(n)
//S.C : O(height of tree due to recursion)
class Solution {
    public static int distributeCandy(Node root) {
        if (root == null || (root.left == null && root.right == null)) {
            return 0;
        }

        int[] moves = {0};
        solve(root, moves);

        return moves[0];
    }
    private static int solve(Node root, int[] moves) {
        if (root == null) {
            return 0;
        }

        int l = solve(root.left, moves);
        int r = solve(root.right, moves);

        int totalExtraCandies = (l + r + root.data) - 1;

        moves[0] += Math.abs(l) + Math.abs(r);

        return totalExtraCandies;
    }
}





















/*
        YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FmHxY2104hc
*/