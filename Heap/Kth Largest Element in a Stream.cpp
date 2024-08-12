/* Leetcode Problem No.: 703. Kth Largest Element in a Stream  */

/*
    Company Tags                : Amazon, Google, Meta, Adobe, Apple, Microsoft, Bloomberg, Uber, Atlassian, Box
    Leetcode Qn Link            : https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/


/*************************************************************** C++ ***************************************************************/
//Approach - (Using min-heap)
//T.C : O(n*logK)
//S.C : O(K)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};

// Other Approach

class KthLargest {
    PriorityQueue<Integer> pq;
    int k;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<>();
        for(int num : nums){
            add(num);
        }
    }
    
    public int add(int val) {
        if(pq.size()<k || val > pq.peek()){
            pq.offer(val);
            if(pq.size()>k){
                pq.poll(); 
            }
        }
        return pq.peek();
    }
}

/*
    Your KthLargest object will be instantiated and called as such:
    KthLargest obj = new KthLargest(k, nums);
    int param_1 = obj.add(val);
*/

/*************************************************************** JAVA ***************************************************************/
//Approach - (Using min-heap)
//T.C : O(n*logK)
//S.C : O(K)
class KthLargest {
    private PriorityQueue<Integer> pq;
    private int K;

    public KthLargest(int k, int[] nums) {
        K = k;
        pq = new PriorityQueue<>(K);

        for (int num : nums) {
            pq.offer(num);
            if (pq.size() > K) {
                pq.poll();
            }
        }
    }

    public int add(int val) {
        pq.offer(val);
        if (pq.size() > K) {
            pq.poll();
        }
        return pq.peek();
    }
}


























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bge5OCcXUk
*/