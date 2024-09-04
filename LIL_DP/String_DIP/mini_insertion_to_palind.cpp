
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

// Function to calculate the minimum insertions required to make a string palindrome
int minInsertion(string s) {
    int n = s.size();
    int k = longestPalindromeSubsequence(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

int main() {
    string s = "abcaa";
    
    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion(s);
    return 0;
}


