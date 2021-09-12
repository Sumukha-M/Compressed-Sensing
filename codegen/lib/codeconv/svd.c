/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

/* Include Files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[1600000]
 *                double U[1600000]
 *                double s[800]
 * Return Type  : void
 */
void svd(const double A[1600000], double U[1600000], double s[800])
{
  static double b_A[1600000];
  double work[2000];
  double e[800];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 1600000U * sizeof(double));
  memset(&s[0], 0, 800U * sizeof(double));
  memset(&e[0], 0, 800U * sizeof(double));
  memset(&work[0], 0, 2000U * sizeof(double));
  memset(&U[0], 0, 1600000U * sizeof(double));
  for (q = 0; q < 800; q++) {
    qp1 = q + 2;
    qq = (q + 2000 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(2000 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        ztest = -nrm;
        s[q] = -nrm;
      } else {
        ztest = nrm;
        s[q] = nrm;
      }
      if (fabs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        qjj = (qq - q) + 1999;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 1999;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] /= s[q];
        }
      }
      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (kase = qp1; kase < 801; kase++) {
      qjj = q + 2000 * (kase - 1);
      if (apply_transform) {
        xaxpy(2000 - q,
              -(xdotc(2000 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 2000 * q]), qq,
              b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (k = q + 1; k < 2001; k++) {
      kase = (k + 2000 * q) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 798) {
      nrm = b_xnrm2(799 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 801; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 801; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 2001; k++) {
          work[k - 1] = 0.0;
        }
        for (kase = qp1; kase < 801; kase++) {
          b_xaxpy(1999 - q, e[kase - 1], b_A, (q + 2000 * (kase - 1)) + 2, work,
                  q + 2);
        }
        for (kase = qp1; kase < 801; kase++) {
          c_xaxpy(1999 - q, -e[kase - 1] / e[q + 1], work, q + 2, b_A,
                  (q + 2000 * (kase - 1)) + 2);
        }
      }
    }
  }
  m = 798;
  e[798] = b_A[1598798];
  e[799] = 0.0;
  for (q = 799; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 2000 * q;
    if (s[q] != 0.0) {
      for (kase = qp1; kase < 801; kase++) {
        qjj = (q + 2000 * (kase - 1)) + 1;
        xaxpy(2000 - q, -(xdotc(2000 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1,
              U, qjj);
      }
      for (k = q + 1; k < 2001; k++) {
        kase = (k + 2000 * q) - 1;
        U[kase] = -U[kase];
      }
      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 2000 * q] = 0.0;
      }
    } else {
      memset(&U[q * 2000], 0, 2000U * sizeof(double));
      U[qq] = 1.0;
    }
  }
  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 800; q++) {
    ztest = s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      s[q] = rt;
      if (q + 1 < 800) {
        e[q] /= nrm;
      }
      kase = 2000 * q;
      qjj = kase + 2000;
      for (k = kase + 1; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if ((q + 1 < 800) && (e[q] != 0.0)) {
      rt = fabs(e[q]);
      nrm = rt / e[q];
      e[q] = rt;
      s[q + 1] *= nrm;
    }
    nrm = fabs(s[q]);
    ztest = fabs(e[q]);
    if ((nrm > ztest) || rtIsNaN(ztest)) {
      ztest = nrm;
    }
    if ((!(snorm > ztest)) && (!rtIsNaN(ztest))) {
      snorm = ztest;
    }
  }
  while ((m + 2 > 0) && (qp1 < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((qp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);
    if (k + 1 == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg2 = false;
      while ((!exitg2) && (kase >= k + 1)) {
        qjj = kase;
        if (kase == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }
          if (kase > k + 2) {
            nrm += fabs(e[kase - 2]);
          }
          ztest = fabs(s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg2 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == k + 1) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        q = qjj;
      }
    }
    switch (kase) {
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      qjj = m + 1;
      for (k = qjj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &ztest, &sm, &sqds);
        if (k > q + 1) {
          rt = e[k - 2];
          ztest = -sqds * rt;
          e[k - 2] = rt * sm;
        }
      }
      break;
    case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = -sqds * rt;
        e[k - 1] = rt * sm;
        xrot(U, 2000 * (k - 1) + 1, 2000 * (q - 1) + 1, sm, sqds);
      }
      break;
    case 3:
      kase = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      ztest = fabs(s[m]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[m]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(s[q]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[q]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      sm = nrm / scale;
      nrm = s[m] / scale;
      ztest = e[m] / scale;
      sqds = s[q] / scale;
      rt = ((nrm + sm) * (nrm - sm) + ztest * ztest) / 2.0;
      nrm = sm * ztest;
      nrm *= nrm;
      if ((rt != 0.0) || (nrm != 0.0)) {
        ztest = sqrt(rt * rt + nrm);
        if (rt < 0.0) {
          ztest = -ztest;
        }
        ztest = nrm / (rt + ztest);
      } else {
        ztest = 0.0;
      }
      ztest += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= kase; k++) {
        xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = ztest;
        }
        nrm = e[k - 1];
        rt = s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * s[k];
        s[k] *= sm;
        s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * s[k];
        s[k] = -sqds * e[k - 1] + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 2000 * (k - 1) + 1, 2000 * k + 1, sm, sqds);
      }
      e[m] = ztest;
      qp1++;
      break;
    default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
      }
      qp1 = q + 1;
      while ((q + 1 < 800) && (s[q] < s[qp1])) {
        rt = s[q];
        s[q] = s[qp1];
        s[qp1] = rt;
        xswap(U, 2000 * q + 1, 2000 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }
      qp1 = 0;
      m--;
      break;
    }
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
