// Q2 :  Find the Smallest Balanced Index

class Solution {

public:
  int smallestBalancedIndex(vector<int> &nums) {
    // i will be balanaced ; if the sum of elements strictly to the left of i
    // equal the product of the elements strictly to the right of i if there is
    // no elements left , the sum is considered as 0 and similar as right side
    // return the smallest balanaced index, else return -1
    //
    //
    // eg: nums=[2,8,2,2,5]
    // 2+8 = 10
    // 2*5 = 10
    // index will be i=2

    int n = nums.size();
    if (n < 2) {
      return -1;
    }

    vector<int> left_side(n);
    vector<int> right_side(n);

    // prefix_sum
    left_side[0] = nums[0];

    for (int i = 1; i < n; i++) {
      left_side[i] = left_side[i - 1] + nums[i];
    }

    // suffixProduct
    right_side[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      right_side[i] = right_side[i + 1] * nums[i];
    }

    // check

    for (int i = 0; i < n; i++) {
      long long leftSum = (i == 0) ? 0 : leftSum[i - 1];
      long long righProduct = (i == n - 1) ? 1 : right_side[i + 1];

      if (leftSum == righProduct) {
        return i;
      }
    }
    return -1;
  }
};
