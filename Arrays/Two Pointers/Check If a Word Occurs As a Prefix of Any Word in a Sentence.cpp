/* Leetcode Problem No.: 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
*/


// ---------------- C++  -------------------

//T.C : O(words * n), words = total number of words, n = length of searchWord
//S.C : O(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);

        string token = "";
        int index = 1;
        while(getline(ss, token, ' ')) {
            if(token.find(searchWord, 0) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};


// ---------------- JAVA -------------------
//T.C : O(words * n), words = total number of words, n = length of searchWord
//S.C : O(1)
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        
        for (int i = 0; i < words.length; i++) {
            if (words[i].startsWith(searchWord)) {
                return i + 1;
            }
        }

        return -1;
    }
}
