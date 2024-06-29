/* Leetcode Problem No.: 2192. All Ancestors of a Node in a Directed Acyclic Graph  */

/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
*/


/*************************************************************** Thought Process ***************************************************************/

/*
    Summary :

        Approach 1: Using DFS

            Time Complexity: 𝑂(𝑛×(𝑛+𝑚))
            Space Complexity: O(n+m)

            In this approach, the algorithm performs Depth-First Search (DFS) from each 
            node to find its ancestors.
            The adjacency list representation of the graph is used to keep track of the 
            edges. For each node, a DFS is initiated to traverse its descendants, 
            marking the ancestors along the way. This approach ensures no duplicate 
            entries by checking if an ancestor has already been recorded.


        Approach 2: Reversing the Graph + Using DFS

            Time Complexity: 𝑂(𝑛×(𝑛+𝑚))
            Space Complexity: O(n+m) 

            This approach involves reversing the graph so that for each edge is 
            reversed. The algorithm then uses DFS from each node in the reversed graph
            to find all nodes that can reach the starting node, which effectively gives 
            all the ancestors of the starting node. The ancestors are collected by 
            traversing the visited nodes for each DFS run.


        Approach 3: Using Topological Sorting

            Time Complexity: O(n + m + n^2 + nlogn)
            Space Complexity: O(n^2+m)

            In this approach, the algorithm first performs a topological sort on the 
            graph. Nodes are processed in topologically sorted order, ensuring that 
            each node's ancestors are processed before the node itself. An adjacency 
            list represents the graph, and an in-degree array keeps track of incoming 
            edges to perform the topological sort. After sorting, a set-based approach 
            is used to accumulate ancestors efficiently, followed by converting the 
            sets to sorted lists.


        Summary of Differences
            DFS-based Approaches (1 & 2):

            Both DFS-based approaches have similar time and space complexities.
            Approach 1 does not reverse the graph, while Approach 2 does.
            
            Both approaches use DFS to find and mark ancestors but differ in how they 
            initialize and use the graph representation.


        Topological Sort Approach (3):

            This approach leverages topological sorting to process nodes in a specific 
            order, ensuring that ancestor information is propagated correctly.

            It includes additional steps to sort the ancestor lists, contributing to 
            its higher space complexity due to maintaining sets and sorting lists.

            This method can be more efficient in practice when dealing with large 
            acyclic graphs due to the structured processing order of nodes.
*/


/*************************************************************** C++ ***************************************************************/



//Approach-1 (Using DFS)
//T.C : O(n * (n+m)) , n = number of vertices and m = number of edges
//S.C : O(n+m)

/*
        Approach 1: Using DFS

            Time Complexity: 𝑂(𝑛×(𝑛+𝑚))
            Space Complexity: O(n+m)

            In this approach, the algorithm performs Depth-First Search (DFS) from each 
            node to find its ancestors.

            The adjacency list representation of the graph is used to keep track of the 
            edges. For each node, a DFS is initiated to traverse its descendants, 
            marking the ancestors along the way. This approach ensures no duplicate 
            entries by checking if an ancestor has already been recorded.
*/

class Solution {
public:

    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result) {

        for(int &ngbr : adj[currNode]) {
            if(result[ngbr].empty() || result[ngbr].back() != ancestor) { //to avoid duplicate entry
                result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);
            }
        }

    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); //u --> v
        }


        for(int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, result);
        }

        return result;
    }
};


//Approach-2 (Reversing the graph + Using DFS)
//T.C : O(n * (n+m)) , n = number of vertices and m = number of edges
//S.C : O(n+m)

/*
        Approach 2: Reversing the Graph + Using DFS

            Time Complexity: 𝑂(𝑛×(𝑛+𝑚))
            Space Complexity: O(n+m) 

            This approach involves reversing the graph so that for each edge is 
            reversed. The algorithm then uses DFS from each node in the reversed graph
            to find all nodes that can reach the starting node, which effectively gives 
            all the ancestors of the starting node. The ancestors are collected by 
            traversing the visited nodes for each DFS run.
*/

class Solution {
public:

    void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;

        for(int &v : adj[u]) {
            if(visited[v] != true) {
                DFS(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : edges) { //O(E)
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u); //v --> u
        }


        for(int u = 0; u < n; u++) {
            vector<int> ancestors;
            vector<bool> visited(n, false);
            DFS(u, adj, visited);

            for(int i = 0; i < n; i++) {
                if(i == u) continue;
                
                if(visited[i] == true) {
                    ancestors.push_back(i);
                }
            }

            result.push_back(ancestors);
        }



        
        return result;
    }
};


