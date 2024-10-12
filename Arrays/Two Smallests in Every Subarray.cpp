/* GFG Problem: Two Smallests in Every Subarray */

/*
    Company Tags                : 
    GFG Link                    : https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1
*/


class Solution {
    public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int maxi=-1;
        for(int i=1;i<arr.size();i++){
            maxi=max(maxi,arr[i]+arr[i-1]);
        }
        return maxi;
    }
};