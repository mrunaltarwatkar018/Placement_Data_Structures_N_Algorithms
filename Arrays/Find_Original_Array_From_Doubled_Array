/* Leetcode Problem No.: 2007. Find Original Array From Doubled Array */


/*
    Company Tags                : Google, HCL, IBM, HCL, Accenture
    Leetcode Link               : https://leetcode.com/problems/find-original-array-from-doubled-array/
*/

/*
    Approach-1 (Using sorting and map)

        First, it checks if the length of the changed array is odd. If it is, 
        it returns an empty array because the original array cannot be constructed 
        from a doubled array with an odd length.

        It sorts the changed array in ascending order.

        It creates a map mp to store the frequency of each number in the changed 
        array.

        It iterates through the changed array, and for each number, it checks if its 
        double exists in the map and has a non-zero frequency. If it does, it adds 
        the number to the result array and decrements the frequencies of both the 
        number and its double in the map. If it doesn't, it returns an empty array.

        Finally, it returns the result array, which represents the original array.
*/


/*
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        //odd length, return empty array
        if(n%2 != 0) {
            return {};
        }

        // sort the array
        sort(changed.begin(), changed.end());

        // creating a map for storing elments and freq of occurance
        unordered_map<int, int> mp;

        // store frequency of each number
        for(int &num : changed) {
            mp[num]++;
        }

        // result array
        vector<int> result;


        for ( int &num : changed) {
            int twice = 2 * num; //  finding twice

            // whenever the frequency of a number is zero, then skip that number
            if (mp[num] == 0) continue; // skip that number 

            // if number is present or frequency is not zero

            // check whether the twice is present or not or if it is present and frequency is zero, then return empty array 
            if(mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }

            // if above conditions are not satisfied, that means, twice are there 
            result.push_back(num);
            
            mp[num]--;
            mp[twice]--;
        }


        return result;
        
    }
};
*/

//Approach-1 (Using sorting and map)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        //odd length
        if(n%2 != 0) {
            return {};
        }
        
        sort(begin(changed), end(changed));
        
        map<int, int> mp;
        
        //store frequency of each number
        for(int &num : changed) {
            mp[num]++;
        }
        
        vector<int> result;
        
        for(int &num : changed) {
            int twice = 2*num;
            
            if(mp[num] == 0) continue; //skip
            
            if(mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }
            
            result.push_back(num);
            
            mp[num]--;
            mp[twice]--;
        }
        
        return result;
    }
};


//Approach-2 (Using sorting and Binary Search)

/*
    Approach-2 (Using sorting and Binary Search)

        It sorts the changed array in ascending order.
        
        It iterates through the changed array, and for each number, 
        it performs a binary search to find its double in the remaining 
        part of the array.

        If the double is found, it marks the found element as -1 (to avoid 
        duplicates) and adds the original number to the result array. If the 
        double is not found, it returns an empty array.

        Finally, it returns the result array, which represents the original array.
*/


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;
        
        sort(begin(changed), end(changed));
		/*
			Since I have sorted the array, so I will find the twice of a number
			If I get it, well and good, check further
			else, return {}
		*/
        for(int i = 0; i<n; i++) {
            int num = changed[i];
            if(num < 0) continue;
            
            auto idx = lower_bound(begin(changed)+i+1, end(changed), 2*num);
            
            if(idx != end(changed) && *idx == 2*num) {
                *idx = -1; //mark it
                result.push_back(num); //found it
            } else {
                return {}; //oooops
            }
        }
        
        return result;
    }
};

/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZfoOyJkD-lo
*/