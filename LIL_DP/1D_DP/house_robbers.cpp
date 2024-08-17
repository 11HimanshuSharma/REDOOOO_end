#include<iostream>
#include<vector>
using namespace std;

// Function to solve the problem using dynamic programming
int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    // If the result for this index is already computed, return it
    if (dp[ind] != -1)
        return dp[ind];

    // Base cases
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;

    // Choose the current element or skip it, and take the maximum
    int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element

    // Store the result in the DP table and return it
    return dp[ind] = max(pick, nonPick);
}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, -1); // Initialize the DP table with -1
    return solveUtil(n - 1, arr, dp); // Start solving from the last element
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solve(n, arr);

    return 0;
}



using namespace std;

// Function to solve the problem using dynamic programming
int solveUtil(int n, vector<int>& arr, vector<int>& dp) {
    // Base case: If there are no elements in the array, return 0
    dp[0] = arr[0];
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        dp[i] = max(pick, nonPick);
    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];
}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, 0); // Initialize dp array with 0
    return solveUtil(n, arr, dp);
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solve(n, arr);

    return 0;
}



using namespace std;

// Function to solve the problem using dynamic programming
int solve(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    
    return prev;  // Return the maximum sum
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solve(n, arr);

    return 0;
}

