/* Leetcode Problem No.: 300. Longest Increasing Subsequence  */

/*
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/longest-increasing-subsequence/
*/


// ************************************************************ C++ ************************************************************
// Approach-1 (Recursion without memorization)  - TLE  
// TC: O(2^n)
class Solution {
public:
    int n;

    int solve(vector<int>& nums, int idx, int prev) {
        if (idx >= n) 
            return 0;

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx + 1, idx);
        }
        int skip = solve(nums, idx + 1, prev);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        return solve(nums, 0, -1);
    }
};



// Approach-2 (TopDown: Recur+Memo) 
// T.C : O(n*n)
class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums, int idx, int prev) {
        if (idx >= n) 
            return 0;

        if ( prev != -1 && dp[idx][prev] != -1 ) {
            return dp[idx][prev];
        }

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx + 1, idx);
        }
        int skip = solve(nums, idx + 1, prev);

        if (prev != -1) {
            dp[idx][prev] = max(take, skip);
        }
        
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};


// or
class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {
        if(curr_idx == n)
            return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};

//Approach-3 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        // t[i] = LIS ending at ith index
        int maxLIS = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;
    }
};

// or
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};

// Approacj-4 (Using concept of Patience Sorting (O(nlogn))
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted; // empty in the beginning

        for (int i = 0; i < n; i++ ) {
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]); // just greater that or equal the nums[i]
            // and if do *it we get element
            if (it == end(sorted)) {
                sorted.push_back(nums[i]); // greatest : so insert it
            } else {
                *it = nums[i]; // replace with nums[i]
            }
        }
        return sorted.size(); // LIS
    }
};

// or
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        
        for(int i = 0; i<n; i++) {
            /*
                    Why lower bound ?
                    We want increasing subsequence and  hence 
                    we want to eliminate the duplicates as well.
                    lower_bound returns iterator to "next greater or equal to"
			*/
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]);
            
            if(it == end(sorted))
                sorted.push_back(nums[i]); //greatest : so insert it
            else
                *it = nums[i]; //replace
        }
        
        return (int)sorted.size();
    }
};


//Approach-5 (Converting the question to Longest Common Subsequence) O(n*n)
class Solution {
public:
    int LCS(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        //if length of nums1/num2 is 0, then LCS is 0
        for(int j = 0; j<n; j++) {
            t[0][j] = 0;
        }
        for(int i = 0; i<n; i++) {
            t[i][0] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(nums1[i-1] == nums2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[m][n];
    }
    int lengthOfLIS(vector<int>& nums) {
        //We need unique elements only because we want 'Longest "Increasing" Subseqnece'
        set<int> st(begin(nums), end(nums));
        
        vector<int> nums2(begin(st), end(st));
        
        return LCS(nums, nums2);
        
    }
};



//Approach-6 (Using same code of Leetcode-2926(Maximum Balanced Subsequence Sum) (YouTube - https://www.youtube.com/watch?v=JrG4tbq6efg)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int len = 1;
            auto it = mp.upper_bound(nums[i]);

            if(it != mp.begin()) {
                it--;
                if(it->first < nums[i]) {
                    len += it->second;
                }
            }

            mp[nums[i]] = max(mp[nums[i]], len);
            it = mp.upper_bound(nums[i]);

            while(it != mp.end() && it->second <= len) {
                mp.erase(it++);
            }

            ans = max(ans, len);
        }

        return ans;
    }
};



// or
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int ans = INT_MIN;
        mp[INT_MIN] = 0;
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]); 
            int curr = 1;
            if(it != mp.begin()) {
                it--;
                if(it->first < nums[i]){
                    curr = curr + it->second;
                }
            }
            mp[nums[i]] = max(mp[nums[i]], curr);
            it = mp.upper_bound(nums[i]);
            while(it != mp.end() && it->second <= curr) {
                mp.erase(it++);
            }
            ans = max(ans, curr);
        }
        return ans;
}


// ************************************************************ JAVA ************************************************************
//Approach-1 (TopDown: Recur+Memo) 
//T.C : O(n*n)
class Solution {
    private int n;
    private int[][] t;

    public int lis(int[] nums, int prevIdx, int currIdx) {
        if (currIdx == n)
            return 0;

        if (prevIdx != -1 && t[prevIdx][currIdx] != -1)
            return t[prevIdx][currIdx];

        int taken = 0;
        if (prevIdx == -1 || nums[currIdx] > nums[prevIdx])
            taken = 1 + lis(nums, currIdx, currIdx + 1);

        int notTaken = lis(nums, prevIdx, currIdx + 1);

        if (prevIdx != -1)
            t[prevIdx][currIdx] = Math.max(taken, notTaken);

        return Math.max(taken, notTaken);
    }

    public int lengthOfLIS(int[] nums) {
        t = new int[2501][2501];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        n = nums.length;
        return lis(nums, -1, 0);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n^2)
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        int[] t = new int[n];
        Arrays.fill(t,1);
    
        int maxLIS = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) {
                    t[i] = Math.max(t[i], t[j] + 1);
                    maxLIS = Math.max(maxLIS, t[i]);
                }
            }
        }

        return maxLIS;
    }
}


//Approacj-4 (Using concept of Patience Sorting (O(nlogn))
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        List<Integer> sorted = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            /*
                Why lower bound?
                We want an increasing subsequence, and hence
                we want to eliminate the duplicates as well.
                lower_bound returns the index of "next greater or equal to."
            */
            int index = binarySearch(sorted, nums[i]);

            if (index == sorted.size())
                sorted.add(nums[i]); // greatest: so insert it
            else
                sorted.set(index, nums[i]); // replace
        }

        return sorted.size();
    }

    private int binarySearch(List<Integer> sorted, int target) {
        int left = 0, right = sorted.size();
        int result = sorted.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (sorted.get(mid) < target) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid;
            }
        }
        return result;
    }
}

	
//Approach-5 (Using same code of Leetcode-2926(Maximum Balanced Subsequence Sum) (YouTube - https://www.youtube.com/watch?v=JrG4tbq6efg)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int len = 1;

            Integer key = mp.lowerKey(nums[i]);
            if (key != null) {
                len += mp.get(key);
            }

            mp.put(nums[i], Math.max(mp.getOrDefault(nums[i], 0), len));

            key = mp.higherKey(nums[i]);
            while (key != null && mp.get(key) <= len) {
                mp.remove(key);
                key = mp.higherKey(nums[i]);
            }

            ans = Math.max(ans, len);
        }

        return ans;
    }
}































/*
    YouTube Link  : Recursion + Memoization -  https://www.youtube.com/watch?v=DG50PJIx2SM
                    Bottom Up - https://www.youtube.com/watch?v=h9rm4N8XbL0
                    Patience Sorting - https://www.youtube.com/watch?v=dWmh3O8uX8A
*/