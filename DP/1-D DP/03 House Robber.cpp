/* Leetcode Problem No.: 198. House Robber  */

/*
    Company Tags                :   Amazon, OYO Rooms, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb
    Leetcode Link               :   https://leetcode.com/problems/house-robber/
    GfG Link                    :   https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
    Also Famouse as             :   Stickler Thief
*/

//Approach-1 (Recur) : Brute force - TLE

class Solution {
public:

    int solve(vector<int> & nums, int i, int n) {
        if ( i >= n) {
            return 0;  // we have exhausted all the houses
        }

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i+1, n);

        return max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};


//Approach-2 (Recur + Memo)
class Solution {
public:
    int t[101];
    int solve(vector<int> & nums, int i, int n) {
        if ( i >= n) {
            return 0;  // we have exhausted all the houses
        }

        if (t[i] != -1 ) {
            return t[i];
        }

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

// or
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};


//Approach-3 (Bottom up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
        //t[i] = max stolen money till i house 
        
        t[0] = 0; // no house : i = 0
        t[1] = nums[0]; // 1 house : i = 1

        for ( int i = 2; i <= n; i++ ) {
            /*
                SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
                STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
            */
            int steal = nums[i - 1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(skip, steal); //max(skip, steal)
        }
        return t[n];
    }
};

// or
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
        //t[i] = max profit till house i
        
        t[0] = 0;
        t[1] = nums[0];
        
        for(int i = 2; i<=n; i++) {
            
            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];

            t[i] = max(skip, steal); //max(skip, steal)
            /*
                SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
                STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
            */
        }
        
        return t[n];
        
    }
};


//Approach-4 (Space Optimized Bottom Up - Converting Approach-3)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevPrev = 0;
        int prev     = nums[0];
        
        for(int i = 2; i<=n; i++) {
            int skip = prev;
            
            int take = nums[i-1] + prevPrev;
                
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
};