/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> nums3(m + n);
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        nums3[k] = nums1[i];
        i++;
      } else {
        nums3[k] = nums2[j];
        j++;
      }
      k++;
    }
    while (i < m) {
      nums3[k] = nums1[i];
      i++;
      k++;
    }
    while (j < n) {
      nums3[k] = nums2[j];
      j++;
      k++;
    }
    if ((m + n) % 2 == 0) {
      return (nums3[(m + n) / 2 - 1] + nums3[(m + n) / 2]) / 2.0;
    } else {
      return nums3[(m + n) / 2];
    }
  }
};

int Example1(){
  Solution solution;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  float result = solution.findMedianSortedArrays(nums1, nums2);
  cout << "Example1: " << result << endl;
  return 0; 
}

int Example2(){
  Solution solution;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  float result = solution.findMedianSortedArrays(nums1, nums2);
  cout << "Example2: " << result << endl;
  return 0; 
}

int main() {
  Example1();
  Example2();
  return 0;
}
