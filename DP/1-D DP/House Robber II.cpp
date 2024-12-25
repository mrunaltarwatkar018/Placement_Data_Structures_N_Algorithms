/* Leetcode Problem No.: 213. House Robber II  */

/*
    Company Tags                : Airbnb, Microsoft
    Leetcode Link               : https://leetcode.com/problems/house-robber-ii/
*/

//Approach-1 (Recur + Memo)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if(i > n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int steal = nums[i] + solve(nums, i+2, n); 
        int skip = solve(nums, i+1, n); 
        
        return t[i]=max(steal, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        memset(t, -1, sizeof(t));
        
        // case 1 : Take first house i.e 0th index house
        int take_0th_index_house = solve(nums, 0, n-2);
        
        memset(t, -1, sizeof(t));
        
        // case 2 : Take 2nd house i.e 1st index house
        int take_1st_index_house = solve(nums, 1, n-1);
        
        
        return max(take_0th_index_house, take_1st_index_house);
    }
};

//  or
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if(i > n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        memset(t, -1, sizeof(t));
        
        //case-1 - Take first house 0th index wala house
        
        int take_0th_index_house = solve(nums, 0, n-2);
        
        memset(t, -1, sizeof(t));
        
        //case-2  - Take second house 1st index wala house
        int take_1st_index_house = solve(nums, 1, n-1);
        
        
        return max(take_0th_index_house, take_1st_index_house);
        
        
    }
};



