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

void ProcessAlgorithm()
{
	TimedCall([]()
		{
			lengthOfLongestSubstring("sdsd");
		}, "lengthOfLongestSubstring");
}
} // namespace

int main()
{
	std::cout << "Processing..." << std::endl << std::endl;

	ProcessAlgorithm();

	std::cout << "Press any key to continue..." << std::endl << std::endl;
	
	_getch();
}


