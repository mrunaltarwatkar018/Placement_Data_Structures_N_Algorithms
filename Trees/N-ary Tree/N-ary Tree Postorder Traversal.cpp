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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Approach 2
// Left Right Root : Post Order Traversal


// Time Complexity: O(N)
// Space Complexity: O(N)  no extra space required
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(Node* root, vector<int>& list) {
        if (root == nullptr) {
            return;
        }

        for (Node* child : root->children) {
            dfs(child, list);
        }
        list.push_back(root->val);
    }
};








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




/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/


// Approach 2
// Left Right Root : Post Order Traversal


// Time Complexity: O(N)
// Space Complexity: O(N)  no extra space required


class Solution {

    public void dfs(Node root, List<Integer> List) {
        if ( root == null ) {
            return;
        }

        for ( Node child : root.children) {
            dfs(child, List);
        }
        List.add(root.val);
    }

    public List<Integer> postorder(Node root) {
        List<Integer> List = new ArrayList<> ();
        dfs(root, List);
        return List;
    }
}

























//if in Qn is asked to find out -
// For level order, just print the children at every level. 

class Solution {
public:
    vector<int> levelOrder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        // Use a queue to perform the level order traversal
        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            Node* currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Add the current node's value to the result
            result.push_back(currentNode->val);

            // Enqueue all the children of the current node
            for (Node* childNode : currentNode->children) {
                nodeQueue.push(childNode);
            }
        }

        return result;
    }
};