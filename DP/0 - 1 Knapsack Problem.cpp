/* GFG Problem: 0 - 1 Knapsack Problem */

/*
    Company Tags                : Flipkart, Morgan Stanley, Amazon, Microsoft, Snapdeal, Oracle, Payu, Visa, Directi, GreyOrange, Mobicip
    GFG Link                    : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

class Solution {

    private:
    int rec(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& mem) {
        if(i>=val.size()) return 0;
        if(mem[i][W]!=-1) return mem[i][W];
        int take=0;
        if(W>=wt[i])
            take=val[i]+rec(i+1,W-wt[i],wt,val,mem);
        int not_take=rec(i+1,W,wt,val,mem);
        return mem[i][W]=max(take,not_take);
    }
    public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>> mem(val.size()+1, vector<int>(W+1,-1));
        return rec(0,W,wt,val,mem);
    }

};


// Java 
class Solution {
    // Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[]) {
        int n = val.length;
        
        // Create a 2D DP array
        int[][] dp = new int[n + 1][W + 1];

        // Iterate over all items
        for (int i = 0; i <= n; i++) {
            // Iterate over all possible capacities
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    // Base case: If no items or no capacity, the value is 0
                    dp[i][w] = 0;
                } else if (wt[i - 1] <= w) {
                    // If the weight of the current item is less than or equal to the current capacity
                    dp[i][w] = Math.max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                } else {
                    // If the weight of the current item is more than the current capacity, skip it
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        // Return the maximum value that can be obtained
        return dp[n][W];
    }
}






// Java Script Solution
class Solution {
    // Function to return max value that can be put in knapsack of capacity W.
    knapSack(W, wt, val) {
        // code here
        const arr = []
        for(let i = 0; i < wt.length; i++){
            arr.push([wt[i], val[i]])
        }
        
        arr.sort((a,b)=>{
            if(a[0] == b[0]){
                return b[1] - a[1]
            }
            return a[0]-b[0]
        })
        
        let max = 0
        const len = arr.length
        const helper = (weight, sum, idx)=>{
            max = Math.max(sum, max)
            if(weight < 0 || idx >= len) return
            
            for(let i = idx; i < len; i++){
                if(weight - arr[i][0] >= 0){
                    helper(weight - arr[i][0], sum + arr[i][1], i + 1)
                }
            }
        }
        
        helper(W, 0, 0)
        return max
    }
}