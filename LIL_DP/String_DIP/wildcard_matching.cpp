
#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

// Function to check if S1 matches S2 using wildcard pattern matching
bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp) {
    // Base Cases
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match or S1 has a '?'
    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    else {
        if (S1[i] == '*')
            // Two options: either '*' represents an empty string or it matches a character in S2
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

// Main function to check if S1 matches S2 using wildcard pattern matching
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    // Initialize the first row and column
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = isAllStars(S1, i);
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (S1[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

    // The value at dp[n][m] contains whether S1 matches S2
    return dp[n][m];
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current rows of matching results
    vector<bool> prev(m + 1, false);
    vector<bool> cur(m + 1, false);

    prev[0] = true; // Initialize the first element of the previous row to true

    for (int i = 1; i <= n; i++) {
        cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                cur[j] = prev[j - 1]; // Characters match or S1 has '?'
            } else {
                if (S1[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
                } else {
                    cur[j] = false; // Characters don't match and S1[i-1] is not '*'
                }
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at prev[m] contains whether S1 matches S2
    return prev[m];
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}

