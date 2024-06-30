/* Leetcode Problem No.: 645. Set Mismatch */
/*
    Company tags               : Amazon
    Leetcode Link              : https://leetcode.com/problems/set-mismatch/
*/

/****************************************************************** C++ ******************************************************************/
/*
    Approach Summary : 

        This method takes a vector of integers nums as input, where the integers 
        represent a set of numbers from 1 to n.

        The method aims to find and return a vector containing two integers - one 
        representing a duplicate number in the input vector, and the other representing 
        a missing number. The approach involves iterating through the input vector and 
        using the array itself to mark the presence of numbers. 
        
        It does this by negating the value at the index corresponding to the absolute 
        value of the current number. 

        If at any point, a number is encountered whose corresponding index already has 
        a negative value, it implies that the number is a duplicate. 
        After the iteration, the missing number is identified by finding the index with 
        a positive value.

        The final result is a vector containing the duplicate and missing numbers, 
        which is then returned.
*/


//Approach-1 (Smart Approach)
//T.C : O(n)
//S.C : O(1)

// expected approach: smart approach
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        int duplicate = -1;
        int missing = -1;

        // to find duplicate number
        for ( int i = 0; i< n; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                duplicate = abs(nums[i]);
            } else {
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }

        // to find missing numbers
        for ( int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = (i+1);
                break;
            }
        }
        return {duplicate, missing};
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int dup     = -1;
        int missing = -1;
        
        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0)
                dup = num;
            else
                nums[num-1] *= (-1);
        }
        
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        
        return {dup, missing};
    }
};


//Approach-2 (Basic Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss = 0, dup = 0;
        
        map<int, int> mp;
        for(int x:nums) {
            mp[x]++;
        }
        
        for(int i = 1; i<=n; i++) {
            if(mp.count(i)) {
                if(mp[i] == 2)
                    dup = i;
            } else
                miss = i;
        }
        
        return {dup, miss};
    }
};














































/****************************************************************** C++ ******************************************************************/
//Approach-1 (Smart Approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        
        int dup = -1;
        int missing = -1;
        
        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);
            
            if (nums[num - 1] < 0)
                dup = num;
            else
                nums[num - 1] *= (-1);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        
        return new int[]{dup, missing};
    }
}



//Approach-2 (Basic Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int miss = 0, dup = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        
        for (int i = 1; i <= n; i++) {
            if (map.containsKey(i)) {
                if (map.get(i) == 2) {
                    dup = i;
                }
            } else {
                miss = i;
            }
        }
        
        return new int[]{dup, miss};
    }
}



/*
    YOUTUE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=j89Yzq3IwVY
*/