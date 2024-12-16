/* Leetcode Problem No.: 823. Binary Trees With Factors  */

/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/binary-trees-with-factors/
*/


/************************************************ C++ ************************************************/
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            int root = arr[i];
            mp[root] = 1;
            for (int j = 0; j < i; j++) {
                int leftChild = arr[j];
                // RootChild = arr[i] / leftChild
                if (root % leftChild == 0 && mp.find(arr[i] / leftChild) != mp.end()) {
                    mp[root] += mp[leftChild] * mp[arr[i]/leftChild];
                }

            }
        }
        long result = 0;
        // in map we have two values i.e, value and number of ways of binary trees to be formed 
        for (auto &it : mp) {
            // it.first = value
            // it.second = ways
            result = (result + it.second) % MOD;
        }
        return result;
    }
};


// or
class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;
        
        for(int i = 1; i<n; i++) {
            
            long long count = 1;
            
            for(int j = 0; j < i; j++) {
                int v = arr[j];
                if(arr[i]%v == 0 && mp.find(arr[i]/v) != mp.end()) {
                    
                    count += (mp[v] * mp[arr[i]/v]);
                    
                }
                
            }
            
            mp[arr[i]] = count;
            
        }
        
        int result = 0;
        for(auto &it : mp){
            result = (result + it.second) % MOD;
        }
        return result;
    }
};



/************************************************ JAVA ************************************************/
//T.C : O(n^2)
//S.C : O(n)
public class Solution {
    private static final int MOD = 1000000007;

    public int numFactoredBinaryTrees(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);

        Map<Integer, Long> mp = new HashMap<>();
        mp.put(arr[0], 1L);

        for (int i = 1; i < n; i++) {
            long count = 1;

            for (int j = 0; j < i; j++) {
                int v = arr[j];
                if (arr[i] % v == 0 && mp.containsKey(arr[i] / v)) {
                    count += (mp.get(v) * mp.get(arr[i] / v)) % MOD;
                    count %= MOD;
                }
            }

            mp.put(arr[i], count);
        }

        int result = 0;
        for (long val : mp.values()) {
            result = (int) ((result + val) % MOD);
        }
        return result;
    }
}