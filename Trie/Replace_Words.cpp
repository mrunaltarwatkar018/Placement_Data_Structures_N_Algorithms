/* Leetcode Problem No.: 3093. Replace Words */

/*
    Company Tags                : UBER
    Leetcode Link               : https://leetcode.com/problems/replace-words
*/


/*************************************************************************** C++ ******************************************************************************************/

/*
    Summary : 

        TrieNode Class: This inner class represents a node in the trie. Each node has 
        an array of 26 children (one for each lowercase English letter) and a boolean 
        isEndOfWord to mark the end of a word.

        Solution Constructor: Initializes the root of the trie.

            Insert Method: 
                Inserts a word into the trie by traversing each character and creating 
                new TrieNode objects as necessary.

            Search Method: 
                Searches for the shortest prefix in the trie that matches the start of 
                the given word. If no such prefix is found, it returns the original 
                word.

            ReplaceWords Method: 
                Takes a list of dictionary words and a sentence. It first inserts all 
                dictionary words into the trie. Then, it splits the sentence into 
                words, searches for each word in the trie, and builds the resulting 
                sentence with replaced words.

                This Java implementation should match the functionality of your 
                original C++ code.
*/

//Using Trie
//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)
class Solution {
public:
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }

            
    trieNode* root;

    /* Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return word; 
            crawler = crawler->children[index];
            if(crawler->isEndOfWord) {
                return word.substr(0, i+1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);
        string word;
        string result;
        root = getNode();
        for (string word : dictionary) {
            insert(word);
        }

        while(getline(ss, word, ' ')) {
            result += search(word) + " ";
        }

        result.pop_back();
        return result;
    }
};












































/* 
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FxmFhwmKumU
*/

/*************************************************************************** JAVA ******************************************************************************************/
//Using Trie
//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)
import java.util.List;
import java.util.StringTokenizer;
import java.util.StringJoiner;

class Solution {
    class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;

        TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
    }

    TrieNode root;

    public Solution() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null) {
                crawler.children[index] = new TrieNode();
            }
            crawler = crawler.children[index];
        }

        crawler.isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    public String search(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null) {
                return word;
            }
            crawler = crawler.children[index];
            if (crawler.isEndOfWord) {
                return word.substring(0, i + 1);
            }
        }
        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        for (String word : dictionary) {
            insert(word);
        }

        StringTokenizer st = new StringTokenizer(sentence);
        StringJoiner sj = new StringJoiner(" ");
        
        while (st.hasMoreTokens()) {
            String word = st.nextToken();
            sj.add(search(word));
        }

        return sj.toString();
    }
}