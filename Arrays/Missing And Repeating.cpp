/* GFG Problem: Missing And Repeating */

/*
    Company Tags                : Amazon, Samsung, D-E-Shaw, Goldman Sachs, MAQ Software
    GFG Link                    : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/


class Solution {
    public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long S=((long long)n*(n+1))/2;
        long long Sq=(((long long)n*(n+1)*(2*n+1)))/6;
        long Si=0,Sqi=0;
        for(int i=0;i<n;i++){
            Si+=arr[i];
            Sqi+=((long long)arr[i]*arr[i]);
        }
        long long X_minus_Y=S-Si;
        long long X_plus_Y=(Sq-Sqi)/X_minus_Y;
        long long miss=(X_minus_Y+X_plus_Y)/2;
        long long rep=X_plus_Y-miss;
        return {rep,miss};
    }
};