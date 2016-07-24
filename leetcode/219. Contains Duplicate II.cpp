class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> count;
		for (int i = 0; i < nums.size(); i++) {
			if (count[nums[i]] && i - count[nums[i]] < k)   return true;
			count[nums[i]] = i + 1; // ע����С��ֵΪ1������0
		}
		return false;
	}

};