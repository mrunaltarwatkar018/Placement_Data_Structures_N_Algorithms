/* Leetcode Problem No.: 3093. Longest Common Suffix Queries */


/*
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/longest-common-suffix-queries/
*/


/************************************************************************* C++ ********************************************************************/
/*
    T.C : 
        Assuming m is the total number of characters in all words in wordsContainer, 
        the time complexity of the insertTrie method is O(m).

        Assuming n is the average length of words in wordsQuery, the time complexity of 
        the search method is O(n).

        T.C for stringIndices can be represented as O(m + n), where m is the total 
        number of characters in wordsContainer and n is the average length of words in 
        wordsQuery.

    S.C :
        Each node in the trie has an array of 26 pointers (assuming only lowercase 
        English alphabets), resulting in a space complexity of O(26 * m) for storing 
        all characters of words in wordsContainer. 
        m = total number of characters in all words in wordsContainer.
*/

/*
    Approach Summary : 

        The provided solution utilizes a trie data structure to efficiently store and 
        retrieve words from the `wordsContainer` array. The `insertTrie` method 
        constructs a trie by iteratively inserting characters of each word from the 
        `wordsContainer` array into the trie. Each node in the trie represents a 
        character, and the children of each node represent subsequent characters in the 
        word.

        The `search` method traverses the trie based on characters from a given word to 
        find the index of the longest word in the `wordsContainer` array that matches 
        the prefix of the given word. It updates the result index as it traverses the 
        trie, ensuring it holds the index of the longest word found so far.

        In the `stringIndices` method, the trie is constructed by calling `insertTrie` 
        for each word in `wordsContainer`. Then, it performs a search for each word in 
        the `wordsQuery` array, utilizing the constructed trie to find the appropriate 
        indices. The results are stored in an array and returned.

        The trie data structure efficiently stores words, facilitating quick retrieval 
        and comparison of prefixes. By traversing the trie, the solution identifies the 
        longest word that matches the prefix of each word in the `wordsQuery` array.
        
        The solution achieves a time complexity of O(m + n), where `m` is the total 
        number of characters in `wordsContainer` and `n` is the average length of words 
        in `wordsQuery`. The space complexity is influenced primarily by the trie 
        structure and the input and output arrays, resulting in a space complexity of O
        (m), where `m` is the total number of characters in `wordsContainer`.
*/




class Solution {
public:

    struct trieNode {
        int idx;
        trieNode* children[26];
    };

    trieNode* getNode(int i) {
        trieNode* temp = new trieNode();
        temp->idx = i;

        for(int i = 0; i<26; i++) {
            temp->children[i] = NULL;
        }
        return temp;
    }

    void insertTrie(trieNode* pCrawl, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.size();

        for(int j = n-1; j >= 0; j--) {
            int ch_idx = word[j] - 'a';

            if(pCrawl->children[ch_idx] == NULL) {
                pCrawl->children[ch_idx] = getNode(i);
            }
            pCrawl = pCrawl->children[ch_idx];
            
            if(wordsContainer[pCrawl->idx].size() > n) {
                pCrawl->idx = i;
            }
        }
    }

    int search(trieNode* pCrawl, string &word) {
        int result_idx = pCrawl->idx;
        int n = word.size();

        for(int i = n-1; i >= 0; i--) {
            int ch_idx = word[i]-'a';
            pCrawl = pCrawl->children[ch_idx];
            if(pCrawl == NULL) {
                return result_idx;
            }
            result_idx = pCrawl->idx;
        }
        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> result(n);

        trieNode* root = getNode(0);

        for(int i = 0 ; i < m; i++) {
            if(wordsContainer[root->idx].size() > wordsContainer[i].size()) {
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for(int i = 0; i < n; i++) {
            result[i] = search(root, wordsQuery[i]);
        }

        return result;
    }
};












































































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=jZX2Z5DKR2M
*/


/************************************************************************* JAVA ********************************************************************/
/*
    T.C : 
        Assuming m is the total number of characters in all words in wordsContainer, 
        the time complexity of the insertTrie method is O(m).

        Assuming n is the average length of words in wordsQuery, the time complexity of 
        the search method is O(n).

        T.C for stringIndices can be represented as O(m + n), where m is the total 
        number of characters in wordsContainer and n is the average length of words in 
        wordsQuery.

    S.C :
        Each node in the trie has an array of 26 pointers (assuming only lowercase 
        English alphabets), resulting in a space complexity of O(26 * m) for storing 
        all characters of words in wordsContainer. 
        m = total number of characters in all words in wordsContainer.
*/
class Solution {
    
    static class TrieNode {
        int idx;
        TrieNode[] children;

        TrieNode() {
            idx = -1; // Initialize with a default value
            children = new TrieNode[26];
        }
    }

    public TrieNode getNode(int idx) {
        TrieNode temp = new TrieNode();
        temp.idx = idx;

        for (int i = 0; i < 26; i++) {
            temp.children[i] = null;
        }
        return temp;
    }

    public void insertTrie(TrieNode pCrawl, int i, String[] wordsContainer) {
        String word = wordsContainer[i];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            int ch_idx = word.charAt(j) - 'a';

            if (pCrawl.children[ch_idx] == null) {
                pCrawl.children[ch_idx] = getNode(i);
            }
            pCrawl = pCrawl.children[ch_idx];

            if (wordsContainer[pCrawl.idx].length() > n) {
                pCrawl.idx = i;
            }
        }
    }

    public int search(TrieNode pCrawl, String word, String[] wordsContainer) {
        int result_idx = pCrawl.idx;
        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int ch_idx = word.charAt(i) - 'a';
            pCrawl = pCrawl.children[ch_idx];
            if (pCrawl == null) {
                return result_idx;
            }
            result_idx = pCrawl.idx;
        }
        return result_idx;
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        int m = wordsContainer.length;
        int n = wordsQuery.length;
        int[] result = new int[n];

        TrieNode root = getNode(0);

        for (int i = 0; i < m; i++) {
            if (wordsContainer[root.idx].length() > wordsContainer[i].length()) {
                root.idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            result[i] = search(root, wordsQuery[i], wordsContainer);
        }

        return result;
    }
}