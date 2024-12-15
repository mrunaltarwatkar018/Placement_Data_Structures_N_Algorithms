/* Leetcode Problem No.: 2336. Smallest Number in Infinite Set */

/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/smallest-number-in-infinite-set/
*/



/*

The Time and Space Complexity : 
Let's assume :
---- The size of our set is  = n
---- No. of calls for popSmallest() = M
---- No. of calls for addBack() = L

Approach-1 - 
T.C :
popSmallest() - Suppose we popped element from 1 to n and then we added back 1. So, next time popSmallest() will be called, we will pop 1 and then loop again till the end i.e. n which takes O(n) time. And since, M calls are made - Total = O(M*n)

addBack() - takes O(1) time . And since L calls are made - Total = O(1*L) = O(L)

TOTAL = popSmallest() + addBack() = O(M*n) + O(L)

S.C : 
O(n) because we are assuming size of set is n (But you can also say your TC is O(1) because we have taken vector of fixed size 1001.)


Approach-2-
T.C : 
popSmallest() - We pop from min_heap which will take O(log(n)) where we assume all the n elements are in min_heap in worst case and hence it's size if n. And since, M calls are made - Total = O(M*log(n))

addBack() - takes O(log(n)) time because we push to min_heap which is logarithmic in operation. And since, L calls are made - Total = O(L*log(n))

TOTAL = popSmallest() + addBack()  = O(M*log(n)) + O(L*log(n))

S.C : 
O(n) - We take min_heap and unordered_set which can have size up to the size of total elements in set in worst case.


Approach-3-
T.C : 
popSmallest() - We pop from min_heap which will take O(log(n)) where we assume all the n elements are in min_heap in worst case and hence it's size if n. And since, M calls are made - Total = O(M*log(n))

addBack() - takes O(log(n)) time because we push to min_heap which is logarithmic in operation. And since, L calls are made - Total = O(L*log(n))

TOTAL = popSmallest() + addBack()  = O(M*log(n)) + O(L*log(n))

S.C : 
O(n) - We take min_heap and unordered_set which can have size up to the size of total elements in set in worst case.





In the 3rd approach inside pop function we can also use st.erase(result) instead of  st.erase(st.begin()) . both will work
*/





//Approach-1 (Using vector<bool> of size 1000 (after seeing the constraints)

class SmallestInfiniteSet {
public:

    vector<bool> nums; 
    int i; // current smallest ko point karega

    SmallestInfiniteSet() {
        nums = vector<bool> (1001, true);
        i = 1;
    }
    
    int popSmallest() {
        int result = i;
        nums[i] = false;
        // i++ nhi karenge 
        for (int j = i + 1; j < 1001; j++) {
            if (nums[j] == true) {
                i = j;
                break;
            }
        }
        return result;
    }
    
    void addBack(int num) {
        nums[num] = true;
        if (num < i) {
            i = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

// OR

class SmallestInfiniteSet {
public:
    vector<bool> nums;
    int i;
    
    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);
        i = 1;
    }
    
    int popSmallest() {
        
        int result = i;
        
        nums[i] = false;
        for(int j = i + 1; j < 1001; j++) {
            if(nums[j] == true) {
                i = j;
                break;
            }
        }
        
        return result;
        
    }
    
    void addBack(int num) {
        nums[num] = true;
        if(num < i) {
            i = num;
        }
    }
};


//Approach-2 (Using map + priority+queue + a variable to point to smallest num)
class SmallestInfiniteSet {
public:
    
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!pq.empty()) {
            result = pq.top();
            pq.pop();
            st.erase(result);
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
        pq.push(num);
    }
};


//Approach-3 (Using only ordered_set and a variable to point to smallest num)
class SmallestInfiniteSet {
public:
    set<int> st;
    
    int currSmallest;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!st.empty()) {
            result = *st.begin();
            st.erase(st.begin()); //or, st.erase(result) also works
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
    }
};