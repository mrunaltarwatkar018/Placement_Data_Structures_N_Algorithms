/* GFG Problem: Product array puzzle */

/*
    Company Tags                : Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, D-E-Shaw, Intuit, Opera 
    GFG Link                    : https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
*/


class Solution {
    public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // Code here
        
        int n=nums.size();
        
        vector<long long int> ans(n,1);
        
        // left product
        long long int left=1;
        
        for(int i=0;i<n;i++){
            ans[i]=left;
            left=left*nums[i];
        }
        
        // right product
        long long int right=1;
        
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right=right*nums[i];
        }
        
        return ans;
    }
};