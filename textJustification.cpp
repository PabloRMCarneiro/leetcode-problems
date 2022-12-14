/*
Given an array of strings words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right)
justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line does not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters
only. Each word's length is guaranteed to be greater than 0 and not exceed
maxWidth. The input array words contains at least one word.

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."],
maxWidth = 16 Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall be",
because the last line must be left-justified instead of fully-justified. Note
that the second line is also left-justified because it contains only one word.

Example 3:

Input: words =
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
maxWidth = 20 Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

*/
#include "iostream"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector <string> fullJustify(vector<string> &words, int maxWidth) {
    vector <string> result;
    int i = 0;
    while (i < words.size()) {
      int j = i + 1;
      int len = words[i].size();
      while (j < words.size() && len + words[j].size() + 1 <= maxWidth) {
        len += words[j].size() + 1;
        j++;
      }
      int space = 1;
      int extra = 0;
      if (j != i + 1 && j != words.size()) {
        space = (maxWidth - len) / (j - i - 1) + 1;
        extra = (maxWidth - len) % (j - i - 1);
      }
      string line = words[i];
      for (int k = i + 1; k < j; k++) {
        line += string(space, ' ');
        if (extra > 0) {
          line += ' ';
          extra--;
        }
        line += words[k];
      }
      line += string(maxWidth - line.size(), ' ');
      result.push_back(line);
      i = j;
    }
    return result;
  }
};

int main() {
  Solution solution;
  vector <string> words = {"This", "is", "an", "example", "of", "text",
                           "justification."};
  vector <string> result = solution.fullJustify(words, 16);
  for (auto &line : result) {
    std::cout << line << std::endl;
  }
  return 0;
}