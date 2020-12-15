#include "stdafx.h"
#include "1209_RemoveAllAdjacentDuplicatesInString2.h"

using namespace std;

string removeDuplicates(string s, int k)
{
	int ind = 0;
	while (ind < (int)s.length() - (k - 1))
	{
		char currCh = s[ind];
		int j = ind + 1;
		while (currCh == s[j] && j - ind < k)
		{
			++j;
		}

		if (j - ind == k)
		{
			s.erase(ind, k);
			ind = 0;
		}
		else
		{
			ind = j;
		}
	}

	return s;
}
