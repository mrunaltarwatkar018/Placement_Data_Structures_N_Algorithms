/*    Leetcode Problem No.: 1530. Number of Good Leaf Nodes Pairs    */

/*
    Company Tags                : TIKTOK
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



//Approach-2 (Using DFS)
//T.C : O(n*m^2) where m = number of leaf nodes
//S.C : O(n*m) where m = number of leaf nodes

/*
    Summary :

        The given C++ code defines a solution to count the number of good leaf node 
        pairs within a given distance in a binary tree. Here is a step-by-step 
        summary of the approach:

        Helper Function solve:

            The solve function is a recursive helper function that traverses the 
            tree and calculates distances from each node to its leaf nodes.

            Base Case: 
                If the current node (root) is NULL, it returns a vector containing a 
                single 0.

            Leaf Node: 
                If the current node is a leaf node (no left or right child), it 
                returns a vector containing 1.

            Recursive Case: 
                For non-leaf nodes, it recursively calculates distances for the left 
                and right subtrees.

        Distance Calculation:

            After obtaining distances from the left (left_d) and right (right_d) 
            subtrees, it checks pairs of distances from these lists.

            If the sum of any pair of distances is less than or equal to the given 
            distance, it increments the goodLeafNodes counter.

        Updating Distances:

            The function then constructs a new list of distances (curr_d) for the 
            current node by incrementing each valid distance from the left and right 
            subtrees by 1 (to account for the distance to the current node itself).
        
        Returning Distances:

            Finally, the updated list of distances is returned to the caller.

        Main Function countPairs:

            The countPairs function initializes the goodLeafNodes counter and calls 
            the solve function with the root of the tree.

            It returns the total count of good leaf node pairs.

        Key Points:

        Recursion: 
            The solution leverages recursion to traverse the tree and compute 
            distances.

        Distance Lists: 
            At each node, lists of distances to leaf nodes are maintained and   
            updated.

        Pairwise Comparison: 
            Pairs of distances from left and right subtrees are compared to 
            determine good leaf node pairs.

        Efficiency: 
            The method ensures that only valid distances (within the specified 
            limit) are propagated up the tree to minimize unnecessary calculations.

    This approach effectively combines tree traversal and distance computation to 
    solve the problem within the constraints provided.
*/




class Solution {
public:

    vector<int> solve(TreeNode * root, int & distance, int & goodLeafNodes) {
        if ( root == NULL) {
            return {0};
        }

        if (root -> left == NULL && root -> right == NULL) {
            return {1};
        }

        vector<int > left_distance = solve(root -> left, distance, goodLeafNodes);
        vector<int > right_distance = solve(root -> right, distance, goodLeafNodes);

        for ( int & l : left_distance) {
            for ( int & r : right_distance) {
                if (( l != 0 && r != 0) && l + r <= distance ) {
                    goodLeafNodes++;
                }
            }
        }

        vector<int> cuur_distance;
        for ( int & l : left_distance ) {
            if ( l != 0 && l + 1 <= distance )
                cuur_distance.push_back(l + 1);
        }

        for ( int & r : right_distance ) {
            if ( r != 0 && r + 1 <= distance )
                cuur_distance.push_back(r + 1);
        }

        return cuur_distance;
    }

    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        solve(root, distance, goodLeafNodes);
        return goodLeafNodes;
    }
};












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




//Approach-2 (Using DFS)
//T.C : O(n*m^2) where m = number of leaf nodes
//S.C : O(n*m) where m = number of leaf nodes
public class Solution {

    public List<Integer> solve(TreeNode root, int distance, int[] goodLeafNodes) {
        if (root == null) {
            List<Integer> emptyList = new ArrayList<>();
            emptyList.add(0);
            return emptyList;
        }

        if (root.left == null && root.right == null) {
            List<Integer> leafList = new ArrayList<>();
            leafList.add(1);
            return leafList;
        }

        List<Integer> leftDistances = solve(root.left, distance, goodLeafNodes);
        List<Integer> rightDistances = solve(root.right, distance, goodLeafNodes);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l != 0 && r != 0 && l + r <= distance) {
                    goodLeafNodes[0]++;
                }
            }
        }

        List<Integer> currentDistances = new ArrayList<>();
        for (int ld : leftDistances) {
            if (ld != 0 && ld + 1 <= distance) {
                currentDistances.add(ld + 1);
            }
        }

        for (int rd : rightDistances) {
            if (rd != 0 && rd + 1 <= distance) {
                currentDistances.add(rd + 1);
            }
        }

        return currentDistances;
    }

    public int countPairs(TreeNode root, int distance) {
        int[] goodLeafNodes = new int[1];
        solve(root, distance, goodLeafNodes);
        return goodLeafNodes[0];
    }
}





























/*
    YOUTUBE VIDEO ON THIS Qn :  Approach-1 : https://youtu.be/vrbJ7aDuK-A?si=3-8sRu8qdYcJvJf1
                                Approach-2 : https://www.youtube.com/watch?v=AW-gpXiR5DQ
*/