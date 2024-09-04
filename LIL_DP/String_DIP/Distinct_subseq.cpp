
#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;
    
    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } else {
        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Create a 2D DP array to store the count of distinct subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first column: s1 can't match any non-empty s2
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, we have two options:
                // 1. Match the current characters and move diagonally (dp[i-1][j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                // If the characters don't match, we can only leave the current character in s1
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The value at dp[n][m] contains the count of distinct subsequences
    return dp[n][m];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Create an array to store the count of distinct subsequences for each character in s2
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) { // Iterate in reverse direction to avoid overwriting values prematurely
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as is
        }
    }

    // The value at prev[m] contains the count of distinct subsequences
    return prev[m];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}

