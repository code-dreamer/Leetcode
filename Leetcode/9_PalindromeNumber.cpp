#include "stdafx.h"
#include "9_PalindromeNumber.h"

bool isPalindrome(int x)
{
	unsigned long long y = 0;
	int n = x;

	while (n > 0)
	{
		y = (y + (n % 10)) * 10;
		n /= 10;
	}

	return (abs(x) == y / 10);
}
