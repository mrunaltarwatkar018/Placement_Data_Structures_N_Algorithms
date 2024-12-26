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

