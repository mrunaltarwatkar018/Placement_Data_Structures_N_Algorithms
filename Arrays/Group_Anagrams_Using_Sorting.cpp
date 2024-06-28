/* Leetcode Problem No.: 49. Group Anagram  */

/*
    Company Tags                : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, 
                                    Twilio, Affirm
    Leetcode Link               : https://leetcode.com/problems/group-anagrams/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/

/************************************************************** C++ **************************************************************/

/*
    Approach Summary : (Using Sorting)

        Simply sort the strings and store them in a map in which the key is the
        sorted string and the values are the original strings whose sorted
        versions are same (Anagram). Then collect those values and return as a
        result. The result is a list of lists, where each inner list represents a
        group of anagrams.
*/

//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)




// one way
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for (auto& it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};


// another way

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto str:strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};




/*
        Approach-2 Summary :  Without Sorting

            It utilizes a hash map to categorize strings based on their
            character frequencies. The generate method converts a string into a 
            unique representation by counting the occurrences of each character and
            creating a sorted string. The main groupAnagrams function iterates 
            through the input strings, generates their unique representations, and 
            uses the hash map to group anagrams together. The result is a list of 
            lists, where each inner list represents a group of anagrams.
*/

// Approach-2:
// T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input
// vector) S.C : O(n*k)

// one way

class Solution {
public:

    string generate(string &word) {
        int count[26] = {0};

        for (char &ch: word) {
            count[ch-'a']++;   // for index, ch-'a'
        }

        string new_word = "";

        for(int i = 0; i < 26; i++) {
            int freq = count[i];
            if (freq > 0) {
                new_word += string(freq, i + 'a'); // for element, i + 'a'
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for ( int i = 0; i < n; i++) {
            string word = strs[i];
            string new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for (auto &it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};




// another way

class Solution {
public:
    
    string generate(string &s) {
        int count[26] = {0};
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        string new_s;
        
        for(int i = 0; i<26; i++) {
            
            if(count[i] > 0) {
                new_s += string(count[i], i+'a');
            }
        }
        
        return new_s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string new_s = generate(s);
            
            mp[new_s].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(std::move(it.second));
        }
        
        return result;
        
    }
};


/************************************************************** JAVA **************************************************************/
//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);

            if (!map.containsKey(sortedStr)) {
                map.put(sortedStr, new ArrayList<>());
            }

            map.get(sortedStr).add(str);
        }

        return new ArrayList<>(map.values());
    }
}


//Approach-2
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
    private String generate(String s) {
        int[] count = new int[26];

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        StringBuilder newS = new StringBuilder();

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                newS.append(String.valueOf((char) (i + 'a')).repeat(count[i]));
            }
        }

        return newS.toString();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            String newS = generate(s);

            if (!map.containsKey(newS)) {
                map.put(newS, new ArrayList<>());
            }

            map.get(newS).add(s);
        }

        return new ArrayList<>(map.values());
    }
}





/*
YOUTUBE VIDEO ON THIS Qn :  Using Sortng     - https://www.youtube.com/watch?v=--k5-3EOObs&t=2s
                            Without Sorting  - https://www.youtube.com/watch?v=TNe3gF4r128&t=1s
*/