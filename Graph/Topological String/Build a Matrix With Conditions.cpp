/* Leetcode Problem No.: 2392. Build a Matrix With Conditions  */


/*
    Company Tags                : APPLE
    Leetcode Link               : https://leetcode.com/problems/build-a-matrix-with-conditions
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Topological Sorting using DFS)
//T.C : O(k*^2 + n)
//S.C : O(k*^2 + n)

/*
    Summary :
        Approach 1: Topological Sorting using DFS

            Time Complexity (T.C.): O(k2+n)
            Space Complexity (S.C.): O(k2+n)

            This approach uses Depth-First Search (DFS) to perform topological 
            sorting. Here’s a breakdown:

            Graph Representation: 
                The graph is represented using an adjacency list stored in an 
                unordered map.

            DFS for Topological Sort:
                Nodes are marked as not visited, visiting, or visited using a 
                visited vector.

                A DFS is performed, pushing nodes onto a stack when their entire 
                subtree has been processed.

                During DFS, if a node that is currently being visited is encountered 
                again, a cycle is detected.

            Cycle Detection: 
                If a cycle is detected during the DFS, an empty order is returned, 
                indicating no valid topological ordering is possible.

            Order Construction: 
                Nodes are popped from the stack to form the topological order.

*/

class Solution {
public:

    void dfs(int u, vector<int> & visited, unordered_map<int, vector<int>> & adj, stack<int> & st, bool & cycle ) {
        visited[u] = 1;  // Mark node as visiting
        //First, visit node's children
        for ( int & v : adj[u] ) {
            if ( visited[v] == 0 ) {
                dfs(v, visited, adj, st, cycle);
            } else if ( visited[v] == 1 ) {
                cycle = true;
                return;
            }
        }

        visited[u] = 2; // visited
        st.push(u); //Now node can be added
    }

    vector<int> topologicalSort( vector<vector<int>> & edges, int & n ) {
        // make adjacency list (graph)
        unordered_map<int, vector<int>> adj;

        for ( vector<int> & edge: edges ) {
            int u = edge[0];
            int v = edge[1];
            // u ----> v
            adj[u].push_back(v);
        }

        // visited[i] = 0 : not visited;
        // visited[i] = 1 : DFS is on going from this node OR visiting (currently in stack via some other DFS)
        // visited[i] = 2 : visited
        vector<int> visited(n + 1, 0); // nodes k values = 1, 2, ........, n
        stack<int> st; // u ----> v
        // {u, v2, v1, v}
        vector<int> order;
        bool cycle = false;
        for ( int  i = 0; i <= n; i++ ) {
            if ( visited[i] == 0 ) {
                dfs(i, visited, adj, st, cycle);
                if ( cycle == true ) {
                    return {};
                }
            }
        }

        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> topoRows = topologicalSort(rowConditions, k); //k == number of nodes
        vector<int> topoColumns = topologicalSort(colConditions, k); //k == number of nodes
        
        // We might have found cycle. That's why topo order is empty
        if ( topoRows.empty() || topoColumns.empty() ) {
            return {};
        }

        // if not found cycle, so we can find matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for ( int  i = 0; i < k; i++ ) {
            for ( int j = 0; j < k; j++ ) {
                if ( topoRows[i] == topoColumns[j] ) {
                    // [i][j]
                    matrix[i][j] = topoRows[i]; // topoColumns[j];
                }
            }
        } 

        return matrix;
    }
};


// another way
class Solution {
public:

    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        vector<int> order;
        //0 : not visited;
        //1 : visiting (currently in stack via some other DFS)
        //2 : visited
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, st, hasCycle);
                if (hasCycle) 
                    return {}; //no ordering possible
            }
        }
        
        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited,
            stack<int>& st, bool& hasCycle) {
        
        visited[node] = 1;  // Mark node as visiting
        //First, visit node's children
        for (int& nbr : adj[node]) {
            if (visited[nbr] == 0) {
                dfs(nbr, adj, visited, st, hasCycle);
            } else if (visited[nbr] == 1) {
                // Cycle detected
                hasCycle = true;
                return;
            }
        }

        visited[node] = 2; //visited
        st.push(node); //Now node can be added
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {        
        vector<int> orderRows    = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // We might have found cycle. That's why topo order is empty
        if (orderRows.empty() or orderColumns.empty())
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }
};













//Approach-2 (Topological Sorting using BFS)
//T.C : O(k*^2 + n)
//S.C : O(k*^2 + n)


/*
    Summary :

        Approach 2: Topological Sorting using BFS

        Time Complexity (T.C.): O(k2+n)
        Space Complexity (S.C.): O(k2+n)

        This approach uses Breadth-First Search (BFS) and Kahn's algorithm to 
        perform topological sorting. Here’s a breakdown:

        Graph Representation: 
            The graph is represented using an adjacency list stored in a vector of 
            vectors. An in-degree vector is also maintained.

        Queue for BFS:
            Nodes with an in-degree of zero are added to a queue.
            
            Nodes are processed from the queue, and their neighbors’ in-degrees are 
            decremented. If a neighbor’s in-degree becomes zero, it is added to the 
            queue.

        Cycle Detection: 
            If the total number of nodes processed does not match the number of 
            nodes in the graph, a cycle is detected.

        Order Construction: 
            Nodes are added to the order list in the sequence they are processed 
            from the queue.

        Building the Matrix:

            Row and Column Orders: 
                Both approaches first compute topological orders for row and column 
                conditions.

            Matrix Construction: 
                If either topological order is empty (indicating a cycle), an empty 
                matrix is returned. Otherwise, a matrix is constructed where 
                elements are placed according to the computed row and column orders.
*/



