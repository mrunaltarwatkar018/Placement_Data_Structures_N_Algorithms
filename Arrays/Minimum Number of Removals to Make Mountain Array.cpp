/* Leetcode Problem No.: 1671. Minimum Number of Removals to Make Mountain Array */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
*/



class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // calculate LIS
        for ( int i = 0; i < n; i++ ) {
            for ( int j = i - 1; j >= 0; j-- ) {
                if ( nums[i] > nums[j] ) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // calculate LDS
        for ( int i = n - 1; i >= 0; i-- ) {
            for ( int j = i + 1; j < n; j++ ) {
                if ( nums[i] > nums[j] ) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }


        int minRemovals = n;
        for ( int i = 0; i < n; i++ ) { // treat each element as PEAK and find removal
            if ( LIS[i] > 1 && LDS[i] > 1 ) // mountain array minimum length tabhi >= 3 aa payega
                minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);
        }
        

        return minRemovals;
    }
};






// other NlogN aaproach

class Solution {
public:
    void f(vector<int>& nums,vector<int>& dp)
    {
        vector<int>temp;
        for(int i =0 ;i < nums.size(); i++){
            if(temp.size() == 0 || temp.back() < nums[i]){
                temp.push_back(nums[i]);
                dp.push_back(temp.size());
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
                dp.push_back(ind+1);
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>dp1;
        vector<int>dp2;
        f(nums,dp1);
        reverse(nums.begin(),nums.end());
        f(nums,dp2);
        reverse(dp2.begin(),dp2.end());
        int ans = 0;
        for(int i =0 ;i < dp1.size(); i++){
            if(dp1[i] > 1 && dp2[i] > 1 ){
                int r = dp1[i] + dp2[i]-1;
                ans = max(ans,r);
            }
        }
        return nums.size() - ans;
    }
};


