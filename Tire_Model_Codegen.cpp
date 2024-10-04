//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Tire_Model_Codegen.cpp
//
// Code generated for Simulink model 'Tire_Model_Codegen'.
//
// Model version                  : 1.4
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Fri Oct  4 00:33:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Tire_Model_Codegen.h"
#include "rtwtypes.h"
#include <cmath>
#include <emmintrin.h>
#include <cstring>
#include "cmath"

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_PSS_FY(const real_T P[22],
  const real_T INPUT[3], const real_T *FZO, const real_T *LFZO) const
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
  FZOPRIME = *FZO * *LFZO;
  DFZ = (FZ - FZOPRIME) / FZOPRIME;
  GAMMA_AST = std::sin(0.017453292519943295 * INPUT[2]);
  CY = P[0] * Tire_Model_Codegen_DW.LCY;
  DY_tmp = GAMMA_AST * GAMMA_AST;
  DY = std::abs((P[2] * DFZ + P[1]) / (DY_tmp * P[3] + 1.0) *
                Tire_Model_Codegen_DW.LMUYAST) * FZ *
    Tire_Model_Codegen_DW.ZETA2;
  KYALPHA = std::sin(std::atan(FZ / ((DY_tmp * P[13] + P[10]) * FZOPRIME)) * P
                     [12]) * (P[9] * FZOPRIME) / (DY_tmp * P[11] + 1.0) *
    Tire_Model_Codegen_DW.ZETA3 * Tire_Model_Codegen_DW.LKYALPHA;
  FZOPRIME = (P[21] * DFZ + P[20]) * FZ * GAMMA_AST *
    Tire_Model_Codegen_DW.LKYGAMMA * Tire_Model_Codegen_DW.LMUYPRIME *
    Tire_Model_Codegen_DW.ZETA2;
  u_tmp = (P[15] * DFZ + P[14]) * FZ * Tire_Model_Codegen_DW.LKYGAMMA *
    GAMMA_AST - FZOPRIME;
  if (std::isnan(u_tmp)) {
    tmp = (rtNaN);
  } else if (u_tmp < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (u_tmp > 0.0);
  }

  ALPHAY = (((u_tmp * Tire_Model_Codegen_DW.ZETA4 /
              (Tire_Model_Codegen_DW.EPSILON * tmp + KYALPHA) + (P[17] * DFZ +
    P[16]) * Tire_Model_Codegen_DW.LHY) + Tire_Model_Codegen_DW.ZETA3) - 1.0) +
    std::tan(ALPHA);
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

  KYALPHA = KYALPHA / (CY * DY + Tire_Model_Codegen_DW.EPSILON * tmp) * ALPHAY;
  FY = -(std::sin(std::atan(KYALPHA - ((DY_tmp * P[8] + 1.0) - (P[7] * GAMMA_AST
             + P[6]) * u_tmp) * (P[5] * DFZ + P[4]) * Tire_Model_Codegen_DW.LEY *
           (KYALPHA - std::atan(KYALPHA))) * CY) * DY + ((P[19] * DFZ + P[18]) *
          FZ * Tire_Model_Codegen_DW.LVY * Tire_Model_Codegen_DW.LMUYPRIME *
          Tire_Model_Codegen_DW.ZETA2 + FZOPRIME));
  if (ALPHA == 0.0) {
    FY = 0.0;
  }

  return FY;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FY(const real_T
  R[15], const real_T INPUT[4], const real_T *FZO, const real_T *LFZO) const
{
  real_T tmp[22];
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
  tmp[0] = Tire_Model_Codegen_DW.PCY1;
  tmp[1] = Tire_Model_Codegen_DW.PDY1;
  tmp[2] = Tire_Model_Codegen_DW.PDY2;
  tmp[3] = Tire_Model_Codegen_DW.PDY3;
  tmp[4] = Tire_Model_Codegen_DW.PEY1;
  tmp[5] = Tire_Model_Codegen_DW.PEY2;
  tmp[6] = Tire_Model_Codegen_DW.PEY3;
  tmp[7] = Tire_Model_Codegen_DW.PEY4;
  tmp[8] = Tire_Model_Codegen_DW.PEY5;
  tmp[9] = Tire_Model_Codegen_DW.PKY1;
  tmp[10] = Tire_Model_Codegen_DW.PKY2;
  tmp[11] = Tire_Model_Codegen_DW.PKY3;
  tmp[12] = Tire_Model_Codegen_DW.PKY4;
  tmp[13] = Tire_Model_Codegen_DW.PKY5;
  tmp[14] = Tire_Model_Codegen_DW.PKY6;
  tmp[15] = Tire_Model_Codegen_DW.PKY7;
  tmp[16] = Tire_Model_Codegen_DW.PHY1;
  tmp[17] = Tire_Model_Codegen_DW.PHY2;
  tmp[18] = Tire_Model_Codegen_DW.PVY1;
  tmp[19] = Tire_Model_Codegen_DW.PVY2;
  tmp[20] = Tire_Model_Codegen_DW.PVY3;
  tmp[21] = Tire_Model_Codegen_DW.PVY4;
  INPUT_0[0] = INPUT[1];
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FYO = Tire_Model_Codegen_Pacejka52_PSS_FY(tmp, INPUT_0, FZO, LFZO);
  FYO = -FYO;
  FZ = std::abs(INPUT[2]);
  FZOPRIME = *FZO * *LFZO;
  FZOPRIME = (FZ - FZOPRIME) / FZOPRIME;
  GAMMA_AST = std::sin(0.017453292519943295 * INPUT[3]);
  ALPHA_AST = std::tan(-(0.017453292519943295 * INPUT[1]));
  EYKAPPA = R[6] * FZOPRIME + R[5];
  BYKAPPA_tmp = GAMMA_AST * GAMMA_AST;
  BYKAPPA = std::abs((BYKAPPA_tmp * R[3] + R[0]) * std::cos(std::atan((ALPHA_AST
    - R[2]) * R[1])) * Tire_Model_Codegen_DW.LYKAPPA);
  SHYKAPPA = R[8] * FZOPRIME + R[7];
  FY_tmp = (INPUT[0] + SHYKAPPA) * BYKAPPA;
  BYKAPPA *= SHYKAPPA;
  FY = std::abs((Tire_Model_Codegen_DW.PDY2 * FZOPRIME +
                 Tire_Model_Codegen_DW.PDY1) / (BYKAPPA_tmp *
    Tire_Model_Codegen_DW.PDY3 + 1.0) * Tire_Model_Codegen_DW.LMUYPRIME) * FZ *
    ((R[10] * FZOPRIME + R[9]) + R[11] * GAMMA_AST) * std::cos(std::atan(R[12] *
    ALPHA_AST)) * Tire_Model_Codegen_DW.ZETA2 * std::sin(std::atan(INPUT[0] * R
    [14]) * R[13]) * Tire_Model_Codegen_DW.LVYKAPPA + std::abs(std::cos(std::
    atan(FY_tmp - (FY_tmp - std::atan(FY_tmp)) * EYKAPPA) * R[4]) / std::cos(std::
    atan(BYKAPPA - (BYKAPPA - std::atan(BYKAPPA)) * EYKAPPA) * R[4])) * FYO;
  if (std::abs(FY) > std::abs(FYO)) {
    FY = FYO;
  }

  FY = -FY;
  return FY;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_PLS_FX(const real_T A[15],
  const real_T INPUT[3], const real_T *FZO, const real_T *LFZO, const real_T
  *LMUX, const real_T *LKXKAPPA) const
{
  real_T CX;
  real_T DX;
  real_T FX;
  real_T FZ;
  real_T FZOPRIME;
  real_T KAPPAX;
  real_T tmp;
  FZ = std::abs(INPUT[1]);
  FZOPRIME = *FZO * *LFZO;
  FZOPRIME = (FZ - FZOPRIME) / FZOPRIME;
  DX = std::sin(0.017453292519943295 * INPUT[2]);
  KAPPAX = (A[12] * FZOPRIME + A[11]) * Tire_Model_Codegen_DW.LHX + INPUT[0];
  CX = A[0] * Tire_Model_Codegen_DW.LCX;
  DX = (1.0 - DX * DX * A[3]) * (A[2] * FZOPRIME + A[1]) * *LMUX * FZ *
    Tire_Model_Codegen_DW.ZETA1;
  if (std::isnan(KAPPAX)) {
    tmp = (rtNaN);
  } else if (KAPPAX < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (KAPPAX > 0.0);
  }

  KAPPAX *= (A[9] * FZOPRIME + A[8]) * FZ * std::exp(A[10] * FZOPRIME) *
    *LKXKAPPA / (CX * DX + Tire_Model_Codegen_DW.EPSILON);
  FX = std::sin(std::atan(KAPPAX - ((A[5] * FZOPRIME + A[4]) + FZOPRIME *
    FZOPRIME * A[6]) * (1.0 - A[7] * tmp) * Tire_Model_Codegen_DW.LEX * (KAPPAX
    - std::atan(KAPPAX))) * CX) * DX + (A[14] * FZOPRIME + A[13]) * FZ *
    Tire_Model_Codegen_DW.LVX * Tire_Model_Codegen_DW.LMUXPRIME *
    Tire_Model_Codegen_DW.ZETA1;
  if (INPUT[0] == 0.0) {
    FX = 0.0;
  }

  return FX;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_MZ(const real_T
  S[4], const real_T INPUT[4], const real_T *FZO, const real_T *RO, const real_T
  *VCX, const real_T *LFZO, const real_T *LMUX, const real_T *LKXKAPPA) const
{
  real_T tmp_0[22];
  real_T tmp[15];
  real_T INPUT_0[3];
  real_T ALPHAR;
  real_T ALPHAT;
  real_T BT;
  real_T BT_tmp;
  real_T BXALPHA;
  real_T CY;
  real_T EXALPHA;
  real_T EXALPHA_tmp;
  real_T EYKAPPA;
  real_T FXO;
  real_T FX_tmp;
  real_T FY_tmp;
  real_T KYALPHAPRIME;
  real_T MZ;
  real_T MZ_tmp;
  real_T SHYKAPPA;
  real_T SVYGAMMA;
  real_T b_FZOPRIME;
  real_T b_FZOPRIME_tmp;
  real_T c_a_tmp;
  real_T tmp_1;
  real_T tmp_2;
  real_T u_tmp;
  tmp[0] = Tire_Model_Codegen_DW.PCX1;
  tmp[1] = Tire_Model_Codegen_DW.PDX1;
  tmp[2] = Tire_Model_Codegen_DW.PDX2;
  tmp[3] = Tire_Model_Codegen_DW.PDX3;
  tmp[4] = Tire_Model_Codegen_DW.PEX1;
  tmp[5] = Tire_Model_Codegen_DW.PEX2;
  tmp[6] = Tire_Model_Codegen_DW.PEX3;
  tmp[7] = Tire_Model_Codegen_DW.PEX4;
  tmp[8] = Tire_Model_Codegen_DW.PKX1;
  tmp[9] = Tire_Model_Codegen_DW.PKX2;
  tmp[10] = Tire_Model_Codegen_DW.PKX3;
  tmp[11] = Tire_Model_Codegen_DW.PHX1;
  tmp[12] = Tire_Model_Codegen_DW.PHX2;
  tmp[13] = Tire_Model_Codegen_DW.PVX1;
  tmp[14] = Tire_Model_Codegen_DW.PVX2;
  INPUT_0[0] = 0.0;
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FXO = Tire_Model_Codegen_Pacejka52_PLS_FX(tmp, INPUT_0, FZO, LFZO, LMUX,
    LKXKAPPA);
  b_FZOPRIME_tmp = *FZO * *LFZO;
  c_a_tmp = std::sin(0.017453292519943295 * INPUT[3]);
  EXALPHA_tmp = std::abs(INPUT[2]);
  EXALPHA = (EXALPHA_tmp - b_FZOPRIME_tmp) / b_FZOPRIME_tmp *
    Tire_Model_Codegen_DW.REX2 + Tire_Model_Codegen_DW.REX1;
  ALPHAR = std::tan(-(0.017453292519943295 * INPUT[1]));
  b_FZOPRIME = c_a_tmp * c_a_tmp;
  BXALPHA = std::abs((b_FZOPRIME * Tire_Model_Codegen_DW.RBX3 +
                      Tire_Model_Codegen_DW.RBX1) * std::cos(std::atan
    (Tire_Model_Codegen_DW.RBX2 * 0.0)) * Tire_Model_Codegen_DW.LXALPHA);
  FX_tmp = (ALPHAR + Tire_Model_Codegen_DW.RHX1) * BXALPHA;
  BXALPHA *= Tire_Model_Codegen_DW.RHX1;
  EXALPHA = std::abs(std::cos(std::atan(FX_tmp - (FX_tmp - std::atan(FX_tmp)) *
    EXALPHA) * Tire_Model_Codegen_DW.RCX1) / std::cos(std::atan(BXALPHA -
    (BXALPHA - std::atan(BXALPHA)) * EXALPHA) * Tire_Model_Codegen_DW.RCX1)) *
    FXO;
  if (std::abs(EXALPHA) > std::abs(FXO)) {
    EXALPHA = FXO;
  }

  tmp_0[0] = Tire_Model_Codegen_DW.PCY1;
  tmp_0[1] = Tire_Model_Codegen_DW.PDY1;
  tmp_0[2] = Tire_Model_Codegen_DW.PDY2;
  tmp_0[3] = Tire_Model_Codegen_DW.PDY3;
  tmp_0[4] = Tire_Model_Codegen_DW.PEY1;
  tmp_0[5] = Tire_Model_Codegen_DW.PEY2;
  tmp_0[6] = Tire_Model_Codegen_DW.PEY3;
  tmp_0[7] = Tire_Model_Codegen_DW.PEY4;
  tmp_0[8] = Tire_Model_Codegen_DW.PEY5;
  tmp_0[9] = Tire_Model_Codegen_DW.PKY1;
  tmp_0[10] = Tire_Model_Codegen_DW.PKY2;
  tmp_0[11] = Tire_Model_Codegen_DW.PKY3;
  tmp_0[12] = Tire_Model_Codegen_DW.PKY4;
  tmp_0[13] = Tire_Model_Codegen_DW.PKY5;
  tmp_0[14] = Tire_Model_Codegen_DW.PKY6;
  tmp_0[15] = Tire_Model_Codegen_DW.PKY7;
  tmp_0[16] = Tire_Model_Codegen_DW.PHY1;
  tmp_0[17] = Tire_Model_Codegen_DW.PHY2;
  tmp_0[18] = Tire_Model_Codegen_DW.PVY1;
  tmp_0[19] = Tire_Model_Codegen_DW.PVY2;
  tmp_0[20] = Tire_Model_Codegen_DW.PVY3;
  tmp_0[21] = Tire_Model_Codegen_DW.PVY4;
  INPUT_0[0] = INPUT[1];
  INPUT_0[1] = INPUT[2];
  INPUT_0[2] = INPUT[3];
  FXO = Tire_Model_Codegen_Pacejka52_PSS_FY(tmp_0, INPUT_0, FZO, LFZO);
  FXO = -FXO;
  FX_tmp = (EXALPHA_tmp - b_FZOPRIME_tmp) / b_FZOPRIME_tmp;
  EYKAPPA = Tire_Model_Codegen_DW.REY2 * FX_tmp + Tire_Model_Codegen_DW.REY1;
  BXALPHA = std::abs((b_FZOPRIME * Tire_Model_Codegen_DW.RBY4 +
                      Tire_Model_Codegen_DW.RBY1) * std::cos(std::atan((ALPHAR -
    Tire_Model_Codegen_DW.RBY3) * Tire_Model_Codegen_DW.RBY2)) *
                     Tire_Model_Codegen_DW.LYKAPPA);
  SHYKAPPA = Tire_Model_Codegen_DW.RHY2 * FX_tmp + Tire_Model_Codegen_DW.RHY1;
  CY = (INPUT[0] + SHYKAPPA) * BXALPHA;
  FY_tmp = BXALPHA * SHYKAPPA;
  BXALPHA = std::abs((Tire_Model_Codegen_DW.PDY2 * FX_tmp +
                      Tire_Model_Codegen_DW.PDY1) / (b_FZOPRIME *
    Tire_Model_Codegen_DW.PDY3 + 1.0) * Tire_Model_Codegen_DW.LMUYPRIME) *
    EXALPHA_tmp;
  SHYKAPPA = ((Tire_Model_Codegen_DW.RVY2 * FX_tmp + Tire_Model_Codegen_DW.RVY1)
              + Tire_Model_Codegen_DW.RVY3 * c_a_tmp) * BXALPHA * std::cos(std::
    atan(Tire_Model_Codegen_DW.RVY4 * ALPHAR)) * Tire_Model_Codegen_DW.ZETA2;
  EYKAPPA = std::abs(std::cos(std::atan(CY - (CY - std::atan(CY)) * EYKAPPA) *
    Tire_Model_Codegen_DW.RCY1) / std::cos(std::atan(FY_tmp - (FY_tmp - std::
    atan(FY_tmp)) * EYKAPPA) * Tire_Model_Codegen_DW.RCY1)) * FXO + std::sin(std::
    atan(INPUT[0] * Tire_Model_Codegen_DW.RVY6) * Tire_Model_Codegen_DW.RVY5) *
    SHYKAPPA * Tire_Model_Codegen_DW.LVYKAPPA;
  if (std::abs(EYKAPPA) > std::abs(FXO)) {
    EYKAPPA = FXO;
  }

  FXO = std::sin(std::atan(EXALPHA_tmp / ((b_FZOPRIME *
    Tire_Model_Codegen_DW.PKY5 + Tire_Model_Codegen_DW.PKY2) * b_FZOPRIME_tmp)) *
                 Tire_Model_Codegen_DW.PKY4) * (Tire_Model_Codegen_DW.PKY1 *
    b_FZOPRIME_tmp) / (b_FZOPRIME * Tire_Model_Codegen_DW.PKY3 + 1.0) *
    Tire_Model_Codegen_DW.ZETA3 * Tire_Model_Codegen_DW.LKYALPHA;
  SVYGAMMA = (Tire_Model_Codegen_DW.PVY4 * FX_tmp + Tire_Model_Codegen_DW.PVY3) *
    EXALPHA_tmp * c_a_tmp * Tire_Model_Codegen_DW.LKYGAMMA *
    Tire_Model_Codegen_DW.LMUYPRIME * Tire_Model_Codegen_DW.ZETA2;
  CY = Tire_Model_Codegen_DW.PCY1 * Tire_Model_Codegen_DW.LCY;
  FY_tmp = std::abs(c_a_tmp);
  BT_tmp = FX_tmp * FX_tmp;
  BT = ((Tire_Model_Codegen_DW.QBZ2 * FX_tmp + Tire_Model_Codegen_DW.QBZ1) +
        BT_tmp * Tire_Model_Codegen_DW.QBZ3) * ((Tire_Model_Codegen_DW.QBZ5 *
    FY_tmp + 1.0) + b_FZOPRIME * Tire_Model_Codegen_DW.QBZ6) *
    Tire_Model_Codegen_DW.LKYALPHA / Tire_Model_Codegen_DW.LMUYAST;
  ALPHAT = ((Tire_Model_Codegen_DW.QHZ4 * FX_tmp + Tire_Model_Codegen_DW.QHZ3) *
            c_a_tmp + (Tire_Model_Codegen_DW.QHZ2 * FX_tmp +
                       Tire_Model_Codegen_DW.QHZ1)) + ALPHAR;
  KYALPHAPRIME = FXO + Tire_Model_Codegen_DW.EPSILON;
  u_tmp = (Tire_Model_Codegen_DW.PKY7 * FX_tmp + Tire_Model_Codegen_DW.PKY6) *
    EXALPHA_tmp * Tire_Model_Codegen_DW.LKYGAMMA * c_a_tmp - SVYGAMMA;
  if (std::isnan(u_tmp)) {
    MZ_tmp = (rtNaN);
  } else if (u_tmp < 0.0) {
    MZ_tmp = -1.0;
  } else {
    MZ_tmp = (u_tmp > 0.0);
  }

  ALPHAR += ((Tire_Model_Codegen_DW.PVY2 * FX_tmp + Tire_Model_Codegen_DW.PVY1) *
             EXALPHA_tmp * Tire_Model_Codegen_DW.LVY *
             Tire_Model_Codegen_DW.LMUYPRIME * Tire_Model_Codegen_DW.ZETA2 +
             SVYGAMMA) / KYALPHAPRIME + (((u_tmp * Tire_Model_Codegen_DW.ZETA4 /
    (Tire_Model_Codegen_DW.EPSILON * MZ_tmp + FXO) + (Tire_Model_Codegen_DW.PHY2
    * FX_tmp + Tire_Model_Codegen_DW.PHY1) * Tire_Model_Codegen_DW.LHY) +
    Tire_Model_Codegen_DW.ZETA3) - 1.0);
  KYALPHAPRIME = (Tire_Model_Codegen_DW.PKX2 * FX_tmp +
                  Tire_Model_Codegen_DW.PKX1) * EXALPHA_tmp * std::exp
    (Tire_Model_Codegen_DW.PKX3 * FX_tmp) * *LKXKAPPA / KYALPHAPRIME;
  if (std::isnan(ALPHAT)) {
    MZ_tmp = (rtNaN);
  } else if (ALPHAT < 0.0) {
    MZ_tmp = -1.0;
  } else {
    MZ_tmp = (ALPHAT > 0.0);
  }

  KYALPHAPRIME = KYALPHAPRIME * KYALPHAPRIME * 0.0;
  SVYGAMMA = std::cos(-(0.017453292519943295 * INPUT[1]));
  if (std::isnan(*VCX)) {
    u_tmp = (rtNaN);
  } else if (*VCX < 0.0) {
    u_tmp = -1.0;
  } else {
    u_tmp = (*VCX > 0.0);
  }

  if (std::isnan(FXO)) {
    tmp_1 = (rtNaN);
  } else if (FXO < 0.0) {
    tmp_1 = -1.0;
  } else {
    tmp_1 = (FXO > 0.0);
  }

  if (std::isnan(ALPHAR)) {
    tmp_2 = (rtNaN);
  } else if (ALPHAR < 0.0) {
    tmp_2 = -1.0;
  } else {
    tmp_2 = (ALPHAR > 0.0);
  }

  MZ_tmp = std::sqrt(ALPHAT * ALPHAT + KYALPHAPRIME) * MZ_tmp * BT;
  MZ = -(((((((Tire_Model_Codegen_DW.QDZ9 * FX_tmp + Tire_Model_Codegen_DW.QDZ8)
              * c_a_tmp * Tire_Model_Codegen_DW.LKZGAMMA *
              Tire_Model_Codegen_DW.ZETA0 + (Tire_Model_Codegen_DW.QDZ7 * FX_tmp
    + Tire_Model_Codegen_DW.QDZ6) * Tire_Model_Codegen_DW.LMR *
              Tire_Model_Codegen_DW.ZETA2) + (Tire_Model_Codegen_DW.QDZ11 *
              FX_tmp + Tire_Model_Codegen_DW.QDZ10) * c_a_tmp * FY_tmp *
             Tire_Model_Codegen_DW.ZETA0) * (EXALPHA_tmp * *RO) * SVYGAMMA *
            Tire_Model_Codegen_DW.LMUYAST * u_tmp + Tire_Model_Codegen_DW.ZETA8)
           - 1.0) * std::cos(std::atan((FXO / (BXALPHA *
              Tire_Model_Codegen_DW.ZETA2 * CY + Tire_Model_Codegen_DW.EPSILON *
              tmp_1) * Tire_Model_Codegen_DW.QBZ10 * CY +
             Tire_Model_Codegen_DW.QBZ9 * Tire_Model_Codegen_DW.LKYALPHA /
             Tire_Model_Codegen_DW.LMUYAST) * Tire_Model_Codegen_DW.ZETA6 * (std::
             sqrt(ALPHAR * ALPHAR + KYALPHAPRIME) * tmp_2)) *
           Tire_Model_Codegen_DW.ZETA7) + -(std::cos(std::atan(MZ_tmp -
             ((Tire_Model_Codegen_DW.QEZ5 * c_a_tmp + Tire_Model_Codegen_DW.QEZ4)
              * 0.63661977236758138 * std::atan(BT * Tire_Model_Codegen_DW.QCZ1 *
    ALPHAT) + 1.0) * ((Tire_Model_Codegen_DW.QEZ2 * FX_tmp +
                       Tire_Model_Codegen_DW.QEZ1) + BT_tmp *
                      Tire_Model_Codegen_DW.QEZ3) * (MZ_tmp - std::atan(MZ_tmp)))
            * Tire_Model_Codegen_DW.QCZ1) * (*RO / b_FZOPRIME_tmp * EXALPHA_tmp *
            (Tire_Model_Codegen_DW.QDZ2 * FX_tmp + Tire_Model_Codegen_DW.QDZ1) *
            Tire_Model_Codegen_DW.LT * u_tmp * ((Tire_Model_Codegen_DW.QDZ3 *
              FY_tmp + 1.0) + b_FZOPRIME * Tire_Model_Codegen_DW.QDZ4) *
            Tire_Model_Codegen_DW.ZETA5) * SVYGAMMA) * (EYKAPPA - std::sin(std::
            atan(Tire_Model_Codegen_DW.RVY6 * 0.0) * Tire_Model_Codegen_DW.RVY5)
           * SHYKAPPA * Tire_Model_Codegen_DW.LVYKAPPA)) + ((EYKAPPA /
           b_FZOPRIME_tmp * S[1] + S[0]) + (S[3] * FX_tmp + S[2]) * c_a_tmp) *
         *RO * Tire_Model_Codegen_DW.LS * EXALPHA);
  return MZ;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_repelem(real_T x, real_T y[100])
{
  for (int32_T j{0}; j < 100; j++) {
    y[j] = x;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FY_m(const real_T
  R[15], const real_T INPUT[400], const real_T *FZO, const real_T *LFZO, real_T
  FY[100]) const
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
  b_FZOPRIME_tmp = *FZO * *LFZO;
  CY = Tire_Model_Codegen_DW.PCY1 * Tire_Model_Codegen_DW.LCY;
  P = Tire_Model_Codegen_DW.PKY1 * b_FZOPRIME_tmp;
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
    b_MUY_tmp_0 = (Tire_Model_Codegen_DW.PDY2 * DFZ_tmp +
                   Tire_Model_Codegen_DW.PDY1) / (b_MUY_tmp *
      Tire_Model_Codegen_DW.PDY3 + 1.0);
    b_MUY_0 = std::abs(b_MUY_tmp_0 * Tire_Model_Codegen_DW.LMUYAST) * FZ_tmp *
      Tire_Model_Codegen_DW.ZETA2;
    KYALPHA = std::sin(std::atan(FZ_tmp / ((b_MUY_tmp *
      Tire_Model_Codegen_DW.PKY5 + Tire_Model_Codegen_DW.PKY2) * b_FZOPRIME_tmp))
                       * Tire_Model_Codegen_DW.PKY4) * P / (b_MUY_tmp *
      Tire_Model_Codegen_DW.PKY3 + 1.0) * Tire_Model_Codegen_DW.ZETA3 *
      Tire_Model_Codegen_DW.LKYALPHA;
    SVYGAMMA = (Tire_Model_Codegen_DW.PVY4 * DFZ_tmp +
                Tire_Model_Codegen_DW.PVY3) * FZ_tmp * GAMMA_AST_tmp *
      Tire_Model_Codegen_DW.LKYGAMMA * Tire_Model_Codegen_DW.LMUYPRIME *
      Tire_Model_Codegen_DW.ZETA2;
    SHYKAPPA_0 = (Tire_Model_Codegen_DW.PKY7 * DFZ_tmp +
                  Tire_Model_Codegen_DW.PKY6) * FZ_tmp *
      Tire_Model_Codegen_DW.LKYGAMMA * GAMMA_AST_tmp - SVYGAMMA;
    if (std::isnan(SHYKAPPA_0)) {
      tmp = (rtNaN);
    } else if (SHYKAPPA_0 < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (SHYKAPPA_0 > 0.0);
    }

    ALPHA_AST_tmp = std::tan(ALPHA);
    ALPHA_AST = ((((Tire_Model_Codegen_DW.PHY2 * DFZ_tmp +
                    Tire_Model_Codegen_DW.PHY1) * Tire_Model_Codegen_DW.LHY +
                   SHYKAPPA_0 * Tire_Model_Codegen_DW.ZETA4 /
                   (Tire_Model_Codegen_DW.EPSILON * tmp + KYALPHA)) +
                  Tire_Model_Codegen_DW.ZETA3) - 1.0) + ALPHA_AST_tmp;
    if (std::isnan(KYALPHA)) {
      tmp = (rtNaN);
    } else if (KYALPHA < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (KYALPHA > 0.0);
    }

    KYALPHA = KYALPHA / (CY * b_MUY_0 + Tire_Model_Codegen_DW.EPSILON * tmp) *
      ALPHA_AST;
    if (std::isnan(ALPHA_AST)) {
      tmp = (rtNaN);
    } else if (ALPHA_AST < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (ALPHA_AST > 0.0);
    }

    b_MUY_0 = -(std::sin(std::atan(KYALPHA - ((b_MUY_tmp *
      Tire_Model_Codegen_DW.PEY5 + 1.0) - (Tire_Model_Codegen_DW.PEY4 *
      GAMMA_AST_tmp + Tire_Model_Codegen_DW.PEY3) * tmp) *
      (Tire_Model_Codegen_DW.PEY2 * DFZ_tmp + Tire_Model_Codegen_DW.PEY1) *
      Tire_Model_Codegen_DW.LEY * (KYALPHA - std::atan(KYALPHA))) * CY) *
                b_MUY_0 + ((Tire_Model_Codegen_DW.PVY2 * DFZ_tmp +
      Tire_Model_Codegen_DW.PVY1) * FZ_tmp * Tire_Model_Codegen_DW.LVY *
      Tire_Model_Codegen_DW.LMUYPRIME * Tire_Model_Codegen_DW.ZETA2 + SVYGAMMA));
    if (ALPHA == 0.0) {
      b_MUY_0 = 0.0;
    }

    b_MUY[i] = -b_MUY_0;
    ALPHA = INPUT[i];
    SVYGAMMA = R_d * DFZ_tmp + R_c;
    ALPHA_AST = std::abs((b_MUY_tmp * R_5 + R_4) * std::cos(std::atan
      ((ALPHA_AST_tmp - R_3) * R_2)) * Tire_Model_Codegen_DW.LYKAPPA);
    SHYKAPPA_0 = R_f * DFZ_tmp + R_e;
    KYALPHA = ALPHA_AST * SHYKAPPA_0;
    ALPHA_AST *= ALPHA + SHYKAPPA_0;
    FZ_tmp = ((R_9 * DFZ_tmp + R_8) + R_a * GAMMA_AST_tmp) * (std::abs
      (b_MUY_tmp_0 * Tire_Model_Codegen_DW.LMUYPRIME) * FZ_tmp) * std::cos(std::
      atan(R_b * ALPHA_AST_tmp)) * Tire_Model_Codegen_DW.ZETA2 * std::sin(std::
      atan(R_0 * ALPHA) * R_1) * Tire_Model_Codegen_DW.LVYKAPPA + std::abs(std::
      cos(std::atan(ALPHA_AST - (ALPHA_AST - std::atan(ALPHA_AST)) * SVYGAMMA) *
          R_7) / std::cos(std::atan(KYALPHA - (KYALPHA - std::atan(KYALPHA)) *
      SVYGAMMA) * R_6)) * -b_MUY_0;
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

// Function for MATLAB Function: '<Root>/MATLAB Function'
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

// Function for MATLAB Function: '<Root>/MATLAB Function'
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

// Function for MATLAB Function: '<Root>/MATLAB Function'
void Tire_Model_Codegen::Tire_Model_Codegen_Pacejka52_COMBINED_FX(const real_T
  R[7], const real_T INPUT[400], const real_T *FZO, const real_T *LFZO, const
  real_T *LMUX, const real_T *LKXKAPPA, real_T FX[100]) const
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
  b_FZOPRIME_tmp = *FZO * *LFZO;
  CX = Tire_Model_Codegen_DW.PCX1 * Tire_Model_Codegen_DW.LCX;
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
    KAPPAX = (Tire_Model_Codegen_DW.PHX2 * DFZ_tmp + Tire_Model_Codegen_DW.PHX1)
      * Tire_Model_Codegen_DW.LHX + INPUT_0;
    DX_tmp = GAMMA_AST_tmp * GAMMA_AST_tmp;
    GAMMA_AST_tmp = (1.0 - DX_tmp * Tire_Model_Codegen_DW.PDX3) *
      (Tire_Model_Codegen_DW.PDX2 * DFZ_tmp + Tire_Model_Codegen_DW.PDX1) *
      *LMUX * FZ * Tire_Model_Codegen_DW.ZETA1;
    x = (Tire_Model_Codegen_DW.PKX2 * DFZ_tmp + Tire_Model_Codegen_DW.PKX1) * FZ
      * std::exp(Tire_Model_Codegen_DW.PKX3 * DFZ_tmp) * *LKXKAPPA / (CX *
      GAMMA_AST_tmp + Tire_Model_Codegen_DW.EPSILON) * KAPPAX;
    if (std::isnan(KAPPAX)) {
      KAPPAX = (rtNaN);
    } else if (KAPPAX < 0.0) {
      KAPPAX = -1.0;
    } else {
      KAPPAX = (KAPPAX > 0.0);
    }

    GAMMA_AST_tmp = std::sin(std::atan(x - ((Tire_Model_Codegen_DW.PEX2 *
      DFZ_tmp + Tire_Model_Codegen_DW.PEX1) + DFZ_tmp * DFZ_tmp *
      Tire_Model_Codegen_DW.PEX3) * (1.0 - Tire_Model_Codegen_DW.PEX4 * KAPPAX) *
      Tire_Model_Codegen_DW.LEX * (x - std::atan(x))) * CX) * GAMMA_AST_tmp +
      (Tire_Model_Codegen_DW.PVX2 * DFZ_tmp + Tire_Model_Codegen_DW.PVX1) * FZ *
      Tire_Model_Codegen_DW.LVX * Tire_Model_Codegen_DW.LMUXPRIME *
      Tire_Model_Codegen_DW.ZETA1;
    DX[i] = GAMMA_AST_tmp;
    if (INPUT_0 == 0.0) {
      GAMMA_AST_tmp = 0.0;
      DX[i] = 0.0;
    }

    FZ = DFZ_tmp * R_1 + R_0;
    INPUT_0 = std::abs((DX_tmp * R_4 + R_3) * std::cos(std::atan(R_2 * INPUT_0))
                       * Tire_Model_Codegen_DW.LXALPHA);
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

// Function for MATLAB Function: '<Root>/MATLAB Function'
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

// Model step function
void Tire_Model_Codegen::step()
{
  real_T maxFX_INPUT[400];
  real_T FZrange_tmp[100];
  real_T FxEnvelope[100];
  real_T x_0[100];
  real_T INPUT[4];
  real_T MZ_INPUT[4];
  real_T x[3];
  real_T y[3];
  real_T BXALPHA;
  real_T FXO;
  real_T FZOPRIME;
  real_T a;
  int32_T n;
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

  __m128d tmp_0;
  real_T tmp[15];
  real_T FZO;
  real_T LFZO;
  real_T LKXKAPPA;
  real_T LMUX;
  real_T RO;
  real_T VCX;
  real_T rtb_Abs;
  real_T rtb_Switch4;
  boolean_T b_INPUT_tmp;
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

  // Abs: '<Root>/Abs' incorporates:
  //   Inport: '<Root>/LC Raw'

  rtb_Abs = std::abs(Tire_Model_Codegen_U.LCRaw);

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/Interp_x1'
  //   Inport: '<Root>/Interp_x2'
  //   Inport: '<Root>/Interp_x3'
  //   Inport: '<Root>/interp_y1'
  //   Inport: '<Root>/interp_y2'
  //   Inport: '<Root>/interp_y3'

  x[0] = Tire_Model_Codegen_U.Interp_x1;
  y[0] = Tire_Model_Codegen_U.interp_y1;
  x[1] = Tire_Model_Codegen_U.Interp_x2;
  y[1] = Tire_Model_Codegen_U.interp_y2;
  x[2] = Tire_Model_Codegen_U.Interp_x3;
  y[2] = Tire_Model_Codegen_U.interp_y3;
  if (Tire_Model_Codegen_U.Interp_x2 < Tire_Model_Codegen_U.Interp_x1) {
    x[0] = Tire_Model_Codegen_U.Interp_x3;
    x[2] = Tire_Model_Codegen_U.Interp_x1;
    y[0] = Tire_Model_Codegen_U.interp_y3;
    y[2] = Tire_Model_Codegen_U.interp_y1;
  }

  if (std::isnan(rtb_Abs)) {
    rtb_Abs = (rtNaN);
  } else if (rtb_Abs > x[2]) {
    rtb_Abs = (rtb_Abs - x[2]) / (x[2] - Tire_Model_Codegen_U.Interp_x2) * (y[2]
      - Tire_Model_Codegen_U.interp_y2) + y[2];
  } else if (rtb_Abs < x[0]) {
    rtb_Abs = (rtb_Abs - x[0]) / (Tire_Model_Codegen_U.Interp_x2 - x[0]) *
      (Tire_Model_Codegen_U.interp_y2 - y[0]) + y[0];
  } else {
    n = 0;
    if (rtb_Abs >= Tire_Model_Codegen_U.Interp_x2) {
      n = 1;
    }

    rtb_Abs = (rtb_Abs - x[n]) / (x[n + 1] - x[n]);
    if (rtb_Abs == 0.0) {
      rtb_Abs = y[n];
    } else if (rtb_Abs == 1.0) {
      rtb_Abs = y[n + 1];
    } else {
      VCX = y[n + 1];
      if (VCX == y[n]) {
        rtb_Abs = y[n];
      } else {
        rtb_Abs = (1.0 - rtb_Abs) * y[n] + VCX * rtb_Abs;
      }
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // Outport: '<Root>/FZ [N]' incorporates:
  //   Gain: '<Root>/Gain'

  Tire_Model_Codegen_Y.FZN = -rtb_Abs;

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant10'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'
  //   Inport: '<Root>/SA SAE'
  //   Outport: '<Root>/FZ [N]'

  rtb_Switch4 = Tire_Model_Codegen_U.SASAE;
  FZO = 1100.0;
  RO = 0.2032;
  VCX = 10.0;
  LFZO = 1.0;
  LMUX = 1.0;
  LKXKAPPA = 1.0;
  Tire_Model_Codegen_DW.LKYALPHA = 1.0;
  Tire_Model_Codegen_DW.LCX = 1.0;
  Tire_Model_Codegen_DW.LCY = 1.0;
  Tire_Model_Codegen_DW.LEX = 1.0;
  Tire_Model_Codegen_DW.LEY = 1.0;
  Tire_Model_Codegen_DW.LHX = 1.0;
  Tire_Model_Codegen_DW.LHY = 1.0;
  Tire_Model_Codegen_DW.LVX = 1.0;
  Tire_Model_Codegen_DW.LVY = 1.0;
  Tire_Model_Codegen_DW.LKYGAMMA = 1.0;
  Tire_Model_Codegen_DW.LKZGAMMA = 1.0;
  Tire_Model_Codegen_DW.LT = 1.0;
  Tire_Model_Codegen_DW.LMR = 1.0;
  Tire_Model_Codegen_DW.LXALPHA = 1.0;
  Tire_Model_Codegen_DW.LYKAPPA = 1.0;
  Tire_Model_Codegen_DW.LVYKAPPA = 1.0;
  Tire_Model_Codegen_DW.LS = 1.0;
  Tire_Model_Codegen_DW.LMUYAST = 1.0;
  Tire_Model_Codegen_DW.LMUYPRIME = 1.0;
  Tire_Model_Codegen_DW.LMUXPRIME = 1.0;
  Tire_Model_Codegen_DW.ZETA0 = 1.0;
  Tire_Model_Codegen_DW.ZETA1 = 1.0;
  Tire_Model_Codegen_DW.ZETA2 = 1.0;
  Tire_Model_Codegen_DW.ZETA3 = 1.0;
  Tire_Model_Codegen_DW.ZETA4 = 1.0;
  Tire_Model_Codegen_DW.ZETA5 = 1.0;
  Tire_Model_Codegen_DW.ZETA6 = 1.0;
  Tire_Model_Codegen_DW.ZETA7 = 1.0;
  Tire_Model_Codegen_DW.ZETA8 = 1.0;
  Tire_Model_Codegen_DW.EPSILON = 0.0;
  Tire_Model_Codegen_DW.PCY1 = 1.2313596424808264;
  Tire_Model_Codegen_DW.PDY1 = -2.6218419146715011;
  Tire_Model_Codegen_DW.PDY2 = 0.49408874960332233;
  Tire_Model_Codegen_DW.PDY3 = -0.11562925978358389;
  Tire_Model_Codegen_DW.PEY1 = -0.00020039977873071517;
  Tire_Model_Codegen_DW.PEY2 = -6.1624811679236686E-5;
  Tire_Model_Codegen_DW.PEY3 = -6462.4579045933542;
  Tire_Model_Codegen_DW.PEY4 = -8275.5305117925272;
  Tire_Model_Codegen_DW.PEY5 = -183377.60377369338;
  Tire_Model_Codegen_DW.PKY1 = -7315.6447735127331;
  Tire_Model_Codegen_DW.PKY2 = 0.42782363781656935;
  Tire_Model_Codegen_DW.PKY3 = -13.929724953423026;
  Tire_Model_Codegen_DW.PKY4 = 0.0033491621141695819;
  Tire_Model_Codegen_DW.PKY5 = 32.474941895851266;
  Tire_Model_Codegen_DW.PKY6 = -5.3924206132297385;
  Tire_Model_Codegen_DW.PKY7 = -1.1437118392148171;
  Tire_Model_Codegen_DW.PHY1 = 0.013038327933469776;
  Tire_Model_Codegen_DW.PHY2 = 0.011296068799727077;
  Tire_Model_Codegen_DW.PVY1 = 0.39276810893419961;
  Tire_Model_Codegen_DW.PVY2 = 0.11759126372372954;
  Tire_Model_Codegen_DW.PVY3 = 2.4196438576260042;
  Tire_Model_Codegen_DW.PVY4 = -2.2799338208165532;
  Tire_Model_Codegen_DW.QBZ1 = 4.9526422636959877;
  Tire_Model_Codegen_DW.QBZ2 = -7.2422862784529825;
  Tire_Model_Codegen_DW.QBZ3 = -10.433971205664054;
  Tire_Model_Codegen_DW.QBZ5 = 0.77944191839338994;
  Tire_Model_Codegen_DW.QBZ6 = -9.71479041489902;
  Tire_Model_Codegen_DW.QBZ9 = -2.989328033231569;
  Tire_Model_Codegen_DW.QBZ10 = -2.2553054654455269;
  Tire_Model_Codegen_DW.QCZ1 = 1.9026761440857638;
  Tire_Model_Codegen_DW.QDZ1 = 0.23113387578400904;
  Tire_Model_Codegen_DW.QDZ2 = -0.20543034094838589;
  Tire_Model_Codegen_DW.QDZ3 = 0.55581015300396353;
  Tire_Model_Codegen_DW.QDZ4 = -18.186230455018009;
  Tire_Model_Codegen_DW.QDZ6 = 0.013834236558124526;
  Tire_Model_Codegen_DW.QDZ7 = -0.0034629288702784995;
  Tire_Model_Codegen_DW.QDZ8 = -3.6810885235768844;
  Tire_Model_Codegen_DW.QDZ9 = 0.27684422041191259;
  Tire_Model_Codegen_DW.QDZ10 = 9.0142454275334973;
  Tire_Model_Codegen_DW.QDZ11 = -19.441653240509762;
  Tire_Model_Codegen_DW.QEZ1 = 0.23508992687673802;
  Tire_Model_Codegen_DW.QEZ2 = -3.3749765671914345;
  Tire_Model_Codegen_DW.QEZ3 = -6.1406524270110854;
  Tire_Model_Codegen_DW.QEZ4 = 0.021651480299257862;
  Tire_Model_Codegen_DW.QEZ5 = -1.4372940653303785;
  Tire_Model_Codegen_DW.QHZ1 = 0.0015200989869332228;
  Tire_Model_Codegen_DW.QHZ2 = 0.0025005904446104409;
  Tire_Model_Codegen_DW.QHZ3 = -0.19487232420426584;
  Tire_Model_Codegen_DW.QHZ4 = -0.36178954227207794;
  Tire_Model_Codegen_DW.PCX1 = 1.2034887637986136;
  Tire_Model_Codegen_DW.PDX1 = 3.2231064881613674;
  Tire_Model_Codegen_DW.PDX2 = -1.4293771989131587;
  Tire_Model_Codegen_DW.PDX3 = 19.159268279790737;
  Tire_Model_Codegen_DW.PEX1 = 0.1940276390791833;
  Tire_Model_Codegen_DW.PEX2 = -3.1562992390056057;
  Tire_Model_Codegen_DW.PEX3 = -3.6719183871745229;
  Tire_Model_Codegen_DW.PEX4 = 0.12250922922693948;
  Tire_Model_Codegen_DW.PKX1 = 51.782867956170833;
  Tire_Model_Codegen_DW.PKX2 = -0.016339727620495743;
  Tire_Model_Codegen_DW.PKX3 = -0.67948719519730594;
  Tire_Model_Codegen_DW.PHX1 = 0.0013277631420764162;
  Tire_Model_Codegen_DW.PHX2 = -0.00023916516076804978;
  Tire_Model_Codegen_DW.PVX1 = -0.0933355519695686;
  Tire_Model_Codegen_DW.PVX2 = 0.057220635815684533;
  Tire_Model_Codegen_DW.RBX1 = 0.1847722351557832;
  Tire_Model_Codegen_DW.RBX2 = 1.0686028080704413;
  Tire_Model_Codegen_DW.RBX3 = 0.092442780323963469;
  Tire_Model_Codegen_DW.RCX1 = 48.050559189883764;
  Tire_Model_Codegen_DW.REX1 = 378.6317374571675;
  Tire_Model_Codegen_DW.REX2 = -451.58083629101958;
  Tire_Model_Codegen_DW.RHX1 = -1.4338511440035567E-6;
  Tire_Model_Codegen_DW.RBY1 = 1260.0102414255728;
  Tire_Model_Codegen_DW.RBY2 = 73.133743850153778;
  Tire_Model_Codegen_DW.RBY3 = -0.8434204280635893;
  Tire_Model_Codegen_DW.RBY4 = -11015.214396340958;
  Tire_Model_Codegen_DW.RCY1 = -0.821649935696013;
  Tire_Model_Codegen_DW.REY1 = -0.70411999544448289;
  Tire_Model_Codegen_DW.REY2 = -1.5230000008611388;
  Tire_Model_Codegen_DW.RHY1 = 0.018803505998137737;
  Tire_Model_Codegen_DW.RHY2 = 0.032224920705998458;
  Tire_Model_Codegen_DW.RVY1 = -0.028170004305692924;
  Tire_Model_Codegen_DW.RVY2 = -0.052746999557708542;
  Tire_Model_Codegen_DW.RVY3 = -0.12522000044206391;
  Tire_Model_Codegen_DW.RVY4 = 304.85650116575681;
  Tire_Model_Codegen_DW.RVY5 = 2.9901000013571277;
  Tire_Model_Codegen_DW.RVY6 = -10.651899999870379;
  if (std::isnan(Tire_Model_Codegen_U.SASAE)) {
    rtb_Switch4 = 0.0;
  }

  INPUT[0] = Tire_Model_Codegen_U.SLSAE;
  INPUT[1] = rtb_Switch4;
  INPUT[2] = -Tire_Model_Codegen_Y.FZN;
  INPUT[3] = Tire_Model_Codegen_U.IASAE;
  rtb_Abs = std::abs(rtb_Switch4);
  if (std::isnan(rtb_Switch4)) {
    BXALPHA = (rtNaN);
  } else if (rtb_Switch4 < 0.0) {
    BXALPHA = -1.0;
  } else {
    BXALPHA = (rtb_Switch4 > 0.0);
  }

  b_INPUT_tmp = (rtb_Abs >= 6.0);
  MZ_INPUT[1] = rtb_Switch4;
  MZ_INPUT[2] = -Tire_Model_Codegen_Y.FZN;
  MZ_INPUT[3] = Tire_Model_Codegen_U.IASAE;
  MZ_INPUT[0] = 0.0;
  if (rtb_Abs >= 10.0) {
    MZ_INPUT[1] = 10.0 * BXALPHA;
  }

  if (std::abs(Tire_Model_Codegen_Y.FZN) >= 1600.0) {
    MZ_INPUT[2] = -1600.0;
  }

  rtb_Abs = Tire_Model_Codegen_Pacejka52_COMBINED_FY
    (Tire_Model_Codegen_ConstP.Constant9_Value, INPUT, &FZO, &LFZO);
  tmp[0] = 1.2034887637986136;
  tmp[1] = 3.2231064881613674;
  tmp[2] = -1.4293771989131587;
  tmp[3] = 19.159268279790737;
  tmp[4] = 0.1940276390791833;
  tmp[5] = -3.1562992390056057;
  tmp[6] = -3.6719183871745229;
  tmp[7] = 0.12250922922693948;
  tmp[8] = 51.782867956170833;
  tmp[9] = -0.016339727620495743;
  tmp[10] = -0.67948719519730594;
  tmp[11] = 0.0013277631420764162;
  tmp[12] = -0.00023916516076804978;
  tmp[13] = -0.0933355519695686;
  tmp[14] = 0.057220635815684533;
  x[0] = Tire_Model_Codegen_U.SLSAE;
  x[1] = -Tire_Model_Codegen_Y.FZN;
  x[2] = Tire_Model_Codegen_U.IASAE;
  FXO = Tire_Model_Codegen_Pacejka52_PLS_FX(tmp, x, &FZO, &LFZO, &LMUX,
    &LKXKAPPA);
  a = std::sin(0.017453292519943295 * Tire_Model_Codegen_U.IASAE);
  FZOPRIME = (std::abs(-Tire_Model_Codegen_Y.FZN) - 1100.0) / 1100.0 *
    -451.58083629101958 + 378.6317374571675;
  if (b_INPUT_tmp) {
    rtb_Switch4 = 6.0 * BXALPHA;
  }

  BXALPHA = std::abs((a * a * 0.092442780323963469 + 0.1847722351557832) * std::
                     cos(std::atan(1.0686028080704413 *
    Tire_Model_Codegen_U.SLSAE)));
  rtb_Switch4 = (std::tan(-(0.017453292519943295 * rtb_Switch4)) -
                 1.4338511440035567E-6) * BXALPHA;
  rtb_Switch4 = std::abs(std::cos(std::atan(rtb_Switch4 - (rtb_Switch4 - std::
    atan(rtb_Switch4)) * FZOPRIME) * 48.050559189883764) / std::cos(std::atan
    (BXALPHA * -1.4338511440035567E-6 - (BXALPHA * -1.4338511440035567E-6 - std::
    atan(BXALPHA * -1.4338511440035567E-6)) * FZOPRIME) * 48.050559189883764)) *
    FXO;
  if (std::abs(rtb_Switch4) > std::abs(FXO)) {
    rtb_Switch4 = FXO;
  }

  RO = Tire_Model_Codegen_Pacejka52_COMBINED_MZ
    (Tire_Model_Codegen_ConstP.Constant10_Value, MZ_INPUT, &FZO, &RO, &VCX,
     &LFZO, &LMUX, &LKXKAPPA);
  Tire_Model_Codegen_repelem(-Tire_Model_Codegen_Y.FZN, FZrange_tmp);
  for (n = 0; n < 100; n++) {
    maxFX_INPUT[n] = 0.0;
    maxFX_INPUT[n + 100] = b[n];
    maxFX_INPUT[n + 200] = FZrange_tmp[n];
    maxFX_INPUT[n + 300] = 0.0;
  }

  Tire_Model_Codegen_Pacejka52_COMBINED_FY_m
    (Tire_Model_Codegen_ConstP.Constant9_Value, maxFX_INPUT, &FZO, &LFZO, x_0);
  for (n = 0; n < 100; n++) {
    FxEnvelope[n] = std::abs(x_0[n]);
  }

  FXO = Tire_Model_Codegen_maximum(FxEnvelope);
  if (Tire_Model_Codegen_Y.FZN == 0.0) {
    rtb_Abs = 0.0;
    rtb_Switch4 = 0.0;
    RO = 0.0;
    FXO = 1.0;
  }

  VCX = std::abs(rtb_Abs);
  if (VCX > 0.0) {
    for (n = 0; n <= 98; n += 2) {
      tmp_0 = _mm_set1_pd(FXO);
      _mm_storeu_pd(&FxEnvelope[n], _mm_mul_pd(_mm_loadu_pd(&c_a[n]), tmp_0));
      _mm_storeu_pd(&x_0[n], _mm_mul_pd(_mm_loadu_pd(&b_a[n]), tmp_0));
    }

    FXO = Tire_Model_Codegen_interp1(FxEnvelope, x_0, VCX);
  } else {
    for (n = 0; n <= 98; n += 2) {
      _mm_storeu_pd(&x_0[n], _mm_mul_pd(_mm_loadu_pd(&b_a[n]), _mm_set1_pd(FXO)));
    }

    FXO = Tire_Model_Codegen_maximum(x_0);
  }

  if (std::abs(rtb_Switch4) > FXO) {
    if (std::isnan(rtb_Switch4)) {
      VCX = (rtNaN);
    } else if (rtb_Switch4 < 0.0) {
      VCX = -1.0;
    } else {
      VCX = (rtb_Switch4 > 0.0);
    }

    rtb_Switch4 = FXO * VCX;
  }

  for (n = 0; n < 100; n++) {
    maxFX_INPUT[n] = c[n];
    maxFX_INPUT[n + 100] = 0.0;
    maxFX_INPUT[n + 200] = FZrange_tmp[n];
    maxFX_INPUT[n + 300] = 0.0;
  }

  Tire_Model_Codegen_Pacejka52_COMBINED_FX
    (Tire_Model_Codegen_ConstP.Constant8_Value, maxFX_INPUT, &FZO, &LFZO, &LMUX,
     &LKXKAPPA, x_0);
  Tire_Model_Codegen_Pacejka52_COMBINED_FX
    (Tire_Model_Codegen_ConstP.Constant8_Value, maxFX_INPUT, &FZO, &LFZO, &LMUX,
     &LKXKAPPA, FxEnvelope);

  // Switch: '<Root>/Switch3' incorporates:
  //   Constant: '<Root>/Constant15'

  if (Tire_Model_Codegen_U.SLSAE != 0.0) {
    // Abs: '<S4>/Abs1'
    FZO = std::abs(Tire_Model_Codegen_U.SLSAE);

    // Switch: '<S4>/Switch1' incorporates:
    //   MATLAB Function: '<Root>/MATLAB Function'
    //   Polyval: '<S4>/Polynomial'
    //   Product: '<S4>/Product1'

    if (FZO >= 0.2) {
      rtb_Switch4 *= ((3.3028912605643311E-15 * FZO - 6.8204108340895218E-15) *
                      FZO + 4.3720979729643442E-15) * FZO + 0.99999999999999922;
    }

    // End of Switch: '<S4>/Switch1'
  } else {
    rtb_Switch4 = 0.0;
  }

  // End of Switch: '<Root>/Switch3'

  // Outport: '<Root>/FX FLU' incorporates:
  //   Inport: '<Root>/LMUX'
  //   Product: '<Root>/Product'

  Tire_Model_Codegen_Y.FXFLU = rtb_Switch4 * Tire_Model_Codegen_U.LMUX;

  // Switch: '<Root>/Switch4' incorporates:
  //   Constant: '<Root>/Constant12'
  //   Inport: '<Root>/SA SAE'
  //   Switch: '<Root>/Switch5'

  if (Tire_Model_Codegen_U.SASAE != 0.0) {
    // Abs: '<S3>/Abs1'
    FZO = std::abs(Tire_Model_Codegen_U.SASAE);

    // Switch: '<S3>/Switch1' incorporates:
    //   Gain: '<Root>/Gain3'
    //   MATLAB Function: '<Root>/MATLAB Function'
    //   Polyval: '<S3>/Polynomial'
    //   Product: '<S3>/Product1'

    if (FZO >= 10.0) {
      rtb_Switch4 = (-0.0 * FZO * FZO + 1.0) * -rtb_Abs;
    } else {
      rtb_Switch4 = -rtb_Abs;
    }

    // End of Switch: '<S3>/Switch1'

    // Outport: '<Root>/MZ FLU' incorporates:
    //   Gain: '<Root>/Gain4'

    Tire_Model_Codegen_Y.MZFLU = -RO;
  } else {
    rtb_Switch4 = 0.0;

    // Outport: '<Root>/MZ FLU' incorporates:
    //   Constant: '<Root>/Constant12'
    //   Constant: '<Root>/Constant13'

    Tire_Model_Codegen_Y.MZFLU = 0.0;
  }

  // End of Switch: '<Root>/Switch4'

  // Outport: '<Root>/FY FLU' incorporates:
  //   Inport: '<Root>/LMUY'
  //   Product: '<Root>/Product1'

  Tire_Model_Codegen_Y.FYFLU = rtb_Switch4 * Tire_Model_Codegen_U.LMUY;

  // Outport: '<Root>/Brake Torque Saturation' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/LMUX'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   Product: '<Root>/Product3'

  Tire_Model_Codegen_Y.BrakeTorqueSaturation = Tire_Model_Codegen_minimum
    (FxEnvelope) * 0.2 / 11.86 * 0.6 * Tire_Model_Codegen_U.LMUX;

  // Outport: '<Root>/Acceleration Torque Saturation' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/LMUX'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   Product: '<Root>/Product2'

  Tire_Model_Codegen_Y.AccelerationTorqueSaturation = Tire_Model_Codegen_maximum
    (x_0) * 0.2 / 11.86 * 0.6 * Tire_Model_Codegen_U.LMUX;
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
