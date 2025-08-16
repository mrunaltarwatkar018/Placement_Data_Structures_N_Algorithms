/*    GFG Problem. Sum of Query II    */

/*
    Company Tags                : AMAZON
    GfG Link                    : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
*/


/************************************************************************ C++ ************************************************************************/

/*
    Summary : 
        In this video, We see how we can use Segment Tree concepts to easily solve this problem - Query Sum II. 
        This code implements a segment tree data structure to efficiently compute range sum queries on an array. 
        The buildSegmentTree function constructs the segment tree recursively from the input array, where each node 
        stores the sum of a segment of the array. The querySegmentTree function performs range sum queries on the 
        segment tree. The querySum function initializes the segment tree and iterates through a list of queries to 
        compute and return the sum for specified ranges in the array. Overall, this approach ensures that both 
        construction of the segment tree and querying for sums are handled efficiently with O(logn) time complexity 
        per query after an O(n) initial setup time, making it suitable for scenarios requiring frequent range sum 
        computations on static arrays.
*/


//NOTE - Since this is Range Sum Query, you can simply solve it using Prefix Sum Array as well. But this is segment tree repo, so I have mentioned Segment tree approach
//Using Segment Tree
//T.C : O(q*log(n))
//S.C : O(4*n)
class Solution{
public:
    
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
        if(l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }
    
    int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        if(l > end || r < start) {
            return 0;
        }
        
        if(l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid, segmentTree) + 
                querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<int> segmentTree(4*n);
        
        buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        vector<int> result;
        for(int i = 0; i < 2*q; i+=2) {
            int start = queries[i]-1;   //Input is in 1 base indexing
            int end   = queries[i+1]-1; //Input is in 1 based indexing
            
            result.push_back(querySegmentTree(start, end, 0, 0, n-1, segmentTree));
        }
        
        return result;
        
    }
};




/************************************************************************ JAVA ************************************************************************/
//NOTE - Since this is Range Sum Query, you can simply solve it using Prefix Sum Array as well. But this is segment tree repo, so I have mentioned Segment tree approach
//Using Segment Tree
//T.C : O(q*log(n))
//S.C : O(4*n)
class Solution{
    void buildSegmentTree(int i, int l, int r, int[] segmentTree, int[] arr) {
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    
    int querySegmentTree(int start, int end, int i, int l, int r, int[] segmentTree) {
        if (l > end || r < start) {
            return 0;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l) / 2;
        return querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree) + 
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree);
    }
    
    List<Integer> querySum(int n, int[] arr, int q, int[] queries) {
        int[] segmentTree = new int[4 * n];
        
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < 2 * q; i += 2) {
            int start = queries[i] - 1;   // Input is in 1-based indexing
            int end = queries[i + 1] - 1; // Input is in 1-based indexing
            
            result.add(querySegmentTree(start, end, 0, 0, n - 1, segmentTree));
        }
        
        return result;
    }
}




/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VJ67kQHYbv8
*/