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
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				for (int m = j + 1; m < nums.size(); m++)
				{
					if (nums[i] + nums[j] + nums[m] == 0)
					{
						vector<int> tmpres{ nums[i], nums[j], nums[m] };
						auto p = find(res.begin(), res.end(), tmpres);
						if(p == res.end())
							res.push_back(tmpres);
					}
				}
			}

		}
		return res;
	}
};

int main()
{
	vector<int> nums = {11, 4, 9, -7, -7, 4, -6, 13, 12, -1, -5, -15, -2, -4, 7, 14, 14, 13, -2, -11, -9, -3, -15, 6, -4, 14, -7, -15, 2, 2, 7, -10, 13, -6, -1, 14, 5, 8, 12, 3, 14, -15, 3, -10, -4, -12, -11, -4, -14, -6, -8, 14, 6, -15, 5, 10, 14, 13, 10, -6, -8, -6, -1, -9, 3, 13, -10, -6, -1, 9, 4, -2, 9, 14, 3, -9, -13, -1, -6, 10, 8, -7, 9, -8, -7, -1, 9, -15, -3, 4, -6, 5, 13, 8, 3, -6, -1, 8, -5, 13, 2, 14, -12, -11, 13, -1, -13, 8, 13, -4, 3, -1, -4, -2, -2, 5, 12, -8, 5, -13, 3, 14
};

	Solution solution;
	vector<vector<int>> output = solution.threeSum(nums);
	return 0;
}