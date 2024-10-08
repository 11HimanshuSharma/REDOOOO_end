#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int add = 0;
    stack<char> st;

    for (auto c : s) {
      if (c == '(') {
        st.push('(');
      } else {
        if (!st.empty()) {
          st.pop();
        } else {
          add++;
        }
      }
    }
    return st.size() + add;
  }
};

int main() {
  Solution solution;
  string input;
  cout << "Enter a string of parentheses: ";
  cin >> input;
  int result = solution.minAddToMakeValid(input);
  cout << "Minimum number of additions to make the string valid: " << result << endl;
  return 0;
}