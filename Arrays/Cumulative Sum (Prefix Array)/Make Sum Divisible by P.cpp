/* Leetcode Problem No.: 1590. Make Sum Divisible by P  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/make-sum-divisible-by-p/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach  (Using prefix sum modulo and storing in hashmap)
//T.C : O(n)
//S.C : O(n)

/*

    Summary :

        The solution aims to find the smallest subarray that, when removed, makes the sum of 
        the remaining array divisible by a given integer p. Here’s how it works:

        Calculate Total Modulo: 

            First, compute the total sum of the array modulo p. This determines the target 
            remainder that needs to be removed to make the remaining sum divisible by p.

        Early Exit: 

            If the total sum is already divisible by p (target == 0), the function 
            immediately returns 0, as no subarray needs to be removed.

        Iterate through the Array:

            Maintain a prefix sum (curr) modulo p while iterating through the array.
        
            Use a hash map (map) to store the indices of seen remainders to efficiently find 
            subarrays with a specific remainder.

        Check for Subarray:

            For each element, calculate the remainder remain that, if removed, would make 
            the remaining sum divisible by p.

            If this remainder has been seen before, update the result with the length of the 
            smallest subarray.

        Return Result:

            If a valid subarray is found, return its length. Otherwise, return -1.

    This approach leverages prefix sums and hash maps for efficient subarray length 
    calculation, making it run in linear time O(n).

*/


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;

        //(a+b)%p = (a%p + b%p) % p
        for(int &num : nums) {
            SUM = (SUM + num) % p;
        }

        int target = SUM%p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp; //prev sum%p ko store karega

        int curr = 0;
        mp[0] = -1;

        int result = n;
        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }

            mp[curr] = j;
        }

        return result == n ? -1 : result;

    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach  (Using prefix sum modulo and storing in hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int sum = 0;

        // Calculate the sum of all elements and take % p
        for (int num : nums) {
            sum = (sum + num) % p;
        }

        int target = sum % p;
        
        // If sum is already divisible by p, no need to remove any subarray
        if (target == 0) {
            return 0;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);  // Initialize with remainder 0 at index -1
        
        int curr = 0;
        int result = n;
        
        // Traverse through the array
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            // Calculate the remainder needed to achieve the target
            int remain = (curr - target + p) % p;
            
            // If the required remainder exists in the map, update the result
            if (map.containsKey(remain)) {
                result = Math.min(result, j - map.get(remain));
            }
            
            // Store the current remainder with its index
            map.put(curr, j);
        }

        return result == n ? -1 : result;
    }
}