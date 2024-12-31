/* Leetcode Problem No.: 368. Largest Divisible Subset  */

/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/largest-divisible-subset/
*/

/*
Approach Summary : Using the same concept of LIS. Just sort the array so that we are ensured to tak elements in increasing order. We will be solving it using simple recursion just like LIS and simple bottom up just like LIS. Only difference will be to keep track of the LIS elements to return the result.
*/

/**************************************************** C++ ****************************************************/
// Approach-1 (Using Brute Force same as LIS)  47 / 49 testcases passed
// T.C : O(2^n) without memoization
// S.C : O(n)
class Solution {
public:
    void solve(int idx, vector<int> & nums, vector<int> & result, vector<int> & temp, int prev) {
        if (idx >= nums.size() ) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        } 

        // take option
        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]); // take
            solve(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back(); // not_take
        }

        solve(idx + 1, nums, result, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<int> result;
        vector<int> temp;

        int prev = -1;
        solve(0, nums, result, temp, prev);

        return result;
    }
};


// or
class Solution {
public:
    
    void generate(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if(idx >= nums.size()) {
            if(temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        
        if(prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            generate(idx+1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }
        
        generate(idx+1, nums, result, temp, prev);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);
        
        return result;
    }
};


// Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
// T.C : O(n^2)
// S.C : O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};



/**************************************************** JAVA ****************************************************/
//Approach-1 (Using Brute Force same as LIS)
//T.C : O(2^n) without memoization
//S.C : O(n)
public class Solution {

    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);

        List<Integer> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        generate(0, nums, result, temp, -1);

        return result;
    }

    private void generate(int idx, int[] nums, List<Integer> result, List<Integer> temp, int prev) {
        if (idx >= nums.length) {
            if (temp.size() > result.size()) {
                result.clear();
                result.addAll(temp);
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0) {
            temp.add(nums[idx]);
            generate(idx + 1, nums, result, temp, nums[idx]);
            temp.remove(temp.size() - 1);
        }

        generate(idx + 1, nums, result, temp, prev);
    }
}


//Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
//T.C : O(n^2)
//S.C : O(n)
public class Solution {

    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;
        int[] t = new int[n];
        Arrays.fill(t, 1);

        int[] prevIdx = new int[n];
        Arrays.fill(prevIdx, -1);

        int lastChosenIndex = 0;
        int maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (t[i] < t[j] + 1) {
                        t[i] = t[j] + 1;
                        prevIdx[i] = j;
                    }

                    if (t[i] > maxL) {
                        maxL = t[i];
                        lastChosenIndex = i;
                    }
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (lastChosenIndex >= 0) {
            result.add(nums[lastChosenIndex]);
            lastChosenIndex = prevIdx[lastChosenIndex];
        }

        return result;
    }
}















/*

Did on my own, to be honest LIS variant is difficult to determine in certain questions but in most cases you just have to check these things
1) does the question use terms like longest,largest,tallest
2) does the question use 2 indices i and j
3) does the question talk about subsets/subsequences
4) We get a sense that we need to have a track of previous element (prev)
5) We get a sense that we need to have a track of length of LIS (t)
6) We get a sense that we need to have a track of previous index (prev_idx)
7) We get a sense that we need to have a track of last chosen index (last_chosen_index)
8) We get a sense that we need to have a track of max length of LIS (maxL)


*/