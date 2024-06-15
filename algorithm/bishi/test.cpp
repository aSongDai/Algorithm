#include <iostream>
#include <vector>
// ȫ����

/*
	����һ�����飬������������ȫ����
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
			std::swap(nums[start], nums[i]);		// ������ǰԪ�ص�λ��
			backtrace(result, nums, start + 1);		// �ݹ���������
			std::swap(nums[start], nums[i]);		// �ָ�ԭʼ״̬
		}
	}
};