/* Leetcode Problem No.: 2926. Maximum Balanced Subsequence Sum  */

/*
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-balanced-subsequence-sum
*/

/********************************************************************************** C++ **********************************************************************************/

/*
    The solutions below will give TLE but we must know how this is exactly the same Qn as LIS.
    We are just changing the condition of LIS here.

    So, my code below are exact copy of LIS code with slight variations (This asks for sum).

    So i think it's worth knowing these two approaches as well.
*/



//Approach-1 (Using LIS) - Recursion (TLE) 

class Solution {
public:
    long long solve(int prev, int i, vector<int> & nums) {
        if(i >= nums.size()) {
            return 0; // no elements = sum is 0
        }

        long long taken = INT_MIN;
        long long not_taken = INT_MIN;

        if (prev == -1 || nums[i] - i >=  nums[prev] - prev )  { // same as LIS, only codintion change here
            taken = nums[i] + solve(i, i + 1, nums);
        }

        not_taken = solve(prev, i + 1, nums);

        return max<long long>(taken, not_taken);

    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxElement = *max_element(begin(nums), end(nums));

        if (maxElement <= 0) {
            return maxElement;
        }
        return solve(-1, 0, nums);
    }
};



// Approach-2 (Using LIS) - Recursion + Memorization (TLE) ---> 341 / 345 testcases passed
// T.C : O(n^2) - prev index for every i
// memorized using unordered_map because given constraints are large, 1 <= nums.length <= 10^5  and  -10^9 <= nums[i] <= 10^9
class Solution {
public:
    unordered_map<string, long long> mp; //For memoization
    long long solve(int prev, int i, vector<int> & nums) {
        if(i >= nums.size()) {
            return 0; // no elements = sum is 0
        }

        string key = to_string(prev) + "_" + to_string(i);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long taken = INT_MIN;
        long long not_taken = INT_MIN;

        if (prev == -1 || nums[i] - i >=  nums[prev] - prev )  { // same as LIS, only codintion change here
            taken = nums[i] + solve(i, i + 1, nums);
        }

        not_taken = solve(prev, i + 1, nums);

        return mp[key] = max<long long>(taken, not_taken);

    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxElement = *max_element(begin(nums), end(nums));

        if (maxElement <= 0) {
            return maxElement;
        }
        return solve(-1, 0, nums);
    }
};



// or
class Solution {
public:
    unordered_map<string, long long> mp; //For memoization
    long long solve(int i, int prev, vector<int>& nums) {
        if(i >= nums.size()) {
            return 0;
        }

        string key = to_string(i) + "_" + to_string(prev);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long taken = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i+1, i, nums);
        }
        
        long long not_taken = solve(i+1, prev, nums);
        return mp[key] = max<long long>(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }
        return solve(0, -1, nums);
    }
};


// Approach-3 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
// Time : O(n^2)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        
        int maxElement = *max_element(begin(nums), end(nums));
        if(maxElement <= 0) {
            return maxElement;
        }

        vector<long long> t(n);
        // t[i] = maximum maxBalancedSubsequenceSum till index i
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - i >= nums[j] - j) { // olny condition changed here of LIS bottom Up 
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }
            }
        }
        return maxSum > maxElement ? maxSum : maxElement;
    }
};


// or
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        vector<long long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for(int i = 0; i<n; i++) {

            for(int j = 0; j<i; j++) {

                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }

            }
        }

        return maxSum > maxEl ? maxSum : maxEl;
    }
};


//Approach-4 (Using Optimal LIS - Similar to Patience Sorting) - Accepted
//Time : O(nlogn)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;  // nums[i] - i

        long long result = INT_MIN;

        for (int i = 0; i < n; i++) {
            auto it = mp.upper_bound(nums[i]-i); // it -> first (nums[j] - j), it -> second : sum

            long long sum = nums[i];
            
            if ( it != mp.begin()) {
                it--;
                // sum += *it.second; or
                sum += it -> second;
            }

            mp[nums[i] - i] = max(mp[nums[i] - i], sum);

            it = mp.upper_bound(nums[i] - i);

            while(it != mp.end() && it -> second <= sum) {
                mp.erase(it++);
            }

            result = max(result, sum);
        }
        return result;
    }
};

// or
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};


/********************************************************************************** JAVA **********************************************************************************/
//Approach-1 (Using LIS) - Recursion (TLE) ---> 316 / 345 testcases passed
//T.C : O(n^2) - prev index for every i
public class Solution {
    private Map<String, Long> memo = new HashMap<>();

    public long solve(int i, int prev, int[] nums) {
        if (i >= nums.length) {
            return 0;
        }

        String key = i + "_" + prev;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        long taken = Integer.MIN_VALUE;

        if (prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i + 1, i, nums);
        }

        long notTaken = solve(i + 1, prev, nums);
        long result = Math.max(taken, notTaken);
        memo.put(key, result);

        return result;
    }

    public long maxBalancedSubsequenceSum(int[] nums) {
        boolean allNegative = true;
        long maxEl = Integer.MIN_VALUE;
        memo.clear();

        for (int x : nums) {
            maxEl = Math.max(maxEl, x);
            if (x >= 0) {
                allNegative = false;
            }
        }

        if (allNegative) {
            return maxEl;
        }

        return solve(0, -1, nums);
    }
}



//Approach-2 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
//Time : O(n^2)
class Solution {
    public long maxBalancedSubsequenceSum(int[] nums) {
        int n = nums.length;
        
        int maxEl = Arrays.stream(nums).max().getAsInt();
        if(maxEl <= 0) {
            return maxEl;
        }

        long[] t = new long[n];
        for(int i = 0; i < n; i++) {
            t[i] = nums[i];
        }

        long maxSum = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] - i >= nums[j] - j) {
                    t[i] = Math.max(t[i], t[j] + nums[i]);
                    maxSum = Math.max(maxSum, t[i]);
                }
            }
        }

        return maxSum > maxEl ? maxSum : maxEl;
    }
}


//Approach-3 (Using Optimal LIS - Similar to Patience Sorting) - Accepted
//Time : O(nlogn)
class Solution {
    public long maxBalancedSubsequenceSum(int[] nums) {
        int n = nums.length;
        int [] arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = nums[i]-i;
        }
        TreeMap<Integer, Long> map = new TreeMap<>();
        long ans = Integer.MIN_VALUE;
        for(int i = 0; i<n; i++){
            if(nums[i]<=0){
                ans = Math.max(ans, nums[i]);
            }
            else{
                long temp = nums[i];
                if(map.floorKey(arr[i])!=null){
                    temp += map.get(map.floorKey(arr[i]));
                }
                while(map.ceilingKey(arr[i])!=null && map.get(map.ceilingKey(arr[i]))<temp){
                    map.remove(map.ceilingKey(arr[i]));
                }
                if(map.floorKey(arr[i])==null || map.get(map.floorKey(arr[i]))<temp){
                    map.put(arr[i], temp);
                }
                ans = Math.max(ans, temp);
            }
        }
        return ans;
    }
}