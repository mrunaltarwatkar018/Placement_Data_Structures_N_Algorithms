/* GFG Problem: Kth Smallest */

/*
    Company Tags                : VMWare, Accolite, Amazon, Microsoft, Snapdeal, Hike, Adobe, Google, ABCO, Cisco
    GFG Link                    : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

// User function template for C++
class Solution {
    public:
    
    int kthSmallest(vector<int> &arr, int k) {
        // arr : given array
        // k : find kth smallest element and return using this function
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            k--;
            if(k==0) return i.first;
        }
        return 0;
    }
};




// Java Solution
class Solution {
    public static int kthSmallest(int[] arr, int k) {
        // Your code here
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
        }
        Set<Integer> set = new TreeSet<>(mp.keySet());
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()){
            k--;
            if(k==0) return it.next();
            it.next();
        }
        return 0;
    }
}
