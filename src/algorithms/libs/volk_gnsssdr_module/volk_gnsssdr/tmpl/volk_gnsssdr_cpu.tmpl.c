/* Copyright (C) 2010-2019 (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software-defined Global Navigation Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// clang-format off
#include <volk_gnsssdr/volk_gnsssdr_cpu.h>
#include <volk_gnsssdr/volk_gnsssdr_config_fixed.h>
#include <stdlib.h>
#include <string.h>
// clang-format on

#include "cpu_features_macros.h"
#if defined(CPU_FEATURES_ARCH_X86)
#include "cpuinfo_x86.h"
#elif defined(CPU_FEATURES_ARCH_ARM)
#include "cpuinfo_arm.h"
#elif defined(CPU_FEATURES_ARCH_AARCH64)
#include "cpuinfo_aarch64.h"
#elif defined(CPU_FEATURES_ARCH_MIPS)
#include "cpuinfo_mips.h"
#elif defined(CPU_FEATURES_ARCH_PPC)
#include "cpuinfo_ppc.h"
#endif

// This is required for MSVC
#if defined(__cplusplus)
using namespace cpu_features;
#endif

struct VOLK_CPU volk_gnsssdr_cpu;

// clang-format off

%for arch in archs:
static int i_can_has_${arch.name} (void) {
    %for check, params in arch.checks:
      %if "neon" in arch.name:
#if defined(CPU_FEATURES_ARCH_ARM)
    if (GetArmInfo().features.${check} == 0){ return 0; }
#endif
    %else:
#if defined(CPU_FEATURES_ARCH_X86)
    if (GetX86Info().features.${check} == 0){ return 0; }
#endif
    %endif
    %endfor
    return 1;
}
%endfor

#if defined(HAVE_FENV_H)
    #if defined(FE_TONEAREST)
        #include <fenv.h>
        static inline void set_float_rounding(void){
            fesetround(FE_TONEAREST);
        }
    #else
        static inline void set_float_rounding(void){
            //do nothing
        }
    #endif
#elif defined(_MSC_VER)
    #include <float.h>
    static inline void set_float_rounding(void){
        unsigned int cwrd;
        _controlfp_s(&cwrd, 0, 0);
        _controlfp_s(&cwrd, _RC_NEAR, _MCW_RC);
    }
#else
    static inline void set_float_rounding(void){
        //do nothing
    }
#endif

void volk_gnsssdr_cpu_init() {
    %for arch in archs:
    volk_gnsssdr_cpu.has_${arch.name} = &i_can_has_${arch.name};
    %endfor
    set_float_rounding();
}

unsigned int volk_gnsssdr_get_lvarch() {
    unsigned int retval = 0;
    volk_gnsssdr_cpu_init();
    %for arch in archs:
    retval += volk_gnsssdr_cpu.has_${arch.name}() << LV_${arch.name.upper()};
    %endfor
    return retval;
}
// clang-format on
