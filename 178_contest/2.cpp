// q2: merge close characters
// string s : lowercase english and k integer
// two equal characters in the current string s are consider close if the
// distance between their indices is at most k; when 2 characters are close ,
// the right one merges into the lft, merge happens once at a time, and after
// each merge , the string updates untill no more merges are possible.
//
// return the resulting string after performing all possible merges
//
class Solution {
public:
  string mergeCharacters(string s, int k) {
    string res = "";
    unordered_map<char, int> last;

    for (char c : s) {
      if (last.count(c)) {
        int dist = res.size() - last[c];
        if (dist <= k) {
          continue;
        }
      }

      res.push_back(c);
      last[c] = res.size() - 1;
    }
    return res;
  }
};
