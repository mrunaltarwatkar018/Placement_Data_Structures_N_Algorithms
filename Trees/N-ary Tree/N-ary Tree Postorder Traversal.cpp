/*    Leetcode Problem No.: 590. N-ary Tree Postorder Traversal    */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
*/


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
















