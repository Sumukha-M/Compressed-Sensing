/*
 * rtwtypes.h
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Jul 11 12:27:47 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->C6000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTWTYPES_H
#define RTWTYPES_H
#include "tmwtypes.h"
#ifndef POINTER_T
#define POINTER_T

typedef void * pointer_T;

#endif

/* Logical type definitions */
#if (!defined(__cplusplus))
#ifndef false
#define false                          (0U)
#endif

#ifndef true
#define true                           (1U)
#endif
#endif

/*===========================================================================*
 * Additional type definitions: Embedded Hardware                            *
 *===========================================================================*/
typedef long int40_T;
typedef unsigned long uint40_T;

#define MAX_int40_T                    ((int40_T)(549755813887L))
#define MIN_int40_T                    ((int40_T)(-549755813887L-1L))
#define MAX_uint40_T                   ((uint40_T)(0xFFFFFFFFFFUL))

/*===========================================================================*
 * Additional complex number type definitions                                           *
 *===========================================================================*/
typedef struct {
  int40_T re;
  int40_T im;
} cint40_T;

typedef struct {
  uint40_T re;
  uint40_T im;
} cuint40_T;

#endif                                 /* RTWTYPES_H */
