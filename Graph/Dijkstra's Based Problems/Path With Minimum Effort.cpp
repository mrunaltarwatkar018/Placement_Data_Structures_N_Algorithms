/* Leetcode Problem No.: 1631. Path With Minimum Effort  */

/*
    Company Tags                : Google, Uber
    Leetcode Link               : https://leetcode.com/problems/path-with-minimum-effort/
*/


//Approach-1 : Using Dijkstra's Algo

class Solution {
public:

    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        result[0][0] = 0;
        pq.push({0, {0, 0}});


        while(!pq.empty()) {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();

            int x = cord.first;
            int y = cord.second;

            if (x == m - 1 && y == n - 1) {
                return diff;
            }


            for (auto &dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if (result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};





//  OR
class Solution {
public:

    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        result[0][0] = 0;
        pq.push({0, {0, 0}});


        while(!pq.empty()) {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();

            int x = cord.first;
            int y = cord.second;

            for (auto &dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if (result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};













// OR



class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };


   // Interesting right :-) 
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()) {
            int diff  = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;
            
            //Why returning now ?
            //Because there is no way that the rest of elements can update the weight of destination cell even smaller due to the min heap.
            if(x == m-1 && y == n-1)
                return diff;
            
            for(auto dir:directions) {
                int x_   = x + dir[0];
                int y_   = y + dir[1];

                if(isSafe(x_, y_)) {

                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if(result[x_][y_] > newDiff) {
                        result[x_][y_] = newDiff;
                        pq.push({result[x_][y_], {x_, y_}});
                    }
                }
            }
        }

        return result[m-1][n-1];

    }
};


//Approach-2 (Binary Search + DFS)
//Will update, soon