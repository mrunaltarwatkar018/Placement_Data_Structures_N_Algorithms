/* Leetcode Problem No.: 1301. Number of Paths with Max Score  */

/*
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-paths-with-max-score/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {

    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') 
            return {0, 1};   // reached end - no more coins, but found one path that reaches end - {0, 1}
        if (board[i][j] == 'X') 
            return {0, 0};   // dead end

        if (t[i][j] != make_pair(-1, -1))
            return t[i][j];

        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) {                 // move left
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) {             // move up-left (diagonal)
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        t[i][j] = {bestScore, bestPaths % MOD};
        return t[i][j];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }
    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        t.assign(n, vector<pair<int, int>>(n, {0, 0}));
        // t[i][j] = {best score, count of paths} to reach E from (i,j)

        // Base case
        t[0][0] = {0, 1};

        // Predecessors are up/left/up-left, so fill i,j INCREASING.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (board[i][j] == 'E') 
                    continue;
                if (board[i][j] == 'X') 
                    continue;

                int upScore = 0,   upPaths = 0;
                int leftScore = 0, leftPaths = 0;
                int diagScore = 0, diagPaths = 0;
                char ch = board[i][j];

                if (isValid(i - 1, j, board)) {              // move up
                    auto [score, paths] = t[i - 1][j];       //solve(i-1, j)
                    upScore = score;
                    upPaths = paths;
                    if (upPaths > 0)
                        upScore += getIntFromChar(ch);
                }
                if (isValid(i, j - 1, board)) {              // move left
                    auto [score, paths] = t[i][j - 1];       //solve(i, j-1)
                    leftScore = score;
                    leftPaths = paths;
                    if (leftPaths > 0)
                        leftScore += getIntFromChar(ch);
                }
                if (isValid(i - 1, j - 1, board)) {          // move up-left
                    auto [score, paths] = t[i - 1][j - 1];   //solve(i-1, j-1)
                    diagScore = score;
                    diagPaths = paths;
                    if (diagPaths > 0)
                        diagScore += getIntFromChar(ch);
                }

                int bestScore, bestPaths;
                if (upScore == leftScore && leftScore == diagScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                } else if (upScore == leftScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                } else if (leftScore == diagScore) {
                    bestScore = leftScore;
                    bestPaths = leftPaths + diagPaths;
                    if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                        bestScore = upScore; bestPaths = upPaths;
                    }
                } else {
                    bestScore = upScore; bestPaths = upPaths;
                    if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                        bestScore = leftScore; bestPaths = leftPaths;
                    }
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }

                t[i][j] = {bestScore, bestPaths % MOD};
            }
        }

        auto result = t[n - 1][n - 1]; //solve(n-1, n-1)
        return {result.first, result.second};
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    int MOD = 1_000_000_007;
    int[][] tScore;
    int[][] tPaths;

    private int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    private boolean isValid(int i, int j, List<String> board) {
        return i >= 0 && i < n && j >= 0 && j < n && board.get(i).charAt(j) != 'X';
    }

    private int[] solve(int i, int j, List<String> board) {
        char here = board.get(i).charAt(j);

        if (here == 'E')
            return new int[]{0, 1};
        if (here == 'X')
            return new int[]{0, 0}; 

        if (tScore[i][j] != -1)
            return new int[]{tScore[i][j], tPaths[i][j]};

        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = here;

        if (isValid(i - 1, j, board)) {
            int[] r = solve(i - 1, j, board);
            upScore = r[0];
            upPaths = r[1];
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) {
            int[] r = solve(i, j - 1, board);
            leftScore = r[0];
            leftPaths = r[1];
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) {
            int[] r = solve(i - 1, j - 1, board);
            diagScore = r[0];
            diagPaths = r[1];
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        tScore[i][j] = bestScore;
        tPaths[i][j] = (int)(((long) bestPaths) % MOD);
        return new int[]{tScore[i][j], tPaths[i][j]};
    }

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        tScore = new int[n][n];
        tPaths = new int[n][n];
        for (int[] row : tScore) Arrays.fill(row, -1);

        int[] result = solve(n - 1, n - 1, board);
        return new int[]{result[0], result[1]};
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    int MOD = 1_000_000_007;

    private int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    private boolean isValid(int i, int j, List<String> board) {
        return i >= 0 && i < n && j >= 0 && j < n && board.get(i).charAt(j) != 'X';
    }

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();

        int[][] tScore = new int[n][n];
        int[][] tPaths = new int[n][n];

        tScore[0][0] = 0;
        tPaths[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = board.get(i).charAt(j);

                if (ch == 'E') continue;
                if (ch == 'X') continue;

                int upScore = 0,   upPaths = 0;
                int leftScore = 0, leftPaths = 0;
                int diagScore = 0, diagPaths = 0;

                if (isValid(i - 1, j, board)) {              // move up
                    upScore = tScore[i - 1][j];
                    upPaths = tPaths[i - 1][j];
                    if (upPaths > 0)
                        upScore += getIntFromChar(ch);
                }
                if (isValid(i, j - 1, board)) {              // move left
                    leftScore = tScore[i][j - 1];
                    leftPaths = tPaths[i][j - 1];
                    if (leftPaths > 0)
                        leftScore += getIntFromChar(ch);
                }
                if (isValid(i - 1, j - 1, board)) {          // move up-left
                    diagScore = tScore[i - 1][j - 1];
                    diagPaths = tPaths[i - 1][j - 1];
                    if (diagPaths > 0)
                        diagScore += getIntFromChar(ch);
                }

                int bestScore, bestPaths;
                if (upScore == leftScore && leftScore == diagScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                } else if (upScore == leftScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                } else if (leftScore == diagScore) {
                    bestScore = leftScore;
                    bestPaths = leftPaths + diagPaths;
                    if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                        bestScore = upScore; bestPaths = upPaths;
                    }
                } else {
                    bestScore = upScore; bestPaths = upPaths;
                    if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                        bestScore = leftScore; bestPaths = leftPaths;
                    }
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }

                tScore[i][j] = bestScore;
                tPaths[i][j] = (int)(((long) bestPaths) % MOD);
            }
        }

        return new int[]{tScore[n - 1][n - 1], tPaths[n - 1][n - 1]};
    }
}