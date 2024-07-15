/*    Leetcode Problem No.: 2196. Create Binary Tree From Descriptions    */

/*
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/create-binary-tree-from-descriptions/description
*/


/******************************************************** C++ ********************************************************/
// Simple Approach using map and set
// T.C : O(n), where n is the size of descriptions
// S.C : O(n), size of map and set

/*
    Summary :

        The given approach creates a binary tree from a list of 
        descriptions, where each description contains a parent node, a 
        child node, and an indicator of whether the child is a left child.

        Initialize Data Structures:

            mp : An unordered map to store pointers to TreeNode objects, 
            keyed by their values.

            childSet: An unordered set to keep track of all child nodes.

        Process Each Description:

            For each description in the input list:

                Extract the parent, child, and isLeft (indicating whether 
                the child is a left child).

                If the parent node is not already in nodes, create a new 
                TreeNode for it and add it to nodes.

                If the child node is not already in nodes, create a new 
                TreeNode for it and add it to nodes.

            Establish the parent-child relationship:
                If isLeft is true, set the left child of the parent node.
                Otherwise, set the right child of the parent node.
                Add the child node to childSet.

            Identify the Root Node:
                Iterate through the descriptions again to find the root 
                node, which is a node that is never a child.

                The root node is the node in nodes that is not present in 
                childSet.

            Return the Root Node:
                Return the root node found in the previous step. If no such 
                node is found, return nullptr.

    This method ensures that all nodes are created and linked correctly 
    according to the given descriptions, and efficiently identifies the 
    root node by excluding any node that appears as a child.


*/


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; //they can never be root of the tree


        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }


        //Find the root
        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; //we will never reach here
    }
};






// other way

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

/*
    Summary :

        The given approach creates a binary tree from a list of 
        descriptions, where each description contains a parent node, a 
        child node, and an indicator of whether the child is a left child.

        Initialize Data Structures:

            mp : An unordered map to store pointers to TreeNode objects, 
            keyed by their values.

            childSet: An unordered set to keep track of all child nodes.

        Process Each Description:

            For each description in the input list:

                Extract the parent, child, and isLeft (indicating whether 
                the child is a left child).

                If the parent node is not already in nodes, create a new 
                TreeNode for it and add it to nodes.

                If the child node is not already in nodes, create a new 
                TreeNode for it and add it to nodes.

            Establish the parent-child relationship:
                If isLeft is true, set the left child of the parent node.
                Otherwise, set the right child of the parent node.
                Add the child node to childSet.

            Identify the Root Node:
                Iterate through the descriptions again to find the root 
                node, which is a node that is never a child.

                The root node is the node in nodes that is not present in 
                childSet.

            Return the Root Node:
                Return the root node found in the previous step. If no such 
                node is found, return nullptr.

    This method ensures that all nodes are created and linked correctly 
    according to the given descriptions, and efficiently identifies the 
    root node by excluding any node that appears as a child.


*/

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> mp;

        unordered_set<int> childSet;  //they can never be root of the tree

        for ( vector <int> & vec : descriptions) {  // O(n)
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if ( mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if ( mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { // left child
                mp[parent] -> left = mp[child];
            } else {
                mp[parent] -> right = mp[child];
            }

            childSet.insert(child);
        }

        //Find the roo
        for (vector<int> & vec : descriptions ) {  // O(n)
            int parent = vec[0];

            if ( childSet.find(parent) == childSet.end()) { // if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; // we will never reach here

    }
};






















/******************************************************** JAVA ********************************************************/
//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> mp = new HashMap<>();
        Set<Integer> childSet = new HashSet<>();

        // Create nodes and set up parent-child relationships
        for (int[] description : descriptions) {
            int parent = description[0];
            int child = description[1];
            boolean isLeft = description[2] == 1;

            mp.putIfAbsent(parent, new TreeNode(parent));
            mp.putIfAbsent(child, new TreeNode(child));

            if (isLeft) {
                mp.get(parent).left = mp.get(child);
            } else {
                mp.get(parent).right = mp.get(child);
            }

            childSet.add(child);
        }

        // Find the root node (which is not any child)
        for (int[] description : descriptions) {
            int parent = description[0];
            if (!childSet.contains(parent)) {
                return mp.get(parent);
            }
        }

        return null;
    }
}























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Rt2prDOV2hU
*/