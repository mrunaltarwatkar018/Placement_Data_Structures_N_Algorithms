/* GFG Problem : Maximum Perimeter of Triangle from array */

/*
    Company Tags                : C3.ai
    Leetcode Link               : https://www.geeksforgeeks.org/problems/maximum-perimeter-of-triangle-from-array4322/1

*/
// Similar Question on Leetcode: Largest Perimeter Triangle https://leetcode.com/problems/largest-perimeter-triangle/





int maxPerimeter(int arr[], int n){
    sort(arr, arr + n); // Use sort function from algorithm library
    
    for (int i = n - 3; i >= 0; i--) {
        if (arr[i] + arr[i+1] > arr[i+2] && arr[i] + arr[i+2] > arr[i+1] && arr[i+1] + arr[i+2] > arr[i]) { 
            return arr[i] + arr[i+1] + arr[i+2];
        }
    }
    return 0;
}


int maxPerimeter(int arr[], int n){
    sort(arr, arr + n); // Use sort function from algorithm library
    
    for (int i = n - 3; i >= 0; i--) {
        if (arr[i] + arr[i+1] > arr[i+2] && arr[i] + arr[i+2] > arr[i+1] && arr[i+1] + arr[i+2] > arr[i]) { 
            return arr[i] + arr[i+1] + arr[i+2];
        }
    }
    return 0;
}