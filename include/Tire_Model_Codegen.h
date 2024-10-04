//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Tire_Model_Codegen.h
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
    real_T EPSILON;                    // synthesized block
    real_T LCX;                        // synthesized block
    real_T LCY;                        // synthesized block
    real_T LCZ;                        // synthesized block
    real_T LEX;                        // synthesized block
    real_T LEY;                        // synthesized block
    real_T LHX;                        // synthesized block
    real_T LHY;                        // synthesized block
    real_T LKYALPHA;                   // synthesized block
    real_T LKYGAMMA;                   // synthesized block
    real_T LKZGAMMA;                   // synthesized block
    real_T LMR;                        // synthesized block
    real_T LMUXPRIME;                  // synthesized block
    real_T LMUYAST;                    // synthesized block
    real_T LMUYPRIME;                  // synthesized block
    real_T LMY;                        // synthesized block
    real_T LS;                         // synthesized block
    real_T LT;                         // synthesized block
    real_T LVX;                        // synthesized block
    real_T LVY;                        // synthesized block
    real_T LVYKAPPA;                   // synthesized block
    real_T LXALPHA;                    // synthesized block
    real_T LYKAPPA;                    // synthesized block
    real_T PCX1;                       // synthesized block
    real_T PCY1;                       // synthesized block
    real_T PDX1;                       // synthesized block
    real_T PDX2;                       // synthesized block
    real_T PDX3;                       // synthesized block
    real_T PDY1;                       // synthesized block
    real_T PDY2;                       // synthesized block
    real_T PDY3;                       // synthesized block
    real_T PEX1;                       // synthesized block
    real_T PEX2;                       // synthesized block
    real_T PEX3;                       // synthesized block
    real_T PEX4;                       // synthesized block
    real_T PEY1;                       // synthesized block
    real_T PEY2;                       // synthesized block
    real_T PEY3;                       // synthesized block
    real_T PEY4;                       // synthesized block
    real_T PEY5;                       // synthesized block
    real_T PHX1;                       // synthesized block
    real_T PHX2;                       // synthesized block
    real_T PHY1;                       // synthesized block
    real_T PHY2;                       // synthesized block
    real_T PKX1;                       // synthesized block
    real_T PKX2;                       // synthesized block
    real_T PKX3;                       // synthesized block
    real_T PKY1;                       // synthesized block
    real_T PKY2;                       // synthesized block
    real_T PKY3;                       // synthesized block
    real_T PKY4;                       // synthesized block
    real_T PKY5;                       // synthesized block
    real_T PKY6;                       // synthesized block
    real_T PKY7;                       // synthesized block
    real_T PVX1;                       // synthesized block
    real_T PVX2;                       // synthesized block
    real_T PVY1;                       // synthesized block
    real_T PVY2;                       // synthesized block
    real_T PVY3;                       // synthesized block
    real_T PVY4;                       // synthesized block
    real_T QBZ1;                       // synthesized block
    real_T QBZ10;                      // synthesized block
    real_T QBZ2;                       // synthesized block
    real_T QBZ3;                       // synthesized block
    real_T QBZ5;                       // synthesized block
    real_T QBZ6;                       // synthesized block
    real_T QBZ9;                       // synthesized block
    real_T QCZ1;                       // synthesized block
    real_T QDZ1;                       // synthesized block
    real_T QDZ10;                      // synthesized block
    real_T QDZ11;                      // synthesized block
    real_T QDZ2;                       // synthesized block
    real_T QDZ3;                       // synthesized block
    real_T QDZ4;                       // synthesized block
    real_T QDZ6;                       // synthesized block
    real_T QDZ7;                       // synthesized block
    real_T QDZ8;                       // synthesized block
    real_T QDZ9;                       // synthesized block
    real_T QEZ1;                       // synthesized block
    real_T QEZ2;                       // synthesized block
    real_T QEZ3;                       // synthesized block
    real_T QEZ4;                       // synthesized block
    real_T QEZ5;                       // synthesized block
    real_T QHZ1;                       // synthesized block
    real_T QHZ2;                       // synthesized block
    real_T QHZ3;                       // synthesized block
    real_T QHZ4;                       // synthesized block
    real_T QX1;                        // synthesized block
    real_T QX2;                        // synthesized block
    real_T QX3;                        // synthesized block
    real_T QX4;                        // synthesized block
    real_T QX5;                        // synthesized block
    real_T QX6;                        // synthesized block
    real_T RBX1;                       // synthesized block
    real_T RBX2;                       // synthesized block
    real_T RBX3;                       // synthesized block
    real_T RBY1;                       // synthesized block
    real_T RBY2;                       // synthesized block
    real_T RBY3;                       // synthesized block
    real_T RBY4;                       // synthesized block
    real_T RCX1;                       // synthesized block
    real_T RCY1;                       // synthesized block
    real_T REX1;                       // synthesized block
    real_T REX2;                       // synthesized block
    real_T REY1;                       // synthesized block
    real_T REY2;                       // synthesized block
    real_T RHX1;                       // synthesized block
    real_T RHY1;                       // synthesized block
    real_T RHY2;                       // synthesized block
    real_T RVY1;                       // synthesized block
    real_T RVY2;                       // synthesized block
    real_T RVY3;                       // synthesized block
    real_T RVY4;                       // synthesized block
    real_T RVY5;                       // synthesized block
    real_T RVY6;                       // synthesized block
    real_T ZETA0;                      // synthesized block
    real_T ZETA1;                      // synthesized block
    real_T ZETA2;                      // synthesized block
    real_T ZETA3;                      // synthesized block
    real_T ZETA4;                      // synthesized block
    real_T ZETA5;                      // synthesized block
    real_T ZETA6;                      // synthesized block
    real_T ZETA7;                      // synthesized block
    real_T ZETA8;                      // synthesized block
  };

  // Constant parameters (default storage)
  struct ConstP_Tire_Model_Codegen_T {
    // Expression: tireCoeffs.G
    //  Referenced by: '<Root>/Constant10'

    real_T Constant10_Value[4];

    // Expression: tireCoeffs.E
    //  Referenced by: '<Root>/Constant8'

    real_T Constant8_Value[7];

    // Expression: tireCoeffs.F
    //  Referenced by: '<Root>/Constant9'

    real_T Constant9_Value[15];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Tire_Model_Codegen_T {
    real_T SLSAE;                      // '<Root>/SL SAE'
    real_T SASAE;                      // '<Root>/SA SAE'
    real_T LCRaw;                      // '<Root>/LC Raw'
    real_T IASAE;                      // '<Root>/IA SAE'
    real_T LMUX;                       // '<Root>/LMUX'
    real_T LMUY;                       // '<Root>/LMUY'
    real_T Interp_x1;                  // '<Root>/Interp_x1'
    real_T Interp_x2;                  // '<Root>/Interp_x2'
    real_T Interp_x3;                  // '<Root>/Interp_x3'
    real_T interp_y1;                  // '<Root>/interp_y1'
    real_T interp_y2;                  // '<Root>/interp_y2'
    real_T interp_y3;                  // '<Root>/interp_y3'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Tire_Model_Codegen_T {
    real_T FXFLU;                      // '<Root>/FX FLU'
    real_T FYFLU;                      // '<Root>/FY FLU'
    real_T MZFLU;                      // '<Root>/MZ FLU'
    real_T BrakeTorqueSaturation;      // '<Root>/Brake Torque Saturation'
    real_T AccelerationTorqueSaturation;
                                     // '<Root>/Acceleration Torque Saturation'
    real_T FZN;                        // '<Root>/FZ [N]'
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

  // private member function(s) for subsystem '<Root>'
  real_T Tire_Model_Codegen_Pacejka52_PSS_FY(const real_T P[22], const real_T
    INPUT[3], const real_T *FZO, const real_T *LFZO) const;
  real_T Tire_Model_Codegen_Pacejka52_COMBINED_FY(const real_T R[15], const
    real_T INPUT[4], const real_T *FZO, const real_T *LFZO) const;
  real_T Tire_Model_Codegen_Pacejka52_PLS_FX(const real_T A[15], const real_T
    INPUT[3], const real_T *FZO, const real_T *LFZO, const real_T *LMUX, const
    real_T *LKXKAPPA) const;
  real_T Tire_Model_Codegen_Pacejka52_COMBINED_MZ(const real_T S[4], const
    real_T INPUT[4], const real_T *FZO, const real_T *RO, const real_T *VCX,
    const real_T *LFZO, const real_T *LMUX, const real_T *LKXKAPPA) const;
  void Tire_Model_Codegen_repelem(real_T x, real_T y[100]);
  void Tire_Model_Codegen_Pacejka52_COMBINED_FY_m(const real_T R[15], const
    real_T INPUT[400], const real_T *FZO, const real_T *LFZO, real_T FY[100])
    const;
  real_T Tire_Model_Codegen_maximum(const real_T x[100]);
  real_T Tire_Model_Codegen_interp1(const real_T varargin_1[100], const real_T
    varargin_2[100], real_T varargin_3);
  void Tire_Model_Codegen_Pacejka52_COMBINED_FX(const real_T R[7], const real_T
    INPUT[400], const real_T *FZO, const real_T *LFZO, const real_T *LMUX, const
    real_T *LKXKAPPA, real_T FX[100]) const;
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
//  '<S1>'   : 'Tire_Model_Codegen/MATLAB Function'
//  '<S2>'   : 'Tire_Model_Codegen/MATLAB Function1'
//  '<S3>'   : 'Tire_Model_Codegen/SA Extrapolation Constraint1'
//  '<S4>'   : 'Tire_Model_Codegen/SL Extrapolation Constraint1'

#endif                                 // Tire_Model_Codegen_h_

//
// File trailer for generated code.
//
// [EOF]
//
