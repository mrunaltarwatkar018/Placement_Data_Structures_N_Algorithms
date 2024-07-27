/* Leetcode Problem No.: 990. Satisfiability of Equality Equations  */

/*
        Company Tags                : GOOGLE
        Leetcode Link               : https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

// Appraoch: Using DSU



class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i = 0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        // First do union of equal (=) chars 
        for ( string &s : equations ) {
            if ( s[1] == '=') { // case: "a" == "b"
                Union(s[0]-'a', s[3]-'a');
            }
        }

        // Find != wale cases and check validity
        for(string &s : equations) {
            if(s[1] == '!') { // case: "a" != "b"
                char first = s[0]; // a
                char second = s[3]; // b

                int parent_of_first = find(first - 'a');
                int parent_of_second = find(second - 'a');

            
                if(parent_of_first == parent_of_second) {
                    return false;
                }
            }
        }
        return true;
    }
};














// another similar appraoch
class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i = 0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        // First do union of equal (=) chars 
        for ( string &s : equations ) {
            if ( s[1] == '=') { // case: "a" == "b"
                Union(s[0]-'a', s[3]-'a');
            }
        }

        // Find != wale cases and check validity
        for(string &s : equations) {
            if(s[1] == '!') { // case: "a" != "b"
                if(find(s[0]-'a') == find(s[3]-'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};




















/*
        YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0Z8lt7U_kiE
*/