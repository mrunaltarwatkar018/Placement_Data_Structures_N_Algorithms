/*    Leetcode Problem No.: 3254. Find the Power of K-Size Subarrays I */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i
*/



/**************************************************************** C++ ****************************************************************/
//Approach (Using sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result(n-k+1, -1);

        int count = 1; //count of consecutive elements

        //preprocess the first window
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) {
                count++;
            } else {
                count = 1;
            }
        }

        if(count == k) {
            result[0] = nums[k-1];
        }

        int i = 1;
        int j = k;

        while(j < n) {
            if(nums[j] == nums[j-1]+1) {
                count++;
            } else {
                count = 1;
            }

            if(count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;

    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (Using sliding window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;

        int[] result = new int[n - k + 1];
        // Initialize the result array with -1
        java.util.Arrays.fill(result, -1);

        int count = 1; // Count of consecutive elements

        // Preprocess the first window
        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
        }

        // Check if the first window satisfies the condition
        if (count == k) {
            result[0] = nums[k - 1];
        }

        int i = 1;
        int j = k;

        // Process the sliding window
        while (j < n) {
            if (nums[j] == nums[j - 1] + 1) {
                count++;
            } else {
                count = 1;
            }

            if (count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;
    }
}

























class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;

        // Iterate through all subarrays of size k
        for (int i = 0; i <= nums.size() - k; ++i) {
            bool isConsecutive = true;
            
            // Check if the subarray nums[i..i+k-1] is sorted and consecutive
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j + 1] != nums[j] + 1) {
                    isConsecutive = false;
                    break;
                }
            }
            
            // If the subarray is consecutive and sorted, add the max element to the result
            if (isConsecutive) {
                result.push_back(nums[i + k - 1]);
            } else {
                // Otherwise, add -1 to the result
                result.push_back(-1);
            }
        }

        return result;
    }
};
