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



// another way
class Solution {
    public:
    bool canSplit(vector<int>& arr) {
        int leftSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            leftSum += arr[i];

        int rightSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            rightSum += arr[i];
            leftSum -= arr[i];
            if (rightSum == leftSum)
                return true;
        }
        return false;
    }
};







// Java Code

class Solution {
    public boolean canSplit(int arr[]) {
        int leftSum = 0;
        int n = arr.length;
        for (int i = 0; i < n; i++) leftSum += arr[i];

        // again traverse array and compute right
        // sum and also check left_sum equal to
        // right sum or not
        int rightSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            // add current element to right_sum
            rightSum += arr[i];

            // exclude current element to the left_sum
            leftSum -= arr[i];

            if (rightSum == leftSum) return true;
        }
        return false;
    }
}
