/* GFG Problem: Missing in Array */

/*
    Company Tags                : Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, D-E-Shaw, Ola Cabs, Payu, Visa, Intuit, Adobe, Cisco, Qualcommm TCS
    GFG Link                    : https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
*/





// C++ code  T.C =O(N) 


class Solution {
    public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        int x=0;
        for(auto z:arr)
            x^=z;
        for(int i=1;i<=n;i++)
            x^=i;
            
        return x;
    }
};

// C++ code  T.C =O(N) 


class Solution {
    public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        
        // Your code goes here
        int sum =0 , total;
        for(int i=0 ; i<arr.size(); i++){
            sum += arr[i];
        }
        total = n*(n+1)/2;
        return total -sum;
    }
};





// C++ code  T.C =O(N) 

class Solution {
    public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        long long sum = 0;
        for(auto &e : arr){
            sum += (long long)e;
        }
        long long desiredSum = (long long)n*(n + 1)/2LL;
        return desiredSum - sum;
    }
};