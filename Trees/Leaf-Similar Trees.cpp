/*    Leetcode Problem No.: 872. Leaf-Similar Trees    */

/*
    Company Tags                : Meta, Microsoft, Twitter, Amazon, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/leaf-similar-trees/
*/

/******************************************************** C++ ********************************************************/


/*
    Approach Summary : 
        The approach involves performing an in-order traversal on each tree using a 
        helper method called inOrder. 

        During the traversal, the leaf node values are appended to string/
        StringBuilder objects in a specific format.

        The resulting strings for both trees are then compared, and the method 
        returns true if the leaf sequences are similar and false otherwise.

        This approach leverages in-order traversal to capture the leaf nodes and 
        compares their sequences for similarity.
*/


//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
class Solution {
public:
    
    void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;
    }
};



// anpther way
class Solution {
public:

    void inOrder(TreeNode* root, string & s ) {

        if (root == NULL) 
            return ;

        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }

        inOrder(root -> left, s);
        inOrder(root -> right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        string s1 = "";
        string s2 = "";

        inOrder(root1, s1);
        inOrder(root2, s2);

        if (s1 == s2)
            return true;

        return false;
    }
};


// using vector
//T.C : O(n)
//S.C : O(n)

class Solution {
private:

    void addLeafToSum(TreeNode* root, vector<int>& ourVec) {
        if (!root) {
            return;
			// Push back the value of each leaf into our vector
        } else if (root && root->left == nullptr && root->right == nullptr) {
            ourVec.push_back(root->val);
        }
        addLeafToSum(root->left, ourVec);
        addLeafToSum(root->right, ourVec);
        return;
    }
    
public:

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Vec;
        vector<int> root2Vec;
        addLeafToSum(root1, root1Vec);
        addLeafToSum(root2, root2Vec);
		// If there are a different number of leafs, it can't be the same
        if (root1Vec.size() != root2Vec.size()) return false;
        for (int i{}; i < root1Vec.size(); ++i) {
            if (root1Vec[i] != root2Vec[i]) return false;
        }
		// If all checks passed, return true
        return true;
    }
};






















/******************************************************** JAVA ********************************************************/
//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
public class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        inOrder(root1, s1);
        inOrder(root2, s2);

        return s1.toString().equals(s2.toString());
    }

    private void inOrder(TreeNode root, StringBuilder s) {
        if (root == null) return;

        // Leaf node
        if (root.left == null && root.right == null) {
            s.append(root.val).append("_");
            return;
        }

        inOrder(root.left, s);
        inOrder(root.right, s);
    }
}

































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rlWJlXQNt0Q
*/