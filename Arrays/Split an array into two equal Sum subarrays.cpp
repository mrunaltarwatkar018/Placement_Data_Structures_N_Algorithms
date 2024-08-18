/* GFG Problem: Split an array into two equal Sum subarrays */

/*
    Company Tags                : Facebook 
    GFG Link                    : https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1
*/

class Solution {
    public:
    bool canSplit(vector<int>& arr) {
        
        int arrSum=0,subArrSum=0,n=arr.size();
        //poore array ka sum
        for(int i=0;i<n;i++){
            arrSum+=arr[i];
        }
        //sub array ka sum *2== arrSum 
        for(int i=0;i<n;i++){
            subArrSum+=arr[i];
            if(subArrSum*2==arrSum) return true;
        }
        return false;
    }
};