/* GFG Problem: Array Pair Sum Divisibility Problem  */

/*
    Company Tags                : Amazon, Microsoft, Goldman Sachs, Directi
    GfG Leetcode Link           : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
*/


/***************************************************************** C++ ***************************************************************************/
//Approach-1 (Try all possible pairs)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();

        // Mark pairs as used to avoid repetition
        vector<bool> used(n, false);
    
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue; // Skip if this element is already used in a pair
            }
    
            bool foundPair = false;
    
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && (nums[i] + nums[j]) % k == 0) {
                    used[i] = true;
                    used[j] = true;
                    foundPair = true;
                    break;
                }
            }
    
            if (!foundPair) {
                return false; // No pair found for the current element
            }
        }
        
        return true;
    }
};



//Approach-2 (Using hashset)
//T.C : O(n)
//S.C : O(n)

class Solution {
    public:
    bool canPair(vector<int> &nums, int k) {
        // Code here.
        int n = nums.size();
        
        
        // if n is odd, no pair is formed here, so return false
        if (n % 2 == 1) {
            return false;
        }
        
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int rem1 = nums[i] % k;
            int rem2 = k - rem1;
            
            if (st.find(rem2) != st.end()) {
                st.erase(rem2);
            } else if (rem1 == 0 && st.find(0) != st.end()) {
                st.erase(0);
            } else {
                st.insert(rem1);
            }
        }
        
        return st.size() == 0; // all match found and removed from the set
    }
};



// or
class Solution {
    public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        
        if(n%2 == 1){
            return false;
        }
        
        unordered_set<int> st;
        
        for(int i=0; i < n; i++) {
            int remain       = nums[i] % k;
            int other_remain = k - remain;
            
            if(st.find(other_remain) != st.end() || ( (remain == 0) && (st.find(0) != st.end() ))){
                st.erase(remain);
                st.erase(other_remain);
            }
            else{
                st.insert(remain);
            }
        }
        
        return st.size() == 0;
    }
};



/***************************************************************** JAVA ***************************************************************************/
//Approach-1 (Try all possible pairs)
//T.C : O(n^2)
//S.C : O(n)
public class Solution {
    public boolean canPair(int[] nums, int k) {
        int n = nums.length;

        // Mark pairs as used to avoid repetition
        boolean[] used = new boolean[n];
        Arrays.fill(used, false);

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue; // Skip if this element is already used in a pair
            }

            boolean foundPair = false;

            for (int j = i + 1; j < n; j++) {
                if (!used[j] && (nums[i] + nums[j]) % k == 0) {
                    used[i] = true;
                    used[j] = true;
                    foundPair = true;
                    break;
                }
            }

            if (!foundPair) {
                return false; // No pair found for the current element
            }
        }

        return true;
    }
}

//Approach-2 (Using hashset)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean canPair(int[] nums, int k) {
        int n = nums.length;

        if (n % 2 == 1) {
            return false;
        }

        Set<Integer> st = new HashSet<>();

        for (int i = 0; i < n; i++) {
            int remain = nums[i] % k;
            int other_remain = k - remain;

            if (st.contains(other_remain) || ((remain == 0) && (st.contains(0)))) {
                st.remove(remain);
                st.remove(other_remain);
            } else {
                st.add(remain);
            }
        }

        return st.size() == 0;
    }
}