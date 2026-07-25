// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2026 Patrick Carey <patrickfcarey@gmail.com>
#ifndef VR_GLIDEN64_H
#define VR_GLIDEN64_H


#include "m64p_types.h"   // m64p_dynlib_handle (from src/inc, on the mupenplus include path)

typedef struct {
	float ox, oy, oz, ow;   // unit quaternion, OpenXR order (x, y, z, w)
	float px, py, pz;       // metres, XR LOCAL space (unused in v1)
	int valid;              // 0 => consumers MUST no-op
	unsigned frame;         // monotonic publish counter
} CoreVrPose;

extern int (*CoreVR_GetHeadPose)(CoreVrPose*);

void vr_gliden64_resolve(m64p_dynlib_handle _CoreLibHandle);

static inline int vr_gliden64_get_head_pose(CoreVrPose* out)
{
	if (CoreVR_GetHeadPose == nullptr)
		return 0;
	return CoreVR_GetHeadPose(out);
}

#endif // VR_GLIDEN64_H
