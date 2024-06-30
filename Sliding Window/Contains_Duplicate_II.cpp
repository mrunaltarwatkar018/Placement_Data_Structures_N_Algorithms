/* Leetcode Problem No.: 219. Contains Duplicate II  */


/*
    Company Tags                : Airbnb, Palantir Technologies
    Leetcode Link               : https://leetcode.com/problems/contains-duplicate-ii/
    Using sliding window        : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Contains%20Duplicate%20II.cpp
*/

// Approach 2: Using Sliding Window Technique
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        int i = 0, j = 0;

        while ( j < n) {
            // step 1
            if (abs(i-j) > k) { //abs(i-j) <= k
                st.erase(nums[i]);
                i++; // shrink
            }

            // step 2: past me dekha hai nums[j] ?
            if ( st.find(nums[j]) != st.end()) {
                return true;
            }

            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};


/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=B5v3KZpRreQ
*/