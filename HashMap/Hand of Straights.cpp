/* Leetcode Problem No.: 846. Hand of Straights */

/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/hand-of-straights
*/


// Approach (Simply using map)
// T.C  : O(nlogn) + O(n*groupSize)
// S.C  : O(n)
class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();

        // Step 1: Check if grouping is possible
        if (n % groupSize) {
            return false;
        }

        // Step 2: Count the occurrences of each card
        map<int, int> mp;
        for (int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        // Step 3: itereate on map unitl map becomes empty
        while (!mp.empty()) { //O(n*groupSize)
            int curr = mp.begin() -> first; // -> second : frequency
            // curr +1, curr + 2, curr + 3, .....
            for (int i = 0; i < groupSize; i++) {
                // curr + i = curr, curr + 1, curr + 2, ....
                if (mp[curr + i] == 0) {
                    return false;
                }
                mp[curr + i]--;
                if (mp[curr + i] < 1) {
                    mp.erase(curr + i);
                }
            }
        }
        // Step 4: Return true if all groups are formed successfully
        return true;
    }
};

// or
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        while(!mp.empty()) { //O(n*groupSize)

            int curr = mp.begin()->first; //->second : frequency

            for(int i = 0; i < groupSize; i++) {
                if(mp[curr + i] == 0) {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }

        }

        return true;
        
    }
};


//Approach (Simply using map)
//T.C  : O(nlogn) + O(n*groupSize)
//S.C  : O(n)
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;

        if (n % groupSize != 0) {
            return false;
        }

        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int card : hand) {
            map.put(card, map.getOrDefault(card, 0) + 1);
        }

        while (!map.isEmpty()) {
            int curr = map.firstKey();

            for (int i = 0; i < groupSize; i++) {
                if (!map.containsKey(curr + i)) {
                    return false;
                }

                map.put(curr + i, map.get(curr + i) - 1);
                if (map.get(curr + i) == 0) {
                    map.remove(curr + i);
                }
            }
        }

        return true;
    }
}









































// another 
class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // Step 1: Check if grouping is possible
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Step 2: Count the occurrences of each card
        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Step 3: Sort the unique card values
        std::vector<int> sortedKeys;
        for (auto& pair : count) {
            sortedKeys.push_back(pair.first);
        }
        std::sort(sortedKeys.begin(), sortedKeys.end());

        // Step 4: Form consecutive groups
        for (int key : sortedKeys) {
            if (count[key] > 0) {  // If this card is still available
                int startCount = count[key];
                // Check and form a group starting from `key`
                for (int i = key; i < key + groupSize; i++) {
                    if (count[i] < startCount) {
                        return false;
                    }
                    count[i] -= startCount;
                }
            }
        }

        // Step 5: Return true if all groups are formed successfully
        return true;
    }
};