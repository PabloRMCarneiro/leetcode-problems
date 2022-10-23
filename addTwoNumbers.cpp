/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading
zeros.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = l1, *q = l2, *curr = head;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
      int x = (p != nullptr) ? p->val : 0;
      int y = (q != nullptr) ? q->val : 0;
      int sum = carry + x + y;
      carry = sum / 10;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      if (p != nullptr)
        p = p->next;
      if (q != nullptr)
        q = q->next;
    }
    if (carry > 0) {
      curr->next = new ListNode(carry);
    }
    return head->next;
  }
};

int main() {
  // Example 1
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // Example 2
  ListNode *l3 = new ListNode(0);

  ListNode *l4 = new ListNode(0);

  // Example 3
  ListNode *l5 = new ListNode(9);
  l5->next = new ListNode(9);
  l5->next->next = new ListNode(9);
  l5->next->next->next = new ListNode(9);
  l5->next->next->next->next = new ListNode(9);
  l5->next->next->next->next->next = new ListNode(9);
  l5->next->next->next->next->next->next = new ListNode(9);

  ListNode *l6 = new ListNode(9);
  l6->next = new ListNode(9);
  l6->next->next = new ListNode(9);
  l6->next->next->next = new ListNode(9);

  Solution s;

  ListNode *result = s.addTwoNumbers(l1, l2);
  while (result != nullptr) {
    cout << result->val << " ";
    result = result->next;
  }

  cout << endl;

  ListNode *result2 = s.addTwoNumbers(l3, l4);
  while (result2 != nullptr) {
    cout << result2->val << " ";
    result2 = result2->next;
  }

  cout << endl;

  ListNode *result3 = s.addTwoNumbers(l5, l6);
  while (result3 != nullptr) {
    cout << result3->val << " ";
    result3 = result3->next;
  }

  return 0;
}