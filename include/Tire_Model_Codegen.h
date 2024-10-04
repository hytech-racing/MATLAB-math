//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Tire_Model_Codegen.h
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
#ifndef Tire_Model_Codegen_h_
#define Tire_Model_Codegen_h_
#include <cmath>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "Tire_Model_Codegen_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

// Class declaration for model Tire_Model_Codegen
class Tire_Model_Codegen final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_Tire_Model_Codegen_T {
    real_T LCZ;                        // synthesized block
    real_T LMY;                        // synthesized block
    real_T QX1;                        // synthesized block
    real_T QX2;                        // synthesized block
    real_T QX3;                        // synthesized block
    real_T QX4;                        // synthesized block
    real_T QX5;                        // synthesized block
    real_T QX6;                        // synthesized block
  };

  // Constant parameters (default storage)
  struct ConstP_Tire_Model_Codegen_T {
    // Pooled Parameter (Expression: tireCoeffs.G)
    //  Referenced by:
    //    '<S17>/Constant10'
    //    '<S18>/Constant10'
    //    '<S19>/Constant10'
    //    '<S20>/Constant10'

    real_T pooled9[4];

    // Pooled Parameter (Expression: LAMBDA)
    //  Referenced by:
    //    '<S17>/Constant3'
    //    '<S18>/Constant3'
    //    '<S19>/Constant3'
    //    '<S20>/Constant3'

    real_T pooled10[37];

    // Pooled Parameter (Expression: tireCoeffs.A)
    //  Referenced by:
    //    '<S17>/Constant4'
    //    '<S18>/Constant4'
    //    '<S19>/Constant4'
    //    '<S20>/Constant4'

    real_T pooled11[22];

    // Pooled Parameter (Expression: tireCoeffs.B)
    //  Referenced by:
    //    '<S17>/Constant5'
    //    '<S18>/Constant5'
    //    '<S19>/Constant5'
    //    '<S20>/Constant5'

    real_T pooled12[27];

    // Pooled Parameter (Expression: tireCoeffs.C)
    //  Referenced by:
    //    '<S17>/Constant6'
    //    '<S18>/Constant6'
    //    '<S19>/Constant6'
    //    '<S20>/Constant6'

    real_T pooled13[3];

    // Pooled Parameter (Expression: tireCoeffs.D)
    //  Referenced by:
    //    '<S17>/Constant7'
    //    '<S18>/Constant7'
    //    '<S19>/Constant7'
    //    '<S20>/Constant7'

    real_T pooled14[15];

    // Pooled Parameter (Expression: tireCoeffs.E)
    //  Referenced by:
    //    '<S17>/Constant8'
    //    '<S18>/Constant8'
    //    '<S19>/Constant8'
    //    '<S20>/Constant8'

    real_T pooled15[7];

    // Pooled Parameter (Expression: tireCoeffs.F)
    //  Referenced by:
    //    '<S17>/Constant9'
    //    '<S18>/Constant9'
    //    '<S19>/Constant9'
    //    '<S20>/Constant9'

    real_T pooled16[15];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Tire_Model_Codegen_T {
    real_T InitialTorqReqFL;           // '<Root>/Initial Torq Req FL'
    real_T InitialTorqReqFR;           // '<Root>/Initial Torq Req FR'
    real_T InitialTorqReqRL;           // '<Root>/Initial Torq Req RL'
    real_T InitialTorqReqRR;           // '<Root>/Initial Torq Req RR'
    real_T FL;                         // '<Root>/SL FL'
    real_T FR;                         // '<Root>/SL FR'
    real_T RL;                         // '<Root>/SL RL'
    real_T RR;                         // '<Root>/SL RR'
    real_T FL_b;                       // '<Root>/SA FL'
    real_T FR_b;                       // '<Root>/SA FR'
    real_T RL_g;                       // '<Root>/SA RL'
    real_T RR_a;                       // '<Root>/SA RR'
    real_T LMUXFL;                     // '<Root>/LMUX FL'
    real_T LMUXFR;                     // '<Root>/LMUX FR'
    real_T LMUXRL;                     // '<Root>/LMUX RL'
    real_T LMUXRR;                     // '<Root>/LMUX RR'
    real_T LMUYFL;                     // '<Root>/LMUY FL'
    real_T LMUYFR;                     // '<Root>/LMUY FR'
    real_T LMUYRL;                     // '<Root>/LMUY RL'
    real_T LMUYRR;                     // '<Root>/LMUY RR'
    real_T LCFL;                       // '<Root>/LC FL'
    real_T LCFR;                       // '<Root>/LC FR'
    real_T LCRL;                       // '<Root>/LC RL'
    real_T LCRR;                       // '<Root>/LC RR'
    real_T MotorRPMFL;                 // '<Root>/Motor RPM FL'
    real_T MotorRPMFR;                 // '<Root>/Motor RPM FR'
    real_T MotorRPMRL;                 // '<Root>/Motor RPM RL'
    real_T MotorRPMRR;                 // '<Root>/Motor RPM RR'
    real_T Interp_x1_FL;               // '<Root>/Interp_x1_FL'
    real_T Interp_x2_FL;               // '<Root>/Interp_x2_FL'
    real_T Interp_x3_FL;               // '<Root>/Interp_x3_FL'
    real_T interp_y1_FL;               // '<Root>/interp_y1_FL'
    real_T interp_y2_FL;               // '<Root>/interp_y2_FL'
    real_T interp_y3_FL;               // '<Root>/interp_y3_FL'
    real_T Interp_x1_FR;               // '<Root>/Interp_x1_FR'
    real_T Interp_x2_FR;               // '<Root>/Interp_x2_FR'
    real_T Interp_x3_FR;               // '<Root>/Interp_x3_FR'
    real_T interp_y1_FR;               // '<Root>/interp_y1_FR'
    real_T interp_y2_FR;               // '<Root>/interp_y2_FR'
    real_T interp_y3_FR;               // '<Root>/interp_y3_FR'
    real_T Interp_x1_RL;               // '<Root>/Interp_x1_RL'
    real_T Interp_x2_RL;               // '<Root>/Interp_x2_RL'
    real_T Interp_x3_RL;               // '<Root>/Interp_x3_RL'
    real_T interp_y1_RL;               // '<Root>/interp_y1_RL'
    real_T interp_y2_RL;               // '<Root>/interp_y2_RL'
    real_T interp_y3_RL;               // '<Root>/interp_y3_RL'
    real_T Interp_x1_RR;               // '<Root>/Interp_x1_RR'
    real_T Interp_x2_RR;               // '<Root>/Interp_x2_RR'
    real_T Interp_x3_RR;               // '<Root>/Interp_x3_RR'
    real_T interp_y1_RR;               // '<Root>/interp_y1_RR'
    real_T interp_y2_RR;               // '<Root>/interp_y2_RR'
    real_T interp_y3_RR;               // '<Root>/interp_y3_RR'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Tire_Model_Codegen_T {
    real_T FXFL;                       // '<Root>/FX FL'
    real_T FXFR;                       // '<Root>/FX FR'
    real_T FXRL;                       // '<Root>/FX RL'
    real_T FXRR;                       // '<Root>/FX RR'
    real_T FYFL;                       // '<Root>/FY FL'
    real_T FYFR;                       // '<Root>/FY FR'
    real_T FYRL;                       // '<Root>/FY RL'
    real_T FYRR;                       // '<Root>/FY RR'
    real_T FZFL;                       // '<Root>/FZ FL'
    real_T FZFR;                       // '<Root>/FZ FR'
    real_T FZRL;                       // '<Root>/FZ RL'
    real_T FZRR;                       // '<Root>/FZ RR'
    real_T MZFL;                       // '<Root>/MZ FL'
    real_T MZFR;                       // '<Root>/MZ FR'
    real_T MZRL;                       // '<Root>/MZ RL'
    real_T MZRR;                       // '<Root>/MZ RR'
    real_T satAccelTFL;                // '<Root>/satAccelT FL'
    real_T satAccelTFR;                // '<Root>/satAccelT FR'
    real_T satAccelTRL;                // '<Root>/satAccelT RL'
    real_T satAccelTRR;                // '<Root>/satAccelT RR'
    real_T satBrakeTFL;                // '<Root>/satBrakeT FL'
    real_T satBrakeTFR;                // '<Root>/satBrakeT FR'
    real_T satBrakeTRL;                // '<Root>/satBrakeT RL'
    real_T satBrakeTRR;                // '<Root>/satBrakeT RR'
    real_T torq_req_FL;                // '<Root>/torq_req_FL'
    real_T torq_req_FR;                // '<Root>/torq_req_FR'
    real_T torq_req_RL;                // '<Root>/torq_req_RL'
    real_T torq_req_RR;                // '<Root>/torq_req_RR'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Tire_Model_Codegen_T {
    const char_T * volatile errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Copy Constructor
  Tire_Model_Codegen(Tire_Model_Codegen const&) = delete;

  // Assignment Operator
  Tire_Model_Codegen& operator= (Tire_Model_Codegen const&) & = delete;

  // Move Constructor
  Tire_Model_Codegen(Tire_Model_Codegen &&) = delete;

  // Move Assignment Operator
  Tire_Model_Codegen& operator= (Tire_Model_Codegen &&) = delete;

  // Real-Time Model get method
  Tire_Model_Codegen::RT_MODEL_Tire_Model_Codegen_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_Tire_Model_Codegen_T
    *pExtU_Tire_Model_Codegen_T)
  {
    Tire_Model_Codegen_U = *pExtU_Tire_Model_Codegen_T;
  }

  // Root outports get method
  const ExtY_Tire_Model_Codegen_T &getExternalOutputs() const
  {
    return Tire_Model_Codegen_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  Tire_Model_Codegen();

  // Destructor
  ~Tire_Model_Codegen();

  // private data and function members
 private:
  // External inputs
  ExtU_Tire_Model_Codegen_T Tire_Model_Codegen_U;

  // External outputs
  ExtY_Tire_Model_Codegen_T Tire_Model_Codegen_Y;

  // Block states
  DW_Tire_Model_Codegen_T Tire_Model_Codegen_DW;

  // private member function(s) for subsystem '<S1>/MATLAB Function1'
  static void Tire_Model_Codegen_MATLABFunction1(real_T rtu_LC_Raw, real_T
    rtu_interp_X, real_T rtu_interp_X_m, real_T rtu_interp_X_b, real_T
    rtu_interp_Y, real_T rtu_interp_Y_o, real_T rtu_interp_Y_a, real_T *rty_FZ);

  // private member function(s) for subsystem '<S17>/MATLAB Function'
  void Tire_Model_Codegen_MATLABFunction(const real_T rtu_LAMBDA[37], const
    real_T rtu_A[22], const real_T rtu_B[27], const real_T rtu_C[3], const
    real_T rtu_D[15], const real_T rtu_E[7], const real_T rtu_F[15], const
    real_T rtu_G[4], real_T rtu_SL, real_T rtu_SA, real_T rtu_FZ, real_T rtu_IA,
    real_T *rty_COMBINED_FX, real_T *rty_COMBINED_FY, real_T *rty_COMBINED_MZ,
    real_T *rty_satAccelT, real_T *rty_satBrakeT, real_T *rtd_AMU, real_T
    *rtd_EPSILON, real_T *rtd_FZO, real_T *rtd_LCX, real_T *rtd_LCY, real_T
    *rtd_LEX, real_T *rtd_LEY, real_T *rtd_LFZO, real_T *rtd_LHX, real_T
    *rtd_LHY, real_T *rtd_LKXKAPPA, real_T *rtd_LKYALPHA, real_T *rtd_LKYGAMMA,
    real_T *rtd_LKZGAMMA, real_T *rtd_LMR, real_T *rtd_LMUV, real_T *rtd_LMUX,
    real_T *rtd_LMUXAST, real_T *rtd_LMUXPRIME, real_T *rtd_LMUY, real_T
    *rtd_LMUYAST, real_T *rtd_LMUYPRIME, real_T *rtd_LMX, real_T *rtd_LS, real_T
    *rtd_LT, real_T *rtd_LVX, real_T *rtd_LVY, real_T *rtd_LVYKAPPA, real_T
    *rtd_LXALPHA, real_T *rtd_LYKAPPA, real_T *rtd_PCX1, real_T *rtd_PCY1,
    real_T *rtd_PDX1, real_T *rtd_PDX2, real_T *rtd_PDX3, real_T *rtd_PDY1,
    real_T *rtd_PDY2, real_T *rtd_PDY3, real_T *rtd_PEX1, real_T *rtd_PEX2,
    real_T *rtd_PEX3, real_T *rtd_PEX4, real_T *rtd_PEY1, real_T *rtd_PEY2,
    real_T *rtd_PEY3, real_T *rtd_PEY4, real_T *rtd_PEY5, real_T *rtd_PHX1,
    real_T *rtd_PHX2, real_T *rtd_PHY1, real_T *rtd_PHY2, real_T *rtd_PKX1,
    real_T *rtd_PKX2, real_T *rtd_PKX3, real_T *rtd_PKY1, real_T *rtd_PKY2,
    real_T *rtd_PKY3, real_T *rtd_PKY4, real_T *rtd_PKY5, real_T *rtd_PKY6,
    real_T *rtd_PKY7, real_T *rtd_PVX1, real_T *rtd_PVX2, real_T *rtd_PVY1,
    real_T *rtd_PVY2, real_T *rtd_PVY3, real_T *rtd_PVY4, real_T *rtd_QBZ1,
    real_T *rtd_QBZ10, real_T *rtd_QBZ2, real_T *rtd_QBZ3, real_T *rtd_QBZ5,
    real_T *rtd_QBZ6, real_T *rtd_QBZ9, real_T *rtd_QCZ1, real_T *rtd_QDZ1,
    real_T *rtd_QDZ10, real_T *rtd_QDZ11, real_T *rtd_QDZ2, real_T *rtd_QDZ3,
    real_T *rtd_QDZ4, real_T *rtd_QDZ6, real_T *rtd_QDZ7, real_T *rtd_QDZ8,
    real_T *rtd_QDZ9, real_T *rtd_QEZ1, real_T *rtd_QEZ2, real_T *rtd_QEZ3,
    real_T *rtd_QEZ4, real_T *rtd_QEZ5, real_T *rtd_QHZ1, real_T *rtd_QHZ2,
    real_T *rtd_QHZ3, real_T *rtd_QHZ4, real_T *rtd_QSX1, real_T *rtd_QSX2,
    real_T *rtd_QSX3, real_T *rtd_RBX1, real_T *rtd_RBX2, real_T *rtd_RBX3,
    real_T *rtd_RBY1, real_T *rtd_RBY2, real_T *rtd_RBY3, real_T *rtd_RBY4,
    real_T *rtd_RCX1, real_T *rtd_RCY1, real_T *rtd_REX1, real_T *rtd_REX2,
    real_T *rtd_REY1, real_T *rtd_REY2, real_T *rtd_RHX1, real_T *rtd_RHY1,
    real_T *rtd_RHY2, real_T *rtd_RO, real_T *rtd_RVY1, real_T *rtd_RVY2, real_T
    *rtd_RVY3, real_T *rtd_RVY4, real_T *rtd_RVY5, real_T *rtd_RVY6, real_T
    *rtd_SSZ1, real_T *rtd_SSZ2, real_T *rtd_SSZ3, real_T *rtd_SSZ4, real_T
    *rtd_VCX, real_T *rtd_ZETA0, real_T *rtd_ZETA1, real_T *rtd_ZETA2, real_T
    *rtd_ZETA3, real_T *rtd_ZETA4, real_T *rtd_ZETA5, real_T *rtd_ZETA6, real_T *
    rtd_ZETA7, real_T *rtd_ZETA8);
  real_T Tire_Model_Codegen_Pacejka52_PSS_FY(const real_T P[22], const real_T
    INPUT[3], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const real_T
    *rtd_LCY, const real_T *rtd_LEY, const real_T *rtd_LFZO, const real_T
    *rtd_LHY, const real_T *rtd_LKYALPHA, const real_T *rtd_LKYGAMMA, const
    real_T *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const real_T *rtd_LVY,
    const real_T *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T *rtd_ZETA4);
  real_T Tire_Model_Codegen_Pacejka52_COMBINED_FY(const real_T R[15], const
    real_T INPUT[4], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const
    real_T *rtd_LCY, const real_T *rtd_LEY, const real_T *rtd_LFZO, const real_T
    *rtd_LHY, const real_T *rtd_LKYALPHA, const real_T *rtd_LKYGAMMA, const
    real_T *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const real_T *rtd_LVY,
    const real_T *rtd_LVYKAPPA, const real_T *rtd_LYKAPPA, const real_T
    *rtd_PCY1, const real_T *rtd_PDY1, const real_T *rtd_PDY2, const real_T
    *rtd_PDY3, const real_T *rtd_PEY1, const real_T *rtd_PEY2, const real_T
    *rtd_PEY3, const real_T *rtd_PEY4, const real_T *rtd_PEY5, const real_T
    *rtd_PHY1, const real_T *rtd_PHY2, const real_T *rtd_PKY1, const real_T
    *rtd_PKY2, const real_T *rtd_PKY3, const real_T *rtd_PKY4, const real_T
    *rtd_PKY5, const real_T *rtd_PKY6, const real_T *rtd_PKY7, const real_T
    *rtd_PVY1, const real_T *rtd_PVY2, const real_T *rtd_PVY3, const real_T
    *rtd_PVY4, const real_T *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T
    *rtd_ZETA4);
  real_T Tire_Model_Codegen_Pacejka52_PLS_FX(const real_T A[15], const real_T
    INPUT[3], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const real_T
    *rtd_LCX, const real_T *rtd_LEX, const real_T *rtd_LFZO, const real_T
    *rtd_LHX, const real_T *rtd_LKXKAPPA, const real_T *rtd_LMUX, const real_T
    *rtd_LMUXPRIME, const real_T *rtd_LVX, const real_T *rtd_ZETA1);
  real_T Tire_Model_Codegen_Pacejka52_COMBINED_MZ(const real_T S[4], const
    real_T INPUT[4], const real_T *rtd_EPSILON, const real_T *rtd_FZO, const
    real_T *rtd_LCX, const real_T *rtd_LCY, const real_T *rtd_LEX, const real_T *
    rtd_LEY, const real_T *rtd_LFZO, const real_T *rtd_LHX, const real_T
    *rtd_LHY, const real_T *rtd_LKXKAPPA, const real_T *rtd_LKYALPHA, const
    real_T *rtd_LKYGAMMA, const real_T *rtd_LKZGAMMA, const real_T *rtd_LMR,
    const real_T *rtd_LMUX, const real_T *rtd_LMUXPRIME, const real_T
    *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const real_T *rtd_LS, const
    real_T *rtd_LT, const real_T *rtd_LVX, const real_T *rtd_LVY, const real_T
    *rtd_LVYKAPPA, const real_T *rtd_LXALPHA, const real_T *rtd_LYKAPPA, const
    real_T *rtd_PCX1, const real_T *rtd_PCY1, const real_T *rtd_PDX1, const
    real_T *rtd_PDX2, const real_T *rtd_PDX3, const real_T *rtd_PDY1, const
    real_T *rtd_PDY2, const real_T *rtd_PDY3, const real_T *rtd_PEX1, const
    real_T *rtd_PEX2, const real_T *rtd_PEX3, const real_T *rtd_PEX4, const
    real_T *rtd_PEY1, const real_T *rtd_PEY2, const real_T *rtd_PEY3, const
    real_T *rtd_PEY4, const real_T *rtd_PEY5, const real_T *rtd_PHX1, const
    real_T *rtd_PHX2, const real_T *rtd_PHY1, const real_T *rtd_PHY2, const
    real_T *rtd_PKX1, const real_T *rtd_PKX2, const real_T *rtd_PKX3, const
    real_T *rtd_PKY1, const real_T *rtd_PKY2, const real_T *rtd_PKY3, const
    real_T *rtd_PKY4, const real_T *rtd_PKY5, const real_T *rtd_PKY6, const
    real_T *rtd_PKY7, const real_T *rtd_PVX1, const real_T *rtd_PVX2, const
    real_T *rtd_PVY1, const real_T *rtd_PVY2, const real_T *rtd_PVY3, const
    real_T *rtd_PVY4, const real_T *rtd_QBZ1, const real_T *rtd_QBZ10, const
    real_T *rtd_QBZ2, const real_T *rtd_QBZ3, const real_T *rtd_QBZ5, const
    real_T *rtd_QBZ6, const real_T *rtd_QBZ9, const real_T *rtd_QCZ1, const
    real_T *rtd_QDZ1, const real_T *rtd_QDZ10, const real_T *rtd_QDZ11, const
    real_T *rtd_QDZ2, const real_T *rtd_QDZ3, const real_T *rtd_QDZ4, const
    real_T *rtd_QDZ6, const real_T *rtd_QDZ7, const real_T *rtd_QDZ8, const
    real_T *rtd_QDZ9, const real_T *rtd_QEZ1, const real_T *rtd_QEZ2, const
    real_T *rtd_QEZ3, const real_T *rtd_QEZ4, const real_T *rtd_QEZ5, const
    real_T *rtd_QHZ1, const real_T *rtd_QHZ2, const real_T *rtd_QHZ3, const
    real_T *rtd_QHZ4, const real_T *rtd_RBX1, const real_T *rtd_RBX2, const
    real_T *rtd_RBX3, const real_T *rtd_RBY1, const real_T *rtd_RBY2, const
    real_T *rtd_RBY3, const real_T *rtd_RBY4, const real_T *rtd_RCX1, const
    real_T *rtd_RCY1, const real_T *rtd_REX1, const real_T *rtd_REX2, const
    real_T *rtd_REY1, const real_T *rtd_REY2, const real_T *rtd_RHX1, const
    real_T *rtd_RHY1, const real_T *rtd_RHY2, const real_T *rtd_RO, const real_T
    *rtd_RVY1, const real_T *rtd_RVY2, const real_T *rtd_RVY3, const real_T
    *rtd_RVY4, const real_T *rtd_RVY5, const real_T *rtd_RVY6, const real_T
    *rtd_VCX, const real_T *rtd_ZETA0, const real_T *rtd_ZETA1, const real_T
    *rtd_ZETA2, const real_T *rtd_ZETA3, const real_T *rtd_ZETA4, const real_T
    *rtd_ZETA5, const real_T *rtd_ZETA6, const real_T *rtd_ZETA7, const real_T
    *rtd_ZETA8);
  void Tire_Model_Codegen_repelem(real_T x, real_T y[100]);
  void Tire_Model_Codegen_Pacejka52_COMBINED_FY_m(const real_T R[15], const
    real_T INPUT[400], real_T FY[100], const real_T *rtd_EPSILON, const real_T
    *rtd_FZO, const real_T *rtd_LCY, const real_T *rtd_LEY, const real_T
    *rtd_LFZO, const real_T *rtd_LHY, const real_T *rtd_LKYALPHA, const real_T
    *rtd_LKYGAMMA, const real_T *rtd_LMUYAST, const real_T *rtd_LMUYPRIME, const
    real_T *rtd_LVY, const real_T *rtd_LVYKAPPA, const real_T *rtd_LYKAPPA,
    const real_T *rtd_PCY1, const real_T *rtd_PDY1, const real_T *rtd_PDY2,
    const real_T *rtd_PDY3, const real_T *rtd_PEY1, const real_T *rtd_PEY2,
    const real_T *rtd_PEY3, const real_T *rtd_PEY4, const real_T *rtd_PEY5,
    const real_T *rtd_PHY1, const real_T *rtd_PHY2, const real_T *rtd_PKY1,
    const real_T *rtd_PKY2, const real_T *rtd_PKY3, const real_T *rtd_PKY4,
    const real_T *rtd_PKY5, const real_T *rtd_PKY6, const real_T *rtd_PKY7,
    const real_T *rtd_PVY1, const real_T *rtd_PVY2, const real_T *rtd_PVY3,
    const real_T *rtd_PVY4, const real_T *rtd_ZETA2, const real_T *rtd_ZETA3,
    const real_T *rtd_ZETA4);
  real_T Tire_Model_Codegen_maximum(const real_T x[100]);
  real_T Tire_Model_Codegen_interp1(const real_T varargin_1[100], const real_T
    varargin_2[100], real_T varargin_3);
  void Tire_Model_Codegen_Pacejka52_COMBINED_FX(const real_T R[7], const real_T
    INPUT[400], real_T FX[100], const real_T *rtd_EPSILON, const real_T *rtd_FZO,
    const real_T *rtd_LCX, const real_T *rtd_LEX, const real_T *rtd_LFZO, const
    real_T *rtd_LHX, const real_T *rtd_LKXKAPPA, const real_T *rtd_LMUX, const
    real_T *rtd_LMUXPRIME, const real_T *rtd_LVX, const real_T *rtd_LXALPHA,
    const real_T *rtd_PCX1, const real_T *rtd_PDX1, const real_T *rtd_PDX2,
    const real_T *rtd_PDX3, const real_T *rtd_PEX1, const real_T *rtd_PEX2,
    const real_T *rtd_PEX3, const real_T *rtd_PEX4, const real_T *rtd_PHX1,
    const real_T *rtd_PHX2, const real_T *rtd_PKX1, const real_T *rtd_PKX2,
    const real_T *rtd_PKX3, const real_T *rtd_PVX1, const real_T *rtd_PVX2,
    const real_T *rtd_ZETA1);
  real_T Tire_Model_Codegen_minimum(const real_T x[100]);

  // Real-Time Model
  RT_MODEL_Tire_Model_Codegen_T Tire_Model_Codegen_M;
};

// Constant parameters (default storage)
extern const Tire_Model_Codegen::ConstP_Tire_Model_Codegen_T
  Tire_Model_Codegen_ConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Tire_Model_Codegen'
//  '<S1>'   : 'Tire_Model_Codegen/Load Cell Interpreter'
//  '<S2>'   : 'Tire_Model_Codegen/MATLAB Function'
//  '<S3>'   : 'Tire_Model_Codegen/Motor RPM --> Wheel Omega'
//  '<S4>'   : 'Tire_Model_Codegen/Tire Model Pacejka 5.2'
//  '<S5>'   : 'Tire_Model_Codegen/Load Cell Interpreter/MATLAB Function1'
//  '<S6>'   : 'Tire_Model_Codegen/Load Cell Interpreter/MATLAB Function2'
//  '<S7>'   : 'Tire_Model_Codegen/Load Cell Interpreter/MATLAB Function3'
//  '<S8>'   : 'Tire_Model_Codegen/Load Cell Interpreter/MATLAB Function4'
//  '<S9>'   : 'Tire_Model_Codegen/Motor RPM --> Wheel Omega/Subsystem'
//  '<S10>'  : 'Tire_Model_Codegen/Motor RPM --> Wheel Omega/Subsystem1'
//  '<S11>'  : 'Tire_Model_Codegen/Motor RPM --> Wheel Omega/Subsystem2'
//  '<S12>'  : 'Tire_Model_Codegen/Motor RPM --> Wheel Omega/Subsystem3'
//  '<S13>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/FY DIRECTIONAL CONSTRAIN'
//  '<S14>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/FY DIRECTIONAL CONSTRAIN1'
//  '<S15>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/FY DIRECTIONAL CONSTRAIN2'
//  '<S16>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/FY DIRECTIONAL CONSTRAIN3'
//  '<S17>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL'
//  '<S18>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL1'
//  '<S19>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL2'
//  '<S20>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL3'
//  '<S21>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/Radians to Degrees'
//  '<S22>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/Radians to Degrees1'
//  '<S23>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/Radians to Degrees2'
//  '<S24>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/Radians to Degrees3'
//  '<S25>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/Subsystem'
//  '<S26>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/TIRE FACTOR X'
//  '<S27>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/TIRE FACTOR X1'
//  '<S28>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/TIRE FACTOR X2'
//  '<S29>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/TIRE FACTOR X3'
//  '<S30>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/TIRE FORCE SAE --> FLU TRANSFORMATION'
//  '<S31>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL/MATLAB Function'
//  '<S32>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL/SA Extrapolation Constraint1'
//  '<S33>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL/SL Extrapolation Constraint1'
//  '<S34>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL1/MATLAB Function'
//  '<S35>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL1/SA Extrapolation Constraint1'
//  '<S36>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL1/SL Extrapolation Constraint1'
//  '<S37>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL2/MATLAB Function'
//  '<S38>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL2/SA Extrapolation Constraint1'
//  '<S39>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL2/SL Extrapolation Constraint1'
//  '<S40>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL3/MATLAB Function'
//  '<S41>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL3/SA Extrapolation Constraint1'
//  '<S42>'  : 'Tire_Model_Codegen/Tire Model Pacejka 5.2/PACEJKA 5.2 FL3/SL Extrapolation Constraint1'

#endif                                 // Tire_Model_Codegen_h_

//
// File trailer for generated code.
//
// [EOF]
//
