/*
 * multiword_types.h
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

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

/*
 * Definitions supporting external data access
 */
typedef int40_T chunk_T;
typedef uint40_T uchunk_T;

/*
 * MultiWord supporting definitions
 */
typedef long int long_T;

/*
 * MultiWord types
 */
typedef struct {
  uint40_T chunks[2];
} int80m_T;

typedef struct {
  int80m_T re;
  int80m_T im;
} cint80m_T;

typedef struct {
  uint40_T chunks[2];
} uint80m_T;

typedef struct {
  uint80m_T re;
  uint80m_T im;
} cuint80m_T;

typedef struct {
  uint40_T chunks[3];
} int120m_T;

typedef struct {
  int120m_T re;
  int120m_T im;
} cint120m_T;

typedef struct {
  uint40_T chunks[3];
} uint120m_T;

typedef struct {
  uint120m_T re;
  uint120m_T im;
} cuint120m_T;

typedef struct {
  uint40_T chunks[4];
} int160m_T;

typedef struct {
  int160m_T re;
  int160m_T im;
} cint160m_T;

typedef struct {
  uint40_T chunks[4];
} uint160m_T;

typedef struct {
  uint160m_T re;
  uint160m_T im;
} cuint160m_T;

typedef struct {
  uint40_T chunks[5];
} int200m_T;

typedef struct {
  int200m_T re;
  int200m_T im;
} cint200m_T;

typedef struct {
  uint40_T chunks[5];
} uint200m_T;

typedef struct {
  uint200m_T re;
  uint200m_T im;
} cuint200m_T;

typedef struct {
  uint40_T chunks[6];
} int240m_T;

typedef struct {
  int240m_T re;
  int240m_T im;
} cint240m_T;

typedef struct {
  uint40_T chunks[6];
} uint240m_T;

typedef struct {
  uint240m_T re;
  uint240m_T im;
} cuint240m_T;

typedef struct {
  uint40_T chunks[7];
} int280m_T;

typedef struct {
  int280m_T re;
  int280m_T im;
} cint280m_T;

typedef struct {
  uint40_T chunks[7];
} uint280m_T;

typedef struct {
  uint280m_T re;
  uint280m_T im;
} cuint280m_T;

typedef struct {
  uint40_T chunks[8];
} int320m_T;

typedef struct {
  int320m_T re;
  int320m_T im;
} cint320m_T;

typedef struct {
  uint40_T chunks[8];
} uint320m_T;

typedef struct {
  uint320m_T re;
  uint320m_T im;
} cuint320m_T;

typedef struct {
  uint40_T chunks[9];
} int360m_T;

typedef struct {
  int360m_T re;
  int360m_T im;
} cint360m_T;

typedef struct {
  uint40_T chunks[9];
} uint360m_T;

typedef struct {
  uint360m_T re;
  uint360m_T im;
} cuint360m_T;

typedef struct {
  uint40_T chunks[10];
} int400m_T;

typedef struct {
  int400m_T re;
  int400m_T im;
} cint400m_T;

typedef struct {
  uint40_T chunks[10];
} uint400m_T;

typedef struct {
  uint400m_T re;
  uint400m_T im;
} cuint400m_T;

typedef struct {
  uint40_T chunks[11];
} int440m_T;

typedef struct {
  int440m_T re;
  int440m_T im;
} cint440m_T;

typedef struct {
  uint40_T chunks[11];
} uint440m_T;

typedef struct {
  uint440m_T re;
  uint440m_T im;
} cuint440m_T;

typedef struct {
  uint40_T chunks[12];
} int480m_T;

typedef struct {
  int480m_T re;
  int480m_T im;
} cint480m_T;

typedef struct {
  uint40_T chunks[12];
} uint480m_T;

typedef struct {
  uint480m_T re;
  uint480m_T im;
} cuint480m_T;

typedef struct {
  uint40_T chunks[13];
} int520m_T;

typedef struct {
  int520m_T re;
  int520m_T im;
} cint520m_T;

typedef struct {
  uint40_T chunks[13];
} uint520m_T;

typedef struct {
  uint520m_T re;
  uint520m_T im;
} cuint520m_T;

typedef struct {
  uint40_T chunks[14];
} int560m_T;

typedef struct {
  int560m_T re;
  int560m_T im;
} cint560m_T;

