// Q: toggle Light Bulbs

class Solution {
public:
  vector<int> toggleLightBulbs(vector<int> &bulbs) {
    vector<int> ans;

    set<int> set;

    for (int x : bulbs) {
      if (set.count(x) == 1) {
        set.erase(x);
      } else {
        set.insert(x);
      }
    }

    for (int val : set) {
      ans.push_back(val);
    }

    return ans;
  }
};
