/*
You are given an array of k linked-lists lists, each linked-list is sorted in
ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    int min = 0;
    while (true) {
      bool isEnd = true;
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
          isEnd = false;
          break;
        }
      }
      if (isEnd)
        break;
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
          min = i;
          break;
        }
      }
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr && lists[i]->val < lists[min]->val) {
          min = i;
        }
      }
      curr->next = new ListNode(lists[min]->val);
      curr = curr->next;
      lists[min] = lists[min]->next;
    }
    return head->next;
  }
};

int main() {
  // Example 1
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = new ListNode(2);
  l3->next = new ListNode(6);

  vector<ListNode *> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  Solution solution;
  ListNode *head = solution.mergeKLists(lists);
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  return 0;
}