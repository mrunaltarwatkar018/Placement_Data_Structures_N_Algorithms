/* GFG Problem No.: Floyd Warshall  */

/*
    Company Tags                : Samsung
    GFG Link                    : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
*/



//Time Complexity - O(n^3)
class Solution {
    public:
	void shortest_distance(vector<vector<int>>& grid){
        int n = grid.size();
        

        // converting -1 to 100000
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == -1)
                    grid[i][j] = 100000;
                
            }
        }
        
        for(int via = 0; via < n; via++) {
            
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    
                }
            }
        }
        
        // now again converting 100000 to -1
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 100000)
                    grid[i][j] = -1;
                
            }
        }
	}
};