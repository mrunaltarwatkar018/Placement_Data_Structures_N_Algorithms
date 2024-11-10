/*    Leetcode Problem No.: 3097. Shortest Subarray With OR at Least K II    */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
*/


class Solution {
    void updateFreq(vector<int>& bitFreq,int number,int val){
        for(int i=0;i<32;++i)
            if(number&(1<<i))
                bitFreq[i]+=val;
    }
    int getNumber(vector<int>& bitFreq){
        int number=0;
        long long pow = 1;
        for(int i=0;i<32;++i){
            if(bitFreq[i]>0)
                number+=pow;
            pow*=2;
        }
        return number;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0)
            return 1;
    
        int n=nums.size();
        int shortest=INT_MAX;
        int left=0,right=0;
        int currOR=0;
        vector<int> bitFreq(32);
        
        while(right<n){
            updateFreq(bitFreq,nums[right],1);
            currOR |= nums[right];
            
            //Resize window
            while(left<=right and currOR>=k){
                shortest=min(shortest,right-left+1);
                updateFreq(bitFreq,nums[left],-1);
                currOR = getNumber(bitFreq);
                left++;
            }
            right++;
        }
        return shortest==INT_MAX?-1:shortest;
    }
};

/*
//JAVA
import java.util.*;

class Solution {
    void updateFreq(int[] bitFreq, int number, int val) {
        for (int i = 0; i < 32; ++i) {
            if ((number & (1 << i)) != 0) {
                bitFreq[i] += val;
            }
        }
    }

    int getNumber(int[] bitFreq) {
        int number = 0;
        long pow = 1;
        for (int i = 0; i < 32; ++i) {
            if (bitFreq[i] > 0) {
                number += pow;
            }
            pow *= 2;
        }
        return number;
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        if (k == 0) {
            return 1;
        }

        int n = nums.length;
        int shortest = Integer.MAX_VALUE;
        int left = 0, right = 0;
        int currOR = 0;
        int[] bitFreq = new int[32];

        while (right < n) {
            updateFreq(bitFreq, nums[right], 1);
            currOR |= nums[right];

            // Resize window
            while (left <= right && currOR >= k) {
                shortest = Math.min(shortest, right - left + 1);
                updateFreq(bitFreq, nums[left], -1);
                currOR = getNumber(bitFreq);
                left++;
            }
            right++;
        }
        return shortest == Integer.MAX_VALUE ? -1 : shortest;
    }
}

#Python
class Solution:
    def updateFreq(self, bitFreq, number, val):
        for i in range(32):
            if number & (1 << i):
                bitFreq[i] += val

    def getNumber(self, bitFreq):
        number = 0
        pow = 1
        for i in range(32):
            if bitFreq[i] > 0:
                number += pow
            pow *= 2
        return number

    def minimumSubarrayLength(self, nums, k):
        if k == 0:
            return 1

        n = len(nums)
        shortest = float('inf')
        left = 0
        right = 0
        currOR = 0
        bitFreq = [0] * 32

        while right < n:
            self.updateFreq(bitFreq, nums[right], 1)
            currOR |= nums[right]

            # Resize window
            while left <= right and currOR >= k:
                shortest = min(shortest, right - left + 1)
                self.updateFreq(bitFreq, nums[left], -1)
                currOR = self.getNumber(bitFreq)
                left += 1
            right += 1

        return -1 if shortest == float('inf') else shortest

*/