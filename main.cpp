#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define _GLIBCXX_DEBUG
#include <iostream>
#include "MemoryInfo.h"

int main()
{
	auto UseRate = memory::GetMemoryInfoInGByte().physicalMemoryUsage; // �g�p��
	auto Available = memory::GetMemoryInfoInGByte().freePhysicalMemory; // ���p�\
	auto InUse = memory::GetMemoryInfoInGByte().maxPhysicalMemoryCapacity - memory::GetMemoryInfoInGByte().freePhysicalMemory; // ���p�\
	auto Maximum = memory::GetMemoryInfoInGByte().maxPhysicalMemoryCapacity;// �ő�
	std::cout << "����������" << std::endl;
	std::cout << "���p�\ : " << Available << " GB" << std::endl;
	std::cout << "�g�p�� : " << InUse << " GB / " << Maximum << " GB " << "(" << UseRate << "%)" << std::endl;

	std::cout << std::endl;

	Available = memory::GetMemoryInfoInGByte().freeVirtualMemory; // ���p�\
	InUse = memory::GetMemoryInfoInGByte().maxVirtualMemoryCapacity - memory::GetMemoryInfoInGByte().freeVirtualMemory; // ���p�\
	Maximum = memory::GetMemoryInfoInGByte().maxVirtualMemoryCapacity;// �ő�
	std::cout << "���z������" << std::endl;
	std::cout << "���p�\ : " << Available << " GB" << std::endl;
	std::cout << "�g�p�� : " << InUse << " GB / " << Maximum << " GB" << std::endl;

	std::cout << std::endl;

	Available = memory::GetMemoryInfoInGByte().freeUserSpace; // ���p�\
	InUse = memory::GetMemoryInfoInGByte().maxUserSpaceCapacity - memory::GetMemoryInfoInGByte().freeUserSpace; // ���p�\
	Maximum = memory::GetMemoryInfoInGByte().maxUserSpaceCapacity;// �ő�
	std::cout << "�A�v�������p�ł��郁����" << std::endl;
	std::cout << "���p�\ : " << Available << " GB" << std::endl;
	std::cout << "�g�p�� : " << InUse << " GB / " << Maximum << " GB" << std::endl;

	return std::system("PAUSE");
}