/* Leetcode Problem No.: 1207. Unique Number of Occurrences  */

/*
    Company Tags                : Google, Twitter, Amazon, Netflix
    Leetcode Link               : https://leetcode.com/problems/unique-number-of-occurrences/
*/

/****************************************************************************** JAVA ******************************************************************************/
// Approach-1 (Simple using hash map and set)
// T.C : O(n)
// S.C : O(n)

/*
    Approach-1 Summary : 

        The function first creates an unordered_map mp to store the frequency 
        of each number in the input vector.

        It then iterates through the vector, updating the frequency count in 
        the map. Next, the function uses an unordered_set st to keep track of 
        unique occurrence frequencies.

        It iterates through the entries in the frequency map and checks if the 
        current frequency is already present in the set.

        If it is, the function returns false, indicating that there are 
        duplicate occurrence frequencies. 

        Otherwise, it adds the frequency to the set. 

        Finally, if the function completes the iteration without finding any 
        duplicate occurrence frequencies, it returns true, indicating that all 
        unique numbers have distinct occurrences in the input vector.

*/


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        //store frequency of each numbers
        for(int &x : arr) {
            mp[x]++;
        }
        
        unordered_set<int> st;
        
        for(auto &it : mp) {
            int freq = it.second; //it.first = number
            
            if(st.find(freq) != st.end())
                return false;
            st.insert(freq);
        }
        
        return true;
    }
};


//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)

/*
    Approach-2 Summary : 

        In this approach, The algorithm uses an auxiliary vector vec of size 
        2001 to store the count of occurrences for each element.

        It shifts the indices by 1000 to handle negative numbers. After 
        counting occurrences, the vector is sorted. 

        Finally, the function checks if any adjacent elements in the sorted 
        vector have the same count, and if so, it returns false.

        If no such pair is found, it returns true, indicating that the 
        occurrences of each unique element are indeed distinct.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        sort(begin(vec), end(vec));
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] != 0 && vec[i] == vec[i-1])
                return false;
        }
        
        
        return true;
    }
};


//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] == 0) continue;

            int idx = abs(vec[i]);
            
            if (vec[idx] < 0) {
                return false;
            }

            vec[idx] = -1;
        }
        
        
        return true;
    }
};



/************************************************************ PYTHON ************************************************************/

//Approach-1 (Simple using hash map and set)
//T.C : O(n)
//S.C : O(n)

/*
    Approach-1 Summary : 

        The function first creates an unordered_map mp to store the frequency 
        of each number in the input vector.

        It then iterates through the vector, updating the frequency count in 
        the map. Next, the function uses an unordered_set st to keep track of 
        unique occurrence frequencies.

        It iterates through the entries in the frequency map and checks if the 
        current frequency is already present in the set.

        If it is, the function returns false, indicating that there are 
        duplicate occurrence frequencies. 

        Otherwise, it adds the frequency to the set. 

        Finally, if the function completes the iteration without finding any 
        duplicate occurrence frequencies, it returns true, indicating that all 
        unique numbers have distinct occurrences in the input vector.

*/

class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1

        unique_freqs = set()
        for freq in freq_map.values():
            if freq in unique_freqs:
                return False
            unique_freqs.add(freq)

        return True







//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)

/*
    Approach-2 Summary : 

        In this approach, The algorithm uses an auxiliary vector vec of size 
        2001 to store the count of occurrences for each element.

        It shifts the indices by 1000 to handle negative numbers. After 
        counting occurrences, the vector is sorted. 

        Finally, the function checks if any adjacent elements in the sorted 
        vector have the same count, and if so, it returns false.

        If no such pair is found, it returns true, indicating that the 
        occurrences of each unique element are indeed distinct.
*/

class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        vec = [0] * 2001
        for x in arr:
            vec[x + 1000] += 1
        vec.sort()
        for i in range(1, 2001):
            if vec[i] != 0 and vec[i] == vec[i-1]:
                return False
        return True











//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)

class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        vec = [0] * 2001
        
        for x in arr:
            vec[x + 1000] += 1
        
        for i in range(1, 2001):
            if vec[i] == 0:
                continue
            
            idx = abs(vec[i])
            
            if vec[idx] < 0:
                return False
            
            vec[idx] = -1
        
        return True




/************************************************************ PYTHON 3 ************************************************************/