//Approach-3 (Using Topological Sorting)
//T.C : O(n + m + n^2 + nlogn) -> O(n+m) for building the graph and performing the topological sort, 
//                     -> O(n^2) for processing each node and merging ancestor lists.
//                     -> O(nlogn) for sorting the ancestor lists for each node.
//S.C : O(n^2+m)

/*
        Approach 3: Using Topological Sorting

            Time Complexity: O(n + m + n^2 + nlogn)
            Space Complexity: O(n^2+m)

            In this approach, the algorithm first performs a topological sort on the 
            graph. Nodes are processed in topologically sorted order, ensuring that 
            each node's ancestors are processed before the node itself. An adjacency 
            list represents the graph, and an in-degree array keeps track of incoming 
            edges to perform the topological sort. After sorting, a set-based approach 
            is used to accumulate ancestors efficiently, followed by converting the 
            sets to sorted lists.
*/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj; //S.C : O(V+E)
        
        vector<int> indegree(n, 0);

        for(vector<int>& vec : edges) { //O(E)
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); //u --> v
            indegree[v]++;
        }


        //TOPOLOGICAL SORTING
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topoOrder;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int &v : adj[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);

        for(int &node : topoOrder) {
            for(int &v : adj[node]) {
                vec[v].insert(node); //adding node ancestor
                vec[v].insert(vec[node].begin(), vec[node].end()); //adding ancestors of node
            }
        }

        for(int i = 0; i < n; i++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());

            sort(result[i].begin(), result[i].end());
        }

        
        return result;
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using DFS)
//T.C : O(n * (n+m)) , n = number of vertices and m = number of edges
//S.C : O(n+m)
class Solution {

    private void DFS(int ancestor, Map<Integer, List<Integer>> adj, int currNode, List<List<Integer>> result) {
        for (int ngbr : adj.getOrDefault(currNode, new ArrayList<>())) {
            if (result.get(ngbr).isEmpty() || result.get(ngbr).get(result.get(ngbr).size() - 1) != ancestor) { // to avoid duplicate entry
                result.get(ngbr).add(ancestor);
                DFS(ancestor, adj, ngbr, result);
            }
        }
    }

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> result = new ArrayList<>();
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            result.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v); // u --> v
        }

        for (int i = 0; i < n; i++) {
            DFS(i, adj, i, result);
        }

        return result;
    }
}



//Approach-2 (Reversing the graph + Using DFS)
//T.C : O(n * (n+m)) , n = number of vertices and m = number of edges
//S.C : O(n+m)
import java.util.*;

class Solution {

    private void DFS(int u, Map<Integer, List<Integer>> adj, boolean[] visited) {
        visited[u] = true;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> result = new ArrayList<>();
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) { // O(E)
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u); // v --> u
        }

        for (int u = 0; u < n; u++) {
            List<Integer> ancestors = new ArrayList<>();
            boolean[] visited = new boolean[n];
            DFS(u, adj, visited);

            for (int i = 0; i < n; i++) {
                if (i != u && visited[i]) {
                    ancestors.add(i);
                }
            }

            result.add(ancestors);
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] edges = {{0, 1}, {1, 2}, {2, 3}};
        int n = 4;
        List<List<Integer>> ancestors = sol.getAncestors(n, edges);
        for (int i = 0; i < ancestors.size(); i++) {
            System.out.println("Node " + i + " ancestors: " + ancestors.get(i));
        }
    }
}


//Approach-3 (Using Topological Sorting)
//T.C : O(n + m + n^2 + nlogn) -> O(n+m) for building the graph and performing the topological sort, 
//                     -> O(n^2) for processing each node and merging ancestor lists.
//                     -> O(nlogn) for sorting the ancestor lists for each node.
//S.C : O(n^2+m)
class Solution {

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> result = new ArrayList<>(n);
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[n];

        for (int i = 0; i < n; i++) {
            result.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v]++;
        }

        // TOPOLOGICAL SORTING
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        List<Integer> topoOrder = new ArrayList<>();
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            topoOrder.add(curr);

            for (int v : adj.getOrDefault(curr, new ArrayList<>())) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue.offer(v);
                }
            }
        }

        List<Set<Integer>> vec = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            vec.add(new HashSet<>());
        }

        for (int node : topoOrder) {
            for (int v : adj.getOrDefault(node, new ArrayList<>())) {
                vec.get(v).add(node); // adding node ancestor
                vec.get(v).addAll(vec.get(node)); // adding ancestors of node
            }
        }

        for (int i = 0; i < n; i++) {
            result.set(i, new ArrayList<>(vec.get(i)));
            Collections.sort(result.get(i));
        }

        return result;
    }
}



/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zdGouql8XKs
*/