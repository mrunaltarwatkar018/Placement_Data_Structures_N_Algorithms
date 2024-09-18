/*    Leetcode Problem No.: 884. Uncommon Words from Two Sentences    */

/*
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17
*/


/*************************************************************************** C++ ******************************************************************************************/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        
        stringstream ss1(s1);
        string token = "";
        
        while(ss1 >> token) 
            mp[token]++;
        
        stringstream ss2(s2);
        
        while(ss2 >> token)
            mp[token]++;
        
        vector<string> result;
        for(auto &it : mp) {
            if(it.second == 1)
                result.push_back(it.first);
        }
        
        return result;
    }
};
