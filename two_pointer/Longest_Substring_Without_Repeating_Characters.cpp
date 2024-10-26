#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_string_len = 0;
    int left = 0;
    int right = 0;
    unordered_map<char, int> mp; // Changed int to char for the map key
    while (right < s.size()) {
      if (mp.find(s[right]) != mp.end() && left <= mp[s[right]]) {
        left = mp[s[right]] + 1;
      }
      mp[s[right]] = right;
      max_string_len = max(max_string_len, right - left + 1);
      right++;
    }
    return max_string_len;
  }
};

int main() {
  Solution solution;
  string input = "abcabcbb";
  cout << "Length of the longest substring without repeating characters: " 
     << solution.lengthOfLongestSubstring(input) << endl;
  return 0;
}