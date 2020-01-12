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
	vector<vector <int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;

		sort(nums.begin(), nums.end());
		int now = 0;
		int low = 0;
		int high = 0;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			now = i;
			low = i + 1;
			high = nums.size() - 1;
			if (nums[i] > 0)
				return res;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			while (low < high)
			{
				while (low < high && nums[low] + nums[high] + nums[i] < 0)
					low++;
				
				while (low < high && nums[low] + nums[high] + nums[i] > 0)
					high--;

				if (nums[i] + nums[low] + nums[high] == 0 && low != high)
				{
					vector<int> tmp = { nums[i], nums[low], nums[high] };
					if(std::find(res.begin(), res.end(), tmp) == res.end())
						res.push_back(tmp);
					while (low < high && nums[low] == nums[low + 1])
						low++;
					
					while (low < high && nums[high] == nums[high - 1])
						high--;
					
					low++;
					high--;
				}
			}
		}
		return res;

	}
};

int main()
{
	//vector<int> nums = {11, 4, 9, -7, -7, 4, -6, 13, 12, -1, -5, -15, -2, -4, 7, 14, 14, 13, -2, -11, -9, -3, -15, 6, -4, 14, -7, -15, 2, 2, 7, -10, 13, -6, -1, 14, 5, 8, 12, 3, 14, -15, 3, -10, -4, -12, -11, -4, -14, -6, -8, 14, 6, -15, 5, 10, 14, 13, 10, -6, -8, -6, -1, -9, 3, 13, -10, -6, -1, 9, 4, -2, 9, 14, 3, -9, -13, -1, -6, 10, 8, -7, 9, -8, -7, -1, 9, -15, -3, 4, -6, 5, 13, 8, 3, -6, -1, 8, -5, 13, 2, 14, -12, -11, 13, -1, -13, 8, 13, -4, 3, -1, -4, -2, -2, 5, 12, -8, 5, -13, 3, 14};
	vector<int> nums = { -1,0,1,2,-1,-4 };
	Solution solution;
	vector<vector<int>> output = solution.threeSum(nums);
	return 0;
}