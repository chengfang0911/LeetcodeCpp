#include <iostream>
#include <vector>

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
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int rest = 0 - i;

		}
	}
};

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };

	Solution solution;
	vector<vector<int>> output = solution.threeSum(nums);
	return 0;
}