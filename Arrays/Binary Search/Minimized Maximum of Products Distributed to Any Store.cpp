/*    Leetcode Problem No.: 2064. Minimized Maximum of Products Distributed to Any Store  */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
*/


// TC: O(mlog(n)) = O(m*log(maxVaalue))

class Solution {
public:

    bool possibleToDistribute(int x, vector<int> & quantities, int shops) {
        for ( int &products : quantities ) {
            // n -= ciel(product/x);       ciel is very slow function so we can use its alternative
            shops -= (products + x - 1)/x;

            if (shops < 0) {
                return false;
            }
        }

        return true;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(begin(quantities), end(quantities));

        int result = 0;

        while ( l <= r ) {
            int mid = l + (r - l)/2;

            if (possibleToDistribute(mid, quantities, n)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};