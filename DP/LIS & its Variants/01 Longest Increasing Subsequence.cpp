/* Leetcode Problem No.: 300. Longest Increasing Subsequence  */

/*
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/longest-increasing-subsequence/
*/


// ************************************************************ C++ ************************************************************
// Approach-1 (Recursion without memorization)  - TLE  
// TC: O(2^n)
class Solution {
public:
    int n;

    int solve(vector<int>& nums, int idx, int prev) {
        if (idx >= n) 
            return 0;

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx + 1, idx);
        }
        int skip = solve(nums, idx + 1, prev);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        return solve(nums, 0, -1);
    }
};



// Approach-2 (TopDown: Recur+Memo) 
// T.C : O(n*n)
class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums, int idx, int prev) {
        if (idx >= n) 
            return 0;

        if ( prev != -1 && dp[idx][prev] != -1 ) {
            return dp[idx][prev];
        }

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx + 1, idx);
        }
        int skip = solve(nums, idx + 1, prev);

        if (prev != -1) {
            dp[idx][prev] = max(take, skip);
        }
        
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};


// or
class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {
        if(curr_idx == n)
            return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};

