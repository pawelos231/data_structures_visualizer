#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "./structures/bin_ind_tree.h"
#include <iostream>
#include <cstdlib> 

int main(void)
{

	std::vector<int> arr =  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16, 16};

	FenwickTree* fw = new FenwickTree(arr);
	//fw->logTree();
	std::cout << fw->getRangeSum(1, 6) << std::endl;

	return 0;
}