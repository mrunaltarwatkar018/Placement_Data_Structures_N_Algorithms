/*    GFG Problem:  Paths from root with a specified sum    */


/*
    Company Tags                : Microsoft
    GfG Link                    : https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

/********************************************************************** C++ **********************************************************************/
//T.C : O(n)
//S.C : O(height of tree)

/*
    Approach Summary : 
        
        The solve method traverses the binary tree using a depth-first search 
        approach. It keeps track of the current path's sum (curr_sum) and 
        appends each node's value to the temporary vector temp. If the current 
        path's sum equals the given sum, the path is added to the result vector. 
        The method then recursively calls itself for the left and right subtrees 
        of the current node. Finally, it backtracks by removing the last element 
        from the temporary vector temp to explore other paths.The printPaths 
        method initializes an empty vector temp and calls the solve method to 
        find paths with the specified sum. The result vector is then returned. 
        In summary, the code aims to find all paths in a binary tree where the 
        sum of node values equals a given target sum and stores these paths in 
        the result vector.
*/


// one way

class Solution
{
    public:
    
    vector <vector<int>> result;
    
    void solve(Node* root, vector<int>& temp, int curr_sum, int sum) {
        if (root == NULL)
            return;
            
        curr_sum += root -> key;
        temp.push_back(root -> key);
        
        if (sum == curr_sum){
            result.push_back(temp);
        }
        
        solve(root -> left, temp, curr_sum, sum);
        solve(root -> right, temp, curr_sum, sum);
        
        temp.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<int> temp;
        
        solve(root, temp, 0, sum);
        
        return result;
    }
};



// another way

class Solution
{
    public:
    vector<vector<int>> result;
    
    void solve(Node* root, int sum, vector<int>& temp, int curr_sum) {
        if(root == NULL) {
            return;
        }
        
        curr_sum += root->key;
        temp.push_back(root->key);
        
        if(sum == curr_sum) {
            result.push_back(temp);
        }
        
        
        solve(root->left, sum, temp, curr_sum);
        solve(root->right, sum, temp, curr_sum);
        temp.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int> temp;
        solve(root, sum, temp, 0);
        
        return result;
        
    }
};




















































































































































































/********************************************************************** JAVA **********************************************************************/
//T.C : O(n)
//S.C : O(height of tree)
class Solution
{
    private static ArrayList<ArrayList<Integer>> result = new ArrayList<>();
    private static void solve(Node root, int sum, ArrayList<Integer> temp, int currSum) {
        if (root == null) {
            return;
        }

        currSum += root.data;
        temp.add(root.data);

        if (sum == currSum) {
            result.add(new ArrayList<>(temp));
        }

        solve(root.left, sum, temp, currSum);
        solve(root.right, sum, temp, currSum);
        temp.remove(temp.size() - 1);
    }
    
    public static ArrayList<ArrayList<Integer>> printPaths(Node root, int sum) {
        ArrayList<Integer> temp = new ArrayList<>();
        solve(root, sum, temp, 0);

        return result;
    }
}

















































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Nrdm2a5gsr8
*/