typedef struct {
  uint40_T chunks[14];
} uint560m_T;

typedef struct {
  uint560m_T re;
  uint560m_T im;
} cuint560m_T;

typedef struct {
  uint40_T chunks[15];
} int600m_T;

typedef struct {
  int600m_T re;
  int600m_T im;
} cint600m_T;

typedef struct {
  uint40_T chunks[15];
} uint600m_T;

typedef struct {
  uint600m_T re;
  uint600m_T im;
} cuint600m_T;

typedef struct {
  uint40_T chunks[16];
} int640m_T;

typedef struct {
  int640m_T re;
  int640m_T im;
} cint640m_T;

typedef struct {
  uint40_T chunks[16];
} uint640m_T;

typedef struct {
  uint640m_T re;
  uint640m_T im;
} cuint640m_T;

typedef struct {
  uint40_T chunks[17];
} int680m_T;

typedef struct {
  int680m_T re;
  int680m_T im;
} cint680m_T;

typedef struct {
  uint40_T chunks[17];
} uint680m_T;

typedef struct {
  uint680m_T re;
  uint680m_T im;
} cuint680m_T;

typedef struct {
  uint40_T chunks[18];
} int720m_T;

typedef struct {
  int720m_T re;
  int720m_T im;
} cint720m_T;

typedef struct {
  uint40_T chunks[18];
} uint720m_T;

typedef struct {
  uint720m_T re;
  uint720m_T im;
} cuint720m_T;

typedef struct {
  uint40_T chunks[19];
} int760m_T;

typedef struct {
  int760m_T re;
  int760m_T im;
} cint760m_T;

typedef struct {
  uint40_T chunks[19];
} uint760m_T;

typedef struct {
  uint760m_T re;
  uint760m_T im;
} cuint760m_T;

typedef struct {
  uint40_T chunks[20];
} int800m_T;

typedef struct {
  int800m_T re;
  int800m_T im;
} cint800m_T;

typedef struct {
  uint40_T chunks[20];
} uint800m_T;

typedef struct {
  uint800m_T re;
  uint800m_T im;
} cuint800m_T;

typedef struct {
  uint40_T chunks[21];
} int840m_T;

typedef struct {
  int840m_T re;
  int840m_T im;
} cint840m_T;

typedef struct {
  uint40_T chunks[21];
} uint840m_T;

typedef struct {
  uint840m_T re;
  uint840m_T im;
} cuint840m_T;

typedef struct {
  uint40_T chunks[22];
} int880m_T;

typedef struct {
  int880m_T re;
  int880m_T im;
} cint880m_T;

typedef struct {
  uint40_T chunks[22];
} uint880m_T;

typedef struct {
  uint880m_T re;
  uint880m_T im;
} cuint880m_T;

typedef struct {
  uint40_T chunks[23];
} int920m_T;

typedef struct {
  int920m_T re;
  int920m_T im;
} cint920m_T;

typedef struct {
  uint40_T chunks[23];
} uint920m_T;

typedef struct {
  uint920m_T re;
  uint920m_T im;
} cuint920m_T;

typedef struct {
  uint40_T chunks[24];
} int960m_T;

typedef struct {
  int960m_T re;
  int960m_T im;
} cint960m_T;

typedef struct {
  uint40_T chunks[24];
} uint960m_T;

typedef struct {
  uint960m_T re;
  uint960m_T im;
} cuint960m_T;

typedef struct {
  uint40_T chunks[25];
} int1000m_T;

typedef struct {
  int1000m_T re;
  int1000m_T im;
} cint1000m_T;

typedef struct {
  uint40_T chunks[25];
} uint1000m_T;

typedef struct {
  uint1000m_T re;
  uint1000m_T im;
} cuint1000m_T;

typedef struct {
  uint40_T chunks[26];
} int1040m_T;

typedef struct {
  int1040m_T re;
  int1040m_T im;
} cint1040m_T;

typedef struct {
  uint40_T chunks[26];
} uint1040m_T;

typedef struct {
  uint1040m_T re;
  uint1040m_T im;
} cuint1040m_T;

typedef struct {
  uint40_T chunks[27];
} int1080m_T;

typedef struct {
  int1080m_T re;
  int1080m_T im;
} cint1080m_T;

typedef struct {
  uint40_T chunks[27];
} uint1080m_T;

typedef struct {
  uint1080m_T re;
  uint1080m_T im;
} cuint1080m_T;

