/*    Leetcode Problem No.: 1791. Find Center of Star Graph   */

/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=Sp9kcIX0Ep0
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/find-center-of-star-graph
*/


/************************************************************************ C++ ********************************************************/


/*
    Approach 1: Using a Map

    Time Complexity (T.C): O(n)
    Space Complexity (S.C): O(n)

    This approach uses a hashmap to keep track of the degree of each node in the 
    graph. The steps are as follows:

    Initialize Map: Create a hashmap to store the degree of each node.
    Count Degrees: Iterate through the list of edges, incrementing the degree of 
    each node involved in an edge.
    Find Center: Iterate through the entries in the hashmap to find the node whose 
    degree is equal to the number of edges. This node is the center of the star 
    graph.
    This approach has a linear time complexity because it processes each edge once 
    and a linear space complexity because it stores the degree of each node.

*/

//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> degree;

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        for(auto &it : degree) {
            int node = it.first;
            int deg  = it.second;

            if(deg == n)
                return node;
        }

        return -1;
    }
};


/*
    Approach 2: Constant Time

    Time Complexity (T.C): O(1)
    Space Complexity (S.C): O(1)

    This approach leverages the property of a star graph where the center node will 
    appear in the first two edges. The steps are as follows:

    Extract First Two Edges: Retrieve the first two edges from the list.
    Compare Nodes: Compare the nodes in the first and second edges to identify the 
    common node. This common node is the center of the star graph.
    This approach has a constant time complexity and constant space complexity 
    since it only involves checking two edges and does not require any additional 
    data structures.

*/


//Approach-2 (Constant time)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first  = edges[0]; //{a, b}
        vector<int> second = edges[1]; //{c, a}

        if(first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }

        return first[1];

    }
};

/************************************************************************ JAVA ********************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int findCenter(int[][] edges) {
        Map<Integer, Integer> degree = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            degree.put(u, degree.getOrDefault(u, 0) + 1);
            degree.put(v, degree.getOrDefault(v, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : degree.entrySet()) {
            if (entry.getValue() == edges.length) {
                return entry.getKey(); // star graph center node
            }
        }

        return -1;
    }
}



//Approach-2 (Constant time)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int findCenter(int[][] edges) {
        int[] first = edges[0]; // {a, b}
        int[] second = edges[1]; // {c, a}

        if (first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }

        return first[1];
    }
}