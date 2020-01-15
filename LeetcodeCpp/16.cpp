#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
	[-1, 0, 1],
	[-1, -1, 2]
]
*/


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int sum = 0;
		int low = 0;
		int high = 0;
		int ret = 0;
		sort(nums.begin(), nums.end());
		ret = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
		for (int i = 0; i < nums.size() - 2; i++)
		{
			low = i + 1;
			high = nums.size() - 1;
			while (low < high)
			{
				int tmpret = 0;
				sum = nums[i] + nums[low] + nums[high];
				if (abs(ret - target) > abs(sum - target))
					ret = sum;
				if (sum == target)
					return sum;
				else if (sum < target)
					low++;
				else
					high--;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = {1,1,1,0};
	Solution solution;
	int target = -100;
	int output = solution.threeSumClosest(nums, target);
	return 0;
}