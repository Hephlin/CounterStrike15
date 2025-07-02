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

inline HANDLE GetProcess(const wchar_t* processName)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(entry);

	do
		if (!_wcsicmp(entry.szExeFile, processName)) {
			TargetId = entry.th32ProcessID;
			CloseHandle(handle);
			TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, false, TargetId);
			return TargetProcess;
		}
	while (Process32Next(handle, &entry));

	return nullptr;
}