typedef struct {
  uint40_T chunks[28];
} int1120m_T;

typedef struct {
  int1120m_T re;
  int1120m_T im;
} cint1120m_T;

typedef struct {
  uint40_T chunks[28];
} uint1120m_T;

typedef struct {
  uint1120m_T re;
  uint1120m_T im;
} cuint1120m_T;

typedef struct {
  uint40_T chunks[29];
} int1160m_T;

typedef struct {
  int1160m_T re;
  int1160m_T im;
} cint1160m_T;

typedef struct {
  uint40_T chunks[29];
} uint1160m_T;

typedef struct {
  uint1160m_T re;
  uint1160m_T im;
} cuint1160m_T;

typedef struct {
  uint40_T chunks[30];
} int1200m_T;

typedef struct {
  int1200m_T re;
  int1200m_T im;
} cint1200m_T;

typedef struct {
  uint40_T chunks[30];
} uint1200m_T;

typedef struct {
  uint1200m_T re;
  uint1200m_T im;
} cuint1200m_T;

typedef struct {
  uint40_T chunks[31];
} int1240m_T;

typedef struct {
  int1240m_T re;
  int1240m_T im;
} cint1240m_T;

typedef struct {
  uint40_T chunks[31];
} uint1240m_T;

typedef struct {
  uint1240m_T re;
  uint1240m_T im;
} cuint1240m_T;

typedef struct {
  uint40_T chunks[32];
} int1280m_T;

typedef struct {
  int1280m_T re;
  int1280m_T im;
} cint1280m_T;

typedef struct {
  uint40_T chunks[32];
} uint1280m_T;

typedef struct {
  uint1280m_T re;
  uint1280m_T im;
} cuint1280m_T;

typedef struct {
  uint40_T chunks[33];
} int1320m_T;

typedef struct {
  int1320m_T re;
  int1320m_T im;
} cint1320m_T;

typedef struct {
  uint40_T chunks[33];
} uint1320m_T;

typedef struct {
  uint1320m_T re;
  uint1320m_T im;
} cuint1320m_T;

typedef struct {
  uint40_T chunks[34];
} int1360m_T;

typedef struct {
  int1360m_T re;
  int1360m_T im;
} cint1360m_T;

typedef struct {
  uint40_T chunks[34];
} uint1360m_T;

typedef struct {
  uint1360m_T re;
  uint1360m_T im;
} cuint1360m_T;

typedef struct {
  uint40_T chunks[35];
} int1400m_T;

typedef struct {
  int1400m_T re;
  int1400m_T im;
} cint1400m_T;

typedef struct {
  uint40_T chunks[35];
} uint1400m_T;

typedef struct {
  uint1400m_T re;
  uint1400m_T im;
} cuint1400m_T;

typedef struct {
  uint40_T chunks[36];
} int1440m_T;

typedef struct {
  int1440m_T re;
  int1440m_T im;
} cint1440m_T;

typedef struct {
  uint40_T chunks[36];
} uint1440m_T;

typedef struct {
  uint1440m_T re;
  uint1440m_T im;
} cuint1440m_T;

typedef struct {
  uint40_T chunks[37];
} int1480m_T;

typedef struct {
  int1480m_T re;
  int1480m_T im;
} cint1480m_T;

typedef struct {
  uint40_T chunks[37];
} uint1480m_T;

typedef struct {
  uint1480m_T re;
  uint1480m_T im;
} cuint1480m_T;

typedef struct {
  uint40_T chunks[38];
} int1520m_T;

typedef struct {
  int1520m_T re;
  int1520m_T im;
} cint1520m_T;

typedef struct {
  uint40_T chunks[38];
} uint1520m_T;

typedef struct {
  uint1520m_T re;
  uint1520m_T im;
} cuint1520m_T;

typedef struct {
  uint40_T chunks[39];
} int1560m_T;

typedef struct {
  int1560m_T re;
  int1560m_T im;
} cint1560m_T;

typedef struct {
  uint40_T chunks[39];
} uint1560m_T;

typedef struct {
  uint1560m_T re;
  uint1560m_T im;
} cuint1560m_T;

typedef struct {
  uint40_T chunks[40];
} int1600m_T;

typedef struct {
  int1600m_T re;
  int1600m_T im;
} cint1600m_T;

