/* Leetcode Problem No.: 2053. Kth Distinct String in an Array */

/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
*/


/************************* C++ *************************/
// Approach-1 (Using Brute Force)
// T.C : O(n^2)
// S.C : O(1)
class Solution {
public:

    int frquencyOfString(vector<string>& arr, const string& findStr) {
        int count = 0;
        for(string &s : arr) {
            if(s == findStr) { //I have ignore the time taken for this comparison
                count++;
            }
            if(count > 1) {//return early
                return count;
            }
        }

        return count;
    }

    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        
        int count = 0;
        for(string &s : arr) {
            if(frquencyOfString(arr, s) == 1) {
                count++;
                if(count == k) {
                    return s;
                }
            }
        }

        return "";
    }
};


//Approach-2 (Using unordered_set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> st;
        unordered_set<string> unique;

        for(string &s : arr) {
            
            if(st.find(s) != st.end()) {
                continue;
            }

            if(unique.find(s) != unique.end()) {
                unique.erase(s);
                st.insert(s);
            } else {
                unique.insert(s);
            }
        }

        int count = 0;
        for(string &s : arr) {
            if(unique.find(s) != unique.end()) {
                count++;
            }
            if(count == k) {
                return s;
            }
        }

        return "";
    }
};


//Approach-3 (Using Hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(string &s : arr) {
            mp[s]++;
        }

        int count = 0;
        for(string &s : arr) {
            if(mp[s] == 1) {
                count++;
                if(count == k) {
                    return s;
                }
            }
        }

        return "";
    }
};












/************************* JAVA *************************/

// hashset
class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashSet<String> distinct = new HashSet<>();
        HashSet<String> duplicate = new HashSet<>();
        for(String str : arr){
            if(duplicate.contains(str)){
                continue;
            }
            if(distinct.contains(str)){
                distinct.remove(str);
                duplicate.add(str);
            }else{
                distinct.add(str);
            }
        }
        for(String str : arr){
            if(!duplicate.contains(str)){
                k--;
            }
            if(k==0){
                return str;
            }
        }
        return "";
    }
}

// hashmap
class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String,Integer> freqMap = new HashMap<>();
        for(String str : arr){
            freqMap.put(str,freqMap.getOrDefault(str,0)+1);
        }
        for(String str : arr){
            if(freqMap.get(str)==1){
                k--;
            }
            if(k==0){
                return str;
            }
        }
        return "";
    }
}