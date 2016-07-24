class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> count;
		for (int i = 0; i < nums.size(); i++) {
			if (count[nums[i]] && i - count[nums[i]] < k)   return true;
			count[nums[i]] = i + 1; // 注意最小键值为1，不是0
		}
		return false;
	}

};