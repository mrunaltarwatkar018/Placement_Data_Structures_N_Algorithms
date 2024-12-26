/* Leetcode Problem No.: 1911. Maximum Alternating Subsequence Sum  */

/*
    Company Tags                : META, GOOGLE, AMAZON
    Leetcode Link               : https://leetcode.com/problems/maximum-alternating-subsequence-sum/
*/

// approach 1 : Recursion - Brute force - TLE
class Solution {
public:
    int n;
    int solve(int idx, vector<int> &nums, int flag) {
        if (idx >= n)
            return 0;

        int skip = solve(idx+1, nums, flag);
        int val = nums[idx];
        if (flag == false) val = -val;
        int take = solve(idx+1, nums, !flag) + val;
        return max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        return solve(0, nums, true); // index = 0 which es a even index;    true : + 
    } 
};

// in problem, value is very very long, so replace long long in place of int data type, so that we can handle the big values as well
class Solution {
public:
    typedef long long ll;
    int n;
    ll solve(int idx, vector<int> &nums, int flag) {
        if (idx >= n)
            return 0;

        ll skip = solve(idx+1, nums, flag);
        ll val = nums[idx];
        if (flag == false) val = -val;
        ll take = solve(idx+1, nums, !flag) + val;
        return max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        return solve(0, nums, true); // index = 0 which es a even index;    true : + 
    } 
};



//Approach-2 (Recursion + Memo) (Time Complexity - n*2 : We visit all states of t once)
class Solution {
public:
    typedef long long ll;
    int n;
    long long t[1000001][2];
    ll solve(int idx, vector<int> &nums, int flag) {
        if (idx >= n) return 0;

        if (t[idx][flag] != -1) return t[idx][flag];

        ll skip = solve(idx+1, nums, flag);
        ll val = nums[idx];
        if (flag == false) val = -val;
        ll take = solve(idx+1, nums, !flag) + val;
        return t[idx][flag] = max(skip, take);
    } 

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true); // index = 0 which es a even index;    true : + 
    } 
};

// or
class Solution {
public:
    int n;
    long long t[1000001][2];
    long long solve(int idx, vector<int>& nums, bool iseven) {
        
        if(idx >= n) {
            return 0;
        }
        if(t[idx][iseven] != -1)
            return t[idx][iseven];
        
        long long skip = solve(idx+1, nums, iseven);
        
        long long val = nums[idx];
        if(iseven == false) {
            val = -val;
        }
        
        long long take = solve(idx+1, nums, !iseven) + val;
        
        return t[idx][iseven] = max(skip, take);
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};

