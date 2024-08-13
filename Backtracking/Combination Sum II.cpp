/* Leetcode Problem No.: 40. Combination Sum II  */

/*
    Company Tags                : Adobe, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/combination-sum-ii/
*/


/******************************************************** C++ ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n)
//S.C : O(n)

/*
    Summary :
        The provided approach is designed to find all unique combinations of 
        numbers in a given array (candidates) that sum up to a specified target 
        (target). The core idea is to use a backtracking algorithm, which explores 
        potential combinations by building up partial solutions and discarding them 
        if they don't lead to a valid solution.

        Key Steps:

            Sorting the Input:

                The candidates array is first sorted to facilitate the identification and 
                skipping of duplicate elements, ensuring that only unique combinations 
                are considered.

            Recursive Backtracking:

                The solve function is called recursively, exploring different combinations by 
                including or excluding each candidate.

                It starts from the current index (idx) and adds elements to the current 
                combination (curr). If the remaining target becomes zero, the current 
                combination is valid and added to the result.

                If the target becomes negative, the current path is discarded as it 
                cannot produce a valid combination.

            Avoiding Duplicates:

                Within the loop, if a candidate is the same as the previous one, it is 
                skipped to avoid generating duplicate combinations.

            Base Cases:

                The recursion terminates when the target becomes zero (valid combination) 
                or negative (invalid path).

            The algorithm efficiently generates all unique combinations that sum up to the 
            target by leveraging sorting and careful pruning of the search space.
*/


class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        solve(candidates, target, curr, result, 0);
        return result;
    }
};



/******************************************************** JAVA ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n)
//S.C : O(n)
class Solution {
    public void solve(int[] candidates, int target, List<Integer> curr, List<List<Integer>> result, int idx) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.add(new ArrayList<>(curr));
            return;
        }
        
        for (int i = idx; i < candidates.length; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue; // Ignore duplicate elements
            }
            curr.add(candidates[i]);
            solve(candidates, target - candidates[i], curr, result, i + 1);
            curr.remove(curr.size() - 1);
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        Arrays.sort(candidates); // Sort to handle duplicates
        solve(candidates, target, curr, result, 0);
        return result;
    }
}

















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bfKwLi6jtDk
*/