/* GFG Problem: Not a subset sum */

/*
    Company Tags                : Salesforce
    GFG Link                    : https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1
*/


class Solution {
    public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long ans=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>ans) return ans;
            ans+=arr[i];
        }
        return ans;
    }
};