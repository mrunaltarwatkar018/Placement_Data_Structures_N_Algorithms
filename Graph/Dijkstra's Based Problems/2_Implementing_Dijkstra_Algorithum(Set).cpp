/* GFG Problem No.: Implementing Dijkstra Algorithm With Set  */

/*
    Company Tags                : Flipkart, Microsoft,
    GFG Link                    : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/


// Implementing Dijkstra Algorithm With Set

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        // Code here
        set<pair<int, int>> st;
        
        vector<int> result(V, INT_MAX);
        
        result[source] = 0;
        
        st.insert({0, source});
        
        while(!st.empty()) {
            
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for ( auto & vec : adj[node] ) {
                int adjNode = vec[0];
                int dist = vec[1];
                
                if ( d + dist < result[adjNode] ) {
                    
                    if (result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});  // direct wy to erase
                        /*
                            // another way to erase it 
                            auto iter = st.find({result[adjNode], adjNode});
                            st.erase(iter);
                        */
                    }
                    
                    result[adjNode] = d + dist;
                    st.insert({d + dist, adjNode});
                }
            }
        }
        return result;
    }
};





































/*
    YOUTUBE VIDEO ON THIS Qn :   https://www.youtube.com/watch?v=3qIoYIMidpc&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=27
*/
