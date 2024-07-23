/* Leetcode Problem No.: 918. Maximum Sum Circular Subarray  */


/*
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-sum-circular-subarray/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
*/


//Approach-1 (Using Kadane's Algo) Brute Force O(n^2) - Time Limit Exceed


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;

        for (int i = 0; i < n; i++) {
            vector<int> rotated_nums = rotateArray(nums, i);
            int sum = kadanesMax(rotated_nums, n);
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }

    vector<int> rotateArray(vector<int>& nums, int k) {
        vector<int> rotated_nums = nums;
        rotate(rotated_nums.begin(), rotated_nums.begin() + k, rotated_nums.end());
        return rotated_nums;
    }

    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};



















//Approach-1 (Using Kadane's Algo) - O(N)
class Solution {
public:

    int kadanesMax(vector<int> & nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];

        for ( int  i = 1; i < n; i++ ) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int> & nums, int n) {
        int sum = nums[0];
        int minSum = nums[0];

        for ( int  i = 1; i < n; i++ ) {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // step 1: Calculate Total Sum
        int SUM = accumulate(begin(nums), end(nums), 0);

        // step 2: Calculate min Sum
        int minSum = kadanesMin(nums, n);

        // step 3: Calculate max Sum
        int maxSum = kadanesMax(nums, n);  // case - 1

        // step 4: Calculate circular Sum
        int circular_sum = SUM - minSum;  // case - 2

        if ( maxSum > 0 ) {
            return max(maxSum, circular_sum);
        }

        return maxSum;

    }
};


// leetcode

//Approach-2 (Writing everything in one loop) - O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n   = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        
        int k_sum_min = nums[0];
        int min_sum   = nums[0];
        
        int k_sum_max = nums[0];
        int max_sum   = nums[0];
        
        for(int i = 1; i<nums.size(); i++) {
            
            min_sum   = min(nums[i]+min_sum, nums[i]);
            k_sum_min = min(k_sum_min, min_sum);
            
            max_sum = max(nums[i]+max_sum, nums[i]);
            k_sum_max = max(k_sum_max, max_sum);
            
        }
        
        int circular_sum = SUM - k_sum_min;
        
        if(k_sum_max > 0) {
            return max(k_sum_max, circular_sum);
        }
        
        return k_sum_max;
        
    }
};








class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
	
        int n=nums.size();
		//First we would apply the kadanes algo in the normal array
		//for that we will have a keep count of continuous sum in the sum 
		//variable and if the cumulative sum gets less than zero we will assign sum to value zero and 
		//continue our iteration
        int sum=0,ans=-1e9;

        
        for(int i=0;i<n;i++){
            sum+=nums[i];
			//on every point after adding an element we are storing the maximum of ans and sum in the ans
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }

        sum=0;
		// we will have to find the sum that could be in case 2 so for that we 
		//will make an vector which will store the max value till the index
        vector<int>maxTill(n);
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxTill[i]=max(i>0?maxTill[i-1]:nums[i],sum);
        }
        // now we will start traversing from the last and add value to the cur variable and 
		//check if maxTill[i-1]+cur is greater than ans or not
        int cur=0;
        for(int i=n-1;i>=1;i--){
            cur+=nums[i];
            ans=max(ans,maxTill[i-1]+cur);
        }
        //returning the ans
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)



















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Za8V4wkZKkM
*/