#include "stdafx.h"
#include "3_LongestSubstringWithoutRepeatingCharacters.h"

namespace
{

template <class Function>
void TimedCall(Function&& calledFunc, std::string_view funcName)
{
	auto d1 = std::chrono::steady_clock::now();
	calledFunc();
	auto d2 = std::chrono::steady_clock::now();

	std::cout << funcName << " time = " << std::chrono::duration_cast<std::chrono::milliseconds>(d2 - d1).count() 
		<< " ms" << std::endl << std::endl;
}

void MeasureAlgorithm()
{
#ifdef _DEBUG
	size_t count = 1;
#else
	size_t count = 4000000;
#endif

	auto testFunc = [count](std::function<void()> func)
	{
		for (size_t i = 0; i < count; ++i)
		{
			func();
		}
	};

	const std::string str = "abcabcbb";

	TimedCall([&]()
		{
			testFunc(std::bind(lengthOfLongestSubstring1, str));
		}, "lengthOfLongestSubstring1");

	TimedCall([&]()
		{
			testFunc(std::bind(lengthOfLongestSubstring2, str));
		}, "lengthOfLongestSubstring2");
}
} // namespace

int main()
{
	std::cout << "Processing..." << std::endl << std::endl;

	MeasureAlgorithm();

	std::cout << "Press any key to continue..." << std::endl << std::endl;
	
	_getch();
}


