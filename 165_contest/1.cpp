// Q1 :
//
//
class Solution {
public:
  int smallestAbsent(vector<int> &nums) {
    // array nums
    // return smallest absent positive integer in nums
    // such that it strictly greater than the average of all elements in nums
    // the average: sum of all its elements us dicvide by the all elements

    int n = nums.size();
    unordered_set<int> set;
    long long sum = 0;
    for (int num : nums) {
      sum += num;
      set.insert(num);
    }
    int target = max(1LL, sum / n + 1LL);
    while (set.count(target)) {
      target++;
    }

    return target;
  }
};
