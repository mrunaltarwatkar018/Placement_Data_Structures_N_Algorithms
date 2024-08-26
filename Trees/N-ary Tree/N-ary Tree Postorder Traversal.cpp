/*    Leetcode Problem No.: 590. N-ary Tree Postorder Traversal    */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
*/

// Approach 1
class Solution {
public:
    vector<int> result;
    
    void traverse(Node* root) {
        if(!root)
            return;
        
        for(Node*& x : root->children) {
            traverse(x);
        }
        
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        result.clear();
        traverse(root);
        return result;
    }
};








// Approach 2









/************************ Java **************************************/
// Approach 1
class Solution {
    private List<Integer> result = new ArrayList<>();

    private void traverse(Node root) {
        if (root == null) {
            return;
        }

        for (Node child : root.children) {
            traverse(child);
        }

        result.add(root.val);
    }

    public List<Integer> postorder(Node root) {
        result.clear();
        traverse(root);
        return result;
    }
}