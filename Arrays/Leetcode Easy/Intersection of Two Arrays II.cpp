/* Leetcode Problem No.: 350. Intersection of Two Arrays II  */


/*    Scroll below to see JAVA code also   */

/*
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/


/************************************************************ C++ *****************************************************************/
//Approach-1 (Using map)
//T.C:  O(n)
//S.C : O(n)

/*
    Approach 1: Using Hash Map

        Time Complexity: O(n) 
        Space Complexity: O(n)

        Hash Map for Counting Elements:
            Traverse the first array (nums1) and use an unordered_map (or HashMap in 
            Java) to count the occurrences of each element.
        
        Intersection Calculation:
            Traverse the second array (nums2).

            For each element in nums2, check if it exists in the map with a count 
            greater than zero.
            
            If it exists, add it to the result list and decrement its count in the map.
        
        Advantages:
            Efficient in terms of both time and space for large arrays with many 
            duplicate elements.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for(int &num : nums1) {
            mp[num]++;
        }

        vector<int> result;
        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];

            if(mp[num] > 0) {
                mp[num]--;
                result.push_back(num);
            }
        }

        return result;

    }
};





//Approach-2 (Using sorting and 2-Pointers)
//T.C:  O(n)
//S.C : O(n)



/*
    Approach 2: Using Sorting and Two Pointers

        Time Complexity: O(n log n) Space Complexity: O(n)

        Sort Both Arrays:
            Sort both input arrays (nums1 and nums2).

        Two-Pointer Technique:
            Use two pointers to traverse the sorted arrays.

            If elements at both pointers are equal, add the element to the result list 
            and increment both pointers.

            If the element in nums1 is smaller, increment the pointer for nums1.

            If the element in nums2 is smaller, increment the pointer for nums2.

        Advantages:
            Simple and easy to understand.
            Efficient when the arrays are already sorted or nearly sorted.

        Comparison

            Efficiency: 
                The hash map approach has a linear time complexity, making it faster 
                for large arrays. The sorting and two-pointer approach has a higher 
                time complexity due to the sorting step.
        
            Space: 
                Both approaches use extra space, but the hash map approach uses 
                additional space proportional to the number of unique elements in the 
                first array, whereas the sorting approach uses extra space mainly for 
                the sorted arrays.

            Use Case: 
                The hash map approach is more efficient for unsorted arrays with many 
                duplicates, while the sorting and two-pointer approach is better for 
                arrays that are already sorted or when space is a concern.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        int i = 0; // -> nums1
        int j = 0; // -> nums2

        vector<int> result;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************************/
//Approach-1 (Using map)
//T.C:  O(n)
//S.C : O(n)
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        List<Integer> result = new ArrayList<>();
        for (int num : nums2) {
            if (map.getOrDefault(num, 0) > 0) {
                result.add(num);
                map.put(num, map.get(num) - 1);
            }
        }

        int[] intersection = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            intersection[i] = result.get(i);
        }

        return intersection;
    }
}




//Approach-2 (Using sorting and 2-Pointers)
//T.C:  O(n)
//S.C : O(n)
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0;
        int j = 0;
        List<Integer> result = new ArrayList<>();

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                result.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        int[] intersection = new int[result.size()];
        for (int k = 0; k < result.size(); k++) {
            intersection[k] = result.get(k);
        }

        return intersection;
    }
}

/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gRpn4pyXf8I
*/