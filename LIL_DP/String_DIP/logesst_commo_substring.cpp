#include<isotream>
using namespace std;
#include<vector>

int Solve(string s1,string s2){
  int m = s1.size();
  int n = s2.size();

  vector<vector<int>> dp(m+1,vector<int>(n+1,0));
  int maxi = INT_MIN;

  for (int i = 1; i <= m ; i++){
    for (int j = 1 ; j <= n ;j++){
      if (s1[i-1] == s2[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        maxi = max(maxi,dp[i][j]);
      }
      else{
        dp[i][j] = 0;
      }
    }
  }
  return maxi == INT_MIN ? -1 : maxi;
  
}


//-----------------------

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Substring (LCS)
int lcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    // Initialize two vectors to store previous and current row values
    vector<int> prev(m+1, 0); // Stores values of the previous row
    vector<int> cur(m+1, 0);  // Stores values of the current row

    int ans = 0; // Initialize the answer variable to store the maximum LCS length found
    
    // Loop through both strings
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; // Characters match, increment substring length
                cur[j] = val; // Update the current row with the new value
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = cur; // Update the previous row with the values of the current row
    }
    
    return ans; // Return the length of the Longest Common Substring
}

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}

