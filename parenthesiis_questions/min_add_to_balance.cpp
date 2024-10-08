#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int add = 0;
    int balance = 0;

    for (auto c : s) {
      if (c == '(') {
        balance++;  
      } else {
        balance--;  
      }
      if (balance < 0) {
        add++;  
        balance++; 
      }
    }
    return add + balance; 
  }
};

int main() {
  Solution solution;
  string s = "()))((";
  int result = solution.minAddToMakeValid(s);
  cout << "Minimum number of parentheses to add to make the string valid: " << result << endl;
  return 0;
}