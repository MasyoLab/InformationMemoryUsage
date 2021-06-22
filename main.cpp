#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define _GLIBCXX_DEBUG
#include <iostream>
#include "MemoryInfo.h"

int main()
{
	auto UseRate = memory::GetMemoryInfoInGByte().physicalMemoryUsage; // 使用率
	auto Available = memory::GetMemoryInfoInGByte().freePhysicalMemory; // 利用可能
	auto InUse = memory::GetMemoryInfoInGByte().maxPhysicalMemoryCapacity - memory::GetMemoryInfoInGByte().freePhysicalMemory; // 利用可能
	auto Maximum = memory::GetMemoryInfoInGByte().maxPhysicalMemoryCapacity;// 最大
	std::cout << "物理メモリ" << std::endl;
	std::cout << "利用可能 : " << Available << " GB" << std::endl;
	std::cout << "使用中 : " << InUse << " GB / " << Maximum << " GB " << "(" << UseRate << "%)" << std::endl;

	std::cout << std::endl;

	Available = memory::GetMemoryInfoInGByte().freeVirtualMemory; // 利用可能
	InUse = memory::GetMemoryInfoInGByte().maxVirtualMemoryCapacity - memory::GetMemoryInfoInGByte().freeVirtualMemory; // 利用可能
	Maximum = memory::GetMemoryInfoInGByte().maxVirtualMemoryCapacity;// 最大
	std::cout << "仮想メモリ" << std::endl;
	std::cout << "利用可能 : " << Available << " GB" << std::endl;
	std::cout << "使用中 : " << InUse << " GB / " << Maximum << " GB" << std::endl;

	std::cout << std::endl;

	Available = memory::GetMemoryInfoInGByte().freeUserSpace; // 利用可能
	InUse = memory::GetMemoryInfoInGByte().maxUserSpaceCapacity - memory::GetMemoryInfoInGByte().freeUserSpace; // 利用可能
	Maximum = memory::GetMemoryInfoInGByte().maxUserSpaceCapacity;// 最大
	std::cout << "アプリが利用できるメモリ" << std::endl;
	std::cout << "利用可能 : " << Available << " GB" << std::endl;
	std::cout << "使用中 : " << InUse << " GB / " << Maximum << " GB" << std::endl;

	return std::system("PAUSE");
}