//Approach-1 (Simple using hash map and set)
//T.C : O(n)
//S.C : O(n)

/*
    Approach-1 Summary : 

        The function first creates an unordered_map mp to store the frequency 
        of each number in the input vector.

        It then iterates through the vector, updating the frequency count in 
        the map. Next, the function uses an unordered_set st to keep track of 
        unique occurrence frequencies.

        It iterates through the entries in the frequency map and checks if the 
        current frequency is already present in the set.

        If it is, the function returns false, indicating that there are 
        duplicate occurrence frequencies. 

        Otherwise, it adds the frequency to the set. 

        Finally, if the function completes the iteration without finding any 
        duplicate occurrence frequencies, it returns true, indicating that all 
        unique numbers have distinct occurrences in the input vector.

*/

from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1

        unique_freqs = set()
        for freq in freq_map.values():
            if freq in unique_freqs:
                return False
            unique_freqs.add(freq)

        return True




//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)

/*
    Approach-2 Summary : 

        In this approach, The algorithm uses an auxiliary vector vec of size 
        2001 to store the count of occurrences for each element.

        It shifts the indices by 1000 to handle negative numbers. After 
        counting occurrences, the vector is sorted. 

        Finally, the function checks if any adjacent elements in the sorted 
        vector have the same count, and if so, it returns false.

        If no such pair is found, it returns true, indicating that the 
        occurrences of each unique element are indeed distinct.
*/

from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        vec = [0] * 2001
        for x in arr:
            vec[x + 1000] += 1
        vec.sort()
        for i in range(1, 2001):
            if vec[i] != 0 and vec[i] == vec[i-1]:
                return False
        return True





//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)


from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        vec = [0] * 2001
        
        for x in arr:
            vec[x + 1000] += 1
        
        for i in range(1, 2001):
            if vec[i] == 0:
                continue
            
            idx = abs(vec[i])
            
            if vec[idx] < 0:
                return False
            
            vec[idx] = -1
        
        return True









/****************************************************************************** JAVA ******************************************************************************/
//Approach-1 (Simple using hash map and set)
//T.C : O(n)
//S.C : O(n)

/*
    Approach-1 Summary : 

        The function first creates an unordered_map mp to store the frequency 
        of each number in the input vector.

        It then iterates through the vector, updating the frequency count in 
        the map. Next, the function uses an unordered_set st to keep track of 
        unique occurrence frequencies.

        It iterates through the entries in the frequency map and checks if the 
        current frequency is already present in the set.

        If it is, the function returns false, indicating that there are 
        duplicate occurrence frequencies. 

        Otherwise, it adds the frequency to the set. 

        Finally, if the function completes the iteration without finding any 
        duplicate occurrence frequencies, it returns true, indicating that all 
        unique numbers have distinct occurrences in the input vector.

*/

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Store frequency of each number
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        
        HashSet<Integer> set = new HashSet<>();
        
        for (int freq : map.values()) {
            if (set.contains(freq)) {
                return false;
            }
            set.add(freq);
        }
        
        return true;
    }
}


//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)

/*
    Approach-2 Summary : 

        In this approach, The algorithm uses an auxiliary vector vec of size 
        2001 to store the count of occurrences for each element.

        It shifts the indices by 1000 to handle negative numbers. After 
        counting occurrences, the vector is sorted. 

        Finally, the function checks if any adjacent elements in the sorted 
        vector have the same count, and if so, it returns false.

        If no such pair is found, it returns true, indicating that the 
        occurrences of each unique element are indeed distinct.
*/



public class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] vec = new int[2001];

        for (int x : arr) {
            vec[x + 1000]++;
        }

        Arrays.sort(vec);

        for (int i = 1; i < 2001; i++) {
            if (vec[i] != 0 && vec[i] == vec[i - 1]) {
                return false;
            }
        }

        return true;
    }
}


//Approach-3 (Improvement on Approach-2)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] vec = new int[2001];

        for (int x : arr) {
            vec[x + 1000]++;
        }

        for (int i = 0; i < 2001; i++) {
            if(vec[i] == 0) continue;

            int idx = Math.abs(vec[i]);
            
            if (vec[idx] < 0) {
                return false;
            }

            vec[idx] = -1;
        }

        return true;
    }
}



















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=b2_rw2NZkr8
*/