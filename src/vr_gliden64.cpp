// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2026 Patrick Carey <patrickfcarey@gmail.com>
#include "vr_gliden64.h"
#include "Log.h"

#ifdef OS_WINDOWS
#include <windows.h>
#define DLSYM(a, b) GetProcAddress(a, b)
#else
#include <dlfcn.h>
#define DLSYM(a, b) dlsym(a, b)
#endif // OS_WINDOWS

int (*CoreVR_GetHeadPose)(CoreVrPose*) = nullptr;

void vr_gliden64_resolve(m64p_dynlib_handle _CoreLibHandle)
{
	CoreVR_GetHeadPose = (int (*)(CoreVrPose*)) DLSYM(_CoreLibHandle, "CoreVR_GetHeadPose");
	if (CoreVR_GetHeadPose != nullptr)
		LOG(LOG_MINIMAL, "[VR] CoreVR_GetHeadPose resolved: head-pose import available.\n");
	else
		LOG(LOG_MINIMAL, "[VR] CoreVR_GetHeadPose not found (stock core): head-pose import disabled.\n");
}
