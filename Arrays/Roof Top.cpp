/* GFG Problem: Roof Top */

/*
    Company Tags                : 
    GFG Link                    : https://www.geeksforgeeks.org/problems/roof-top-1587115621/1
*/


class Solution {
    public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int consecutive_steps=0,maxi=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                consecutive_steps++;
                maxi=max(maxi,consecutive_steps);
            }
            else{
                consecutive_steps=0;
            }
        }
        return maxi;
    }
};