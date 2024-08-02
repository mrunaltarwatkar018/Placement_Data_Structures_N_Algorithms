/* Leetcode Problem No.: 2225. Find Players With Zero or One Losses  */

/*
    Company Tags                : Google, Indeed
    Leetcode Link               : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
*/


/************************************************************ C++ ************************************************************/

/*
    Approach Summary : 
        The solution uses an unordered map named lost to keep track of the 
        number of times each player has lost. It first iterates through the 
        matches to populate the lost map. Then, it iterates through the matches 
        again to identify players who have not lost (notLost) and players who 
        have lost only once (oneLos). The notLost players are those who either 
        have not lost any match or have not been encountered in the losing 
        position before. The oneLos players are those who have lost only once. 
        The final step involves sorting the notLost and oneLos vectors and 
        returning them as a vector of vectors containing the winners. In 
        summary, the approach focuses on tracking the number of losses for each 
        player, identifying players who have not lost or have lost only once, 
        and then presenting the sorted results.
*/


//T.C : O(n*logn)
//S.C : O(n)


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map; // key: Player Number, value: count of losses

        for ( int i = 0; i < matches.size(); i++ ) {
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        vector<int> notLost;
        vector<int> lostOnce;

        for ( int i = 0; i < matches.size(); i++ ) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if( lost_map.find(winner) == lost_map.end() ) {
                notLost.push_back(winner);
                lost_map[winner] = 2;
            }

            if ( lost_map[loser] == 1 ) {
                lostOnce.push_back(loser);
            }
        }

        sort(begin(notLost), end(notLost));
        sort(begin(lostOnce), end(lostOnce));

        return {notLost, lostOnce};
    }
};






// another simialr way
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        for(auto &it : matches) {
            int lose = it[1];
            lost[lose]++;
        }
        
        vector<int> notLost;
        vector<int> oneLos;
        
        for(auto &it : matches) {
            int lose = it[1];
            int win  = it[0];
            
            if(lost[lose] == 1) {
                oneLos.push_back(lose);
            }
            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;
            }
            
        }
        
        sort(begin(notLost), end(notLost));
        sort(begin(oneLos), end(oneLos));
        
        return {notLost, oneLos};
        
    }
};


/************************************************************ JAVA ************************************************************/
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> lost = new HashMap<>();

        for (int[] it : matches) {
            int lose = it[1];
            lost.put(lose, lost.getOrDefault(lose, 0) + 1);
        }

        List<Integer> notLost = new ArrayList<>();
        List<Integer> oneLos = new ArrayList<>();

        for (int[] it : matches) {
            int lose = it[1];
            int win = it[0];

            if (lost.get(lose) == 1) {
                oneLos.add(lose);
            }
            if (!lost.containsKey(win)) {
                notLost.add(win);
                lost.put(win, 2);
            }
        }

        Collections.sort(notLost);
        Collections.sort(oneLos);

        return Arrays.asList(notLost, oneLos);
    }
}



















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bXptmD2qWYI
*/