//==========================================================================
// 物理メモリと仮想メモリの現在の状態 [MemoryInfo.cpp]
// author : MasyoLab
//==========================================================================
#include "MemoryInfo.h"

namespace memory
{
	static MemoryInfo<DWORDLONG> memoryInfoDwordLong; // メモリ情報
	static MemoryInfo<float> memoryInfoFloat; // メモリ情報

	struct MemoryStatus : public MEMORYSTATUSEX
	{
		MemoryStatus()
		{
			dwLength = sizeof(MEMORYSTATUSEX);
		}

		const MemoryInfo<float>& ChangeByteSize(int64_t byte)
		{
			float fbyte = 1.0f / byte;
			memoryInfoFloat.physicalMemoryUsage = dwMemoryLoad;
			memoryInfoFloat.maxPhysicalMemoryCapacity = ullTotalPhys * fbyte;
			memoryInfoFloat.freePhysicalMemory = ullAvailPhys * fbyte;
			memoryInfoFloat.maxVirtualMemoryCapacity = ullTotalPageFile * fbyte;
			memoryInfoFloat.freeVirtualMemory = ullAvailPageFile * fbyte;
			memoryInfoFloat.maxUserSpaceCapacity = ullTotalVirtual * fbyte;
			memoryInfoFloat.freeUserSpace = ullAvailVirtual * fbyte;
			memoryInfoFloat.freeExtensionUserSpace = ullAvailExtendedVirtual * fbyte;
			return memoryInfoFloat;
		}

		const MemoryInfo<DWORDLONG>& ChangeByteSize()
		{
			memoryInfoDwordLong.physicalMemoryUsage = dwMemoryLoad;
			memoryInfoDwordLong.maxPhysicalMemoryCapacity = ullTotalPhys;
			memoryInfoDwordLong.freePhysicalMemory = ullAvailPhys;
			memoryInfoDwordLong.maxVirtualMemoryCapacity = ullTotalPageFile;
			memoryInfoDwordLong.freeVirtualMemory = ullAvailPageFile;
			memoryInfoDwordLong.maxUserSpaceCapacity = ullTotalVirtual;
			memoryInfoDwordLong.freeUserSpace = ullAvailVirtual;
			memoryInfoDwordLong.freeExtensionUserSpace = ullAvailExtendedVirtual;
			return memoryInfoDwordLong;
		}
	};

	static MemoryStatus nemoryStatus; // ステータス
	constexpr int64_t KByte = 1024;
	constexpr int64_t MByte = KByte * KByte;
	constexpr int64_t GByte = MByte * KByte;

	const MemoryInfo<DWORDLONG>& GetMemoryInfoInByte()
	{
		GlobalMemoryStatusEx(&nemoryStatus);
		return nemoryStatus.ChangeByteSize();
	}
	const MemoryInfo<float>& GetMemoryInfoInKByte()
	{
		GlobalMemoryStatusEx(&nemoryStatus);
		return nemoryStatus.ChangeByteSize(KByte);
	}
	const MemoryInfo<float>& GetMemoryInfoInMByte()
	{
		GlobalMemoryStatusEx(&nemoryStatus);
		return nemoryStatus.ChangeByteSize(MByte);
	}
	const MemoryInfo<float>& GetMemoryInfoInGByte()
	{
		GlobalMemoryStatusEx(&nemoryStatus);
		return nemoryStatus.ChangeByteSize(GByte);
	}
}
