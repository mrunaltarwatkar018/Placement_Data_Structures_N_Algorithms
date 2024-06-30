/* Leetcode Problem No.: 219. Contains Duplicate II  */

/*
    Company Tags                : Airbnb, Palantir Technologies
    Leetcode Link               : https://leetcode.com/problems/contains-duplicate-ii/
    Using sliding window        : https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Sliding%20Window/Contains_Duplicate_II_.cpp
*/

// Approach 1: Using Map without sliding window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(mp.find(nums[i]) != mp.end() &&  //check if present in map and abs(i-j) <= k
                abs(mp[nums[i]] - i) <= k)
                return true;
            else
                mp[nums[i]] = i; //{number, index}
            
        }
        
        return false;
    }
};


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