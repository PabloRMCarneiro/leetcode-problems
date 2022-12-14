/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the
string is s, divide it to x and y where s = x + y. Randomly decide to swap the
two substrings or to keep them in the same order. i.e., after this step, s may
become s = x + y or s = y + x. Apply step 1 recursively on each of the two
substrings x and y. Given two strings s1 and s2 of the same length, return true
if s2 is a scrambled string of s1, otherwise, return false.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and
keep them in order. "gr/eat" --> "g/r / e/at" // apply the same algorithm
recursively on both substrings. divide at random index each of them. "g/r /
e/at" --> "r/g / e/at" // random decision was to swap the first substring and to
keep the second substring in the same order. "r/g / e/at" --> "r/g / e/ a/t" //
again apply the algorithm recursively, divide "at" to "a/t". "r/g / e/ a/t" -->
"r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

Example 3:

Input: s1 = "a", s2 = "a"
Output: true

Example 4:

Input:
Constraints: s1 = "eebaacbcbcadaaedceaaacadccd", s2 =
"eadcaacabaddaceacbceaabeccd" Output: false

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.

*/
#include "iostream"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2)
      return true;
    if (s1.length() != s2.length())
      return false;
    int n = s1.length();
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
      count[s1[i] - 'a']++;
      count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0)
        return false;
    }
    for (int i = 1; i < n; i++) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return true;
      if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
          isScramble(s1.substr(i), s2.substr(0, n - i)))
        return true;
    }
    return false;
  }
};

int Example1() {
  Solution *solution = new Solution();
  string s1 = "great";
  string s2 = "rgeat";
  cout << solution->isScramble(s1, s2) << endl;
  return 0;
}

int Example2() {
  Solution *solution = new Solution();
  string s1 = "abcde";
  string s2 = "caebd";
  cout << solution->isScramble(s1, s2) << endl;
  return 0;
}

int Example3() {
  Solution *solution = new Solution();
  string s1 = "a";
  string s2 = "a";
  cout << solution->isScramble(s1, s2) << endl;
  return 0;
}
int Example4() {
  Solution *solution = new Solution();
  string s1 = "eebaacbcbcadaaedceaaacadccd";
  string s2 = "eadcaacabaddaceacbceaabeccd";
  cout << solution->isScramble(s1, s2) << endl;
  return 0;
}
int main() {
  Example1();
  Example2();
  Example3();
  Example4();
  return 0;
}
