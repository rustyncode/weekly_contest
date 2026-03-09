/*
Q1. Minimum Capacity Box
You are given an integer array capacity, where capacity[i] represents the capacity of the ith box, and an integer itemSize representing the size of an item.

The ith box can store the item if capacity[i] >= itemSize.

Return an integer denoting the index of the box with the minimum capacity that can store the item. If multiple such boxes exist, return the smallest index.

If no box can store the item, return -1.
* /


/*
Input: capacity = [1,5,3,7], itemSize = 3

Output: 2

Explanation:

The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.
* /

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int min_val = INT_MAX;
        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] == itemSize) {
                return i;
            }
            if (capacity[i] > itemSize && capacity[i] < min_val) {

                ans = i;
                min_val = capacity[i];
            }
        }
        return ans;
    }
};
