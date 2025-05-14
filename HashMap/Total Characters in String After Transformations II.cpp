/*    Leetcode Problem Nco.: 3337. Total Characters in String After Transformations II  */

/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/total-characters-in-string-after-transformations-ii
*/

/************************************************************ C++ *****************************************************/
//Approach - Using matrix exponentiation on a 26×26 character-transition matrix
//T.C : O(26^3 logt) ≈ O(logt) (with a 26^3 constant factor).
//S.C : O(26^2)=O(1) (constant space with respect to s and t)
class Solution {
public:
    static const int M = 1e9+7;
    using ll = long long;

    // multiply two 26×26 matrices mod M
    vector<vector<ll>> mul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
        vector<vector<ll>> C(26, vector<ll>(26, 0));
        for(int i = 0; i < 26; i++) {
            for(int k = 0; k < 26; k++) {
                ll aik = A[i][k];
                if (!aik) continue;
                for(int j = 0; j < 26; j++) {
                    C[i][j] = (C[i][j] + aik * B[k][j]) % M;
                }
            }
        }
        return C;
    }

    // exponentiate a 26×26 matrix to power e
    vector<vector<ll>> matPow(vector<vector<ll>> T, long long e) {
        vector<vector<ll>> R(26, vector<ll>(26, 0));
        for(int i = 0; i < 26; i++) R[i][i] = 1;
        while(e > 0) {
            if(e & 1) R = mul(R, T);
            T = mul(T, T);
            e >>= 1;
        }
        return R;
    }

    int lengthAfterTransformations(string s, long long t, vector<int>& nums) {
        // 1) build transition matrix T
        vector<vector<ll>> T(26, vector<ll>(26, 0));
        for(int i = 0; i < 26; i++) {
            int cnt = nums[i];
            for(int k = 1; k <= cnt; k++) {
                int j = (i + k) % 26;
                T[j][i] = (T[j][i] + 1) % M;
            }
        }

        // 2) raise T to the t-th power
        auto P = matPow(T, t);

        // 3) initial frequency vector
        vector<ll> freq(26, 0);
        for(char c : s) freq[c - 'a']++;

        // 4) multiply P by freq to get final_freq
        vector<ll> final_freq(26, 0);
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                final_freq[i] = (final_freq[i] + P[i][j] * freq[j]) % M;
            }
        }

        // 5) sum up
        ll ans = 0;
        for(int i = 0; i < 26; i++) {
            ans = (ans + final_freq[i]) % M;
        }
        return (int)ans;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach - Using matrix exponentiation on a 26×26 character-transition matrix
//T.C : O(26^3 logt) ≈ O(logt) (with a 26^3 constant factor).
//S.C : O(26^2)=O(1) (constant space with respect to s and t)
class Solution {
    private static final int MOD = 1_000_000_007;
    private static final int ALPHABET = 26;

    // Multiply two 26×26 matrices A and B modulo MOD
    private long[][] mul(long[][] A, long[][] B) {
        long[][] C = new long[ALPHABET][ALPHABET];
        for (int i = 0; i < ALPHABET; i++) {
            for (int k = 0; k < ALPHABET; k++) {
                long aik = A[i][k];
                if (aik == 0) continue;
                for (int j = 0; j < ALPHABET; j++) {
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Exponentiate a 26×26 matrix T to the e-th power
    private long[][] matPow(long[][] T, long e) {
        long[][] R = new long[ALPHABET][ALPHABET];
        // initialize R = identity
        for (int i = 0; i < ALPHABET; i++) {
            R[i][i] = 1;
        }
        while (e > 0) {
            if ((e & 1) == 1) {
                R = mul(R, T);
            }
            T = mul(T, T);
            e >>= 1;
        }
        return R;
    }

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        // 1) Build transition matrix T[j][i]:
        //    how many of old-char i map to new-char j in one step
        long[][] T = new long[ALPHABET][ALPHABET];
        for (int i = 0; i < ALPHABET; i++) {
            int cnt = nums.get(i);
            for (int k = 1; k <= cnt; k++) {
                int j = (i + k) % ALPHABET;
                T[j][i] = (T[j][i] + 1) % MOD;
            }
        }

        // 2) Raise T to the t-th power
        long[][] P = matPow(T, t);

        // 3) Compute initial frequency vector
        long[] freq = new long[ALPHABET];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // 4) Multiply P by freq to get final_freq
        long[] finalFreq = new long[ALPHABET];
        for (int i = 0; i < ALPHABET; i++) {
            for (int j = 0; j < ALPHABET; j++) {
                finalFreq[i] = (finalFreq[i] + P[i][j] * freq[j]) % MOD;
            }
        }

        // 5) Sum up final frequencies
        long ans = 0;
        for (long v : finalFreq) {
            ans = (ans + v) % MOD;
        }
        return (int) ans;
    }
}
