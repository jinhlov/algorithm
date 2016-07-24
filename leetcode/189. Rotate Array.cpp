class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
			return;

		auto n = nums.size(); // 长度
		k %= n; // 注意除以n
		vector<int> rotatedNums(nums.begin() + n - k, nums.end()); // 先存入后k个数字
		rotatedNums.insert(rotatedNums.end(), nums.begin(), nums.begin() + n - k); // 再存入前n-k个数字
		nums = rotatedNums;
	}
};