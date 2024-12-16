/* Leetcode Problem No.: 1814. Count Nice Pairs in an Array  */

/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/count-nice-pairs-in-an-array/
*/


/*
SUGGESTION: (Pattern)
    When you see something like this ...[i] + ...[j] == ...[j] + ...[i]
    always regroup so that the terms with the same i/j are on the same side of the equation
    e.g. ...[i] - ...[i] == [j] - ...[j]

    Another example : Leetcode-2926 - Where you should rearrange i and j on either side to make it easy to handle
*/

/************************************************************ C++ ************************************************************/
//Approach (Rearrange i and j and compute with Map)
//T.C : O(n)
//S.C : O(n) using map

class Solution {
public:
    int MOD = 1e9 + 7;
    int rev(int num) {
        int ans = 0;
        while (num > 0) {
            int remainder = num % 10;
            ans = (ans * 10) + remainder;
            num = num / 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; 

        // Step 1: nums[i] - rev(nums[i])
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }
        // Step 2: return count as result
        int result = 0;
        for (int i = 0; i < n; i++ ) {
            result = (result + mp[nums[i]]) % MOD;
            mp[nums[i]]++;
        }
        return result;
    }
};

// or

class Solution {
public:
    int M = 1e9+7;
    int reverse(int num) {
        int rev = 0;
        
        while(num > 0) {
            int rem = num%10;
            rev = rev*10 + rem;
            num /= 10;
        }
        
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        //nums[i] - rev(nums[i]) ==  nums[j] - rev(nums[j])
        for(int i = 0; i<n; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            result = (result + mp[nums[i]]) % M;
            
            mp[nums[i]]++;
        }
        
        return result;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (Rearrange i and j and compute with Map)
//T.C : O(n)
//S.C : O(n) using map
class Solution {
    final int M = 1000000007;

    public int reverse(int num) {
        int rev = 0;

        while (num > 0) {
            int rem = num % 10;
            rev = rev * 10 + rem;
            num /= 10;
        }

        return rev;
    }

    public int countNicePairs(int[] nums) {
        int n = nums.length;

        Map<Integer, Integer> mp = new HashMap<>();

        // nums[i] - reverse(nums[i]) == nums[j] - reverse(nums[j])
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = (int) ((result + mp.getOrDefault(nums[i], 0)) % M);
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        return result;
    }
}