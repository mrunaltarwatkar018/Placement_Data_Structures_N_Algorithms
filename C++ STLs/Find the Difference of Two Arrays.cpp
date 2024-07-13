/* Leetcode Problem No.: 2215. Find the Difference of Two Arrays  */

/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/find-the-difference-of-two-arrays/
*/



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // First, put all unique elements from nums1 in set1
        set<int> st1(begin(nums1), end(nums1));

        // Than, put all unique elements from nums2 in set2
        set<int> st2(begin(nums2), end(nums2));

        vector<int> v1;
        vector<int> v2;
        // we will return {v1, v2}

        /*
            set_difference -> This STL copies the elements from the sorted s1 which are not found in the stored s2 to a container in sorted order

            back_inserter -> This STL can be used to add elements to the end of a container
        */

        // Find the difference in between sel1 and set2 and put unique elemenst of set1 into v1
        set_difference(begin(st1), end(st1), begin(st2), end(st2), back_inserter(v1));
        
        // Find the difference in between sel2 and set1 and put unique elemenst of set2 into v2
        set_difference(begin(st2), end(st2), begin(st1), end(st1), back_inserter(v2));

        return {v1, v2};
    }
};



































/*
    Yt link : https://www.youtube.com/watch?v=FZ1J7tRj71w&list=PLpIkg8OmuX-KtmrBzx-dAzRDp0xn_Xjls&index=1&t=1s
*/