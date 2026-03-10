
// Q1: First element with unique frequency

class Solution {
public:
  int firstUniqueFreq(vector<int> &nums) {
    unordered_map<int, int> freqMap;
    for (int x : nums)
      freqMap[x]++;

    unordered_set<int> freqSet;
    unordered_set<int> duplicateFreqs;
    for (auto &p : freqMap) {
      if (freqSet.count(p.second)) {
        duplicateFreqs.insert(p.second);
      } else {
        freqSet.insert(p.second);
      }
    }

    for (int x : nums) {
      if (freqSet.count(freqMap[x]) && !duplicateFreqs.count(freqMap[x])) {
        return x;
      }
    }
    return -1;
  }
};
