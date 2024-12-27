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

//Approach-3 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        // t[i] = LIS ending at ith index
        int maxLIS = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;
    }
};

// or
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};

// Approacj-4 (Using concept of Patience Sorting (O(nlogn))
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted; // empty in the beginning

        for (int i = 0; i < n; i++ ) {
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]); // just greater that or equal the nums[i]
            // and if do *it we get element
            if (it == end(sorted)) {
                sorted.push_back(nums[i]); // greatest : so insert it
            } else {
                *it = nums[i]; // replace with nums[i]
            }
        }
        return sorted.size(); // LIS
    }
};

// or
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        
        for(int i = 0; i<n; i++) {
            /*
                    Why lower bound ?
                    We want increasing subsequence and  hence 
                    we want to eliminate the duplicates as well.
                    lower_bound returns iterator to "next greater or equal to"
			*/
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]);
            
            if(it == end(sorted))
                sorted.push_back(nums[i]); //greatest : so insert it
            else
                *it = nums[i]; //replace
        }
        
        return (int)sorted.size();
    }
};

