class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
			return;

		auto n = nums.size(); // ����
		k %= n; // ע�����n
		vector<int> rotatedNums(nums.begin() + n - k, nums.end()); // �ȴ����k������
		rotatedNums.insert(rotatedNums.end(), nums.begin(), nums.begin() + n - k); // �ٴ���ǰn-k������
		nums = rotatedNums;
	}
};