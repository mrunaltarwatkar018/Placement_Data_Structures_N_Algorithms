/* Leetcode Problem No.: 1497. Check If Array Pairs Are Divisible by k  */

/*
    Company Tags                : Amazon, Uber, Microsoft
    Leetcode Link               : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
*/



/************************************************************ C++ ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)

/*
The approach uses remainder arithmetic to solve the problem of determining if the array can be rearranged into pairs whose sums are divisible by a given integer k. Here's a brief summary of the method:

Calculate Remainder Frequencies:

Traverse through the array and compute the remainders when each element is divided by k.
Use an array mp of size k to count the frequency of these remainders, handling negative remainders correctly.
Check Conditions for Valid Pairing:

For elements with a remainder of 0, their frequency must be even to ensure they can be paired.
For other remainders rem, ensure that mp[rem] (frequency of rem) matches mp[k - rem] (frequency of its complement remainder) to allow pairing.
Return Result:

If all conditions are met, return true; otherwise, return false.

*/


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0); //O(K)
        //mp[r] = x
        //remainder r has frequency x

        for(int &num : arr) {
            int rem = (num%k + k) % k; //handling negative remainders
            mp[rem]++;
        }

        if(mp[0] % 2 != 0) {
            return false;
        }

        for(int rem = 1; rem <= k/2; rem++) {
            int counterHalf = k - rem;
            if(mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
};


/************************************************************ JAVA ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] mp = new int[k];  // Array to store remainders frequency

        // Calculate the remainder frequencies
        for (int num : arr) {
            int rem = (num % k + k) % k;  // Handle negative remainders
            mp[rem]++;
        }

        // Check if the frequency of numbers with 0 remainder is even
        if (mp[0] % 2 != 0) {
            return false;
        }

        // Check if each remainder has a complement remainder with matching frequency
        for (int rem = 1; rem <= k / 2; rem++) {
            int counterHalf = k - rem;
            if (mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
}