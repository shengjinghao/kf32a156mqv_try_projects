#ifndef KF32A1x6_H_
#define KF32A1x6_H_

#include "__Kungfu32_chipmodel_define.h"

#if defined(KF32A136KQS) || \
    defined(KF32A136KQT) || \
    defined(KF32A136KNP) || \
    defined(KF32A136IQT) || \
    defined(KF32A136IQS) || \
    defined(KF32A136INP) || \
    defined(KF32A136GQS) || \
    defined(KF32A136GNP)

#define KF32A136

#include "KF32A136.h"
#include "KF32A136Config.h"

#elif defined(KF32A146KQT) || \
      defined(KF32A146KQS) || \
      defined(KF32A146IQT) || \
      defined(KF32A146IQS) 

#define KF32A146
#include "KF32A146.h"
#include "KF32A146Config.h"

#else

#define KF32A156
#include "KF32A156.h"
#include "KF32A156Config.h"

#endif
#endif
