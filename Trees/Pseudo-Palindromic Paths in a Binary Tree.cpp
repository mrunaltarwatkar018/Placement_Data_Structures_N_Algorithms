/*    Leetcode Problem No.: 1457. Pseudo-Palindromic Paths in a Binary Tree   */



/*
    Company Tags                 : will update soon
    Leetcode Link                : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/


/****************************************************** C++ ******************************************************/
// Approach-1 (Simple and straight forward)
// T.C : O(n)
// S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))

/*
    Approach-1 Summary : 
        The approach involves a recursive depth-first search (DFS) 
        function called solve that traverses the tree while maintaining a 
        temporary vector (temp) to count the occurrences of each node 
        value. For each node encountered during the DFS, the corresponding 
        value in the temp vector is incremented. When a leaf node is 
        reached, the algorithm checks whether the frequency of each value 
        in temp is such that at most one value has an odd frequency. If 
        this condition is met, the global variable result is incremented, 
        signifying the discovery of a pseudo-palindromic path. The DFS 
        continues to explore the left and right subtrees, updating the 
        temp vector accordingly. The count for the current node is 
        decremented before backtracking to the parent node, ensuring 
        correct frequency tracking. The main function 
        pseudoPalindromicPaths initializes the temp vector and calls the 
        solve function to traverse the tree. Finally, it returns the total 
        count of pseudo-palindromic paths stored in the global variable 
        result. The approach essentially leverages DFS and a frequency 
        tracking vector to identify and count pseudo-palindromic paths in 
        the binary tree.
*/

class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& count) {
        if(root != NULL) {
            count[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(count[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                if (oddFreq <= 1) {
                    result += 1;
                }
                // or u can write as above 3 lines
                // result += oddFreq <= 1;
            }
            
            
            solve(root->left, count);
            solve(root->right, count);
            
            count[root->val]--;

        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        
        solve(root, count);
        return result;
    }
};

// another way

class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& count) {
        if(root == NULL) {
            return;
        }
            count[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(count[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                if (oddFreq <= 1) {
                    result += 1;
                }
                // or u can write as above 3 lines
                // result += oddFreq <= 1;
            }
            
            
            solve(root->left, count);
            solve(root->right, count);
            
            count[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        
        solve(root, count);
        return result;
    }
};




//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))

/*
    Approach-2 Summary : 
        The approach involves a recursive depth-first search (DFS) 
        function called solve that traverses the tree while maintaining a 
        temporary variable (temp) to keep track of the XOR combination of 
        encountered node values. For each node encountered during the DFS, 
        the value in temp is updated using a bitwise XOR operation with 
        the binary representation of the current node's value. When a leaf 
        node is reached, the algorithm checks whether the bitwise AND 
        operation between temp and (temp - 1) equals 0. This check ensures 
        that there is at most one set bit in the binary representation of 
        temp, indicating a pseudo-palindromic path. If the condition is 
        met, the global variable result is incremented, signifying the 
        discovery of a pseudo-palindromic path. The DFS continues to 
        explore the left and right subtrees, updating the temp variable 
        accordingly. The main function pseudoPalindromicPaths initializes 
        the temp variable to 0 and calls the solve function to traverse 
        the tree. Finally, it returns the total count of 
        pseudo-palindromic paths stored in the global variable result. 
        This approach utilizes bitwise XOR and AND operations to 
        efficiently track the occurrence of node values and identify 
        pseudo-palindromic paths in the binary tree. The use of XOR helps 
        toggle the bits representing the occurrence of node values, and 
        the bitwise AND operation is employed to check the 
        pseudo-palindromic property.
*/
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};

// another way
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int count) {
        if(root == NULL) {
            return;
        }
            count = (count ^ (1 << root -> val));
            
            if(root->left == NULL && root->right == NULL) {
                if ((count & (count -1)) == 0) {
                    result += 1;
                }
            }
            solve(root->left, count);
            solve(root->right, count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return result;
    }
};



/****************************************************** JAVA ******************************************************/
//Approach-1 (Simple and straight forward)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
    private int result = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        int[] temp = new int[10];
        solve(root, temp);
        return result;
    }

    private void solve(TreeNode root, int[] temp) {
        if (root != null) {
            temp[root.val]++;

            if (root.left == null && root.right == null) {
                int oddFreq = 0;
                for (int i = 1; i <= 9; i++) {
                    if (temp[i] % 2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1 ? 1 : 0;
            }

            solve(root.left, temp);
            solve(root.right, temp);

            temp[root.val]--;
        }
    }
}


//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
    private int result = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        solve(root, 0);
        return result;
    }

    private void solve(TreeNode root, int temp) {
        if (root != null) {
            temp = temp ^ (1 << root.val);

            if (root.left == null && root.right == null) {
                if ((temp & (temp - 1)) == 0) {
                    result++;
                }
            }

            solve(root.left, temp);
            solve(root.right, temp);
        }
    }
}























/*
    YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=FK-Fztwj2gM
*/