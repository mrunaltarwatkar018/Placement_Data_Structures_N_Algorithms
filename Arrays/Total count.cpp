/* GFG Problem: Total count */

/*
    Company Tags                : Zoho
    GFG Link                    : https://www.geeksforgeeks.org/problems/total-count2415/1
*/





class Solution {
    public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int count=0;
        for(int i=0;i<arr.size();i++){
            count+=arr[i]/k;
            if(arr[i]%k!=0) count++;
        }
        return count;

    }
};