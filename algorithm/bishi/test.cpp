#include <iostream>
#include <vector>
// 全排列

/*
	给定一个数组，给出这个数组的全排列
*/

class Solution
{
public:
	std::vector<std::vector<int>> getFullyArranged(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> result;
		
		backtrace(result, nums, 0);
		return result;
	}

private:
	void backtrace(std::vector<std::vector<int>>& result, std::vector<int>& nums, int start)
	{
		int len = nums.size();	// 

		if (len == start)
		{
			result.push_back(nums);
			return;
		}

		for (int i = start; i < len; ++i)
		{
			std::swap(nums[start], nums[i]);		// 交换当前元素的位置
			backtrace(result, nums, start + 1);		// 递归生成排列
			std::swap(nums[start], nums[i]);		// 恢复原始状态
		}
	}
};