/*    Leetcode Problem No.: 1530. Number of Good Leaf Nodes Pairs    */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
*/


/****************************************************** C++ *********************************************/
// Approach-1 (Using Graph and BFS)
// T.C : O(n^2)
// S.C : O(n)

/*
    Summary :

        The key methods are makeGraph and countPairs.

        Converts a binary tree into an undirected graph using an adjacency list 
        (adj).

        Marks leaf nodes by adding them to a set (st).
        
        Takes root as the current node, prev as the previous node, and recursively 
        processes the tree.

        If the current node (root) is a leaf node, it is added to the set of leaves.
        
        Connects the current node with its parent (prev) in the adjacency list.

        countPairs(TreeNode root, int distance):

            Initializes an adjacency list (adj) and a set of leaf nodes (st).
            
            Calls makeGraph to populate these structures.
            
            Uses BFS (Breadth-First Search) to find pairs of leaf nodes within the 
            specified distance.

            For each leaf node, it performs BFS up to the given distance, checking 
            if other leaf nodes are reachable within this distance.

            Counts and returns the number of valid leaf node pairs, dividing by 2 to 
            avoid double-counting.

*/

class Solution {
public:

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
                    unordered_set<TreeNode*>& st) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) { //LEAF NODE
            st.insert(root);
        }

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);

    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; //Graph
        unordered_set<TreeNode*> st; //leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0; //count of good node pairs

        for(auto &leaf : st) {

            //BFS hit karo and see if you can find another leaf nodes within distance
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);


            for(int level = 0; level <= distance; level++) { //only go till level <= distance
                int size = que.size();
                while(size--) { //level processed
                    TreeNode* curr = que.front();
                    que.pop();

                    if(curr != leaf && st.count(curr)) { 
                        count++;
                    }

                    for(auto &ngbr : adj[curr]) {
                        if(!visited.count(ngbr)) {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};



//Approach-2 



















/****************************************************** JAVA *********************************************/
//Approach-1 (Using Graph and BFS)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public void makeGraph(TreeNode root, TreeNode prev, Map<TreeNode, List<TreeNode>> adj, Set<TreeNode> leafNodes) {
        if (root == null) {
            return;
        }

        if (root.left == null && root.right == null) { // Leaf node
            leafNodes.add(root);
        }

        if (prev != null) {
            adj.computeIfAbsent(root, k -> new ArrayList<>()).add(prev);
            adj.computeIfAbsent(prev, k -> new ArrayList<>()).add(root);
        }

        makeGraph(root.left, root, adj, leafNodes);
        makeGraph(root.right, root, adj, leafNodes);
    }

    public int countPairs(TreeNode root, int distance) {
        Map<TreeNode, List<TreeNode>> adj = new HashMap<>(); // Graph
        Set<TreeNode> leafNodes = new HashSet<>(); // Leaf nodes

        makeGraph(root, null, adj, leafNodes);

        int count = 0; // Count of good node pairs

        for (TreeNode leaf : leafNodes) {
            // Perform BFS and see if you can find other leaf nodes within distance
            Queue<TreeNode> queue = new LinkedList<>();
            Set<TreeNode> visited = new HashSet<>();
            queue.add(leaf);
            visited.add(leaf);

            for (int level = 0; level <= distance; level++) { // Only go till level <= distance
                int size = queue.size();
                while (size-- > 0) { // Process level
                    TreeNode curr = queue.poll();

                    if (curr != leaf && leafNodes.contains(curr)) {
                        count++;
                    }

                    for (TreeNode neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
                        if (!visited.contains(neighbor)) {
                            queue.add(neighbor);
                            visited.add(neighbor);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
}




//Approach-2 






























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vrbJ7aDuK-A
*/