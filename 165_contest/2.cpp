// Q2: Mimimim discard to balance invenstory

// questions
// integer: w, m and integer array arrivals
// arrivals[i] = type of items arriving on day i (days are 1-indexed)
//
// rules
// each arrival may be kept or discard; an item may only be discard on its
// arrival day
//
// for each day i; considered windows of days: [max(1, i-w+1), i] (the w most
// recent days up to day i) for any such window, each item type may appear at
// most m times kept arrivals whose arrivals days lies in that window if keeping
// the arrival on day i would cause its type to appear more than m times in the
// windows that arrival must be discarded.
//
// return minimum no of arrivals to be disc discarded so that every w-day window
// contains at most m occurance of each type.
//
//
// my approach is
// take i and j to make w size windows
// also make a map to track the counts , so that if the occurance of any
// partcular elements will greater than `m` we can discard and add in count
// variable and return it.

class Solution {
public:
  int minArrivalsToDiscard(vector<int> &arrivals, int w, int m) {
    unordered_map<int, int> mpp;
    int discard_count = 0;
    int i = 0, j = 0;
    while (j < arrivals.size()) {

      if (j - i < w) {
        if (mpp[arrivals[j]] >= m) {
          discard_count++;
          j++;
          continue;
        }
        mpp[arrivals[j]]++;
        j++;
      } else {
        // remove the freq
        mpp[arrivals[i]]--;
        i++;
      }
    }

    return discard_count;
  }
};

// some test case are accepted;
