/*
Given an array of integers nums and an integer target, return indices
of the two numbers such that they add up to target.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int value1, value2;
        for (int i=0; i<nums.size(); i++) {
            value1 = nums[i];
            value2 = target - value1;
            if (map.contains(value2)) {
                return { i, map[value2] };
            } else {
                map[value1] = i; // map values to indices
            }
        }
        return {};
    }
};

