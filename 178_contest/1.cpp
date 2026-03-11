// q1: smallest pairs with different freq
//
// given nums array
// {x, y} : x < y and x's freq and y'freq are different
// choose the pairs with the smallest possuble value of x
// if multiple pairs have the same x, choose the one with the smallest possible
// value of y return an integer [x,y], ikf no valid return [-1,-1];

// lets code:

class Solution {
public:
  vector<int> minDistinctFreqPair(vector<int> &nums) {
    // condition
    int n = nums.size();
    if (n == 2 || n == 1) {
      return {-1, -1};
    }
    unordred_map<int, int> mpp;

    for (int x : nums) {
      mpp[x]++;
    }
    int minX = INT_MAX;
    for (auto x : mpp) {
      if (minX == INT_MAX) {
        minX = x.first;
      }
      if (minX > x.first) {
        minX = x.first;
      }
    }

    int minY = INT_MAX;
    for (auto x : mpp) {
      if (minY == INT_MAX && minX != x.first && x.second != mpp[minX]) {
        minY = x.first;
      }
      if (minX != x.first && minY > x.first && x.second != mpp[minX]) {
        minY = x.first;
      }
    }
    if (minY == INT_MAX) {
      return {-1, -1};
    }

    return {minX, minY};
  }
};
