/* Leetcode Problem No.: 648. Replace Words */

/*
    Company Tags                : UBER
    Leetcode Link               : https://leetcode.com/problems/replace-words
*/


//Know more about TRIE approach: - https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Trie/Replace%20Words.cpp


/*************************************************************************** C++ ******************************************************************************************/
// Approach (Using normal hashset and generating all substrings)
// T.C : o(n*l + m*l^2) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
// S.C : O(n*l)

class Solution {
public:
    string findRoot(string &word, unordered_set<string> st) {
        for (int l = 1; l <= word.length(); l++) { // O(l)
            string root = word.substr(0, l); // O(l)
            if (st.count(root)) { 
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        // store all words of a dictionary in a set
        unordered_set<string> st(begin(dictionary), end(dictionary)); // space: O(n) n : toatl words : total words = n * l

        // tokanization of a given sentence
        stringstream ss(sentence);
        string word;
        string result;

        while (getline(ss, word, ' ')) { // O(w*l*l)
            result += findRoot(word, st) + " ";
        }
        result.pop_back();

        return result;

    }
};

// or
class Solution {
public:

    string findRoot(string& word, unordered_set<string>& st) {

        //try all length substring starting from 0th index
        for(int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l);
            if(st.count(root)) {
                return root;
            }
        }

        return word;

    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result;

        while(getline(ss, word, ' ')) {
            result += findRoot(word, st) + " ";
        }

        result.pop_back();
        return result;

    }
};


/*************************************************************************** JAVA ******************************************************************************************/
//Approach (Using normal hashset and generating all substrings)
//T.C : o(n*l + m*l^2) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l)
class Solution {
    private String findRoot(String word, Set<String> st) {
        // Try all length substring starting from 0th index
        for (int l = 1; l <= word.length(); l++) {
            String root = word.substring(0, l);
            if (st.contains(root)) {
                return root;
            }
        }
        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> st = new HashSet<>(dictionary);
        
        StringBuilder result = new StringBuilder();
        String[] words = sentence.split(" ");
        
        for (String word : words) {
            result.append(findRoot(word, st)).append(" ");
        }
        
        // Remove the trailing space
        return result.toString().trim();
    }
}