class Solution {
public:

    vector<int> topologicalSort( vector<vector<int>> & edges, int & n ) {
        // make adjacency list (graph)
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);

        for ( vector <int> & edge : edges ) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        int count  = 0;
        // Push all integers with in-degree 0 in the queue.
        for ( int i = 1; i <= n; i++ ) {
            if ( indegree[i] == 0 ) {
                que.push(i);
                count++;
            }
        }

        vector<int> topoOrder;
        while ( !que.empty() ) {
            int u = que.front();
            que.pop();
            topoOrder.push_back(u);

            for ( int & v : adj[u] ) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        if (count != n) 
            return {}; //cycle

        return topoOrder;

    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> topoRows = topologicalSort(rowConditions, k); //k == number of nodes
        vector<int> topoColumns = topologicalSort(colConditions, k); //k == number of nodes
        
        // We might have found cycle. That's why topo order is empty
        if ( topoRows.empty() || topoColumns.empty() ) {
            return {};
        }

        // if not found cycle, so we can find matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for ( int  i = 0; i < k; i++ ) {
            for ( int j = 0; j < k; j++ ) {
                if ( topoRows[i] == topoColumns[j] ) {
                    // [i][j]
                    matrix[i][j] = topoRows[i]; // topoColumns[j];
                }
            }
        } 

        return matrix;
    }
};

// another way
class Solution {
public:
    
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        vector<int> order;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        int count = 0;
        // Push all integers with in-degree 0 in the queue.
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }

        while(!que.empty()) {
            int u = que.front();
            order.push_back(u);
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }

            }
        }

        if (count != n) 
            return {}; //cycle

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows    = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // We might have found cycle. That's why topo order is empty
        if (orderRows.empty() or orderColumns.empty())
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }
};































/************************************************************ JAVA ************************************************************/
//Approach-1 (Topological Sorting using DFS)
//T.C : O(k*^2 + n)
//S.C : O(k*^2 + n)
class Solution {

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> orderRows = topoSort(rowConditions, k);
        List<Integer> orderColumns = topoSort(colConditions, k);

        // We might have found cycle. That's why topo order is empty
        if (orderRows.isEmpty() || orderColumns.isEmpty())
            return new int[][]{};

        int[][] matrix = new int[k][k];
        Map<Integer, Integer> positionMap = new HashMap<>();
        for (int i = 0; i < k; i++) {
            positionMap.put(orderColumns.get(i), i);
        }

        for (int i = 0; i < k; i++) {
            int element = orderRows.get(i);
            if (positionMap.containsKey(element)) {
                matrix[i][positionMap.get(element)] = element;
            }
        }
        return matrix;
    }

    private List<Integer> topoSort(int[][] edges, int n) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        List<Integer> order = new ArrayList<>();
        int[] visited = new int[n + 1]; // 0: not visited, 1: visiting, 2: visited
        boolean[] hasCycle = {false};

        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, stack, hasCycle);
                if (hasCycle[0])
                    return new ArrayList<>(); // no ordering possible
            }
        }

        while (!stack.isEmpty()) {
            order.add(stack.pop());
        }
        return order;
    }

    private void dfs(int node, Map<Integer, List<Integer>> adj, int[] visited,
                    Stack<Integer> stack, boolean[] hasCycle) {
        visited[node] = 1; // Mark node as visiting

        for (int neighbor : adj.getOrDefault(node, new ArrayList<>())) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, stack, hasCycle);
            } else if (visited[neighbor] == 1) {
                hasCycle[0] = true; // Cycle detected
                return;
            }
        }

        visited[node] = 2; // Mark node as visited
        stack.push(node); // Add node to the stack
    }
}


//Approach-2 (Topological Sorting using BFS)
//T.C : O(k*^2 + n)
//S.C : O(k*^2 + n)
class Solution {

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> orderRows = topoSort(rowConditions, k);
        List<Integer> orderColumns = topoSort(colConditions, k);

        // We might have found cycle. That's why topo order is empty
        if (orderRows.isEmpty() || orderColumns.isEmpty())
            return new int[][]{};

        int[][] matrix = new int[k][k];
        Map<Integer, Integer> positionMap = new HashMap<>();
        for (int i = 0; i < k; i++) {
            positionMap.put(orderColumns.get(i), i);
        }

        for (int i = 0; i < k; i++) {
            int element = orderRows.get(i);
            if (positionMap.containsKey(element)) {
                matrix[i][positionMap.get(element)] = element;
            }
        }
        return matrix;
    }

    private List<Integer> topoSort(int[][] edges, int n) {
        List<List<Integer>> adj = new ArrayList<>();
        int[] indegree = new int[n + 1];
        List<Integer> order = new ArrayList<>();
        
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            indegree[v]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        int count = 0;
        // Push all integers with in-degree 0 in the queue.
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
                count++;
            }
        }

        while (!queue.isEmpty()) {
            int u = queue.poll();
            order.add(u);
            
            for (int v : adj.get(u)) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue.add(v);
                    count++;
                }
            }
        }

        if (count != n) 
            return new ArrayList<>(); // Cycle detected

        return order;
    }
}

















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QyrmIu4Vo8A
*/