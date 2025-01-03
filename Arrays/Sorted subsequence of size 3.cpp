/* GFG Problem: Sorted subsequence of size 3 */

/*
    Company Tags                : Amazon, FactSet, Walmart
    GFG Link                    : https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1
*/

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> small(n, INT_MAX);
        vector<int> big(n, INT_MIN);
        small[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            small[i] = min(arr[i], small[i - 1]);
        }
        big[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            big[i] = max(arr[i], big[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > small[i] && arr[i] < big[i])
            {
                return {small[i], arr[i], big[i]};
            }
        }
        return {};
    }
};