#include "stdafx.h"
#include "1_TwoSum.h"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> valIndexes;

	for (int i = 0; i < (int)nums.size(); i++)
	{
		int currVal = nums[i];

		auto it = valIndexes.find(target - currVal);
		if (it != valIndexes.end())
			return { it->second, i };

		valIndexes[currVal] = i;
	}

	return {};
}
