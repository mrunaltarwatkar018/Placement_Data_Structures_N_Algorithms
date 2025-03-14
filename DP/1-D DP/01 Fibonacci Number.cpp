/* Leetcode Problem No.: 509. Fibonacci Number  */

/*
    Company Tags                : Amazon, Microsoft, OYO Rooms, Snapdeal, MakeMyTrip, Goldman Sachs, MAQ Software, Adobe
    Leetcode Link               : https://leetcode.com/problems/fibonacci-number/
*/

//Approach-1 (Using Recursion)

class Solution {
public:
    int fib(int n) {
        // base case: it is always lowest possible valid value of the param
        if (n <= 1) {
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};


//Approach-2 (Using Recursion + Memorization)
class Solution {
public:
    int solve(int n, vector<int> & dp) {
        if (n <= 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = solve(n-1, dp) + solve(n-2, dp); 
    }

    int fib(int n) {
        // base case: it is always lowest possible valid value of the param
        if (n <= 1) {
            return n;
        }

        vector<int> dp(n+1, -1);  // n+1 becasuse we have access dp[n] value
        
        return solve(n, dp);
    }
};  

// or
class Solution {
public:
    int t[31];
    int solve(int n) {
        if(n <= 1)
            return n;
        
        if(t[n] != -1)
            return t[n];
        
        return t[n] = fib(n-1) + fib(n-2);
    }
    
    int fib(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};


//Approach-3 (Using Bottom Up DP)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n+1, -1);

        //State definition
        //dp[i] = ith Fibonacci Number
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// or
class Solution {
public:
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        int t[n+1];
        //State definition
        //t[i] = ith Fibonacci Number
        
        t[0] = 0;
        t[1] = 1;
        
        for(int i = 2; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
        
    }
};


//Approach-4 (Constant Space Complexity)
class Solution {
public:
    int fib(int n) {
        if( n<=1)
            return n;
        
        int c;
        int a = 0, b = 1;
        
        for(int i = 1; i<n; i++) {
            
            c = a+b;
            
            a = b;
            b = c;
        }
        return c;
    }
    
};