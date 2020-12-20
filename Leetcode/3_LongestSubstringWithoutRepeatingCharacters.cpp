#include "stdafx.h"
#include "3_LongestSubstringWithoutRepeatingCharacters.h"

using namespace std;

int lengthOfLongestSubstring1(string s)
{
	if (s.empty())
		return 0;

	size_t uniqSubstrLen = 1;

	auto begIt = s.cbegin();
	auto endIt = begIt + 1;
	do
	{	
		while (endIt != s.cend() && std::find(begIt, endIt, *endIt) == endIt)
		{
			auto origIt = endIt++;
			uniqSubstrLen = std::max(uniqSubstrLen, (size_t)(endIt - begIt));

			while (endIt != s.cend() && *origIt == *endIt)
			{
				++endIt;
			}

			if (endIt - origIt > 1)
			{
				// duplicate chars
				begIt = endIt - 1;
			}
		}
		++begIt;
	} while (endIt != s.cend());


	return (int)uniqSubstrLen;
}

int lengthOfLongestSubstring2(string s)
{
	int len = (int)s.length();
	int uniqSubstrLen = 0;

	std::array<int, 128> index{ 0 };
	for (int j = 0, i = 0; j < len; j++) 
	{
		i = std::max(index[s[j]], i);
		uniqSubstrLen = std::max(uniqSubstrLen, j - i + 1);
		index[s[j]] = j + 1;
	}
	
	return uniqSubstrLen;
}
