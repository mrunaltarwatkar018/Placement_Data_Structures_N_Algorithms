/* GFG Problem No.: Alien Dictionary   */

/*
    Company Tags                : Flipkart, Amazon, Microsoft, OYO Rooms, Walmart, Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/alien-dictionary/1
*/



class Solution
{
public:
    string findOrder(string dict[], int N, int k)
    {
        vector<vector<int>> mat(k, vector<int>(k));
        for (int i = 0; i + 1 < N; i++) {
            string &a = dict[i], &b = dict[i + 1];
            int n = a.size(), m = b.size(), j = 0;
            while (j < n and j < m and a[j] == b[j])
                j++;
            if (j < n and j < m)
                mat[a[j] - 'a'][b[j] - 'a'] = 1;
        }
        vector<int> vis(k);
        string ans;
        auto fun = [&](auto self, int u) -> void {
            vis[u] = true;
            for (int v = 0; v < k; v++)
                if (mat[u][v] and !vis[v])
                    self(self, v);
            ans.push_back('a' + u);
        };
        for (int i = 0; i < k; i++)
            if (!vis[i])
                fun(fun, i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};