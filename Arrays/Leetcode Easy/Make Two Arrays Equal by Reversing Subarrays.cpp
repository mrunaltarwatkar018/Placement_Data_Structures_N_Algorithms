/* Leetcode Problem No.: 1460. Make Two Arrays Equal by Reversing Subarrays  */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays
*/


/********************************************************* C++ *********************************************************/
// Approach - 1 (Sorting)
// T.C : O(nlogn)
// S.C : O(1)

/*
    Summary :

        Approach 1: Sorting

            Time Complexity: O(n log n)
            Space Complexity: O(1)

            Description:

                Both arrays (target and arr) are sorted.

                The sorted arrays are then compared element by element.

                If all corresponding elements in the sorted arrays are equal, the method returns 
                true; otherwise, it returns false.

            Advantages:

                Simple and straightforward.

                Does not require additional space beyond the input arrays.

            Disadvantages:

                Sorting both arrays can be less efficient for larger datasets due to O(n log n) 
                time complexity.

*/


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != target[i])
                return false;
        }
        return true;
    }
};


//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)


/*
    Summary :

        Approach 2: Using HashMap

            Time Complexity: O(n)
            Space Complexity: O(n)

            Description:

                A HashMap is used to count the frequency of each element in the arr array.

                The target array is then iterated through, and the frequency of each element is 
                checked against the HashMap.

                If an element in target does not exist in the HashMap or its frequency does not 
                match, the method returns false.

                If all elements match, the method returns true.

            Advantages:

                More efficient for large datasets as it runs in linear time.

                Effectively handles cases where elements need to be compared based on frequency.
            
            Disadvantages:

                Requires additional space proportional to the number of unique elements in the 
                arrays.

*/


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        for (int &num : target) {
            if (mp.find(num) == mp.end())
                return false;

            mp[num]--;
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        return mp.size() == 0;
    }
};


/********************************************************* PYTHON *********************************************************/

// Approach - 1 (Sorting)
// T.C : O(nlogn)
// S.C : O(1)

class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        target.sort()
        arr.sort()
        for i in range(len(arr)):
            if arr[i] != target[i]:
                return False
        return True

//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)

class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        target_map = {}
        for num in target:
            target_map[num] = target_map.get(num, 0) + 1
        
        for num in arr:
            if num not in target_map or target_map[num] == 0:
                return False
            target_map[num] -= 1
        
        return True

// another way

class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1

        for num in target:
            if num not in freq_map:
                return False
            freq_map[num] -= 1
            if freq_map[num] == 0:
                del freq_map[num]

        return not freq_map



/********************************************************* PYTHON 3 *********************************************************/

// Approach - 1 (Sorting)
// T.C : O(nlogn)
// S.C : O(1)

from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target.sort()
        arr.sort()
        for i in range(len(arr)):
            if arr[i] != target[i]:
                return False
        return True




//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)



from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target_map = {}
        for num in target:
            target_map[num] = target_map.get(num, 0) + 1
        
        for num in arr:
            if num not in target_map or target_map[num] == 0:
                return False
            target_map[num] -= 1
        
        return True






// another way

from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1

        for num in target:
            if num not in freq_map:
                return False
            freq_map[num] -= 1
            if freq_map[num] == 0:
                del freq_map[num]

        return not freq_map





/********************************************************* JAVA *********************************************************/
//Approach - 1 (Sorting)
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != target[i])
                return false;
        }
        return true;
    }
}


// Approach-2 (Using map)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        for (int num : target) {
            if (!map.containsKey(num)) {
                return false;
            }
            map.put(num, map.get(num) - 1);
            if (map.get(num) == 0) {
                map.remove(num);
            }
        }
        
        return map.isEmpty();
    }
}

























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=va0iQjn8rXU
*/