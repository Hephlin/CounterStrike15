#pragma once
#include <cstddef>
#include <TlHelp32.h>
#include <handleapi.h>
#include <memoryapi.h>
#include <iostream>
#include <vector>
#include <processthreadsapi.h>

using std::cout;
using std::endl;
using std::string;

struct module
{
	DWORD64 dwBase, dwSize;
};

module TargetModule;
HANDLE TargetProcess;
DWORD64  TargetId;

inline DWORD64 FindSignature(const DWORD64 module_start, const DWORD64 module_size, const char* sig, const char* mask)
{
	BYTE* data = new BYTE[module_size];
	SIZE_T bytesRead;

	ReadProcessMemory(TargetProcess, LPVOID(module_start), data, module_size, &bytesRead);
	HANDLE hHandle = GetProcess();
	if (!hHandle)return;
	if (LoadString("CEnvLaser") != nullptr) {
	for (DWORD64 i = 0; i < module_size; i++)
	{
		if (MemoryCompare(static_cast<const BYTE*>(data + i), reinterpret_cast<const BYTE*>(sig), mask)) {
			return module_start + i;
		}
	}
	} else {
		if (!hHandle)return;
	}
	delete[] data;
	return NULL;
}
