/*    Leetcode Problem No.: 2385. Amount of Time for Binary Tree to Be Infected    */


/*

    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
*/


/******************************************************************** C++ ********************************************************************/
// Approach-1 (Convert tree to graph)
// T.C : O(n) - visiting all nodes
// S.C : O(n) - storing all nodes in graph
class Solution {
public:
    void convert(TreeNode* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) {
            return;
        }

        if (parent != -1) {
            adj[current->val].push_back(parent);
        }

        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        } 
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);

        queue<int> que;
        que.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};


//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack


/*
    Approach Summary : 
        The approach utilizes a recursive depth-first traversal of the 
        binary tree. The "traverse" function calculates the depth of each 
        subtree and updates the maximum distance based on certain 
        conditions. The "amountOfTime" function initiates the traversal 
        with the root of the binary tree and the specified starting node 
        value. The final result returned is the maximum distance from the 
        starting node value to any leaf node in the tree.
*/


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
    Approach Summary : 
        The approach utilizes a recursive depth-first traversal of the 
        binary tree. The "traverse" function calculates the depth of each 
        subtree and updates the maximum distance based on certain 
        conditions. The "amountOfTime" function initiates the traversal 
        with the root of the binary tree and the specified starting node 
        value. The final result returned is the maximum distance from the 
        starting node value to any leaf node in the tree.
*/
class Solution {
public:
int result = INT_MIN;

    int solve (TreeNode * root, int start) {
        if (!root)
            return 0;

        int LH = solve(root -> left, start);
        int RH = solve(root -> right, start);

        if (root -> val == start) {
            result = max(LH, RH);
            return -1;
        } else if (LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int distance = abs(LH) + abs(RH);
            result = max(result, distance);
            return min(LH, RH) -1;
        }
        return 0;
    }


    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);
        return result;
    }
};







// another way
class Solution {
public:
    int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};


/******************************************************************** JAVA ********************************************************************/
//Approach-1 (Convert tree to graph)
//T.C : O(n) - visiting all nodes
//S.C : O(n) - storing all nodes in graph
public class Solution {

    public void convert(TreeNode current, int parent, Map<Integer, List<Integer>> adj) {
        if (current == null) {
            return;
        }

        if (parent != -1) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(parent);
        }

        if (current.left != null) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(current.left.val);
        }
        if (current.right != null) {
            adj.computeIfAbsent(current.val, k -> new ArrayList<>()).add(current.right.val);
        }
        convert(current.left, current.val, adj);
        convert(current.right, current.val, adj);
    }

    public int amountOfTime(TreeNode root, int start) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        convert(root, -1, adj);

        Queue<Integer> que = new LinkedList<>();
        que.add(start);
        Set<Integer> visited = new HashSet<>();
        visited.add(start);
        int minutes = 0;

        while (!que.isEmpty()) {
            int n = que.size();

            while (n-- > 0) {
                int curr = que.poll();

                for (int ngbr : adj.getOrDefault(curr, Collections.emptyList())) {
                    if (!visited.contains(ngbr)) {
                        que.add(ngbr);
                        visited.add(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
}


//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack
public class Solution {
    private int result = Integer.MIN_VALUE;

    public int solve(TreeNode root, int start) {
        if (root == null) {
            return 0;
        }

        int LH = solve(root.left, start);
        int RH = solve(root.right, start);

        if (root.val == start) {
            result = Math.max(LH, RH);
            return -1;
        } else if (LH >= 0 && RH >= 0) {
            return Math.max(LH, RH) + 1;
        } else {
            int d = Math.abs(LH) + Math.abs(RH);
            result = Math.max(result, d);

            return Math.min(LH, RH) - 1;
        }
    }

    public int amountOfTime(TreeNode root, int start) {
        solve(root, start);
        return result;
    }
}



























/*
    MY YOUTUBE VIDEO ON THIS Qn :   2-Pass solution - https://www.youtube.com/watch?v=JIlQvhrKuAk
                                    1-Pass solution - https://www.youtube.com/watch?v=Xm8jIjAK_Zs*/