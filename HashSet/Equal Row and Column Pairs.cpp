/* Leetcode Problem No.: 2352. Equal Row and Column Pairs */

/*
    Company Tags                : Google, Microsoft
    Leetcode Link               : https://leetcode.com/problems/equal-row-and-column-pairs/
*/

//Approach-1 (Brute Force)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int r = 0; r<n; r++) {
            for(int c = 0; c < n; c++) {
                int is_equal = true;
                for(int i = 0; i < n; i++) {
                    if(grid[r][i] != grid[i][c]) {
                        is_equal = false;
                        break;
                    }
                }
                count += is_equal;
            }
        }
        return count;
        
    }
};

//Approach-2 (Using map) - O(n^2 * log(n))
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;

        map<vector<int>, int> mp;

        // step: frequency count
        for (int row = 0; row < n; row++ ) {
            mp[grid[row]]++;
        }
        // step 2: compare with row with column elements and updating count
        for (int col = 0; col < n; col++ ) {
            vector<int> temp;
            for (int row = 0; row < n; row++ ) {
                temp.push_back(grid[row][col]);
            }
            count += mp[temp];
        }
        return count;
    }
};

// OR
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> mp;
        //1 
        for(int row = 0; row < n; row++) {
            
            mp[grid[row]]++;
            
        }
        
        //2
        for(int c = 0; c < n; c++) {
            
            vector<int> temp;
            
            for(int r = 0; r<n; r++) {
                
                temp.push_back(grid[r][c]);
                
            }
            
            count += mp[temp];
            
        }
        
        
        return count;
    }
};