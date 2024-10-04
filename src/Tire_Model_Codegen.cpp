//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Tire_Model_Codegen.cpp
//
// Code generated for Simulink model 'Tire_Model_Codegen'.
//
// Model version                  : 1.11
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Fri Oct  4 18:39:37 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Tire_Model_Codegen.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "cmath"

//
// Output and update for atomic system:
//    '<S1>/MATLAB Function1'
//    '<S1>/MATLAB Function2'
//    '<S1>/MATLAB Function3'
//    '<S1>/MATLAB Function4'
//
void Tire_Model_Codegen::Tire_Model_Codegen_MATLABFunction1(real_T rtu_LC_Raw,
  real_T rtu_interp_X, real_T rtu_interp_X_m, real_T rtu_interp_X_b, real_T
  rtu_interp_Y, real_T rtu_interp_Y_o, real_T rtu_interp_Y_a, real_T *rty_FZ)
{
  real_T x[3];
  real_T y[3];
  real_T Vq;
  real_T b_r;
  real_T r;
  int32_T n;
  b_r = rtu_LC_Raw;
  if (rtu_LC_Raw <= 50.0) {
    b_r = 0.0;
  }

  // SignalConversion generated from: '<S5>/ SFunction '
  x[0] = rtu_interp_X;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[0] = rtu_interp_Y;

  // SignalConversion generated from: '<S5>/ SFunction '
  x[1] = rtu_interp_X_m;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[1] = rtu_interp_Y_o;

  // SignalConversion generated from: '<S5>/ SFunction '
  x[2] = rtu_interp_X_b;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[2] = rtu_interp_Y_a;

  // SignalConversion generated from: '<S5>/ SFunction '
  if (rtu_interp_X_m < rtu_interp_X) {
    x[0] = rtu_interp_X_b;
    x[2] = rtu_interp_X;
    y[0] = rtu_interp_Y_a;
    y[2] = rtu_interp_Y;
  }

  if (x[2] < 0.0) {
    // SignalConversion generated from: '<S5>/ SFunction '
    r = -x[2] / (x[2] - rtu_interp_X_m) * (y[2] - rtu_interp_Y_o) + y[2];
  } else if (x[0] > 0.0) {
    // SignalConversion generated from: '<S5>/ SFunction '
    r = -x[0] / (rtu_interp_X_m - x[0]) * (rtu_interp_Y_o - y[0]) + y[0];
  } else {
    n = 0;

    // SignalConversion generated from: '<S5>/ SFunction '
    if (rtu_interp_X_m <= 0.0) {
      n = 1;
    }

    r = (0.0 - x[n]) / (x[n + 1] - x[n]);
    if (r == 0.0) {
      r = y[n];
    } else if (r == 1.0) {
      r = y[n + 1];
    } else {
      Vq = y[n + 1];
      if (Vq == y[n]) {
        r = y[n];
      } else {
        r = (1.0 - r) * y[n] + Vq * r;
      }
    }
  }

  // SignalConversion generated from: '<S5>/ SFunction '
  x[0] = rtu_interp_X;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[0] = rtu_interp_Y;

  // SignalConversion generated from: '<S5>/ SFunction '
  x[1] = rtu_interp_X_m;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[1] = rtu_interp_Y_o;

  // SignalConversion generated from: '<S5>/ SFunction '
  x[2] = rtu_interp_X_b;

  // SignalConversion generated from: '<S5>/ SFunction '
  y[2] = rtu_interp_Y_a;

  // SignalConversion generated from: '<S5>/ SFunction '
  if (rtu_interp_X_m < rtu_interp_X) {
    x[0] = rtu_interp_X_b;
    x[2] = rtu_interp_X;
    y[0] = rtu_interp_Y_a;
    y[2] = rtu_interp_Y;
  }

  if (std::isnan(b_r)) {
    Vq = (rtNaN);
  } else if (b_r > x[2]) {
    // SignalConversion generated from: '<S5>/ SFunction '
    Vq = (b_r - x[2]) / (x[2] - rtu_interp_X_m) * (y[2] - rtu_interp_Y_o) + y[2];
  } else if (b_r < x[0]) {
    // SignalConversion generated from: '<S5>/ SFunction '
    Vq = (b_r - x[0]) / (rtu_interp_X_m - x[0]) * (rtu_interp_Y_o - y[0]) + y[0];
  } else {
    n = 0;

    // SignalConversion generated from: '<S5>/ SFunction '
    if (b_r >= rtu_interp_X_m) {
      n = 1;
    }

    b_r = (b_r - x[n]) / (x[n + 1] - x[n]);
    if (b_r == 0.0) {
      Vq = y[n];
    } else if (b_r == 1.0) {
      Vq = y[n + 1];
    } else {
      Vq = y[n + 1];
      if (Vq == y[n]) {
        Vq = y[n];
      } else {
        Vq = (1.0 - b_r) * y[n] + Vq * b_r;
      }
    }
  }

  *rty_FZ = Vq - r;
  if (*rty_FZ < 0.0) {
    *rty_FZ = 0.0;
  }
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_PSS_FY(const real_T P[22],
  const real_T INPUT[3], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const
  real_T *rtd_LCY, const real_T *rtd_LEY, const real_T *rtd_LFZO, const real_T
  *rtd_LHY, const real_T *rtd_LKYALPHA, const real_T *rtd_LKYGAMMA, const real_T
  *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const real_T *rtd_LVY, const real_T
  *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T *rtd_ZETA4)
{
  real_T ALPHA;
  real_T ALPHAY;
  real_T CY;
  real_T DFZ;
  real_T DY;
  real_T DY_tmp;
  real_T FY;
  real_T FZ;
  real_T FZOPRIME;
  real_T GAMMA_AST;
  real_T KYALPHA;
  real_T tmp;
  real_T u_tmp;
  ALPHA = -(0.017453292519943295 * INPUT[0]);
  FZ = std::abs(INPUT[1]);
  FZOPRIME = *rtd_FZO * *rtd_LFZO;
  DFZ = (FZ - FZOPRIME) / FZOPRIME;
  GAMMA_AST = std::sin(0.017453292519943295 * INPUT[2]);
  CY = P[0] * *rtd_LCY;
  DY_tmp = GAMMA_AST * GAMMA_AST;
  DY = std::abs((P[2] * DFZ + P[1]) / (DY_tmp * P[3] + 1.0) * *rtd_LMUYAST) * FZ
    * *rtd_ZETA2;
  KYALPHA = std::sin(std::atan(FZ / ((DY_tmp * P[13] + P[10]) * FZOPRIME)) * P
                     [12]) * (P[9] * FZOPRIME) / (DY_tmp * P[11] + 1.0) *
    *rtd_ZETA3 * *rtd_LKYALPHA;
  FZOPRIME = (P[21] * DFZ + P[20]) * FZ * GAMMA_AST * *rtd_LKYGAMMA *
    *rtd_LMUYPRIME * *rtd_ZETA2;
  u_tmp = (P[15] * DFZ + P[14]) * FZ * *rtd_LKYGAMMA * GAMMA_AST - FZOPRIME;
  if (std::isnan(u_tmp)) {
    tmp = (rtNaN);
  } else if (u_tmp < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (u_tmp > 0.0);
  }

  ALPHAY = (((u_tmp * *rtd_ZETA4 / (*rtd_EPSILON * tmp + KYALPHA) + (P[17] * DFZ
    + P[16]) * *rtd_LHY) + *rtd_ZETA3) - 1.0) + std::tan(ALPHA);
  if (std::isnan(KYALPHA)) {
    tmp = (rtNaN);
  } else if (KYALPHA < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (KYALPHA > 0.0);
  }

  if (std::isnan(ALPHAY)) {
    u_tmp = (rtNaN);
  } else if (ALPHAY < 0.0) {
    u_tmp = -1.0;
  } else {
    u_tmp = (ALPHAY > 0.0);
  }

  KYALPHA = KYALPHA / (CY * DY + *rtd_EPSILON * tmp) * ALPHAY;
  FY = -(std::sin(std::atan(KYALPHA - ((DY_tmp * P[8] + 1.0) - (P[7] * GAMMA_AST
             + P[6]) * u_tmp) * (P[5] * DFZ + P[4]) * *rtd_LEY * (KYALPHA - std::
            atan(KYALPHA))) * CY) * DY + ((P[19] * DFZ + P[18]) * FZ * *rtd_LVY *
          *rtd_LMUYPRIME * *rtd_ZETA2 + FZOPRIME));
  if (ALPHA == 0.0) {
    FY = 0.0;
  }

  return FY;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FY(const real_T
  R[15], const real_T INPUT[4], const real_T *rtd_EPSILON, const real_T *rtd_FZO,
  const real_T *rtd_LCY, const real_T *rtd_LEY, const real_T *rtd_LFZO, const
  real_T *rtd_LHY, const real_T *rtd_LKYALPHA, const real_T *rtd_LKYGAMMA, const
  real_T *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const real_T *rtd_LVY, const
  real_T *rtd_LVYKAPPA, const real_T *rtd_LYKAPPA, const real_T *rtd_PCY1, const
  real_T *rtd_PDY1, const real_T *rtd_PDY2, const real_T *rtd_PDY3, const real_T
  *rtd_PEY1, const real_T *rtd_PEY2, const real_T *rtd_PEY3, const real_T
  *rtd_PEY4, const real_T *rtd_PEY5, const real_T *rtd_PHY1, const real_T
  *rtd_PHY2, const real_T *rtd_PKY1, const real_T *rtd_PKY2, const real_T
  *rtd_PKY3, const real_T *rtd_PKY4, const real_T *rtd_PKY5, const real_T
  *rtd_PKY6, const real_T *rtd_PKY7, const real_T *rtd_PVY1, const real_T
  *rtd_PVY2, const real_T *rtd_PVY3, const real_T *rtd_PVY4, const real_T
  *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T *rtd_ZETA4)
{
  real_T rtd_PCY1_0[22];
  real_T INPUT_0[3];
  real_T ALPHA_AST;
  real_T BYKAPPA;
  real_T BYKAPPA_tmp;
  real_T EYKAPPA;
  real_T FY;
  real_T FYO;
  real_T FY_tmp;
  real_T FZ;
  real_T FZOPRIME;
  real_T GAMMA_AST;
  real_T SHYKAPPA;
  rtd_PCY1_0[0] = *rtd_PCY1;
  rtd_PCY1_0[1] = *rtd_PDY1;
  rtd_PCY1_0[2] = *rtd_PDY2;
  rtd_PCY1_0[3] = *rtd_PDY3;
  rtd_PCY1_0[4] = *rtd_PEY1;
  rtd_PCY1_0[5] = *rtd_PEY2;
  rtd_PCY1_0[6] = *rtd_PEY3;
  rtd_PCY1_0[7] = *rtd_PEY4;
  rtd_PCY1_0[8] = *rtd_PEY5;
  rtd_PCY1_0[9] = *rtd_PKY1;
  rtd_PCY1_0[10] = *rtd_PKY2;
  rtd_PCY1_0[11] = *rtd_PKY3;
  rtd_PCY1_0[12] = *rtd_PKY4;
  rtd_PCY1_0[13] = *rtd_PKY5;
  rtd_PCY1_0[14] = *rtd_PKY6;
  rtd_PCY1_0[15] = *rtd_PKY7;
  rtd_PCY1_0[16] = *rtd_PHY1;
  rtd_PCY1_0[17] = *rtd_PHY2;
  rtd_PCY1_0[18] = *rtd_PVY1;
  rtd_PCY1_0[19] = *rtd_PVY2;
  rtd_PCY1_0[20] = *rtd_PVY3;
  rtd_PCY1_0[21] = *rtd_PVY4;
  INPUT_0[0] = INPUT[1];
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FYO = Tire_Model_Codegen_Pacejka52_PSS_FY(rtd_PCY1_0, INPUT_0, rtd_EPSILON,
    rtd_FZO, rtd_LCY, rtd_LEY, rtd_LFZO, rtd_LHY, rtd_LKYALPHA, rtd_LKYGAMMA,
    rtd_LMUYAST, rtd_LMUYPRIME, rtd_LVY, rtd_ZETA2, rtd_ZETA3, rtd_ZETA4);
  FYO = -FYO;
  FZ = std::abs(INPUT[2]);
  FZOPRIME = *rtd_FZO * *rtd_LFZO;
  FZOPRIME = (FZ - FZOPRIME) / FZOPRIME;
  GAMMA_AST = std::sin(0.017453292519943295 * INPUT[3]);
  ALPHA_AST = std::tan(-(0.017453292519943295 * INPUT[1]));
  EYKAPPA = R[6] * FZOPRIME + R[5];
  BYKAPPA_tmp = GAMMA_AST * GAMMA_AST;
  BYKAPPA = std::abs((BYKAPPA_tmp * R[3] + R[0]) * std::cos(std::atan((ALPHA_AST
    - R[2]) * R[1])) * *rtd_LYKAPPA);
  SHYKAPPA = R[8] * FZOPRIME + R[7];
  FY_tmp = (INPUT[0] + SHYKAPPA) * BYKAPPA;
  BYKAPPA *= SHYKAPPA;
  FY = std::abs((*rtd_PDY2 * FZOPRIME + *rtd_PDY1) / (BYKAPPA_tmp * *rtd_PDY3 +
    1.0) * *rtd_LMUYPRIME) * FZ * ((R[10] * FZOPRIME + R[9]) + R[11] * GAMMA_AST)
    * std::cos(std::atan(R[12] * ALPHA_AST)) * *rtd_ZETA2 * std::sin(std::atan
    (INPUT[0] * R[14]) * R[13]) * *rtd_LVYKAPPA + std::abs(std::cos(std::atan
    (FY_tmp - (FY_tmp - std::atan(FY_tmp)) * EYKAPPA) * R[4]) / std::cos(std::
    atan(BYKAPPA - (BYKAPPA - std::atan(BYKAPPA)) * EYKAPPA) * R[4])) * FYO;
  if (std::abs(FY) > std::abs(FYO)) {
    FY = FYO;
  }

  FY = -FY;
  return FY;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_PLS_FX(const real_T A[15],
  const real_T INPUT[3], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const
  real_T *rtd_LCX, const real_T *rtd_LEX, const real_T *rtd_LFZO, const real_T
  *rtd_LHX, const real_T *rtd_LKXKAPPA, const real_T *rtd_LMUX, const real_T
  *rtd_LMUXPRIME, const real_T *rtd_LVX, const real_T *rtd_ZETA1)
{
  real_T CX;
  real_T DX;
  real_T FX;
  real_T FZ;
  real_T FZOPRIME;
  real_T KAPPAX;
  real_T tmp;
  FZ = std::abs(INPUT[1]);
  FZOPRIME = *rtd_FZO * *rtd_LFZO;
  FZOPRIME = (FZ - FZOPRIME) / FZOPRIME;
  DX = std::sin(0.017453292519943295 * INPUT[2]);
  KAPPAX = (A[12] * FZOPRIME + A[11]) * *rtd_LHX + INPUT[0];
  CX = A[0] * *rtd_LCX;
  DX = (1.0 - DX * DX * A[3]) * (A[2] * FZOPRIME + A[1]) * *rtd_LMUX * FZ *
    *rtd_ZETA1;
  if (std::isnan(KAPPAX)) {
    tmp = (rtNaN);
  } else if (KAPPAX < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (KAPPAX > 0.0);
  }

  KAPPAX *= (A[9] * FZOPRIME + A[8]) * FZ * std::exp(A[10] * FZOPRIME) *
    *rtd_LKXKAPPA / (CX * DX + *rtd_EPSILON);
  FX = std::sin(std::atan(KAPPAX - ((A[5] * FZOPRIME + A[4]) + FZOPRIME *
    FZOPRIME * A[6]) * (1.0 - A[7] * tmp) * *rtd_LEX * (KAPPAX - std::atan
    (KAPPAX))) * CX) * DX + (A[14] * FZOPRIME + A[13]) * FZ * *rtd_LVX *
    *rtd_LMUXPRIME * *rtd_ZETA1;
  if (INPUT[0] == 0.0) {
    FX = 0.0;
  }

  return FX;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_MZ(const real_T
  S[4], const real_T INPUT[4], const real_T *rtd_EPSILON, const real_T *rtd_FZO,
  const real_T *rtd_LCX, const real_T *rtd_LCY, const real_T *rtd_LEX, const
  real_T *rtd_LEY, const real_T *rtd_LFZO, const real_T *rtd_LHX, const real_T
  *rtd_LHY, const real_T *rtd_LKXKAPPA, const real_T *rtd_LKYALPHA, const real_T
  *rtd_LKYGAMMA, const real_T *rtd_LKZGAMMA, const real_T *rtd_LMR, const real_T
  *rtd_LMUX, const real_T *rtd_LMUXPRIME, const real_T *rtd_LMUYAST, const
  real_T *rtd_LMUYPRIME, const real_T *rtd_LS, const real_T *rtd_LT, const
  real_T *rtd_LVX, const real_T *rtd_LVY, const real_T *rtd_LVYKAPPA, const
  real_T *rtd_LXALPHA, const real_T *rtd_LYKAPPA, const real_T *rtd_PCX1, const
  real_T *rtd_PCY1, const real_T *rtd_PDX1, const real_T *rtd_PDX2, const real_T
  *rtd_PDX3, const real_T *rtd_PDY1, const real_T *rtd_PDY2, const real_T
  *rtd_PDY3, const real_T *rtd_PEX1, const real_T *rtd_PEX2, const real_T
  *rtd_PEX3, const real_T *rtd_PEX4, const real_T *rtd_PEY1, const real_T
  *rtd_PEY2, const real_T *rtd_PEY3, const real_T *rtd_PEY4, const real_T
  *rtd_PEY5, const real_T *rtd_PHX1, const real_T *rtd_PHX2, const real_T
  *rtd_PHY1, const real_T *rtd_PHY2, const real_T *rtd_PKX1, const real_T
  *rtd_PKX2, const real_T *rtd_PKX3, const real_T *rtd_PKY1, const real_T
  *rtd_PKY2, const real_T *rtd_PKY3, const real_T *rtd_PKY4, const real_T
  *rtd_PKY5, const real_T *rtd_PKY6, const real_T *rtd_PKY7, const real_T
  *rtd_PVX1, const real_T *rtd_PVX2, const real_T *rtd_PVY1, const real_T
  *rtd_PVY2, const real_T *rtd_PVY3, const real_T *rtd_PVY4, const real_T
  *rtd_QBZ1, const real_T *rtd_QBZ10, const real_T *rtd_QBZ2, const real_T
  *rtd_QBZ3, const real_T *rtd_QBZ5, const real_T *rtd_QBZ6, const real_T
  *rtd_QBZ9, const real_T *rtd_QCZ1, const real_T *rtd_QDZ1, const real_T
  *rtd_QDZ10, const real_T *rtd_QDZ11, const real_T *rtd_QDZ2, const real_T
  *rtd_QDZ3, const real_T *rtd_QDZ4, const real_T *rtd_QDZ6, const real_T
  *rtd_QDZ7, const real_T *rtd_QDZ8, const real_T *rtd_QDZ9, const real_T
  *rtd_QEZ1, const real_T *rtd_QEZ2, const real_T *rtd_QEZ3, const real_T
  *rtd_QEZ4, const real_T *rtd_QEZ5, const real_T *rtd_QHZ1, const real_T
  *rtd_QHZ2, const real_T *rtd_QHZ3, const real_T *rtd_QHZ4, const real_T
  *rtd_RBX1, const real_T *rtd_RBX2, const real_T *rtd_RBX3, const real_T
  *rtd_RBY1, const real_T *rtd_RBY2, const real_T *rtd_RBY3, const real_T
  *rtd_RBY4, const real_T *rtd_RCX1, const real_T *rtd_RCY1, const real_T
  *rtd_REX1, const real_T *rtd_REX2, const real_T *rtd_REY1, const real_T
  *rtd_REY2, const real_T *rtd_RHX1, const real_T *rtd_RHY1, const real_T
  *rtd_RHY2, const real_T *rtd_RO, const real_T *rtd_RVY1, const real_T
  *rtd_RVY2, const real_T *rtd_RVY3, const real_T *rtd_RVY4, const real_T
  *rtd_RVY5, const real_T *rtd_RVY6, const real_T *rtd_VCX, const real_T
  *rtd_ZETA0, const real_T *rtd_ZETA1, const real_T *rtd_ZETA2, const real_T
  *rtd_ZETA3, const real_T *rtd_ZETA4, const real_T *rtd_ZETA5, const real_T
  *rtd_ZETA6, const real_T *rtd_ZETA7, const real_T *rtd_ZETA8)
{
  real_T rtd_PCY1_0[22];
  real_T rtd_PCX1_0[15];
  real_T INPUT_0[3];
  real_T ALPHAR;
  real_T ALPHAT;
  real_T BT;
  real_T BT_tmp;
  real_T BXALPHA;
  real_T BXALPHA_tmp;
  real_T CY;
  real_T EXALPHA;
  real_T EXALPHA_tmp;
  real_T EXALPHA_tmp_0;
  real_T FXO;
  real_T FYO;
  real_T FY_tmp;
  real_T KYALPHAPRIME;
  real_T MZ;
  real_T MZ_tmp;
  real_T SHYKAPPA;
  real_T SVYGAMMA;
  real_T b_FZOPRIME_tmp;
  real_T c_a_tmp;
  real_T tmp;
  real_T tmp_0;
  real_T u_tmp;
  rtd_PCX1_0[0] = *rtd_PCX1;
  rtd_PCX1_0[1] = *rtd_PDX1;
  rtd_PCX1_0[2] = *rtd_PDX2;
  rtd_PCX1_0[3] = *rtd_PDX3;
  rtd_PCX1_0[4] = *rtd_PEX1;
  rtd_PCX1_0[5] = *rtd_PEX2;
  rtd_PCX1_0[6] = *rtd_PEX3;
  rtd_PCX1_0[7] = *rtd_PEX4;
  rtd_PCX1_0[8] = *rtd_PKX1;
  rtd_PCX1_0[9] = *rtd_PKX2;
  rtd_PCX1_0[10] = *rtd_PKX3;
  rtd_PCX1_0[11] = *rtd_PHX1;
  rtd_PCX1_0[12] = *rtd_PHX2;
  rtd_PCX1_0[13] = *rtd_PVX1;
  rtd_PCX1_0[14] = *rtd_PVX2;
  INPUT_0[0] = 0.0;
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FXO = Tire_Model_Codegen_Pacejka52_PLS_FX(rtd_PCX1_0, INPUT_0, rtd_EPSILON,
    rtd_FZO, rtd_LCX, rtd_LEX, rtd_LFZO, rtd_LHX, rtd_LKXKAPPA, rtd_LMUX,
    rtd_LMUXPRIME, rtd_LVX, rtd_ZETA1);
  b_FZOPRIME_tmp = *rtd_FZO * *rtd_LFZO;
  c_a_tmp = std::sin(0.017453292519943295 * INPUT[3]);
  EXALPHA_tmp = std::abs(INPUT[2]);
  EXALPHA_tmp_0 = (EXALPHA_tmp - b_FZOPRIME_tmp) / b_FZOPRIME_tmp;
  EXALPHA = EXALPHA_tmp_0 * *rtd_REX2 + *rtd_REX1;
  ALPHAR = std::tan(-(0.017453292519943295 * INPUT[1]));
  BXALPHA_tmp = c_a_tmp * c_a_tmp;
  BXALPHA = std::abs((BXALPHA_tmp * *rtd_RBX3 + *rtd_RBX1) * std::cos(std::atan(*
    rtd_RBX2 * 0.0)) * *rtd_LXALPHA);
  SHYKAPPA = (ALPHAR + *rtd_RHX1) * BXALPHA;
  BXALPHA *= *rtd_RHX1;
  EXALPHA = std::abs(std::cos(std::atan(SHYKAPPA - (SHYKAPPA - std::atan
    (SHYKAPPA)) * EXALPHA) * *rtd_RCX1) / std::cos(std::atan(BXALPHA - (BXALPHA
    - std::atan(BXALPHA)) * EXALPHA) * *rtd_RCX1)) * FXO;
  if (std::abs(EXALPHA) > std::abs(FXO)) {
    EXALPHA = FXO;
  }

  rtd_PCY1_0[0] = *rtd_PCY1;
  rtd_PCY1_0[1] = *rtd_PDY1;
  rtd_PCY1_0[2] = *rtd_PDY2;
  rtd_PCY1_0[3] = *rtd_PDY3;
  rtd_PCY1_0[4] = *rtd_PEY1;
  rtd_PCY1_0[5] = *rtd_PEY2;
  rtd_PCY1_0[6] = *rtd_PEY3;
  rtd_PCY1_0[7] = *rtd_PEY4;
  rtd_PCY1_0[8] = *rtd_PEY5;
  rtd_PCY1_0[9] = *rtd_PKY1;
  rtd_PCY1_0[10] = *rtd_PKY2;
  rtd_PCY1_0[11] = *rtd_PKY3;
  rtd_PCY1_0[12] = *rtd_PKY4;
  rtd_PCY1_0[13] = *rtd_PKY5;
  rtd_PCY1_0[14] = *rtd_PKY6;
  rtd_PCY1_0[15] = *rtd_PKY7;
  rtd_PCY1_0[16] = *rtd_PHY1;
  rtd_PCY1_0[17] = *rtd_PHY2;
  rtd_PCY1_0[18] = *rtd_PVY1;
  rtd_PCY1_0[19] = *rtd_PVY2;
  rtd_PCY1_0[20] = *rtd_PVY3;
  rtd_PCY1_0[21] = *rtd_PVY4;
  INPUT_0[0] = INPUT[1];
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FYO = Tire_Model_Codegen_Pacejka52_PSS_FY(rtd_PCY1_0, INPUT_0, rtd_EPSILON,
    rtd_FZO, rtd_LCY, rtd_LEY, rtd_LFZO, rtd_LHY, rtd_LKYALPHA, rtd_LKYGAMMA,
    rtd_LMUYAST, rtd_LMUYPRIME, rtd_LVY, rtd_ZETA2, rtd_ZETA3, rtd_ZETA4);
  FYO = -FYO;
  BXALPHA = *rtd_REY2 * EXALPHA_tmp_0 + *rtd_REY1;
  FXO = std::abs((BXALPHA_tmp * *rtd_RBY4 + *rtd_RBY1) * std::cos(std::atan
    ((ALPHAR - *rtd_RBY3) * *rtd_RBY2)) * *rtd_LYKAPPA);
  SHYKAPPA = *rtd_RHY2 * EXALPHA_tmp_0 + *rtd_RHY1;
  CY = (INPUT[0] + SHYKAPPA) * FXO;
  FY_tmp = FXO * SHYKAPPA;
  FXO = std::abs((*rtd_PDY2 * EXALPHA_tmp_0 + *rtd_PDY1) / (BXALPHA_tmp *
    *rtd_PDY3 + 1.0) * *rtd_LMUYPRIME) * EXALPHA_tmp;
  SHYKAPPA = ((*rtd_RVY2 * EXALPHA_tmp_0 + *rtd_RVY1) + *rtd_RVY3 * c_a_tmp) *
    FXO * std::cos(std::atan(*rtd_RVY4 * ALPHAR)) * *rtd_ZETA2;
  BXALPHA = std::abs(std::cos(std::atan(CY - (CY - std::atan(CY)) * BXALPHA) *
    *rtd_RCY1) / std::cos(std::atan(FY_tmp - (FY_tmp - std::atan(FY_tmp)) *
    BXALPHA) * *rtd_RCY1)) * FYO + std::sin(std::atan(INPUT[0] * *rtd_RVY6) *
    *rtd_RVY5) * SHYKAPPA * *rtd_LVYKAPPA;
  if (std::abs(BXALPHA) > std::abs(FYO)) {
    BXALPHA = FYO;
  }

  FYO = std::sin(std::atan(EXALPHA_tmp / ((BXALPHA_tmp * *rtd_PKY5 + *rtd_PKY2) *
    b_FZOPRIME_tmp)) * *rtd_PKY4) * (*rtd_PKY1 * b_FZOPRIME_tmp) / (BXALPHA_tmp *
    *rtd_PKY3 + 1.0) * *rtd_ZETA3 * *rtd_LKYALPHA;
  SVYGAMMA = (*rtd_PVY4 * EXALPHA_tmp_0 + *rtd_PVY3) * EXALPHA_tmp * c_a_tmp *
    *rtd_LKYGAMMA * *rtd_LMUYPRIME * *rtd_ZETA2;
  CY = *rtd_PCY1 * *rtd_LCY;
  FY_tmp = std::abs(c_a_tmp);
  BT_tmp = EXALPHA_tmp_0 * EXALPHA_tmp_0;
  BT = ((*rtd_QBZ2 * EXALPHA_tmp_0 + *rtd_QBZ1) + BT_tmp * *rtd_QBZ3) *
    ((*rtd_QBZ5 * FY_tmp + 1.0) + BXALPHA_tmp * *rtd_QBZ6) * *rtd_LKYALPHA /
    *rtd_LMUYAST;
  ALPHAT = ((*rtd_QHZ4 * EXALPHA_tmp_0 + *rtd_QHZ3) * c_a_tmp + (*rtd_QHZ2 *
             EXALPHA_tmp_0 + *rtd_QHZ1)) + ALPHAR;
  KYALPHAPRIME = FYO + *rtd_EPSILON;
  u_tmp = (*rtd_PKY7 * EXALPHA_tmp_0 + *rtd_PKY6) * EXALPHA_tmp * *rtd_LKYGAMMA *
    c_a_tmp - SVYGAMMA;
  if (std::isnan(u_tmp)) {
    MZ_tmp = (rtNaN);
  } else if (u_tmp < 0.0) {
    MZ_tmp = -1.0;
  } else {
    MZ_tmp = (u_tmp > 0.0);
  }

  ALPHAR += ((*rtd_PVY2 * EXALPHA_tmp_0 + *rtd_PVY1) * EXALPHA_tmp * *rtd_LVY * *
             rtd_LMUYPRIME * *rtd_ZETA2 + SVYGAMMA) / KYALPHAPRIME + (((u_tmp * *
    rtd_ZETA4 / (*rtd_EPSILON * MZ_tmp + FYO) + (*rtd_PHY2 * EXALPHA_tmp_0 +
    *rtd_PHY1) * *rtd_LHY) + *rtd_ZETA3) - 1.0);
  KYALPHAPRIME = (*rtd_PKX2 * EXALPHA_tmp_0 + *rtd_PKX1) * EXALPHA_tmp * std::
    exp(*rtd_PKX3 * EXALPHA_tmp_0) * *rtd_LKXKAPPA / KYALPHAPRIME;
  if (std::isnan(ALPHAT)) {
    MZ_tmp = (rtNaN);
  } else if (ALPHAT < 0.0) {
    MZ_tmp = -1.0;
  } else {
    MZ_tmp = (ALPHAT > 0.0);
  }

  KYALPHAPRIME = KYALPHAPRIME * KYALPHAPRIME * 0.0;
  SVYGAMMA = std::cos(-(0.017453292519943295 * INPUT[1]));
  if (std::isnan(*rtd_VCX)) {
    u_tmp = (rtNaN);
  } else if (*rtd_VCX < 0.0) {
    u_tmp = -1.0;
  } else {
    u_tmp = (*rtd_VCX > 0.0);
  }

  if (std::isnan(FYO)) {
    tmp = (rtNaN);
  } else if (FYO < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (FYO > 0.0);
  }

  if (std::isnan(ALPHAR)) {
    tmp_0 = (rtNaN);
  } else if (ALPHAR < 0.0) {
    tmp_0 = -1.0;
  } else {
    tmp_0 = (ALPHAR > 0.0);
  }

  MZ_tmp = std::sqrt(ALPHAT * ALPHAT + KYALPHAPRIME) * MZ_tmp * BT;
  MZ = -(((((((*rtd_QDZ9 * EXALPHA_tmp_0 + *rtd_QDZ8) * c_a_tmp * *rtd_LKZGAMMA *
              *rtd_ZETA0 + (*rtd_QDZ7 * EXALPHA_tmp_0 + *rtd_QDZ6) * *rtd_LMR * *
              rtd_ZETA2) + (*rtd_QDZ11 * EXALPHA_tmp_0 + *rtd_QDZ10) * c_a_tmp *
             FY_tmp * *rtd_ZETA0) * (EXALPHA_tmp * *rtd_RO) * SVYGAMMA *
            *rtd_LMUYAST * u_tmp + *rtd_ZETA8) - 1.0) * std::cos(std::atan((FYO /
             (FXO * *rtd_ZETA2 * CY + *rtd_EPSILON * tmp) * *rtd_QBZ10 * CY +
             *rtd_QBZ9 * *rtd_LKYALPHA / *rtd_LMUYAST) * *rtd_ZETA6 * (std::sqrt
             (ALPHAR * ALPHAR + KYALPHAPRIME) * tmp_0)) * *rtd_ZETA7) + -(std::
           cos(std::atan(MZ_tmp - ((*rtd_QEZ5 * c_a_tmp + *rtd_QEZ4) *
              0.63661977236758138 * std::atan(BT * *rtd_QCZ1 * ALPHAT) + 1.0) *
             ((*rtd_QEZ2 * EXALPHA_tmp_0 + *rtd_QEZ1) + BT_tmp * *rtd_QEZ3) *
             (MZ_tmp - std::atan(MZ_tmp))) * *rtd_QCZ1) * (*rtd_RO /
            b_FZOPRIME_tmp * EXALPHA_tmp * (*rtd_QDZ2 * EXALPHA_tmp_0 +
             *rtd_QDZ1) * *rtd_LT * u_tmp * ((*rtd_QDZ3 * FY_tmp + 1.0) +
             BXALPHA_tmp * *rtd_QDZ4) * *rtd_ZETA5) * SVYGAMMA) * (BXALPHA - std::
           sin(std::atan(*rtd_RVY6 * 0.0) * *rtd_RVY5) * SHYKAPPA *
           *rtd_LVYKAPPA)) + ((BXALPHA / b_FZOPRIME_tmp * S[1] + S[0]) + (S[3] *
           EXALPHA_tmp_0 + S[2]) * c_a_tmp) * *rtd_RO * *rtd_LS * EXALPHA);
  return MZ;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_repelem(real_T x, real_T y[100])
{
  for (int32_T j{0}; j < 100; j++) {
    y[j] = x;
  }
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FY_m(const real_T
  R[15], const real_T INPUT[400], real_T FY[100], const real_T *rtd_EPSILON,
  const real_T *rtd_FZO, const real_T *rtd_LCY, const real_T *rtd_LEY, const
  real_T *rtd_LFZO, const real_T *rtd_LHY, const real_T *rtd_LKYALPHA, const
  real_T *rtd_LKYGAMMA, const real_T *rtd_LMUYAST, const real_T *rtd_LMUYPRIME,
  const real_T *rtd_LVY, const real_T *rtd_LVYKAPPA, const real_T *rtd_LYKAPPA,
  const real_T *rtd_PCY1, const real_T *rtd_PDY1, const real_T *rtd_PDY2, const
  real_T *rtd_PDY3, const real_T *rtd_PEY1, const real_T *rtd_PEY2, const real_T
  *rtd_PEY3, const real_T *rtd_PEY4, const real_T *rtd_PEY5, const real_T
  *rtd_PHY1, const real_T *rtd_PHY2, const real_T *rtd_PKY1, const real_T
  *rtd_PKY2, const real_T *rtd_PKY3, const real_T *rtd_PKY4, const real_T
  *rtd_PKY5, const real_T *rtd_PKY6, const real_T *rtd_PKY7, const real_T
  *rtd_PVY1, const real_T *rtd_PVY2, const real_T *rtd_PVY3, const real_T
  *rtd_PVY4, const real_T *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T
  *rtd_ZETA4)
{
  real_T SHYKAPPA[100];
  real_T b_MUY[100];
  real_T y[100];
  real_T CY;
  real_T P;
  real_T R_0;
  real_T R_1;
  real_T R_2;
  real_T R_3;
  real_T R_4;
  real_T R_5;
  real_T R_6;
  real_T R_7;
  real_T R_8;
  real_T R_9;
  real_T R_a;
  real_T R_b;
  real_T R_c;
  real_T R_d;
  real_T R_e;
  real_T R_f;
  real_T b_FZOPRIME_tmp;
  int32_T i;
  boolean_T b_y;
  boolean_T exitg1;
  b_FZOPRIME_tmp = *rtd_FZO * *rtd_LFZO;
  CY = *rtd_PCY1 * *rtd_LCY;
  P = *rtd_PKY1 * b_FZOPRIME_tmp;
  R_0 = R[14];
  R_1 = R[13];
  R_2 = R[1];
  R_3 = R[2];
  R_4 = R[0];
  R_5 = R[3];
  R_6 = R[4];
  R_7 = R[4];
  R_8 = R[9];
  R_9 = R[10];
  R_a = R[11];
  R_b = R[12];
  R_c = R[5];
  R_d = R[6];
  R_e = R[7];
  R_f = R[8];
  for (i = 0; i < 100; i++) {
    real_T ALPHA;
    real_T ALPHA_AST;
    real_T ALPHA_AST_tmp;
    real_T DFZ_tmp;
    real_T FZ_tmp;
    real_T GAMMA_AST_tmp;
    real_T KYALPHA;
    real_T SHYKAPPA_0;
    real_T SVYGAMMA;
    real_T b_MUY_0;
    real_T b_MUY_tmp;
    real_T b_MUY_tmp_0;
    real_T tmp;
    ALPHA = -(INPUT[i + 100] * 0.017453292519943295);
    FZ_tmp = std::abs(INPUT[i + 200]);
    DFZ_tmp = (FZ_tmp - b_FZOPRIME_tmp) / b_FZOPRIME_tmp;
    GAMMA_AST_tmp = std::sin(INPUT[i + 300] * 0.017453292519943295);
    b_MUY_tmp = GAMMA_AST_tmp * GAMMA_AST_tmp;
    b_MUY_tmp_0 = (*rtd_PDY2 * DFZ_tmp + *rtd_PDY1) / (b_MUY_tmp * *rtd_PDY3 +
      1.0);
    b_MUY_0 = std::abs(b_MUY_tmp_0 * *rtd_LMUYAST) * FZ_tmp * *rtd_ZETA2;
    KYALPHA = std::sin(std::atan(FZ_tmp / ((b_MUY_tmp * *rtd_PKY5 + *rtd_PKY2) *
      b_FZOPRIME_tmp)) * *rtd_PKY4) * P / (b_MUY_tmp * *rtd_PKY3 + 1.0) *
      *rtd_ZETA3 * *rtd_LKYALPHA;
    SVYGAMMA = (*rtd_PVY4 * DFZ_tmp + *rtd_PVY3) * FZ_tmp * GAMMA_AST_tmp *
      *rtd_LKYGAMMA * *rtd_LMUYPRIME * *rtd_ZETA2;
    SHYKAPPA_0 = (*rtd_PKY7 * DFZ_tmp + *rtd_PKY6) * FZ_tmp * *rtd_LKYGAMMA *
      GAMMA_AST_tmp - SVYGAMMA;
    if (std::isnan(SHYKAPPA_0)) {
      tmp = (rtNaN);
    } else if (SHYKAPPA_0 < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (SHYKAPPA_0 > 0.0);
    }

    ALPHA_AST_tmp = std::tan(ALPHA);
    ALPHA_AST = ((((*rtd_PHY2 * DFZ_tmp + *rtd_PHY1) * *rtd_LHY + SHYKAPPA_0 *
                   *rtd_ZETA4 / (*rtd_EPSILON * tmp + KYALPHA)) + *rtd_ZETA3) -
                 1.0) + ALPHA_AST_tmp;
    if (std::isnan(KYALPHA)) {
      tmp = (rtNaN);
    } else if (KYALPHA < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (KYALPHA > 0.0);
    }

    KYALPHA = KYALPHA / (CY * b_MUY_0 + *rtd_EPSILON * tmp) * ALPHA_AST;
    if (std::isnan(ALPHA_AST)) {
      tmp = (rtNaN);
    } else if (ALPHA_AST < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (ALPHA_AST > 0.0);
    }

    b_MUY_0 = -(std::sin(std::atan(KYALPHA - ((b_MUY_tmp * *rtd_PEY5 + 1.0) -
      (*rtd_PEY4 * GAMMA_AST_tmp + *rtd_PEY3) * tmp) * (*rtd_PEY2 * DFZ_tmp +
      *rtd_PEY1) * *rtd_LEY * (KYALPHA - std::atan(KYALPHA))) * CY) * b_MUY_0 +
                ((*rtd_PVY2 * DFZ_tmp + *rtd_PVY1) * FZ_tmp * *rtd_LVY *
                 *rtd_LMUYPRIME * *rtd_ZETA2 + SVYGAMMA));
    if (ALPHA == 0.0) {
      b_MUY_0 = 0.0;
    }

    b_MUY[i] = -b_MUY_0;
    ALPHA = INPUT[i];
    SVYGAMMA = R_d * DFZ_tmp + R_c;
    ALPHA_AST = std::abs((b_MUY_tmp * R_5 + R_4) * std::cos(std::atan
      ((ALPHA_AST_tmp - R_3) * R_2)) * *rtd_LYKAPPA);
    SHYKAPPA_0 = R_f * DFZ_tmp + R_e;
    KYALPHA = ALPHA_AST * SHYKAPPA_0;
    ALPHA_AST *= ALPHA + SHYKAPPA_0;
    FZ_tmp = ((R_9 * DFZ_tmp + R_8) + R_a * GAMMA_AST_tmp) * (std::abs
      (b_MUY_tmp_0 * *rtd_LMUYPRIME) * FZ_tmp) * std::cos(std::atan(R_b *
      ALPHA_AST_tmp)) * *rtd_ZETA2 * std::sin(std::atan(R_0 * ALPHA) * R_1) *
      *rtd_LVYKAPPA + std::abs(std::cos(std::atan(ALPHA_AST - (ALPHA_AST - std::
      atan(ALPHA_AST)) * SVYGAMMA) * R_7) / std::cos(std::atan(KYALPHA -
      (KYALPHA - std::atan(KYALPHA)) * SVYGAMMA) * R_6)) * -b_MUY_0;
    FY[i] = FZ_tmp;
    y[i] = std::abs(FZ_tmp);
    SHYKAPPA[i] = std::abs(-b_MUY_0);
  }

  b_y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 100)) {
    if (!(y[i] > SHYKAPPA[i])) {
      b_y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  for (i = 0; i < 100; i++) {
    if (b_y) {
      FY[i] = b_MUY[i];
    }

    FY[i] = -FY[i];
  }
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_maximum(const real_T x[100])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 101)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 101; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_interp1(const real_T varargin_1
  [100], const real_T varargin_2[100], real_T varargin_3)
{
  real_T x[100];
  real_T y[100];
  real_T Vq;
  real_T xtmp;
  int32_T i;
  std::memcpy(&y[0], &varargin_2[0], 100U * sizeof(real_T));
  std::memcpy(&x[0], &varargin_1[0], 100U * sizeof(real_T));
  if (varargin_1[1] < varargin_1[0]) {
    for (i = 0; i < 50; i++) {
      xtmp = x[i];
      x[i] = x[99 - i];
      x[99 - i] = xtmp;
      xtmp = y[i];
      y[i] = y[99 - i];
      y[99 - i] = xtmp;
    }
  }

  Vq = (rtNaN);
  if ((!std::isnan(varargin_3)) && (!(varargin_3 > x[99])) && (!(varargin_3 < x
        [0]))) {
    int32_T high_i;
    int32_T low_ip1;
    i = 1;
    low_ip1 = 2;
    high_i = 100;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = (i + high_i) >> 1;
      if (varargin_3 >= x[mid_i - 1]) {
        i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xtmp = x[i - 1];
    xtmp = (varargin_3 - xtmp) / (x[i] - xtmp);
    if (xtmp == 0.0) {
      Vq = y[i - 1];
    } else if (xtmp == 1.0) {
      Vq = y[i];
    } else {
      Vq = y[i - 1];
      if (!(Vq == y[i])) {
        Vq = (1.0 - xtmp) * Vq + xtmp * y[i];
      }
    }
  }

  return Vq;
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FX(const real_T
  R[7], const real_T INPUT[400], real_T FX[100], const real_T *rtd_EPSILON,
  const real_T *rtd_FZO, const real_T *rtd_LCX, const real_T *rtd_LEX, const
  real_T *rtd_LFZO, const real_T *rtd_LHX, const real_T *rtd_LKXKAPPA, const
  real_T *rtd_LMUX, const real_T *rtd_LMUXPRIME, const real_T *rtd_LVX, const
  real_T *rtd_LXALPHA, const real_T *rtd_PCX1, const real_T *rtd_PDX1, const
  real_T *rtd_PDX2, const real_T *rtd_PDX3, const real_T *rtd_PEX1, const real_T
  *rtd_PEX2, const real_T *rtd_PEX3, const real_T *rtd_PEX4, const real_T
  *rtd_PHX1, const real_T *rtd_PHX2, const real_T *rtd_PKX1, const real_T
  *rtd_PKX2, const real_T *rtd_PKX3, const real_T *rtd_PVX1, const real_T
  *rtd_PVX2, const real_T *rtd_ZETA1)
{
  real_T DX[100];
  real_T GAMMA_AST[100];
  real_T y[100];
  real_T CX;
  real_T R_0;
  real_T R_1;
  real_T R_2;
  real_T R_3;
  real_T R_4;
  real_T R_5;
  real_T R_6;
  real_T R_7;
  real_T b_FZOPRIME_tmp;
  int32_T i;
  boolean_T b_y;
  boolean_T exitg1;
  b_FZOPRIME_tmp = *rtd_FZO * *rtd_LFZO;
  CX = *rtd_PCX1 * *rtd_LCX;
  R_0 = R[4];
  R_1 = R[5];
  R_2 = R[1];
  R_3 = R[0];
  R_4 = R[2];
  R_5 = R[3];
  R_6 = R[6];
  R_7 = R[3];
  for (i = 0; i < 100; i++) {
    real_T DFZ_tmp;
    real_T DX_tmp;
    real_T FZ;
    real_T GAMMA_AST_tmp;
    real_T INPUT_0;
    real_T KAPPAX;
    real_T x;
    INPUT_0 = INPUT[i];
    FZ = std::abs(INPUT[i + 200]);
    DFZ_tmp = (FZ - b_FZOPRIME_tmp) / b_FZOPRIME_tmp;
    GAMMA_AST_tmp = std::sin(INPUT[i + 300] * 0.017453292519943295);
    KAPPAX = (*rtd_PHX2 * DFZ_tmp + *rtd_PHX1) * *rtd_LHX + INPUT_0;
    DX_tmp = GAMMA_AST_tmp * GAMMA_AST_tmp;
    GAMMA_AST_tmp = (1.0 - DX_tmp * *rtd_PDX3) * (*rtd_PDX2 * DFZ_tmp +
      *rtd_PDX1) * *rtd_LMUX * FZ * *rtd_ZETA1;
    x = (*rtd_PKX2 * DFZ_tmp + *rtd_PKX1) * FZ * std::exp(*rtd_PKX3 * DFZ_tmp) *
      *rtd_LKXKAPPA / (CX * GAMMA_AST_tmp + *rtd_EPSILON) * KAPPAX;
    if (std::isnan(KAPPAX)) {
      KAPPAX = (rtNaN);
    } else if (KAPPAX < 0.0) {
      KAPPAX = -1.0;
    } else {
      KAPPAX = (KAPPAX > 0.0);
    }

    GAMMA_AST_tmp = std::sin(std::atan(x - ((*rtd_PEX2 * DFZ_tmp + *rtd_PEX1) +
      DFZ_tmp * DFZ_tmp * *rtd_PEX3) * (1.0 - *rtd_PEX4 * KAPPAX) * *rtd_LEX *
      (x - std::atan(x))) * CX) * GAMMA_AST_tmp + (*rtd_PVX2 * DFZ_tmp +
      *rtd_PVX1) * FZ * *rtd_LVX * *rtd_LMUXPRIME * *rtd_ZETA1;
    DX[i] = GAMMA_AST_tmp;
    if (INPUT_0 == 0.0) {
      GAMMA_AST_tmp = 0.0;
      DX[i] = 0.0;
    }

    FZ = DFZ_tmp * R_1 + R_0;
    INPUT_0 = std::abs((DX_tmp * R_4 + R_3) * std::cos(std::atan(R_2 * INPUT_0))
                       * *rtd_LXALPHA);
    DFZ_tmp = INPUT_0 * R[6];
    INPUT_0 *= std::tan(-(INPUT[i + 100] * 0.017453292519943295)) + R_6;
    FZ = std::abs(std::cos(std::atan(INPUT_0 - (INPUT_0 - std::atan(INPUT_0)) *
      FZ) * R_7) / std::cos(std::atan(DFZ_tmp - (DFZ_tmp - std::atan(DFZ_tmp)) *
      FZ) * R_5)) * GAMMA_AST_tmp;
    FX[i] = FZ;
    y[i] = std::abs(FZ);
    GAMMA_AST[i] = std::abs(GAMMA_AST_tmp);
  }

  b_y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 100)) {
    if (!(y[i] > GAMMA_AST[i])) {
      b_y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (b_y) {
    std::memcpy(&FX[0], &DX[0], 100U * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S17>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_minimum(const real_T x[100])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 101)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 101; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex > x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

//
// Output and update for atomic system:
//    '<S17>/MATLAB Function'
//    '<S18>/MATLAB Function'
//    '<S19>/MATLAB Function'
//    '<S20>/MATLAB Function'
//
void Tire_Model_Codegen::Tire_Model_Codegen_MATLABFunction(const real_T
  rtu_LAMBDA[37], const real_T rtu_A[22], const real_T rtu_B[27], const real_T
  rtu_C[3], const real_T rtu_D[15], const real_T rtu_E[7], const real_T rtu_F[15],
  const real_T rtu_G[4], real_T rtu_SL, real_T rtu_SA, real_T rtu_FZ, real_T
  rtu_IA, real_T *rty_COMBINED_FX, real_T *rty_COMBINED_FY, real_T
  *rty_COMBINED_MZ, real_T *rty_satAccelT, real_T *rty_satBrakeT, real_T
  *rtd_AMU, real_T *rtd_EPSILON, real_T *rtd_FZO, real_T *rtd_LCX, real_T
  *rtd_LCY, real_T *rtd_LEX, real_T *rtd_LEY, real_T *rtd_LFZO, real_T *rtd_LHX,
  real_T *rtd_LHY, real_T *rtd_LKXKAPPA, real_T *rtd_LKYALPHA, real_T
  *rtd_LKYGAMMA, real_T *rtd_LKZGAMMA, real_T *rtd_LMR, real_T *rtd_LMUV, real_T
  *rtd_LMUX, real_T *rtd_LMUXAST, real_T *rtd_LMUXPRIME, real_T *rtd_LMUY,
  real_T *rtd_LMUYAST, real_T *rtd_LMUYPRIME, real_T *rtd_LMX, real_T *rtd_LS,
  real_T *rtd_LT, real_T *rtd_LVX, real_T *rtd_LVY, real_T *rtd_LVYKAPPA, real_T
  *rtd_LXALPHA, real_T *rtd_LYKAPPA, real_T *rtd_PCX1, real_T *rtd_PCY1, real_T *
  rtd_PDX1, real_T *rtd_PDX2, real_T *rtd_PDX3, real_T *rtd_PDY1, real_T
  *rtd_PDY2, real_T *rtd_PDY3, real_T *rtd_PEX1, real_T *rtd_PEX2, real_T
  *rtd_PEX3, real_T *rtd_PEX4, real_T *rtd_PEY1, real_T *rtd_PEY2, real_T
  *rtd_PEY3, real_T *rtd_PEY4, real_T *rtd_PEY5, real_T *rtd_PHX1, real_T
  *rtd_PHX2, real_T *rtd_PHY1, real_T *rtd_PHY2, real_T *rtd_PKX1, real_T
  *rtd_PKX2, real_T *rtd_PKX3, real_T *rtd_PKY1, real_T *rtd_PKY2, real_T
  *rtd_PKY3, real_T *rtd_PKY4, real_T *rtd_PKY5, real_T *rtd_PKY6, real_T
  *rtd_PKY7, real_T *rtd_PVX1, real_T *rtd_PVX2, real_T *rtd_PVY1, real_T
  *rtd_PVY2, real_T *rtd_PVY3, real_T *rtd_PVY4, real_T *rtd_QBZ1, real_T
  *rtd_QBZ10, real_T *rtd_QBZ2, real_T *rtd_QBZ3, real_T *rtd_QBZ5, real_T
  *rtd_QBZ6, real_T *rtd_QBZ9, real_T *rtd_QCZ1, real_T *rtd_QDZ1, real_T
  *rtd_QDZ10, real_T *rtd_QDZ11, real_T *rtd_QDZ2, real_T *rtd_QDZ3, real_T
  *rtd_QDZ4, real_T *rtd_QDZ6, real_T *rtd_QDZ7, real_T *rtd_QDZ8, real_T
  *rtd_QDZ9, real_T *rtd_QEZ1, real_T *rtd_QEZ2, real_T *rtd_QEZ3, real_T
  *rtd_QEZ4, real_T *rtd_QEZ5, real_T *rtd_QHZ1, real_T *rtd_QHZ2, real_T
  *rtd_QHZ3, real_T *rtd_QHZ4, real_T *rtd_QSX1, real_T *rtd_QSX2, real_T
  *rtd_QSX3, real_T *rtd_RBX1, real_T *rtd_RBX2, real_T *rtd_RBX3, real_T
  *rtd_RBY1, real_T *rtd_RBY2, real_T *rtd_RBY3, real_T *rtd_RBY4, real_T
  *rtd_RCX1, real_T *rtd_RCY1, real_T *rtd_REX1, real_T *rtd_REX2, real_T
  *rtd_REY1, real_T *rtd_REY2, real_T *rtd_RHX1, real_T *rtd_RHY1, real_T
  *rtd_RHY2, real_T *rtd_RO, real_T *rtd_RVY1, real_T *rtd_RVY2, real_T
  *rtd_RVY3, real_T *rtd_RVY4, real_T *rtd_RVY5, real_T *rtd_RVY6, real_T
  *rtd_SSZ1, real_T *rtd_SSZ2, real_T *rtd_SSZ3, real_T *rtd_SSZ4, real_T
  *rtd_VCX, real_T *rtd_ZETA0, real_T *rtd_ZETA1, real_T *rtd_ZETA2, real_T
  *rtd_ZETA3, real_T *rtd_ZETA4, real_T *rtd_ZETA5, real_T *rtd_ZETA6, real_T
  *rtd_ZETA7, real_T *rtd_ZETA8)
{
  real_T maxFX_INPUT[400];
  real_T FZrange_tmp[100];
  real_T FxEnvelope[100];
  real_T x[100];
  real_T rtd_PCX1_0[15];
  real_T INPUT[4];
  real_T MZ_INPUT[4];
  real_T b_INPUT[3];
  real_T BXALPHA;
  real_T FXO;
  real_T FZOPRIME;
  real_T SA;
  real_T a;
  real_T b_INPUT_tmp;
  int32_T k;
  boolean_T b_INPUT_tmp_0;
  static const real_T b[100]{ -20.0, -19.595959595959595, -19.19191919191919,
    -18.787878787878789, -18.383838383838384, -17.979797979797979,
    -17.575757575757574, -17.171717171717173, -16.767676767676768,
    -16.363636363636363, -15.959595959595958, -15.555555555555555,
    -15.15151515151515, -14.747474747474747, -14.343434343434343,
    -13.939393939393939, -13.535353535353535, -13.131313131313131,
    -12.727272727272727, -12.323232323232324, -11.919191919191919,
    -11.515151515151516, -11.111111111111111, -10.707070707070708,
    -10.303030303030303, -9.8989898989899, -9.4949494949494948,
    -9.09090909090909, -8.6868686868686869, -8.282828282828282,
    -7.8787878787878789, -7.4747474747474749, -7.0707070707070709,
    -6.666666666666667, -6.2626262626262621, -5.8585858585858581,
    -5.4545454545454541, -5.05050505050505, -4.6464646464646462,
    -4.2424242424242422, -3.8383838383838382, -3.4343434343434343,
    -3.0303030303030303, -2.6262626262626263, -2.2222222222222223,
    -1.8181818181818181, -1.4141414141414141, -1.0101010101010102,
    -0.60606060606060608, -0.20202020202020202, 0.20202020202020202,
    0.60606060606060608, 1.0101010101010102, 1.4141414141414141,
    1.8181818181818181, 2.2222222222222223, 2.6262626262626263,
    3.0303030303030303, 3.4343434343434343, 3.8383838383838382,
    4.2424242424242422, 4.6464646464646462, 5.05050505050505, 5.4545454545454541,
    5.8585858585858581, 6.2626262626262621, 6.666666666666667,
    7.0707070707070709, 7.4747474747474749, 7.8787878787878789,
    8.282828282828282, 8.6868686868686869, 9.09090909090909, 9.4949494949494948,
    9.8989898989899, 10.303030303030303, 10.707070707070708, 11.111111111111111,
    11.515151515151516, 11.919191919191919, 12.323232323232324,
    12.727272727272727, 13.131313131313131, 13.535353535353535,
    13.939393939393939, 14.343434343434343, 14.747474747474747,
    15.15151515151515, 15.555555555555555, 15.959595959595958,
    16.363636363636363, 16.767676767676768, 17.171717171717173,
    17.575757575757574, 17.979797979797979, 18.383838383838384,
    18.787878787878789, 19.19191919191919, 19.595959595959595, 20.0 };

  static const real_T b_a[100]{ 0.0, 0.015865963834807928, 0.031727933498067649,
    0.0475819158237423, 0.0634239196565645, 0.079249956856788456,
    0.095056043304182672, 0.11083819990101101, 0.12659245357374926,
    0.14231483827328514, 0.15800139597334989, 0.17364817766693033,
    0.18925124436041021, 0.20480666806519068, 0.22031053278654064,
    0.23575893550942723, 0.25114798718107922, 0.266473813690035,
    0.28173255684142967, 0.29692037532827487, 0.31203344569848707,
    0.32706796331742161, 0.34202014332566871, 0.35688622159187183,
    0.37166245566032752, 0.38634512569312868, 0.40093053540661372,
    0.41541501300188644, 0.42979491208917164, 0.44406661260577412,
    0.45822652172741041, 0.47227107477268271, 0.48619673610046871, 0.5,
    0.51367739157340631, 0.52722546761050249, 0.54064081745559756,
    0.55392006386611026, 0.56705986386277074, 0.58005690957119826,
    0.5929079290546404, 0.60560968713766672, 0.61815898622060517,
    0.63055266708452251, 0.64278760968653925, 0.6548607339452851,
    0.66676900051629162, 0.67850941155713218, 0.690079011482112,
    0.70147488770632127, 0.71269417137886293, 0.7237340381050702,
    0.73459170865753332, 0.74526444967575467, 0.75574957435425827,
    0.766044443118978, 0.77614646429175682, 0.78605309474278751,
    0.7957618405308321, 0.80527025753105863, 0.81457595205033573,
    0.8236765814298328, 0.8325698546347714, 0.84125353283118109,
    0.84972542994951439, 0.857983413234977, 0.86602540378443871,
    0.87384937706978494, 0.88145336344758207, 0.88883544865492348,
    0.89599377429133586, 0.90292653828662128, 0.90963199535451833,
    0.91610845743206959, 0.92235429410458147, 0.92836793301607257,
    0.93414786026510666, 0.93969262078590832, 0.94500081871466846,
    0.95007111774094544, 0.95490224144407387, 0.95949297361449748,
    0.963842158559942, 0.96794870139635625, 0.97181156832354165,
    0.975429786885407, 0.97880244621477874, 0.98192869726270671,
    0.984807753012208, 0.9874388886763944, 0.98982144188093268,
    0.99195481283079534, 0.99383846446125412, 0.99547192257308459,
    0.99685477595194238, 0.99798667647188444, 0.998867339183008,
    0.99949654238318508, 0.99987412767387507, 1.0 };

  static const real_T c_a[100]{ 1.0, 0.99987412767387507, 0.99949654238318508,
    0.998867339183008, 0.99798667647188444, 0.99685477595194238,
    0.99547192257308459, 0.99383846446125412, 0.99195481283079534,
    0.98982144188093268, 0.98743888867639429, 0.984807753012208,
    0.98192869726270671, 0.97880244621477874, 0.975429786885407,
    0.97181156832354165, 0.96794870139635625, 0.963842158559942,
    0.95949297361449737, 0.95490224144407387, 0.95007111774094544,
    0.94500081871466846, 0.93969262078590843, 0.93414786026510677,
    0.92836793301607257, 0.92235429410458136, 0.91610845743206959,
    0.90963199535451833, 0.90292653828662117, 0.89599377429133586,
    0.88883544865492348, 0.88145336344758207, 0.87384937706978494,
    0.8660254037844386, 0.85798341323497707, 0.84972542994951439,
    0.84125353283118121, 0.83256985463477129, 0.8236765814298328,
    0.81457595205033573, 0.80527025753105863, 0.7957618405308321,
    0.78605309474278751, 0.77614646429175682, 0.766044443118978,
    0.75574957435425827, 0.74526444967575478, 0.73459170865753332,
    0.72373403810507009, 0.71269417137886282, 0.70147488770632127,
    0.690079011482112, 0.67850941155713218, 0.66676900051629162,
    0.654860733945285, 0.64278760968653936, 0.63055266708452251,
    0.61815898622060528, 0.60560968713766661, 0.59290792905464051,
    0.58005690957119815, 0.56705986386277074, 0.55392006386611026,
    0.54064081745559767, 0.52722546761050237, 0.51367739157340642,
    0.49999999999999989, 0.48619673610046865, 0.47227107477268271,
    0.45822652172741046, 0.44406661260577407, 0.42979491208917159,
    0.41541501300188644, 0.40093053540661377, 0.38634512569312857,
    0.37166245566032752, 0.35688622159187189, 0.34202014332566882,
    0.32706796331742155, 0.31203344569848712, 0.29692037532827492,
    0.28173255684142962, 0.266473813690035, 0.25114798718107922,
    0.23575893550942728, 0.22031053278654053, 0.20480666806519066,
    0.18925124436041021, 0.17364817766693041, 0.15800139597334981,
    0.14231483827328512, 0.12659245357374929, 0.1108381999010111,
    0.095056043304182589, 0.079249956856788442, 0.063423919656564562,
    0.047581915823742181, 0.031727933498067594, 0.015865963834807931,
    6.123233995736766E-17 };

  static const real_T c[100]{ -0.3, -0.29393939393939394, -0.2878787878787879,
    -0.2818181818181818, -0.27575757575757576, -0.26969696969696971,
    -0.26363636363636361, -0.25757575757575757, -0.25151515151515152,
    -0.24545454545454545, -0.23939393939393938, -0.23333333333333334,
    -0.22727272727272727, -0.22121212121212122, -0.21515151515151515,
    -0.20909090909090908, -0.20303030303030303, -0.19696969696969696,
    -0.19090909090909092, -0.18484848484848485, -0.1787878787878788,
    -0.17272727272727273, -0.16666666666666666, -0.16060606060606061,
    -0.15454545454545454, -0.1484848484848485, -0.14242424242424243,
    -0.13636363636363635, -0.13030303030303031, -0.12424242424242424,
    -0.11818181818181818, -0.11212121212121212, -0.10606060606060606, -0.1,
    -0.093939393939393934, -0.087878787878787876, -0.081818181818181818,
    -0.07575757575757576, -0.0696969696969697, -0.06363636363636363,
    -0.057575757575757579, -0.051515151515151514, -0.045454545454545456,
    -0.039393939393939391, -0.033333333333333333, -0.027272727272727271,
    -0.021212121212121213, -0.015151515151515152, -0.00909090909090909,
    -0.0030303030303030303, 0.0030303030303030303, 0.00909090909090909,
    0.015151515151515152, 0.021212121212121213, 0.027272727272727271,
    0.033333333333333333, 0.039393939393939391, 0.045454545454545456,
    0.051515151515151514, 0.057575757575757579, 0.06363636363636363,
    0.0696969696969697, 0.07575757575757576, 0.081818181818181818,
    0.087878787878787876, 0.093939393939393934, 0.1, 0.10606060606060606,
    0.11212121212121212, 0.11818181818181818, 0.12424242424242424,
    0.13030303030303031, 0.13636363636363635, 0.14242424242424243,
    0.1484848484848485, 0.15454545454545454, 0.16060606060606061,
    0.16666666666666666, 0.17272727272727273, 0.1787878787878788,
    0.18484848484848485, 0.19090909090909092, 0.19696969696969696,
    0.20303030303030303, 0.20909090909090908, 0.21515151515151515,
    0.22121212121212122, 0.22727272727272727, 0.23333333333333334,
    0.23939393939393938, 0.24545454545454545, 0.25151515151515152,
    0.25757575757575757, 0.26363636363636361, 0.26969696969696971,
    0.27575757575757576, 0.2818181818181818, 0.2878787878787879,
    0.29393939393939394, 0.3 };

  SA = rtu_SA;
  *rtd_FZO = rtu_LAMBDA[0];
  *rtd_RO = rtu_LAMBDA[1];
  *rtd_VCX = rtu_LAMBDA[2];
  *rtd_LFZO = rtu_LAMBDA[3];
  *rtd_LMUX = rtu_LAMBDA[4];
  *rtd_LMUY = rtu_LAMBDA[5];
  *rtd_LKXKAPPA = rtu_LAMBDA[6];
  *rtd_LKYALPHA = rtu_LAMBDA[7];
  *rtd_LCX = rtu_LAMBDA[8];
  *rtd_LCY = rtu_LAMBDA[9];
  *rtd_LEX = rtu_LAMBDA[10];
  *rtd_LEY = rtu_LAMBDA[11];
  *rtd_LHX = rtu_LAMBDA[12];
  *rtd_LHY = rtu_LAMBDA[13];
  *rtd_LVX = rtu_LAMBDA[14];
  *rtd_LVY = rtu_LAMBDA[15];
  *rtd_LKYGAMMA = rtu_LAMBDA[16];
  *rtd_LKZGAMMA = rtu_LAMBDA[17];
  *rtd_LT = rtu_LAMBDA[18];
  *rtd_LMR = rtu_LAMBDA[19];
  *rtd_LXALPHA = rtu_LAMBDA[20];
  *rtd_LYKAPPA = rtu_LAMBDA[21];
  *rtd_LVYKAPPA = rtu_LAMBDA[22];
  *rtd_LS = rtu_LAMBDA[23];
  *rtd_LMX = rtu_LAMBDA[24];
  *rtd_LMUV = rtu_LAMBDA[25];
  *rtd_AMU = rtu_LAMBDA[26];
  *rtd_LMUXAST = *rtd_LMUX;
  *rtd_LMUYAST = *rtd_LMUY;
  *rtd_LMUYPRIME = *rtd_AMU * *rtd_LMUYAST / ((*rtd_AMU - 1.0) * *rtd_LMUYAST +
    1.0);
  *rtd_LMUXPRIME = *rtd_AMU * *rtd_LMUXAST / ((*rtd_AMU - 1.0) * *rtd_LMUXAST +
    1.0);
  *rtd_ZETA0 = rtu_LAMBDA[27];
  *rtd_ZETA1 = rtu_LAMBDA[28];
  *rtd_ZETA2 = rtu_LAMBDA[29];
  *rtd_ZETA3 = rtu_LAMBDA[30];
  *rtd_ZETA4 = rtu_LAMBDA[31];
  *rtd_ZETA5 = rtu_LAMBDA[32];
  *rtd_ZETA6 = rtu_LAMBDA[33];
  *rtd_ZETA7 = rtu_LAMBDA[34];
  *rtd_ZETA8 = rtu_LAMBDA[35];
  *rtd_EPSILON = rtu_LAMBDA[36];
  *rtd_PCY1 = rtu_A[0];
  *rtd_PDY1 = rtu_A[1];
  *rtd_PDY2 = rtu_A[2];
  *rtd_PDY3 = rtu_A[3];
  *rtd_PEY1 = rtu_A[4];
  *rtd_PEY2 = rtu_A[5];
  *rtd_PEY3 = rtu_A[6];
  *rtd_PEY4 = rtu_A[7];
  *rtd_PEY5 = rtu_A[8];
  *rtd_PKY1 = rtu_A[9];
  *rtd_PKY2 = rtu_A[10];
  *rtd_PKY3 = rtu_A[11];
  *rtd_PKY4 = rtu_A[12];
  *rtd_PKY5 = rtu_A[13];
  *rtd_PKY6 = rtu_A[14];
  *rtd_PKY7 = rtu_A[15];
  *rtd_PHY1 = rtu_A[16];
  *rtd_PHY2 = rtu_A[17];
  *rtd_PVY1 = rtu_A[18];
  *rtd_PVY2 = rtu_A[19];
  *rtd_PVY3 = rtu_A[20];
  *rtd_PVY4 = rtu_A[21];
  *rtd_QBZ1 = rtu_B[0];
  *rtd_QBZ2 = rtu_B[1];
  *rtd_QBZ3 = rtu_B[2];
  *rtd_QBZ5 = rtu_B[3];
  *rtd_QBZ6 = rtu_B[4];
  *rtd_QBZ9 = rtu_B[5];
  *rtd_QBZ10 = rtu_B[6];
  *rtd_QCZ1 = rtu_B[7];
  *rtd_QDZ1 = rtu_B[8];
  *rtd_QDZ2 = rtu_B[9];
  *rtd_QDZ3 = rtu_B[10];
  *rtd_QDZ4 = rtu_B[11];
  *rtd_QDZ6 = rtu_B[12];
  *rtd_QDZ7 = rtu_B[13];
  *rtd_QDZ8 = rtu_B[14];
  *rtd_QDZ9 = rtu_B[15];
  *rtd_QDZ10 = rtu_B[16];
  *rtd_QDZ11 = rtu_B[17];
  *rtd_QEZ1 = rtu_B[18];
  *rtd_QEZ2 = rtu_B[19];
  *rtd_QEZ3 = rtu_B[20];
  *rtd_QEZ4 = rtu_B[21];
  *rtd_QEZ5 = rtu_B[22];
  *rtd_QHZ1 = rtu_B[23];
  *rtd_QHZ2 = rtu_B[24];
  *rtd_QHZ3 = rtu_B[25];
  *rtd_QHZ4 = rtu_B[26];
  *rtd_PCX1 = rtu_D[0];
  *rtd_PDX1 = rtu_D[1];
  *rtd_PDX2 = rtu_D[2];
  *rtd_PDX3 = rtu_D[3];
  *rtd_PEX1 = rtu_D[4];
  *rtd_PEX2 = rtu_D[5];
  *rtd_PEX3 = rtu_D[6];
  *rtd_PEX4 = rtu_D[7];
  *rtd_PKX1 = rtu_D[8];
  *rtd_PKX2 = rtu_D[9];
  *rtd_PKX3 = rtu_D[10];
  *rtd_PHX1 = rtu_D[11];
  *rtd_PHX2 = rtu_D[12];
  *rtd_PVX1 = rtu_D[13];
  *rtd_PVX2 = rtu_D[14];
  *rtd_RBX1 = rtu_E[0];
  *rtd_RBX2 = rtu_E[1];
  *rtd_RBX3 = rtu_E[2];
  *rtd_RCX1 = rtu_E[3];
  *rtd_REX1 = rtu_E[4];
  *rtd_REX2 = rtu_E[5];
  *rtd_RHX1 = rtu_E[6];
  *rtd_RBY1 = rtu_F[0];
  *rtd_RBY2 = rtu_F[1];
  *rtd_RBY3 = rtu_F[2];
  *rtd_RBY4 = rtu_F[3];
  *rtd_RCY1 = rtu_F[4];
  *rtd_REY1 = rtu_F[5];
  *rtd_REY2 = rtu_F[6];
  *rtd_RHY1 = rtu_F[7];
  *rtd_RHY2 = rtu_F[8];
  *rtd_RVY1 = rtu_F[9];
  *rtd_RVY2 = rtu_F[10];
  *rtd_RVY3 = rtu_F[11];
  *rtd_RVY4 = rtu_F[12];
  *rtd_RVY5 = rtu_F[13];
  *rtd_RVY6 = rtu_F[14];
  *rtd_SSZ1 = rtu_G[0];
  *rtd_SSZ2 = rtu_G[1];
  *rtd_SSZ3 = rtu_G[2];
  *rtd_SSZ4 = rtu_G[3];
  *rtd_QSX1 = rtu_C[0];
  *rtd_QSX2 = rtu_C[1];
  *rtd_QSX3 = rtu_C[2];
  if (std::isnan(rtu_SA)) {
    SA = 0.0;
  }

  INPUT[0] = rtu_SL;
  INPUT[1] = SA;
  INPUT[2] = -rtu_FZ;
  INPUT[3] = rtu_IA;
  b_INPUT_tmp = std::abs(SA);
  if (std::isnan(SA)) {
    BXALPHA = (rtNaN);
  } else if (SA < 0.0) {
    BXALPHA = -1.0;
  } else {
    BXALPHA = (SA > 0.0);
  }

  b_INPUT_tmp_0 = (b_INPUT_tmp >= 6.0);
  MZ_INPUT[1] = SA;
  MZ_INPUT[2] = -rtu_FZ;
  MZ_INPUT[3] = rtu_IA;
  MZ_INPUT[0] = 0.0;
  if (b_INPUT_tmp >= 10.0) {
    MZ_INPUT[1] = 10.0 * BXALPHA;
  }

  if (std::abs(rtu_FZ) >= 1600.0) {
    MZ_INPUT[2] = -1600.0;
  }

  b_INPUT_tmp = Tire_Model_Codegen_Pacejka52_COMBINED_FY(rtu_F, INPUT,
    rtd_EPSILON, rtd_FZO, rtd_LCY, rtd_LEY, rtd_LFZO, rtd_LHY, rtd_LKYALPHA,
    rtd_LKYGAMMA, rtd_LMUYAST, rtd_LMUYPRIME, rtd_LVY, rtd_LVYKAPPA, rtd_LYKAPPA,
    rtd_PCY1, rtd_PDY1, rtd_PDY2, rtd_PDY3, rtd_PEY1, rtd_PEY2, rtd_PEY3,
    rtd_PEY4, rtd_PEY5, rtd_PHY1, rtd_PHY2, rtd_PKY1, rtd_PKY2, rtd_PKY3,
    rtd_PKY4, rtd_PKY5, rtd_PKY6, rtd_PKY7, rtd_PVY1, rtd_PVY2, rtd_PVY3,
    rtd_PVY4, rtd_ZETA2, rtd_ZETA3, rtd_ZETA4);
  rtd_PCX1_0[0] = *rtd_PCX1;
  rtd_PCX1_0[1] = *rtd_PDX1;
  rtd_PCX1_0[2] = *rtd_PDX2;
  rtd_PCX1_0[3] = *rtd_PDX3;
  rtd_PCX1_0[4] = *rtd_PEX1;
  rtd_PCX1_0[5] = *rtd_PEX2;
  rtd_PCX1_0[6] = *rtd_PEX3;
  rtd_PCX1_0[7] = *rtd_PEX4;
  rtd_PCX1_0[8] = *rtd_PKX1;
  rtd_PCX1_0[9] = *rtd_PKX2;
  rtd_PCX1_0[10] = *rtd_PKX3;
  rtd_PCX1_0[11] = *rtd_PHX1;
  rtd_PCX1_0[12] = *rtd_PHX2;
  rtd_PCX1_0[13] = *rtd_PVX1;
  rtd_PCX1_0[14] = *rtd_PVX2;
  b_INPUT[0] = rtu_SL;
  b_INPUT[1] = -rtu_FZ;
  b_INPUT[2] = rtu_IA;
  FXO = Tire_Model_Codegen_Pacejka52_PLS_FX(rtd_PCX1_0, b_INPUT, rtd_EPSILON,
    rtd_FZO, rtd_LCX, rtd_LEX, rtd_LFZO, rtd_LHX, rtd_LKXKAPPA, rtd_LMUX,
    rtd_LMUXPRIME, rtd_LVX, rtd_ZETA1);
  FZOPRIME = *rtd_FZO * *rtd_LFZO;
  a = std::sin(0.017453292519943295 * rtu_IA);
  FZOPRIME = (std::abs(-rtu_FZ) - FZOPRIME) / FZOPRIME * rtu_E[5] + rtu_E[4];
  if (b_INPUT_tmp_0) {
    SA = 6.0 * BXALPHA;
  }

  BXALPHA = std::abs((a * a * rtu_E[2] + rtu_E[0]) * std::cos(std::atan(rtu_E[1]
    * rtu_SL)) * *rtd_LXALPHA);
  SA = (std::tan(-(0.017453292519943295 * SA)) + rtu_E[6]) * BXALPHA;
  BXALPHA *= rtu_E[6];
  SA = std::abs(std::cos(std::atan(SA - (SA - std::atan(SA)) * FZOPRIME) *
    rtu_E[3]) / std::cos(std::atan(BXALPHA - (BXALPHA - std::atan(BXALPHA)) *
    FZOPRIME) * rtu_E[3])) * FXO;
  if (std::abs(SA) > std::abs(FXO)) {
    SA = FXO;
  }

  *rty_COMBINED_MZ = Tire_Model_Codegen_Pacejka52_COMBINED_MZ(rtu_G, MZ_INPUT,
    rtd_EPSILON, rtd_FZO, rtd_LCX, rtd_LCY, rtd_LEX, rtd_LEY, rtd_LFZO, rtd_LHX,
    rtd_LHY, rtd_LKXKAPPA, rtd_LKYALPHA, rtd_LKYGAMMA, rtd_LKZGAMMA, rtd_LMR,
    rtd_LMUX, rtd_LMUXPRIME, rtd_LMUYAST, rtd_LMUYPRIME, rtd_LS, rtd_LT, rtd_LVX,
    rtd_LVY, rtd_LVYKAPPA, rtd_LXALPHA, rtd_LYKAPPA, rtd_PCX1, rtd_PCY1,
    rtd_PDX1, rtd_PDX2, rtd_PDX3, rtd_PDY1, rtd_PDY2, rtd_PDY3, rtd_PEX1,
    rtd_PEX2, rtd_PEX3, rtd_PEX4, rtd_PEY1, rtd_PEY2, rtd_PEY3, rtd_PEY4,
    rtd_PEY5, rtd_PHX1, rtd_PHX2, rtd_PHY1, rtd_PHY2, rtd_PKX1, rtd_PKX2,
    rtd_PKX3, rtd_PKY1, rtd_PKY2, rtd_PKY3, rtd_PKY4, rtd_PKY5, rtd_PKY6,
    rtd_PKY7, rtd_PVX1, rtd_PVX2, rtd_PVY1, rtd_PVY2, rtd_PVY3, rtd_PVY4,
    rtd_QBZ1, rtd_QBZ10, rtd_QBZ2, rtd_QBZ3, rtd_QBZ5, rtd_QBZ6, rtd_QBZ9,
    rtd_QCZ1, rtd_QDZ1, rtd_QDZ10, rtd_QDZ11, rtd_QDZ2, rtd_QDZ3, rtd_QDZ4,
    rtd_QDZ6, rtd_QDZ7, rtd_QDZ8, rtd_QDZ9, rtd_QEZ1, rtd_QEZ2, rtd_QEZ3,
    rtd_QEZ4, rtd_QEZ5, rtd_QHZ1, rtd_QHZ2, rtd_QHZ3, rtd_QHZ4, rtd_RBX1,
    rtd_RBX2, rtd_RBX3, rtd_RBY1, rtd_RBY2, rtd_RBY3, rtd_RBY4, rtd_RCX1,
    rtd_RCY1, rtd_REX1, rtd_REX2, rtd_REY1, rtd_REY2, rtd_RHX1, rtd_RHY1,
    rtd_RHY2, rtd_RO, rtd_RVY1, rtd_RVY2, rtd_RVY3, rtd_RVY4, rtd_RVY5, rtd_RVY6,
    rtd_VCX, rtd_ZETA0, rtd_ZETA1, rtd_ZETA2, rtd_ZETA3, rtd_ZETA4, rtd_ZETA5,
    rtd_ZETA6, rtd_ZETA7, rtd_ZETA8);
  Tire_Model_Codegen_repelem(-rtu_FZ, FZrange_tmp);
  for (k = 0; k < 100; k++) {
    maxFX_INPUT[k] = 0.0;
    maxFX_INPUT[k + 100] = b[k];
    maxFX_INPUT[k + 200] = FZrange_tmp[k];
    maxFX_INPUT[k + 300] = 0.0;
  }

  Tire_Model_Codegen_Pacejka52_COMBINED_FY_m(rtu_F, maxFX_INPUT, x, rtd_EPSILON,
    rtd_FZO, rtd_LCY, rtd_LEY, rtd_LFZO, rtd_LHY, rtd_LKYALPHA, rtd_LKYGAMMA,
    rtd_LMUYAST, rtd_LMUYPRIME, rtd_LVY, rtd_LVYKAPPA, rtd_LYKAPPA, rtd_PCY1,
    rtd_PDY1, rtd_PDY2, rtd_PDY3, rtd_PEY1, rtd_PEY2, rtd_PEY3, rtd_PEY4,
    rtd_PEY5, rtd_PHY1, rtd_PHY2, rtd_PKY1, rtd_PKY2, rtd_PKY3, rtd_PKY4,
    rtd_PKY5, rtd_PKY6, rtd_PKY7, rtd_PVY1, rtd_PVY2, rtd_PVY3, rtd_PVY4,
    rtd_ZETA2, rtd_ZETA3, rtd_ZETA4);
  for (k = 0; k < 100; k++) {
    FxEnvelope[k] = std::abs(x[k]);
  }

  BXALPHA = Tire_Model_Codegen_maximum(FxEnvelope);
  if (rtu_FZ == 0.0) {
    b_INPUT_tmp = 0.0;
    SA = 0.0;
    *rty_COMBINED_MZ = 0.0;
    BXALPHA = 1.0;
  }

  FXO = std::abs(b_INPUT_tmp);
  if (FXO > 0.0) {
    for (k = 0; k < 100; k++) {
      FxEnvelope[k] = c_a[k] * BXALPHA;
      x[k] = b_a[k] * BXALPHA;
    }

    BXALPHA = Tire_Model_Codegen_interp1(FxEnvelope, x, FXO);
  } else {
    for (k = 0; k < 100; k++) {
      x[k] = b_a[k] * BXALPHA;
    }

    BXALPHA = Tire_Model_Codegen_maximum(x);
  }

  if (std::abs(SA) > BXALPHA) {
    if (std::isnan(SA)) {
      FXO = (rtNaN);
    } else if (SA < 0.0) {
      FXO = -1.0;
    } else {
      FXO = (SA > 0.0);
    }

    SA = BXALPHA * FXO;
  }

  if (rtu_FZ != 0.0) {
    for (k = 0; k < 100; k++) {
      maxFX_INPUT[k] = c[k];
      maxFX_INPUT[k + 100] = 0.0;
      maxFX_INPUT[k + 200] = FZrange_tmp[k];
      maxFX_INPUT[k + 300] = 0.0;
    }

    Tire_Model_Codegen_Pacejka52_COMBINED_FX(rtu_E, maxFX_INPUT, x, rtd_EPSILON,
      rtd_FZO, rtd_LCX, rtd_LEX, rtd_LFZO, rtd_LHX, rtd_LKXKAPPA, rtd_LMUX,
      rtd_LMUXPRIME, rtd_LVX, rtd_LXALPHA, rtd_PCX1, rtd_PDX1, rtd_PDX2,
      rtd_PDX3, rtd_PEX1, rtd_PEX2, rtd_PEX3, rtd_PEX4, rtd_PHX1, rtd_PHX2,
      rtd_PKX1, rtd_PKX2, rtd_PKX3, rtd_PVX1, rtd_PVX2, rtd_ZETA1);
    Tire_Model_Codegen_Pacejka52_COMBINED_FX(rtu_E, maxFX_INPUT, FxEnvelope,
      rtd_EPSILON, rtd_FZO, rtd_LCX, rtd_LEX, rtd_LFZO, rtd_LHX, rtd_LKXKAPPA,
      rtd_LMUX, rtd_LMUXPRIME, rtd_LVX, rtd_LXALPHA, rtd_PCX1, rtd_PDX1,
      rtd_PDX2, rtd_PDX3, rtd_PEX1, rtd_PEX2, rtd_PEX3, rtd_PEX4, rtd_PHX1,
      rtd_PHX2, rtd_PKX1, rtd_PKX2, rtd_PKX3, rtd_PVX1, rtd_PVX2, rtd_ZETA1);
    *rty_satAccelT = Tire_Model_Codegen_maximum(x) * 0.2 / 11.86;
    *rty_satBrakeT = Tire_Model_Codegen_minimum(FxEnvelope) * 0.2 / 11.86;
  } else {
    *rty_satAccelT = 0.0;
    *rty_satBrakeT = 0.0;
  }

  *rty_COMBINED_FX = SA;
  *rty_COMBINED_FY = b_INPUT_tmp;
}

// Model step function
void Tire_Model_Codegen::step()
{
  real_T AMU;
  real_T COMBINED_FX;
  real_T COMBINED_FX_c;
  real_T COMBINED_FY;
  real_T COMBINED_FY_a;
  real_T COMBINED_FY_c;
  real_T COMBINED_FY_o;
  real_T COMBINED_MZ;
  real_T COMBINED_MZ_e;
  real_T COMBINED_MZ_g;
  real_T COMBINED_MZ_p;
  real_T EPSILON;
  real_T FZO;
  real_T LCX;
  real_T LCY;
  real_T LEX;
  real_T LEY;
  real_T LFZO;
  real_T LHX;
  real_T LHY;
  real_T LKXKAPPA;
  real_T LKYALPHA;
  real_T LKYGAMMA;
  real_T LKZGAMMA;
  real_T LMR;
  real_T LMUV;
  real_T LMUX;
  real_T LMUXAST;
  real_T LMUXPRIME;
  real_T LMUY;
  real_T LMUYAST;
  real_T LMUYPRIME;
  real_T LMX;
  real_T LS;
  real_T LT;
  real_T LVX;
  real_T LVY;
  real_T LVYKAPPA;
  real_T LXALPHA;
  real_T LYKAPPA;
  real_T PCX1;
  real_T PCY1;
  real_T PDX1;
  real_T PDX2;
  real_T PDX3;
  real_T PDY1;
  real_T PDY2;
  real_T PDY3;
  real_T PEX1;
  real_T PEX2;
  real_T PEX3;
  real_T PEX4;
  real_T PEY1;
  real_T PEY2;
  real_T PEY3;
  real_T PEY4;
  real_T PEY5;
  real_T PHX1;
  real_T PHX2;
  real_T PHY1;
  real_T PHY2;
  real_T PKX1;
  real_T PKX2;
  real_T PKX3;
  real_T PKY1;
  real_T PKY2;
  real_T PKY3;
  real_T PKY4;
  real_T PKY5;
  real_T PKY6;
  real_T PKY7;
  real_T PVX1;
  real_T PVX2;
  real_T PVY1;
  real_T PVY2;
  real_T PVY3;
  real_T PVY4;
  real_T QBZ1;
  real_T QBZ10;
  real_T QBZ2;
  real_T QBZ3;
  real_T QBZ5;
  real_T QBZ6;
  real_T QBZ9;
  real_T QCZ1;
  real_T QDZ1;
  real_T QDZ10;
  real_T QDZ11;
  real_T QDZ2;
  real_T QDZ3;
  real_T QDZ4;
  real_T QDZ6;
  real_T QDZ7;
  real_T QDZ8;
  real_T QDZ9;
  real_T QEZ1;
  real_T QEZ2;
  real_T QEZ3;
  real_T QEZ4;
  real_T QEZ5;
  real_T QHZ1;
  real_T QHZ2;
  real_T QHZ3;
  real_T QHZ4;
  real_T QSX1;
  real_T QSX2;
  real_T QSX3;
  real_T RBX1;
  real_T RBX2;
  real_T RBX3;
  real_T RBY1;
  real_T RBY2;
  real_T RBY3;
  real_T RBY4;
  real_T RCX1;
  real_T RCY1;
  real_T REX1;
  real_T REX2;
  real_T REY1;
  real_T REY2;
  real_T RHX1;
  real_T RHY1;
  real_T RHY2;
  real_T RO;
  real_T RVY1;
  real_T RVY2;
  real_T RVY3;
  real_T RVY4;
  real_T RVY5;
  real_T RVY6;
  real_T SSZ1;
  real_T SSZ2;
  real_T SSZ3;
  real_T SSZ4;
  real_T Saturation;
  real_T Saturation1;
  real_T Saturation2;
  real_T Saturation3;
  real_T VCX;
  real_T ZETA0;
  real_T ZETA1;
  real_T ZETA2;
  real_T ZETA3;
  real_T ZETA4;
  real_T ZETA5;
  real_T ZETA6;
  real_T ZETA7;
  real_T ZETA8;
  real_T rtb_Abs1_ao;
  real_T rtb_Abs1_hx;
  real_T rtb_Abs1_p;
  real_T satAccelT_a;
  real_T satAccelT_k;
  real_T satAccelT_k0;
  real_T satBrakeT_f;

  // Gain: '<S21>/Gain' incorporates:
  //   Gain: '<S4>/Gain8'
  //   Inport: '<Root>/SA FL'

  Saturation = 57.295779513082323 * -Tire_Model_Codegen_U.FL_b;

  // Saturate: '<S4>/Saturation'
  if (Saturation > 20.0) {
    // Saturate: '<S4>/Saturation'
    Saturation = 20.0;
  } else if (Saturation < -20.0) {
    // Saturate: '<S4>/Saturation'
    Saturation = -20.0;
  }

  // End of Saturate: '<S4>/Saturation'

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Abs: '<S1>/Abs'
  //   Inport: '<Root>/Interp_x1_FL'
  //   Inport: '<Root>/Interp_x2_FL'
  //   Inport: '<Root>/Interp_x3_FL'
  //   Inport: '<Root>/LC FL'
  //   Inport: '<Root>/interp_y1_FL'
  //   Inport: '<Root>/interp_y2_FL'
  //   Inport: '<Root>/interp_y3_FL'
  //   Outport: '<Root>/FZ FL'

  Tire_Model_Codegen_MATLABFunction1(std::abs(Tire_Model_Codegen_U.LCFL),
    Tire_Model_Codegen_U.Interp_x1_FL, Tire_Model_Codegen_U.Interp_x2_FL,
    Tire_Model_Codegen_U.Interp_x3_FL, Tire_Model_Codegen_U.interp_y1_FL,
    Tire_Model_Codegen_U.interp_y2_FL, Tire_Model_Codegen_U.interp_y3_FL,
    &Tire_Model_Codegen_Y.FZFL);

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   Abs: '<S17>/Abs1'
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S17>/Constant10'
  //   Constant: '<S17>/Constant3'
  //   Constant: '<S17>/Constant4'
  //   Constant: '<S17>/Constant5'
  //   Constant: '<S17>/Constant6'
  //   Constant: '<S17>/Constant7'
  //   Constant: '<S17>/Constant8'
  //   Constant: '<S17>/Constant9'
  //   Gain: '<S17>/Gain'
  //   Gain: '<S4>/Gain'
  //   Inport: '<Root>/SL FL'
  //   Outport: '<Root>/FZ FL'

  Tire_Model_Codegen_MATLABFunction(Tire_Model_Codegen_ConstP.pooled10,
    Tire_Model_Codegen_ConstP.pooled11, Tire_Model_Codegen_ConstP.pooled12,
    Tire_Model_Codegen_ConstP.pooled13, Tire_Model_Codegen_ConstP.pooled14,
    Tire_Model_Codegen_ConstP.pooled15, Tire_Model_Codegen_ConstP.pooled16,
    Tire_Model_Codegen_ConstP.pooled9, Tire_Model_Codegen_U.FL, Saturation, -std::
    abs(-Tire_Model_Codegen_Y.FZFL), 0.0, &COMBINED_FX_c, &COMBINED_FY_o,
    &COMBINED_MZ_p, &satAccelT_k0, &satBrakeT_f, &AMU, &EPSILON, &FZO, &LCX,
    &LCY, &LEX, &LEY, &LFZO, &LHX, &LHY, &LKXKAPPA, &LKYALPHA, &LKYGAMMA,
    &LKZGAMMA, &LMR, &LMUV, &LMUX, &LMUXAST, &LMUXPRIME, &LMUY, &LMUYAST,
    &LMUYPRIME, &LMX, &LS, &LT, &LVX, &LVY, &LVYKAPPA, &LXALPHA, &LYKAPPA, &PCX1,
    &PCY1, &PDX1, &PDX2, &PDX3, &PDY1, &PDY2, &PDY3, &PEX1, &PEX2, &PEX3, &PEX4,
    &PEY1, &PEY2, &PEY3, &PEY4, &PEY5, &PHX1, &PHX2, &PHY1, &PHY2, &PKX1, &PKX2,
    &PKX3, &PKY1, &PKY2, &PKY3, &PKY4, &PKY5, &PKY6, &PKY7, &PVX1, &PVX2, &PVY1,
    &PVY2, &PVY3, &PVY4, &QBZ1, &QBZ10, &QBZ2, &QBZ3, &QBZ5, &QBZ6, &QBZ9, &QCZ1,
    &QDZ1, &QDZ10, &QDZ11, &QDZ2, &QDZ3, &QDZ4, &QDZ6, &QDZ7, &QDZ8, &QDZ9,
    &QEZ1, &QEZ2, &QEZ3, &QEZ4, &QEZ5, &QHZ1, &QHZ2, &QHZ3, &QHZ4, &QSX1, &QSX2,
    &QSX3, &RBX1, &RBX2, &RBX3, &RBY1, &RBY2, &RBY3, &RBY4, &RCX1, &RCY1, &REX1,
    &REX2, &REY1, &REY2, &RHX1, &RHY1, &RHY2, &RO, &RVY1, &RVY2, &RVY3, &RVY4,
    &RVY5, &RVY6, &SSZ1, &SSZ2, &SSZ3, &SSZ4, &VCX, &ZETA0, &ZETA1, &ZETA2,
    &ZETA3, &ZETA4, &ZETA5, &ZETA6, &ZETA7, &ZETA8);

  // Switch: '<S17>/Switch3' incorporates:
  //   Constant: '<S17>/Constant15'
  //   Inport: '<Root>/SL FL'

  if (Tire_Model_Codegen_U.FL != 0.0) {
    // Abs: '<S33>/Abs1'
    rtb_Abs1_hx = std::abs(Tire_Model_Codegen_U.FL);

    // Switch: '<S33>/Switch1' incorporates:
    //   Inport: '<Root>/LMUX FL'
    //   Polyval: '<S33>/Polynomial'
    //   Product: '<S17>/Product'
    //   Product: '<S33>/Product1'

    if (rtb_Abs1_hx >= 0.2) {
      COMBINED_FX_c = (((1.7306074402864622E-15 * rtb_Abs1_hx -
                         3.5736731257900937E-15) * rtb_Abs1_hx +
                        2.2908369318766675E-15) * rtb_Abs1_hx +
                       0.99999999999999956) * (COMBINED_FX_c *
        Tire_Model_Codegen_U.LMUXFL);
    } else {
      COMBINED_FX_c *= Tire_Model_Codegen_U.LMUXFL;
    }

    // End of Switch: '<S33>/Switch1'
  } else {
    COMBINED_FX_c = 0.0;
  }

  // End of Switch: '<S17>/Switch3'

  // Outport: '<Root>/FX FL' incorporates:
  //   Gain: '<S26>/Gain8'
  //   Switch: '<S26>/Switch'

  Tire_Model_Codegen_Y.FXFL = 0.6 * COMBINED_FX_c;

  // Gain: '<S22>/Gain' incorporates:
  //   Gain: '<S4>/Gain9'
  //   Inport: '<Root>/SA FR'

  Saturation1 = 57.295779513082323 * -Tire_Model_Codegen_U.FR_b;

  // Saturate: '<S4>/Saturation1'
  if (Saturation1 > 20.0) {
    // Saturate: '<S4>/Saturation1'
    Saturation1 = 20.0;
  } else if (Saturation1 < -20.0) {
    // Saturate: '<S4>/Saturation1'
    Saturation1 = -20.0;
  }

  // End of Saturate: '<S4>/Saturation1'

  // MATLAB Function: '<S1>/MATLAB Function2' incorporates:
  //   Abs: '<S1>/Abs1'
  //   Inport: '<Root>/Interp_x1_FR'
  //   Inport: '<Root>/Interp_x2_FR'
  //   Inport: '<Root>/Interp_x3_FR'
  //   Inport: '<Root>/LC FR'
  //   Inport: '<Root>/interp_y1_FR'
  //   Inport: '<Root>/interp_y2_FR'
  //   Inport: '<Root>/interp_y3_FR'
  //   Outport: '<Root>/FZ FR'

  Tire_Model_Codegen_MATLABFunction1(std::abs(Tire_Model_Codegen_U.LCFR),
    Tire_Model_Codegen_U.Interp_x1_FR, Tire_Model_Codegen_U.Interp_x2_FR,
    Tire_Model_Codegen_U.Interp_x3_FR, Tire_Model_Codegen_U.interp_y1_FR,
    Tire_Model_Codegen_U.interp_y2_FR, Tire_Model_Codegen_U.interp_y3_FR,
    &Tire_Model_Codegen_Y.FZFR);

  // MATLAB Function: '<S18>/MATLAB Function' incorporates:
  //   Abs: '<S18>/Abs1'
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S18>/Constant10'
  //   Constant: '<S18>/Constant3'
  //   Constant: '<S18>/Constant4'
  //   Constant: '<S18>/Constant5'
  //   Constant: '<S18>/Constant6'
  //   Constant: '<S18>/Constant7'
  //   Constant: '<S18>/Constant8'
  //   Constant: '<S18>/Constant9'
  //   Gain: '<S18>/Gain'
  //   Gain: '<S4>/Gain2'
  //   Inport: '<Root>/SL FR'
  //   Outport: '<Root>/FZ FR'

  Tire_Model_Codegen_MATLABFunction(Tire_Model_Codegen_ConstP.pooled10,
    Tire_Model_Codegen_ConstP.pooled11, Tire_Model_Codegen_ConstP.pooled12,
    Tire_Model_Codegen_ConstP.pooled13, Tire_Model_Codegen_ConstP.pooled14,
    Tire_Model_Codegen_ConstP.pooled15, Tire_Model_Codegen_ConstP.pooled16,
    Tire_Model_Codegen_ConstP.pooled9, Tire_Model_Codegen_U.FR, Saturation1,
    -std::abs(-Tire_Model_Codegen_Y.FZFR), 0.0, &rtb_Abs1_hx, &COMBINED_FY_a,
    &COMBINED_MZ_e, &satAccelT_k, &COMBINED_FX_c, &AMU, &EPSILON, &FZO, &LCX,
    &LCY, &LEX, &LEY, &LFZO, &LHX, &LHY, &LKXKAPPA, &LKYALPHA, &LKYGAMMA,
    &LKZGAMMA, &LMR, &LMUV, &LMUX, &LMUXAST, &LMUXPRIME, &LMUY, &LMUYAST,
    &LMUYPRIME, &LMX, &LS, &LT, &LVX, &LVY, &LVYKAPPA, &LXALPHA, &LYKAPPA, &PCX1,
    &PCY1, &PDX1, &PDX2, &PDX3, &PDY1, &PDY2, &PDY3, &PEX1, &PEX2, &PEX3, &PEX4,
    &PEY1, &PEY2, &PEY3, &PEY4, &PEY5, &PHX1, &PHX2, &PHY1, &PHY2, &PKX1, &PKX2,
    &PKX3, &PKY1, &PKY2, &PKY3, &PKY4, &PKY5, &PKY6, &PKY7, &PVX1, &PVX2, &PVY1,
    &PVY2, &PVY3, &PVY4, &QBZ1, &QBZ10, &QBZ2, &QBZ3, &QBZ5, &QBZ6, &QBZ9, &QCZ1,
    &QDZ1, &QDZ10, &QDZ11, &QDZ2, &QDZ3, &QDZ4, &QDZ6, &QDZ7, &QDZ8, &QDZ9,
    &QEZ1, &QEZ2, &QEZ3, &QEZ4, &QEZ5, &QHZ1, &QHZ2, &QHZ3, &QHZ4, &QSX1, &QSX2,
    &QSX3, &RBX1, &RBX2, &RBX3, &RBY1, &RBY2, &RBY3, &RBY4, &RCX1, &RCY1, &REX1,
    &REX2, &REY1, &REY2, &RHX1, &RHY1, &RHY2, &RO, &RVY1, &RVY2, &RVY3, &RVY4,
    &RVY5, &RVY6, &SSZ1, &SSZ2, &SSZ3, &SSZ4, &VCX, &ZETA0, &ZETA1, &ZETA2,
    &ZETA3, &ZETA4, &ZETA5, &ZETA6, &ZETA7, &ZETA8);

  // Switch: '<S18>/Switch3' incorporates:
  //   Constant: '<S18>/Constant15'
  //   Inport: '<Root>/SL FR'

  if (Tire_Model_Codegen_U.FR != 0.0) {
    // Abs: '<S36>/Abs1'
    rtb_Abs1_ao = std::abs(Tire_Model_Codegen_U.FR);

    // Switch: '<S36>/Switch1' incorporates:
    //   Inport: '<Root>/LMUX FR'
    //   Polyval: '<S36>/Polynomial'
    //   Product: '<S18>/Product'
    //   Product: '<S36>/Product1'

    if (rtb_Abs1_ao >= 0.2) {
      rtb_Abs1_hx = (((1.7306074402864622E-15 * rtb_Abs1_ao -
                       3.5736731257900937E-15) * rtb_Abs1_ao +
                      2.2908369318766675E-15) * rtb_Abs1_ao +
                     0.99999999999999956) * (rtb_Abs1_hx *
        Tire_Model_Codegen_U.LMUXFR);
    } else {
      rtb_Abs1_hx *= Tire_Model_Codegen_U.LMUXFR;
    }

    // End of Switch: '<S36>/Switch1'
  } else {
    rtb_Abs1_hx = 0.0;
  }

  // End of Switch: '<S18>/Switch3'

  // Outport: '<Root>/FX FR' incorporates:
  //   Gain: '<S27>/Gain8'
  //   Switch: '<S27>/Switch'

  Tire_Model_Codegen_Y.FXFR = 0.6 * rtb_Abs1_hx;

  // Gain: '<S23>/Gain' incorporates:
  //   Gain: '<S4>/Gain10'
  //   Inport: '<Root>/SA RL'

  Saturation2 = 57.295779513082323 * -Tire_Model_Codegen_U.RL_g;

  // Saturate: '<S4>/Saturation2'
  if (Saturation2 > 20.0) {
    // Saturate: '<S4>/Saturation2'
    Saturation2 = 20.0;
  } else if (Saturation2 < -20.0) {
    // Saturate: '<S4>/Saturation2'
    Saturation2 = -20.0;
  }

  // End of Saturate: '<S4>/Saturation2'

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   Abs: '<S1>/Abs2'
  //   Inport: '<Root>/Interp_x1_RL'
  //   Inport: '<Root>/Interp_x2_RL'
  //   Inport: '<Root>/Interp_x3_RL'
  //   Inport: '<Root>/LC RL'
  //   Inport: '<Root>/interp_y1_RL'
  //   Inport: '<Root>/interp_y2_RL'
  //   Inport: '<Root>/interp_y3_RL'
  //   Outport: '<Root>/FZ RL'

  Tire_Model_Codegen_MATLABFunction1(std::abs(Tire_Model_Codegen_U.LCRL),
    Tire_Model_Codegen_U.Interp_x1_RL, Tire_Model_Codegen_U.Interp_x2_RL,
    Tire_Model_Codegen_U.Interp_x3_RL, Tire_Model_Codegen_U.interp_y1_RL,
    Tire_Model_Codegen_U.interp_y2_RL, Tire_Model_Codegen_U.interp_y3_RL,
    &Tire_Model_Codegen_Y.FZRL);

  // MATLAB Function: '<S19>/MATLAB Function' incorporates:
  //   Abs: '<S19>/Abs1'
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S19>/Constant10'
  //   Constant: '<S19>/Constant3'
  //   Constant: '<S19>/Constant4'
  //   Constant: '<S19>/Constant5'
  //   Constant: '<S19>/Constant6'
  //   Constant: '<S19>/Constant7'
  //   Constant: '<S19>/Constant8'
  //   Constant: '<S19>/Constant9'
  //   Gain: '<S19>/Gain'
  //   Gain: '<S4>/Gain4'
  //   Inport: '<Root>/SL RL'
  //   Outport: '<Root>/FZ RL'

  Tire_Model_Codegen_MATLABFunction(Tire_Model_Codegen_ConstP.pooled10,
    Tire_Model_Codegen_ConstP.pooled11, Tire_Model_Codegen_ConstP.pooled12,
    Tire_Model_Codegen_ConstP.pooled13, Tire_Model_Codegen_ConstP.pooled14,
    Tire_Model_Codegen_ConstP.pooled15, Tire_Model_Codegen_ConstP.pooled16,
    Tire_Model_Codegen_ConstP.pooled9, Tire_Model_Codegen_U.RL, Saturation2,
    -std::abs(-Tire_Model_Codegen_Y.FZRL), 0.0, &rtb_Abs1_ao, &COMBINED_FY_c,
    &COMBINED_MZ_g, &satAccelT_a, &rtb_Abs1_hx, &AMU, &EPSILON, &FZO, &LCX, &LCY,
    &LEX, &LEY, &LFZO, &LHX, &LHY, &LKXKAPPA, &LKYALPHA, &LKYGAMMA, &LKZGAMMA,
    &LMR, &LMUV, &LMUX, &LMUXAST, &LMUXPRIME, &LMUY, &LMUYAST, &LMUYPRIME, &LMX,
    &LS, &LT, &LVX, &LVY, &LVYKAPPA, &LXALPHA, &LYKAPPA, &PCX1, &PCY1, &PDX1,
    &PDX2, &PDX3, &PDY1, &PDY2, &PDY3, &PEX1, &PEX2, &PEX3, &PEX4, &PEY1, &PEY2,
    &PEY3, &PEY4, &PEY5, &PHX1, &PHX2, &PHY1, &PHY2, &PKX1, &PKX2, &PKX3, &PKY1,
    &PKY2, &PKY3, &PKY4, &PKY5, &PKY6, &PKY7, &PVX1, &PVX2, &PVY1, &PVY2, &PVY3,
    &PVY4, &QBZ1, &QBZ10, &QBZ2, &QBZ3, &QBZ5, &QBZ6, &QBZ9, &QCZ1, &QDZ1,
    &QDZ10, &QDZ11, &QDZ2, &QDZ3, &QDZ4, &QDZ6, &QDZ7, &QDZ8, &QDZ9, &QEZ1,
    &QEZ2, &QEZ3, &QEZ4, &QEZ5, &QHZ1, &QHZ2, &QHZ3, &QHZ4, &QSX1, &QSX2, &QSX3,
    &RBX1, &RBX2, &RBX3, &RBY1, &RBY2, &RBY3, &RBY4, &RCX1, &RCY1, &REX1, &REX2,
    &REY1, &REY2, &RHX1, &RHY1, &RHY2, &RO, &RVY1, &RVY2, &RVY3, &RVY4, &RVY5,
    &RVY6, &SSZ1, &SSZ2, &SSZ3, &SSZ4, &VCX, &ZETA0, &ZETA1, &ZETA2, &ZETA3,
    &ZETA4, &ZETA5, &ZETA6, &ZETA7, &ZETA8);

  // Switch: '<S19>/Switch3' incorporates:
  //   Constant: '<S19>/Constant15'
  //   Inport: '<Root>/SL RL'

  if (Tire_Model_Codegen_U.RL != 0.0) {
    // Abs: '<S39>/Abs1'
    rtb_Abs1_p = std::abs(Tire_Model_Codegen_U.RL);

    // Switch: '<S39>/Switch1' incorporates:
    //   Inport: '<Root>/LMUX RL'
    //   Polyval: '<S39>/Polynomial'
    //   Product: '<S19>/Product'
    //   Product: '<S39>/Product1'

    if (rtb_Abs1_p >= 0.2) {
      rtb_Abs1_ao = (((1.7306074402864622E-15 * rtb_Abs1_p -
                       3.5736731257900937E-15) * rtb_Abs1_p +
                      2.2908369318766675E-15) * rtb_Abs1_p + 0.99999999999999956)
        * (rtb_Abs1_ao * Tire_Model_Codegen_U.LMUXRL);
    } else {
      rtb_Abs1_ao *= Tire_Model_Codegen_U.LMUXRL;
    }

    // End of Switch: '<S39>/Switch1'
  } else {
    rtb_Abs1_ao = 0.0;
  }

  // End of Switch: '<S19>/Switch3'

  // Outport: '<Root>/FX RL' incorporates:
  //   Gain: '<S28>/Gain8'
  //   Switch: '<S28>/Switch'

  Tire_Model_Codegen_Y.FXRL = 0.6 * rtb_Abs1_ao;

  // Gain: '<S24>/Gain' incorporates:
  //   Gain: '<S4>/Gain11'
  //   Inport: '<Root>/SA RR'

  Saturation3 = 57.295779513082323 * -Tire_Model_Codegen_U.RR_a;

  // Saturate: '<S4>/Saturation3'
  if (Saturation3 > 20.0) {
    // Saturate: '<S4>/Saturation3'
    Saturation3 = 20.0;
  } else if (Saturation3 < -20.0) {
    // Saturate: '<S4>/Saturation3'
    Saturation3 = -20.0;
  }

  // End of Saturate: '<S4>/Saturation3'

  // MATLAB Function: '<S1>/MATLAB Function4' incorporates:
  //   Abs: '<S1>/Abs3'
  //   Inport: '<Root>/Interp_x1_RR'
  //   Inport: '<Root>/Interp_x2_RR'
  //   Inport: '<Root>/Interp_x3_RR'
  //   Inport: '<Root>/LC RR'
  //   Inport: '<Root>/interp_y1_RR'
  //   Inport: '<Root>/interp_y2_RR'
  //   Inport: '<Root>/interp_y3_RR'
  //   Outport: '<Root>/FZ RR'

  Tire_Model_Codegen_MATLABFunction1(std::abs(Tire_Model_Codegen_U.LCRR),
    Tire_Model_Codegen_U.Interp_x1_RR, Tire_Model_Codegen_U.Interp_x2_RR,
    Tire_Model_Codegen_U.Interp_x3_RR, Tire_Model_Codegen_U.interp_y1_RR,
    Tire_Model_Codegen_U.interp_y2_RR, Tire_Model_Codegen_U.interp_y3_RR,
    &Tire_Model_Codegen_Y.FZRR);

  // MATLAB Function: '<S20>/MATLAB Function' incorporates:
  //   Abs: '<S20>/Abs1'
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S20>/Constant10'
  //   Constant: '<S20>/Constant3'
  //   Constant: '<S20>/Constant4'
  //   Constant: '<S20>/Constant5'
  //   Constant: '<S20>/Constant6'
  //   Constant: '<S20>/Constant7'
  //   Constant: '<S20>/Constant8'
  //   Constant: '<S20>/Constant9'
  //   Gain: '<S20>/Gain'
  //   Gain: '<S4>/Gain6'
  //   Inport: '<Root>/SL RR'
  //   Outport: '<Root>/FZ RR'

  Tire_Model_Codegen_MATLABFunction(Tire_Model_Codegen_ConstP.pooled10,
    Tire_Model_Codegen_ConstP.pooled11, Tire_Model_Codegen_ConstP.pooled12,
    Tire_Model_Codegen_ConstP.pooled13, Tire_Model_Codegen_ConstP.pooled14,
    Tire_Model_Codegen_ConstP.pooled15, Tire_Model_Codegen_ConstP.pooled16,
    Tire_Model_Codegen_ConstP.pooled9, Tire_Model_Codegen_U.RR, Saturation3,
    -std::abs(-Tire_Model_Codegen_Y.FZRR), 0.0, &COMBINED_FX, &COMBINED_FY,
    &COMBINED_MZ, &rtb_Abs1_p, &rtb_Abs1_ao, &AMU, &EPSILON, &FZO, &LCX, &LCY,
    &LEX, &LEY, &LFZO, &LHX, &LHY, &LKXKAPPA, &LKYALPHA, &LKYGAMMA, &LKZGAMMA,
    &LMR, &LMUV, &LMUX, &LMUXAST, &LMUXPRIME, &LMUY, &LMUYAST, &LMUYPRIME, &LMX,
    &LS, &LT, &LVX, &LVY, &LVYKAPPA, &LXALPHA, &LYKAPPA, &PCX1, &PCY1, &PDX1,
    &PDX2, &PDX3, &PDY1, &PDY2, &PDY3, &PEX1, &PEX2, &PEX3, &PEX4, &PEY1, &PEY2,
    &PEY3, &PEY4, &PEY5, &PHX1, &PHX2, &PHY1, &PHY2, &PKX1, &PKX2, &PKX3, &PKY1,
    &PKY2, &PKY3, &PKY4, &PKY5, &PKY6, &PKY7, &PVX1, &PVX2, &PVY1, &PVY2, &PVY3,
    &PVY4, &QBZ1, &QBZ10, &QBZ2, &QBZ3, &QBZ5, &QBZ6, &QBZ9, &QCZ1, &QDZ1,
    &QDZ10, &QDZ11, &QDZ2, &QDZ3, &QDZ4, &QDZ6, &QDZ7, &QDZ8, &QDZ9, &QEZ1,
    &QEZ2, &QEZ3, &QEZ4, &QEZ5, &QHZ1, &QHZ2, &QHZ3, &QHZ4, &QSX1, &QSX2, &QSX3,
    &RBX1, &RBX2, &RBX3, &RBY1, &RBY2, &RBY3, &RBY4, &RCX1, &RCY1, &REX1, &REX2,
    &REY1, &REY2, &RHX1, &RHY1, &RHY2, &RO, &RVY1, &RVY2, &RVY3, &RVY4, &RVY5,
    &RVY6, &SSZ1, &SSZ2, &SSZ3, &SSZ4, &VCX, &ZETA0, &ZETA1, &ZETA2, &ZETA3,
    &ZETA4, &ZETA5, &ZETA6, &ZETA7, &ZETA8);

  // Switch: '<S20>/Switch3' incorporates:
  //   Constant: '<S20>/Constant15'
  //   Inport: '<Root>/SL RR'

  if (Tire_Model_Codegen_U.RR != 0.0) {
    // Abs: '<S42>/Abs1'
    AMU = std::abs(Tire_Model_Codegen_U.RR);

    // Switch: '<S42>/Switch1' incorporates:
    //   Inport: '<Root>/LMUX RR'
    //   Polyval: '<S42>/Polynomial'
    //   Product: '<S20>/Product'
    //   Product: '<S42>/Product1'

    if (AMU >= 0.2) {
      AMU = (((1.7306074402864622E-15 * AMU - 3.5736731257900937E-15) * AMU +
              2.2908369318766675E-15) * AMU + 0.99999999999999956) *
        (COMBINED_FX * Tire_Model_Codegen_U.LMUXRR);
    } else {
      AMU = COMBINED_FX * Tire_Model_Codegen_U.LMUXRR;
    }

    // End of Switch: '<S42>/Switch1'
  } else {
    AMU = 0.0;
  }

  // End of Switch: '<S20>/Switch3'

  // Outport: '<Root>/FX RR' incorporates:
  //   Gain: '<S29>/Gain8'
  //   Switch: '<S29>/Switch'

  Tire_Model_Codegen_Y.FXRR = 0.6 * AMU;

  // Switch: '<S13>/Switch1' incorporates:
  //   Constant: '<S13>/Constant1'

  if (Saturation != 0.0) {
    // Switch: '<S4>/Switch7' incorporates:
    //   Abs: '<S4>/Abs'
    //   Constant: '<S4>/Constant14'
    //   Gain: '<S4>/Gain1'
    //   Gain: '<S9>/Gain'
    //   Gain: '<S9>/Gain1'
    //   Inport: '<Root>/Motor RPM FL'

    if (std::abs(0.10472 * Tire_Model_Codegen_U.MotorRPMFL *
                 0.084317032040472181) != 0.0) {
      // Switch: '<S17>/Switch4' incorporates:
      //   Constant: '<S17>/Constant12'

      if (Saturation != 0.0) {
        // Abs: '<S32>/Abs1'
        AMU = std::abs(Saturation);

        // Switch: '<S32>/Switch1' incorporates:
        //   Inport: '<Root>/LMUY FL'
        //   Polyval: '<S32>/Polynomial'
        //   Product: '<S17>/Product1'
        //   Product: '<S32>/Product1'

        if (AMU >= 10.0) {
          COMBINED_FY_o = (-5.1674484600257E-19 * AMU * AMU + 1.0) *
            (COMBINED_FY_o * Tire_Model_Codegen_U.LMUYFL);
        } else {
          COMBINED_FY_o *= Tire_Model_Codegen_U.LMUYFL;
        }

        // End of Switch: '<S32>/Switch1'
      } else {
        COMBINED_FY_o = 0.0;
      }

      // End of Switch: '<S17>/Switch4'
      COMBINED_FY_o *= 0.6;
    } else {
      COMBINED_FY_o = 0.0;
    }

    // End of Switch: '<S4>/Switch7'
  } else {
    COMBINED_FY_o = 0.0;
  }

  // End of Switch: '<S13>/Switch1'

  // Switch: '<S13>/Switch'
  if (Saturation > 0.0) {
    // Outport: '<Root>/FY FL' incorporates:
    //   Abs: '<S13>/Abs'

    Tire_Model_Codegen_Y.FYFL = std::abs(COMBINED_FY_o);
  } else {
    // Outport: '<Root>/FY FL' incorporates:
    //   Abs: '<S13>/Abs1'
    //   Gain: '<S30>/Gain'

    Tire_Model_Codegen_Y.FYFL = -std::abs(COMBINED_FY_o);
  }

  // End of Switch: '<S13>/Switch'

  // Switch: '<S14>/Switch1' incorporates:
  //   Constant: '<S14>/Constant1'

  if (Saturation1 != 0.0) {
    // Switch: '<S4>/Switch6' incorporates:
    //   Abs: '<S4>/Abs1'
    //   Constant: '<S4>/Constant13'
    //   Gain: '<S10>/Gain'
    //   Gain: '<S10>/Gain1'
    //   Gain: '<S4>/Gain3'
    //   Inport: '<Root>/Motor RPM FR'

    if (std::abs(0.10472 * Tire_Model_Codegen_U.MotorRPMFR *
                 0.084317032040472181) != 0.0) {
      // Switch: '<S18>/Switch4' incorporates:
      //   Constant: '<S18>/Constant12'

      if (Saturation1 != 0.0) {
        // Abs: '<S35>/Abs1'
        COMBINED_FY_o = std::abs(Saturation1);

        // Switch: '<S35>/Switch1' incorporates:
        //   Inport: '<Root>/LMUY FR'
        //   Polyval: '<S35>/Polynomial'
        //   Product: '<S18>/Product1'
        //   Product: '<S35>/Product1'

        if (COMBINED_FY_o >= 10.0) {
          COMBINED_FY_a = (-5.1674484600257E-19 * COMBINED_FY_o * COMBINED_FY_o
                           + 1.0) * (COMBINED_FY_a * Tire_Model_Codegen_U.LMUYFR);
        } else {
          COMBINED_FY_a *= Tire_Model_Codegen_U.LMUYFR;
        }

        // End of Switch: '<S35>/Switch1'
      } else {
        COMBINED_FY_a = 0.0;
      }

      // End of Switch: '<S18>/Switch4'
      COMBINED_FY_a *= 0.6;
    } else {
      COMBINED_FY_a = 0.0;
    }

    // End of Switch: '<S4>/Switch6'
  } else {
    COMBINED_FY_a = 0.0;
  }

  // End of Switch: '<S14>/Switch1'

  // Switch: '<S14>/Switch'
  if (Saturation1 > 0.0) {
    // Outport: '<Root>/FY FR' incorporates:
    //   Abs: '<S14>/Abs'

    Tire_Model_Codegen_Y.FYFR = std::abs(COMBINED_FY_a);
  } else {
    // Outport: '<Root>/FY FR' incorporates:
    //   Abs: '<S14>/Abs1'
    //   Gain: '<S30>/Gain1'

    Tire_Model_Codegen_Y.FYFR = -std::abs(COMBINED_FY_a);
  }

  // End of Switch: '<S14>/Switch'

  // Switch: '<S15>/Switch1' incorporates:
  //   Constant: '<S15>/Constant1'

  if (Saturation2 != 0.0) {
    // Switch: '<S4>/Switch5' incorporates:
    //   Abs: '<S4>/Abs2'
    //   Constant: '<S4>/Constant12'
    //   Gain: '<S11>/Gain'
    //   Gain: '<S11>/Gain1'
    //   Gain: '<S4>/Gain5'
    //   Inport: '<Root>/Motor RPM RL'

    if (std::abs(0.10472 * Tire_Model_Codegen_U.MotorRPMRL *
                 0.084317032040472181) != 0.0) {
      // Switch: '<S19>/Switch4' incorporates:
      //   Constant: '<S19>/Constant12'

      if (Saturation2 != 0.0) {
        // Abs: '<S38>/Abs1'
        COMBINED_FY_a = std::abs(Saturation2);

        // Switch: '<S38>/Switch1' incorporates:
        //   Inport: '<Root>/LMUY RL'
        //   Polyval: '<S38>/Polynomial'
        //   Product: '<S19>/Product1'
        //   Product: '<S38>/Product1'

        if (COMBINED_FY_a >= 10.0) {
          COMBINED_FY_c = (-5.1674484600257E-19 * COMBINED_FY_a * COMBINED_FY_a
                           + 1.0) * (COMBINED_FY_c * Tire_Model_Codegen_U.LMUYRL);
        } else {
          COMBINED_FY_c *= Tire_Model_Codegen_U.LMUYRL;
        }

        // End of Switch: '<S38>/Switch1'
      } else {
        COMBINED_FY_c = 0.0;
      }

      // End of Switch: '<S19>/Switch4'
      COMBINED_FY_c *= 0.6;
    } else {
      COMBINED_FY_c = 0.0;
    }

    // End of Switch: '<S4>/Switch5'
  } else {
    COMBINED_FY_c = 0.0;
  }

  // End of Switch: '<S15>/Switch1'

  // Switch: '<S15>/Switch'
  if (Saturation2 > 0.0) {
    // Outport: '<Root>/FY RL' incorporates:
    //   Abs: '<S15>/Abs'

    Tire_Model_Codegen_Y.FYRL = std::abs(COMBINED_FY_c);
  } else {
    // Outport: '<Root>/FY RL' incorporates:
    //   Abs: '<S15>/Abs1'
    //   Gain: '<S30>/Gain2'

    Tire_Model_Codegen_Y.FYRL = -std::abs(COMBINED_FY_c);
  }

  // End of Switch: '<S15>/Switch'

  // Switch: '<S16>/Switch1' incorporates:
  //   Constant: '<S16>/Constant1'

  if (Saturation3 != 0.0) {
    // Switch: '<S4>/Switch4' incorporates:
    //   Abs: '<S4>/Abs3'
    //   Constant: '<S4>/Constant11'
    //   Gain: '<S12>/Gain'
    //   Gain: '<S12>/Gain1'
    //   Gain: '<S4>/Gain7'
    //   Inport: '<Root>/Motor RPM RR'

    if (std::abs(0.10472 * Tire_Model_Codegen_U.MotorRPMRR *
                 0.084317032040472181) != 0.0) {
      // Switch: '<S20>/Switch4' incorporates:
      //   Constant: '<S20>/Constant12'

      if (Saturation3 != 0.0) {
        // Abs: '<S41>/Abs1'
        COMBINED_FY_c = std::abs(Saturation3);

        // Switch: '<S41>/Switch1' incorporates:
        //   Inport: '<Root>/LMUY RR'
        //   Polyval: '<S41>/Polynomial'
        //   Product: '<S20>/Product1'
        //   Product: '<S41>/Product1'

        if (COMBINED_FY_c >= 10.0) {
          COMBINED_FY = (-5.1674484600257E-19 * COMBINED_FY_c * COMBINED_FY_c +
                         1.0) * (COMBINED_FY * Tire_Model_Codegen_U.LMUYRR);
        } else {
          COMBINED_FY *= Tire_Model_Codegen_U.LMUYRR;
        }

        // End of Switch: '<S41>/Switch1'
      } else {
        COMBINED_FY = 0.0;
      }

      // End of Switch: '<S20>/Switch4'
      COMBINED_FY *= 0.6;
    } else {
      COMBINED_FY = 0.0;
    }

    // End of Switch: '<S4>/Switch4'
  } else {
    COMBINED_FY = 0.0;
  }

  // End of Switch: '<S16>/Switch1'

  // Switch: '<S16>/Switch'
  if (Saturation3 > 0.0) {
    // Outport: '<Root>/FY RR' incorporates:
    //   Abs: '<S16>/Abs'

    Tire_Model_Codegen_Y.FYRR = std::abs(COMBINED_FY);
  } else {
    // Outport: '<Root>/FY RR' incorporates:
    //   Abs: '<S16>/Abs1'
    //   Gain: '<S30>/Gain3'

    Tire_Model_Codegen_Y.FYRR = -std::abs(COMBINED_FY);
  }

  // End of Switch: '<S16>/Switch'

  // Switch: '<S4>/Switch9' incorporates:
  //   Constant: '<S4>/Constant7'

  if (Saturation != 0.0) {
    // Switch: '<S4>/Switch1' incorporates:
    //   Constant: '<S4>/Constant7'
    //   Gain: '<S4>/Gain12'
    //   Inport: '<Root>/SL FL'
    //   Switch: '<S17>/Switch5'

    if (Tire_Model_Codegen_U.FL != 0.0) {
      // Switch: '<S17>/Switch5' incorporates:
      //   Constant: '<S17>/Constant13'
      //   Inport: '<Root>/LMUY FL'
      //   Product: '<S17>/Product2'

      if (Saturation != 0.0) {
        Saturation = COMBINED_MZ_p * Tire_Model_Codegen_U.LMUYFL;
      } else {
        Saturation = 0.0;
      }

      Saturation *= 0.6;
    } else {
      Saturation = 0.0;
    }

    // End of Switch: '<S4>/Switch1'
  } else {
    Saturation = 0.0;
  }

  // End of Switch: '<S4>/Switch9'

  // Outport: '<Root>/MZ FL' incorporates:
  //   Gain: '<S25>/Gain'

  Tire_Model_Codegen_Y.MZFL = -Saturation;

  // Switch: '<S4>/Switch10' incorporates:
  //   Constant: '<S4>/Constant8'

  if (Saturation1 != 0.0) {
    // Switch: '<S4>/Switch2' incorporates:
    //   Constant: '<S4>/Constant8'
    //   Gain: '<S4>/Gain13'
    //   Inport: '<Root>/SL FR'
    //   Switch: '<S18>/Switch5'

    if (Tire_Model_Codegen_U.FR != 0.0) {
      // Switch: '<S18>/Switch5' incorporates:
      //   Constant: '<S18>/Constant13'
      //   Inport: '<Root>/LMUY FR'
      //   Product: '<S18>/Product2'

      if (Saturation1 != 0.0) {
        Saturation = COMBINED_MZ_e * Tire_Model_Codegen_U.LMUYFR;
      } else {
        Saturation = 0.0;
      }

      Saturation *= 0.6;
    } else {
      Saturation = 0.0;
    }

    // End of Switch: '<S4>/Switch2'
  } else {
    Saturation = 0.0;
  }

  // End of Switch: '<S4>/Switch10'

  // Outport: '<Root>/MZ FR' incorporates:
  //   Gain: '<S25>/Gain1'

  Tire_Model_Codegen_Y.MZFR = -Saturation;

  // Switch: '<S4>/Switch11' incorporates:
  //   Constant: '<S4>/Constant9'

  if (Saturation2 != 0.0) {
    // Switch: '<S4>/Switch3' incorporates:
    //   Constant: '<S4>/Constant9'
    //   Gain: '<S4>/Gain14'
    //   Inport: '<Root>/SL RL'
    //   Switch: '<S19>/Switch5'

    if (Tire_Model_Codegen_U.RL != 0.0) {
      // Switch: '<S19>/Switch5' incorporates:
      //   Constant: '<S19>/Constant13'
      //   Inport: '<Root>/LMUY RL'
      //   Product: '<S19>/Product2'

      if (Saturation2 != 0.0) {
        Saturation = COMBINED_MZ_g * Tire_Model_Codegen_U.LMUYRL;
      } else {
        Saturation = 0.0;
      }

      Saturation *= 0.6;
    } else {
      Saturation = 0.0;
    }

    // End of Switch: '<S4>/Switch3'
  } else {
    Saturation = 0.0;
  }

  // End of Switch: '<S4>/Switch11'

  // Outport: '<Root>/MZ RL' incorporates:
  //   Gain: '<S25>/Gain2'

  Tire_Model_Codegen_Y.MZRL = -Saturation;

  // Switch: '<S4>/Switch12' incorporates:
  //   Constant: '<S4>/Constant10'

  if (Saturation3 != 0.0) {
    // Switch: '<S4>/Switch8' incorporates:
    //   Constant: '<S4>/Constant10'
    //   Gain: '<S4>/Gain15'
    //   Inport: '<Root>/SL RR'
    //   Switch: '<S20>/Switch5'

    if (Tire_Model_Codegen_U.RR != 0.0) {
      // Switch: '<S20>/Switch5' incorporates:
      //   Constant: '<S20>/Constant13'
      //   Inport: '<Root>/LMUY RR'
      //   Product: '<S20>/Product2'

      if (Saturation3 != 0.0) {
        Saturation = COMBINED_MZ * Tire_Model_Codegen_U.LMUYRR;
      } else {
        Saturation = 0.0;
      }

      Saturation *= 0.6;
    } else {
      Saturation = 0.0;
    }

    // End of Switch: '<S4>/Switch8'
  } else {
    Saturation = 0.0;
  }

  // End of Switch: '<S4>/Switch12'

  // Outport: '<Root>/MZ RR' incorporates:
  //   Gain: '<S25>/Gain3'

  Tire_Model_Codegen_Y.MZRR = -Saturation;

  // Gain: '<S17>/Gain1' incorporates:
  //   Inport: '<Root>/LMUX FL'
  //   Product: '<S17>/Product3'

  Tire_Model_Codegen_Y.satAccelTFL = satAccelT_k0 * Tire_Model_Codegen_U.LMUXFL *
    0.6;

  // Gain: '<S18>/Gain1' incorporates:
  //   Inport: '<Root>/LMUX FR'
  //   Product: '<S18>/Product3'

  Tire_Model_Codegen_Y.satAccelTFR = satAccelT_k * Tire_Model_Codegen_U.LMUXFR *
    0.6;

  // Gain: '<S19>/Gain1' incorporates:
  //   Inport: '<Root>/LMUX RL'
  //   Product: '<S19>/Product3'

  Tire_Model_Codegen_Y.satAccelTRL = satAccelT_a * Tire_Model_Codegen_U.LMUXRL *
    0.6;

  // Gain: '<S20>/Gain1' incorporates:
  //   Inport: '<Root>/LMUX RR'
  //   Product: '<S20>/Product3'

  Tire_Model_Codegen_Y.satAccelTRR = rtb_Abs1_p * Tire_Model_Codegen_U.LMUXRR *
    0.6;

  // Gain: '<S17>/Gain2' incorporates:
  //   Inport: '<Root>/LMUX FL'
  //   Product: '<S17>/Product4'

  Tire_Model_Codegen_Y.satBrakeTFL = satBrakeT_f * Tire_Model_Codegen_U.LMUXFL *
    0.6;

  // Gain: '<S18>/Gain2' incorporates:
  //   Inport: '<Root>/LMUX FR'
  //   Product: '<S18>/Product4'

  Tire_Model_Codegen_Y.satBrakeTFR = COMBINED_FX_c * Tire_Model_Codegen_U.LMUXFR
    * 0.6;

  // Gain: '<S19>/Gain2' incorporates:
  //   Inport: '<Root>/LMUX RL'
  //   Product: '<S19>/Product4'

  Tire_Model_Codegen_Y.satBrakeTRL = rtb_Abs1_hx * Tire_Model_Codegen_U.LMUXRL *
    0.6;

  // Gain: '<S20>/Gain2' incorporates:
  //   Inport: '<Root>/LMUX RR'
  //   Product: '<S20>/Product4'

  Tire_Model_Codegen_Y.satBrakeTRR = rtb_Abs1_ao * Tire_Model_Codegen_U.LMUXRR *
    0.6;

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Inport: '<Root>/Initial Torq Req FL'
  //   Inport: '<Root>/Initial Torq Req FR'
  //   Inport: '<Root>/Initial Torq Req RL'
  //   Inport: '<Root>/Initial Torq Req RR'

  if (((Tire_Model_Codegen_U.InitialTorqReqFL +
        Tire_Model_Codegen_U.InitialTorqReqFR) +
       Tire_Model_Codegen_U.InitialTorqReqRL) +
      Tire_Model_Codegen_U.InitialTorqReqRR >= 0.0) {
    // Outport: '<Root>/torq_req_FL'
    Tire_Model_Codegen_Y.torq_req_FL = std::fmin
      (Tire_Model_Codegen_U.InitialTorqReqFL, Tire_Model_Codegen_Y.satAccelTFL);

    // Outport: '<Root>/torq_req_FR'
    Tire_Model_Codegen_Y.torq_req_FR = std::fmin
      (Tire_Model_Codegen_U.InitialTorqReqFR, Tire_Model_Codegen_Y.satAccelTFR);

    // Outport: '<Root>/torq_req_RL'
    Tire_Model_Codegen_Y.torq_req_RL = std::fmin
      (Tire_Model_Codegen_U.InitialTorqReqRL, Tire_Model_Codegen_Y.satAccelTRL);

    // Outport: '<Root>/torq_req_RR'
    Tire_Model_Codegen_Y.torq_req_RR = std::fmin
      (Tire_Model_Codegen_U.InitialTorqReqRR, Tire_Model_Codegen_Y.satAccelTRR);
  } else {
    // Outport: '<Root>/torq_req_FL'
    Tire_Model_Codegen_Y.torq_req_FL = std::fmax
      (Tire_Model_Codegen_U.InitialTorqReqFL, Tire_Model_Codegen_Y.satBrakeTFL);

    // Outport: '<Root>/torq_req_FR'
    Tire_Model_Codegen_Y.torq_req_FR = std::fmax
      (Tire_Model_Codegen_U.InitialTorqReqFR, Tire_Model_Codegen_Y.satBrakeTFR);

    // Outport: '<Root>/torq_req_RL'
    Tire_Model_Codegen_Y.torq_req_RL = std::fmax
      (Tire_Model_Codegen_U.InitialTorqReqRL, Tire_Model_Codegen_Y.satBrakeTRL);

    // Outport: '<Root>/torq_req_RR'
    Tire_Model_Codegen_Y.torq_req_RR = std::fmax
      (Tire_Model_Codegen_U.InitialTorqReqRR, Tire_Model_Codegen_Y.satBrakeTRR);
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'
}

// Model initialize function
void Tire_Model_Codegen::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void Tire_Model_Codegen::terminate()
{
  // (no terminate code required)
}

const char_T* Tire_Model_Codegen::RT_MODEL_Tire_Model_Codegen_T::getErrorStatus()
  const
{
  return (errorStatus);
}

void Tire_Model_Codegen::RT_MODEL_Tire_Model_Codegen_T::setErrorStatus(const
  char_T* const volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
Tire_Model_Codegen::Tire_Model_Codegen() :
  Tire_Model_Codegen_U(),
  Tire_Model_Codegen_Y(),
  Tire_Model_Codegen_DW(),
  Tire_Model_Codegen_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Tire_Model_Codegen::~Tire_Model_Codegen() = default;

// Real-Time Model get method
Tire_Model_Codegen::RT_MODEL_Tire_Model_Codegen_T * Tire_Model_Codegen::getRTM()
{
  return (&Tire_Model_Codegen_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
