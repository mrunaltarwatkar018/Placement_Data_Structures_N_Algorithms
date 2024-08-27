/* GFG Problem No.: Implementing Dijkstra Algorithm With Priority Queue  */

/*
    Company Tags                : Flipkart, Microsoft,
    GFG Link                    : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/




// Implementing Dijkstra Algorithm With Priority Queue
//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {

        // Create a priority queue to store vertices that are being preprocessed.
        // This is weird syntax when we want to create a min heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> result(V, INT_MAX);
        
        // Insert source itself in priority queue and initialize its distance as 0.
        result[source] = 0;
        
        pq.push({0, source});
        
        while(!pq.empty()) {
            
            // Extract first vertex from priority queue (with minimum distance).
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // 'i' is used to get all adjacent vertices of a vertex
            for ( auto & vec : adj[node] ) {
                int adjNode = vec[0];
                int wt = vec[1];
                
                // If there is shorted path to adjNode through wt.
                if ( d + wt < result[adjNode] ) {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        return result;
    }
};





// another way

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a priority queue to store vertices that are being preprocessed.
        // This is weird syntax when we want to create a min heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        // Insert source itself in priority queue and initialize its distance as 0.
        pq.push({0, S});
        dist[S] = 0;

        while (!pq.empty())
        {
            // Extract first vertex from priority queue (with minimum distance).
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a vertex
            for (auto &vec : adj[u])
            {
                int v = vec[0];
                int weight = vec[1];

                // If there is shorted path to v through u.
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};







/*
    YOUTUBE VIDEO ON THIS Qn :   https://www.youtube.com/watch?v=xQ3vjWwFRuI&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=30
*/