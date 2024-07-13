/* Leetcode Problem No.: 1572. Matrix Diagonal Sum  */

/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/matrix-diagonal-sum/description/
*/



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = 0;

        auto lambda = [&] (int sum, vector<int> vec) {
            sum += vec[row];

            if (row != vec.size() - row - 1) {
                sum += vec[vec.size() - row -1];
            }
            row++;
            
            return sum;
        };

        int result = accumulate(begin(mat), end(mat), 0, lambda);

        return result;
    }
};



































/*
    Yt link: https://www.youtube.com/watch?v=kaBSTeurl_E&list=PLpIkg8OmuX-KtmrBzx-dAzRDp0xn_Xjls&index=2
*/