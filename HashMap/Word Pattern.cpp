/* Leetcode Problem No.: 290. Word Pattern  */

/*
    Company Tags			: Amazon, MakeMyTrip, Microsoft
	Leetcode Link 			: https://leetcode.com/problems/word-pattern/
*/


//Approach-1 (using map and set)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);

        string token;
        int countWords = 0;

        while(getline(ss, token, ' ')) {
            words.push_back(token);
            countWords++;
        }

        int n = pattern.length();
        if (n != countWords) {
            return false;
        }


        unordered_map <string, char> mp;
        set<char> used;

        for (int i = 0; i < n; i++ ) {
            string word = words[i];
            char ch = pattern[i];

            if (mp.find(word) == mp.end() && used.find(ch) == used.end()) {
                used.insert(ch);
                mp[word] = ch;
            } else if (mp[word] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};



// Or
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> temp;
        stringstream ss(s);
        string token;
        int count = 0;
        while(getline(ss, token, ' ')) {
            temp.push_back(token);
            count++;
        }
            
            int n = pattern.size();
            
            if (count != n) 
                return false;
            
            unordered_map<string, char> mp;
            set<char> used;
            for (int i = 0; i < n; i++)
            {
                if (mp.find(temp[i]) == mp.end() && used.find(pattern[i]) == used.end()) {
                    used.insert(pattern[i]);
                    mp[temp[i]] = pattern[i];
                }
                else if (mp[temp[i]] != pattern[i]) {
                    return false;
                }
            }
            return true;
    }
};


//Approach-2 (map of char/word to index+1)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;
        
        stringstream ss(s);
        string token;
        int countTokens = 0;
        int i = 0; 
        int n = pattern.size();
        
        while(ss >> token) {
            countTokens++;
            
            if (i == n || charToIndex[pattern[i]] != wordToIndex[token])
                return false;
            
            charToIndex[pattern[i]] = wordToIndex[token] = i+1; 
            /*
                Why i+1 ?
                Because by default, if the key is not in map, it's value is returned as 0
                Dry-run this :
                "abba"
                "dog cat cat fish"

            */
            
            i++;
        }
        
        if(countTokens != pattern.size() || i != n)
            return false;
        
        return true;
    }
};






// or

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;

        stringstream ss(s);
        string token;
        
        int countTokens = 0;
        int i = 0;
        int n = pattern.size();

        while (ss >> token) {
            countTokens++;

            if ( i == n || charToIndex[pattern[i]] != wordToIndex[token]) {
                return false;
            }

            charToIndex[pattern[i]] = i + 1;
            wordToIndex[token] = i + 1;

            i++;
        }

        if (countTokens != n || i != n) {
            return false;
        }

        return true;
    }
};