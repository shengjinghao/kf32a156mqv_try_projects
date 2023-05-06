#ifndef KF32A1x6_CANFD_H_
#define KF32A1x6_CANFD_H_

#if defined(KF32A136KQS) || \
    defined(KF32A136KQT) || \
    defined(KF32A136KNP) || \
    defined(KF32A136IQT) || \
    defined(KF32A136IQS) || \
    defined(KF32A136INP) || \
    defined(KF32A136GQS) || \
    defined(KF32A136GNP)

#include "kf32a1x6_canfd_136.h"

#else

#include "kf32a1x6_canfd_156.h"

#endif


#endif
