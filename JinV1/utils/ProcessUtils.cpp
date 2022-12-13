#pragma once

#include <iostream>
#include <string.h>
#include "ProcessUtils.h"

HWND ProcessUtils::GetWindowHandle(const DWORD TargetID) {
	HWND hWnd = GetTopWindow(NULL);
	do {
		if (GetWindowLongPtr(hWnd, GWLP_HWNDPARENT) != 0 || !IsWindowVisible(hWnd))
			continue;
		DWORD ProcessID;
		GetWindowThreadProcessId(hWnd, &ProcessID);
		if (TargetID == ProcessID) {
			char buf[1000];
			GetWindowText(hWnd, buf, 1000);
			if (strstr(buf, "javaw") == NULL) { // Bypass console made by JinV1
				return hWnd;
			}
		}
	} while ((hWnd = GetNextWindow(hWnd, GW_HWNDNEXT)) != NULL);

	return NULL;
}