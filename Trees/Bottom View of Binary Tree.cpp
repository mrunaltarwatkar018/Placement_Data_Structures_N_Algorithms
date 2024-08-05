/* GFG Problem No.: Bottom View of Binary Tree   */

/*
    Company Tags                : Paytm, Flipkart, Accolite, Amazon, OYO Rooms, Walmart, CouponDunia
    GFG Link                    : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/


class Solution {
public:

    void solve(Node *root,int x,int y,map<int,pair<int,int>>& mp){
        //base case
        if(root==NULL){
            return;
        }
        if(mp.find(x) == mp.end() || mp[x].first<=y)
        mp[x]={y,root->data};
        solve(root->left,x-1,y+1,mp);
        solve(root->right,x+1,y+1,mp);
    }


    vector <int> bottomView(Node *root) {
        
        map<int,pair<int,int>> mp;
        solve(root,0,0,mp);
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second.second);
        }
        return ans;
    }
};