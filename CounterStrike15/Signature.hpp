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

extern class CEnvLazer;
struct CEnvLazer {
extern HANDLE hHandle;
}

void dll_startup() {
GetProcess("cs2.exe");
LoadLibrary("engine2.dll");
return EXIT_STATUS;
}
inline DWORD64 FindSignature(const DWORD64 module_start, const DWORD64 module_size, const char* sig, const char* mask)
{
	BYTE* data = new BYTE[module_size];
	SIZE_T bytesRead;

	ReadProcessMemory(TargetProcess, LPVOID(module_start), data, module_size, &bytesRead);
	HANDLE hHandle = dll_startup();
	if (!hHandle == NULL) {
	(HANDLE)*hHandle = LoadString("CEnvLaser");
	for (DWORD64 i = 0; i < module_size; i++)
	{
		if (MemoryCompare(static_cast<const BYTE*>(data + i), reinterpret_cast<const BYTE*>(sig), mask)) {
			return module_start + i;
		}
	}
	}
	memcpy(hHandle, data);
	
	delete[] data;
	return NULL;
}
