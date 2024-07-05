/*    Leetcode Problem No.: 623. Add One Row to Tree  */

/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/add-one-row-to-tree/
*/




/********************************************* C++ ****************************************/

/*
    Approach-1: Using Depth-First Search (DFS)

        - Time Complexity (T.C): O(n) - 
            In the worst-case scenario, where every node of the tree needs to be 
            visited.

        - Space Complexity (S.C): 
            O(1) Auxiliary Space, O(depth) system stack space of recursion - In 
            this approach, we use a recursive depth-first traversal. The auxiliary '
            space complexity is O(1) because we don't use any additional data 
            structures. However, the system stack space of recursion can be O
            (depth) in the worst-case scenario, where 'depth' represents the depth 
            of the tree.

        - Description: 
            This approach utilizes a depth-first traversal technique to reach the 
            desired depth in the tree. At the target depth, for each existing node, 
            we insert new nodes as children, thereby adding a new row.

*/



//Approach-1 : Using DFS
//T.C : O(n)
//S.C : O(1) Auxiliary Space, O(depth) system stack space of recursion

class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int currentDepth) {
        if (root == NULL)
            return NULL;

        if (currentDepth == depth - 1) {
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }

        root->left = add(root->left, val, depth, currentDepth + 1);
        root->right = add(root->right, val, depth, currentDepth + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);

            newRoot->left = root;
            return newRoot;
        }

        int currentDepth = 1;

        return add(root, val, depth, currentDepth);
    }
};


// another way to write similar approach

// class Solution {
// public:
    
//     TreeNode* add(TreeNode* root, int val, int depth, int curr) {
//         if(!root)
//             return NULL;
        
//         if(curr == depth-1) {
//             TreeNode* lTemp = root->left;
//             TreeNode* rTemp = root->right;
            
//             root->left  = new TreeNode(val);
//             root->right = new TreeNode(val);
//             root->left->left = lTemp;
//             root->right->right = rTemp;
            
//             return root;
//         }
        
//         root->left  = add(root->left, val, depth, curr+1);
//         root->right = add(root->right, val, depth, curr+1);
        
//         return root;
//     }
    
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth == 1) {
//             TreeNode* newRoot = new TreeNode(val);
//             newRoot->left = root;
//             return newRoot;
//         }
        
//         return add(root, val, depth, 1);
//     }
// };



/*
    Approach-2: Using Breadth-First Search (BFS)
        - Time Complexity (T.C): O(n) - 
            In the worst-case scenario, where every node of the tree needs to be 
            visited.

        - Space Complexity (S.C): O(n) - 
            In this approach, we use a queue to perform a level-order traversal of 
            the tree. The space complexity is O(n) because, in the worst case, the 
            queue can hold all nodes of the tree.

        - Description: 
            This approach employs a breadth-first traversal technique to traverse 
            the tree level by level. We traverse the tree until we reach the target 
            depth - 1. At this level, for each existing node, we insert new nodes 
            as children, thereby adding a new row.

*/

//Approach-2 : Using BFS
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> que;
        
        que.push(root);
        int level = 0;
        bool rowAdded = false;
        while(!que.empty()) {
            int n = que.size();
            level++;
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                TreeNode* tempL = curr->left;
                TreeNode* tempR = curr->right;
                if(level == d-1) {
                    curr->left  = new TreeNode(v);
                    curr->right = new TreeNode(v);
                    curr->left->left   = tempL;
                    curr->right->right = tempR;
                    rowAdded = true;
                }
                if(tempL)
                    que.push(tempL);
                if(tempR)
                    que.push(tempR);
            }
            if(rowAdded)
                break;
        }
        
        return root;
    }
};


/*
    Both approaches achieve the same result but use different traversal strategies 
    - DFS for Approach-1 and BFS for Approach-2. The choice between the two may 
    depend on factors such as the structure of the tree, space constraints, and 
    personal preference.
*/





















































/********************************************* JAVA ********************************************/

/*
    Approach-1: Using Depth-First Search (DFS)

        - Time Complexity (T.C): O(n) - 
            In the worst-case scenario, where every node of the tree needs to be 
            visited.

        - Space Complexity (S.C): 
            O(1) Auxiliary Space, O(depth) system stack space of recursion - In 
            this approach, we use a recursive depth-first traversal. The auxiliary '
            space complexity is O(1) because we don't use any additional data 
            structures. However, the system stack space of recursion can be O
            (depth) in the worst-case scenario, where 'depth' represents the depth 
            of the tree.

        - Description: 
            This approach utilizes a depth-first traversal technique to reach the 
            desired depth in the tree. At the target depth, for each existing node, 
            we insert new nodes as children, thereby adding a new row.

    Approach-2: Using Breadth-First Search (BFS)
        - Time Complexity (T.C): O(n) - 
            In the worst-case scenario, where every node of the tree needs to be 
            visited.

        - Space Complexity (S.C): O(n) - 
            In this approach, we use a queue to perform a level-order traversal of 
            the tree. The space complexity is O(n) because, in the worst case, the 
            queue can hold all nodes of the tree.

        - Description: 
            This approach employs a breadth-first traversal technique to traverse 
            the tree level by level. We traverse the tree until we reach the target 
            depth - 1. At this level, for each existing node, we insert new nodes 
            as children, thereby adding a new row.

    Both approaches achieve the same result but use different traversal strategies 
    - DFS for Approach-1 and BFS for Approach-2. The choice between the two may 
    depend on factors such as the structure of the tree, space constraints, and 
    personal preference.
*/



//Approach-1 : Using DFS
//T.C : O(n)
//S.C : O(1) Auxiliary Space, O(depth) system stack space of recursion
public class Solution {
    public TreeNode add(TreeNode root, int val, int depth, int curr) {
        if (root == null)
            return null;

        if (curr == depth - 1) {
            TreeNode lTemp = root.left;
            TreeNode rTemp = root.right;

            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = lTemp;
            root.right.right = rTemp;

            return root;
        }

        root.left = add(root.left, val, depth, curr + 1);
        root.right = add(root.right, val, depth, curr + 1);

        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }

        return add(root, val, depth, 1);
    }
}



//Approach-2 : Using BFS
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode newRoot = new TreeNode(v);
            newRoot.left = root;
            return newRoot;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;
        boolean rowAdded = false;
        while (!queue.isEmpty()) {
            int n = queue.size();
            level++;
            while (n-- > 0) {
                TreeNode curr = queue.poll();
                TreeNode tempL = curr.left;
                TreeNode tempR = curr.right;
                if (level == d - 1) {
                    curr.left = new TreeNode(v);
                    curr.right = new TreeNode(v);
                    curr.left.left = tempL;
                    curr.right.right = tempR;
                    rowAdded = true;
                }
                if (tempL != null)
                    queue.add(tempL);
                if (tempR != null)
                    queue.add(tempR);
            }
            if (rowAdded)
                break;
        }
        return root;
    }
}










































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Za2OFfRLp70
*/