typedef struct {
  uint40_T chunks[40];
} uint1600m_T;

typedef struct {
  uint1600m_T re;
  uint1600m_T im;
} cuint1600m_T;

typedef struct {
  uint40_T chunks[41];
} int1640m_T;

typedef struct {
  int1640m_T re;
  int1640m_T im;
} cint1640m_T;

typedef struct {
  uint40_T chunks[41];
} uint1640m_T;

typedef struct {
  uint1640m_T re;
  uint1640m_T im;
} cuint1640m_T;

typedef struct {
  uint40_T chunks[42];
} int1680m_T;

typedef struct {
  int1680m_T re;
  int1680m_T im;
} cint1680m_T;

typedef struct {
  uint40_T chunks[42];
} uint1680m_T;

typedef struct {
  uint1680m_T re;
  uint1680m_T im;
} cuint1680m_T;

typedef struct {
  uint40_T chunks[43];
} int1720m_T;

typedef struct {
  int1720m_T re;
  int1720m_T im;
} cint1720m_T;

typedef struct {
  uint40_T chunks[43];
} uint1720m_T;

typedef struct {
  uint1720m_T re;
  uint1720m_T im;
} cuint1720m_T;

typedef struct {
  uint40_T chunks[44];
} int1760m_T;

typedef struct {
  int1760m_T re;
  int1760m_T im;
} cint1760m_T;

typedef struct {
  uint40_T chunks[44];
} uint1760m_T;

typedef struct {
  uint1760m_T re;
  uint1760m_T im;
} cuint1760m_T;

typedef struct {
  uint40_T chunks[45];
} int1800m_T;

typedef struct {
  int1800m_T re;
  int1800m_T im;
} cint1800m_T;

typedef struct {
  uint40_T chunks[45];
} uint1800m_T;

typedef struct {
  uint1800m_T re;
  uint1800m_T im;
} cuint1800m_T;

typedef struct {
  uint40_T chunks[46];
} int1840m_T;

typedef struct {
  int1840m_T re;
  int1840m_T im;
} cint1840m_T;

typedef struct {
  uint40_T chunks[46];
} uint1840m_T;

typedef struct {
  uint1840m_T re;
  uint1840m_T im;
} cuint1840m_T;

typedef struct {
  uint40_T chunks[47];
} int1880m_T;

typedef struct {
  int1880m_T re;
  int1880m_T im;
} cint1880m_T;

typedef struct {
  uint40_T chunks[47];
} uint1880m_T;

typedef struct {
  uint1880m_T re;
  uint1880m_T im;
} cuint1880m_T;

typedef struct {
  uint40_T chunks[48];
} int1920m_T;

typedef struct {
  int1920m_T re;
  int1920m_T im;
} cint1920m_T;

typedef struct {
  uint40_T chunks[48];
} uint1920m_T;

typedef struct {
  uint1920m_T re;
  uint1920m_T im;
} cuint1920m_T;

typedef struct {
  uint40_T chunks[49];
} int1960m_T;

typedef struct {
  int1960m_T re;
  int1960m_T im;
} cint1960m_T;

typedef struct {
  uint40_T chunks[49];
} uint1960m_T;

typedef struct {
  uint1960m_T re;
  uint1960m_T im;
} cuint1960m_T;

typedef struct {
  uint40_T chunks[50];
} int2000m_T;

typedef struct {
  int2000m_T re;
  int2000m_T im;
} cint2000m_T;

typedef struct {
  uint40_T chunks[50];
} uint2000m_T;

typedef struct {
  uint2000m_T re;
  uint2000m_T im;
} cuint2000m_T;

typedef struct {
  uint40_T chunks[51];
} int2040m_T;

typedef struct {
  int2040m_T re;
  int2040m_T im;
} cint2040m_T;

typedef struct {
  uint40_T chunks[51];
} uint2040m_T;

typedef struct {
  uint2040m_T re;
  uint2040m_T im;
} cuint2040m_T;

typedef struct {
  uint40_T chunks[52];
} int2080m_T;

typedef struct {
  int2080m_T re;
  int2080m_T im;
} cint2080m_T;

typedef struct {
  uint40_T chunks[52];
} uint2080m_T;

typedef struct {
  uint2080m_T re;
  uint2080m_T im;
} cuint2080m_T;

#endif                                 /* MULTIWORD_TYPES_H */
