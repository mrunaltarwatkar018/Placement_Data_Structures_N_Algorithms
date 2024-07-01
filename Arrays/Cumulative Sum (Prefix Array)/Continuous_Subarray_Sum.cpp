/* Leetcode Problem No.: 523. Continuous Subarray Sum  */

/*
    Company Tags                : Amazon, Facebook, Paytm
    Leetcode Link               : https://leetcode.com/problems/continuous-subarray-sum/
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        int sum  = 0;
        mp[0] = -1;

        for ( int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;

            // check if it's present in map (past mai kahi dekha hai ?)

            if ( mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2)
                    return true;
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};






















































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wmn3c1mP0pY&t=152s
*/