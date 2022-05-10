class Solution {
public:
	int TARGET, SIZE, MAX_VALUE;
	vector<vector<int>> ans;
	void helper(vector<int>& nums, int sum, int lastNum) {
		if(nums.size() == SIZE) {
			if(sum == TARGET) ans.push_back(nums);
			return;
		}
		for(int num = lastNum + 1; num <= MAX_VALUE; num++) {
			nums.push_back(num);
			helper(nums, sum + num, num);
			nums.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		TARGET = n, SIZE = k, MAX_VALUE = 9;
		vector<int> nums = {};
		helper(nums, 0, 0);
		return ans;
	}
};