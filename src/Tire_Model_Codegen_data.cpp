//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Tire_Model_Codegen_data.cpp
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

// Constant parameters (default storage)
const Tire_Model_Codegen::ConstP_Tire_Model_Codegen_T Tire_Model_Codegen_ConstP{
  // Pooled Parameter (Expression: tireCoeffs.G)
  //  Referenced by:
  //    '<S17>/Constant10'
  //    '<S18>/Constant10'
  //    '<S19>/Constant10'
  //    '<S20>/Constant10'

  { -0.018581908494590824, -0.052489029004339445, 0.0354663977022263,
    -0.55926233157320682 },

  // Pooled Parameter (Expression: LAMBDA)
  //  Referenced by:
  //    '<S17>/Constant3'
  //    '<S18>/Constant3'
  //    '<S19>/Constant3'
  //    '<S20>/Constant3'

  { 1100.0, 0.2032, 10.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 10.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0 },

  // Pooled Parameter (Expression: tireCoeffs.A)
  //  Referenced by:
  //    '<S17>/Constant4'
  //    '<S18>/Constant4'
  //    '<S19>/Constant4'
  //    '<S20>/Constant4'

  { 1.2313596424808264, -2.6218419146715011, 0.49408874960332233,
    -0.11562925978358389, -0.00020039977873071517, -6.1624811679236686E-5,
    -6462.4579045933542, -8275.5305117925272, -183377.60377369338,
    -7315.6447735127331, 0.42782363781656935, -13.929724953423026,
    0.0033491621141695819, 32.474941895851266, -5.3924206132297385,
    -1.1437118392148171, 0.013038327933469776, 0.011296068799727077,
    0.39276810893419961, 0.11759126372372954, 2.4196438576260042,
    -2.2799338208165532 },

  // Pooled Parameter (Expression: tireCoeffs.B)
  //  Referenced by:
  //    '<S17>/Constant5'
  //    '<S18>/Constant5'
  //    '<S19>/Constant5'
  //    '<S20>/Constant5'

  { 4.9526422636959877, -7.2422862784529825, -10.433971205664054,
    0.77944191839338994, -9.71479041489902, -2.989328033231569,
    -2.2553054654455269, 1.9026761440857638, 0.23113387578400904,
    -0.20543034094838589, 0.55581015300396353, -18.186230455018009,
    0.013834236558124526, -0.0034629288702784995, -3.6810885235768844,
    0.27684422041191259, 9.0142454275334973, -19.441653240509762,
    0.23508992687673802, -3.3749765671914345, -6.1406524270110854,
    0.021651480299257862, -1.4372940653303785, 0.0015200989869332228,
    0.0025005904446104409, -0.19487232420426584, -0.36178954227207794 },

  // Pooled Parameter (Expression: tireCoeffs.C)
  //  Referenced by:
  //    '<S17>/Constant6'
  //    '<S18>/Constant6'
  //    '<S19>/Constant6'
  //    '<S20>/Constant6'

  { 0.033710872789240572, -1.6989744128879125, -0.10131168407587939 },

  // Pooled Parameter (Expression: tireCoeffs.D)
  //  Referenced by:
  //    '<S17>/Constant7'
  //    '<S18>/Constant7'
  //    '<S19>/Constant7'
  //    '<S20>/Constant7'

  { 1.2034887637986136, 3.2231064881613674, -1.4293771989131587,
    19.159268279790737, 0.1940276390791833, -3.1562992390056057,
    -3.6719183871745229, 0.12250922922693948, 51.782867956170833,
    -0.016339727620495743, -0.67948719519730594, 0.0013277631420764162,
    -0.00023916516076804978, -0.0933355519695686, 0.057220635815684533 },

  // Pooled Parameter (Expression: tireCoeffs.E)
  //  Referenced by:
  //    '<S17>/Constant8'
  //    '<S18>/Constant8'
  //    '<S19>/Constant8'
  //    '<S20>/Constant8'

  { 0.1847722351557832, 1.0686028080704413, 0.092442780323963469,
    48.050559189883764, 378.6317374571675, -451.58083629101958,
    -1.4338511440035567E-6 },

  // Pooled Parameter (Expression: tireCoeffs.F)
  //  Referenced by:
  //    '<S17>/Constant9'
  //    '<S18>/Constant9'
  //    '<S19>/Constant9'
  //    '<S20>/Constant9'

  { 1260.0102414255728, 73.133743850153778, -0.8434204280635893,
    -11015.214396340958, -0.821649935696013, -0.70411999544448289,
    -1.5230000008611388, 0.018803505998137737, 0.032224920705998458,
    -0.028170004305692924, -0.052746999557708542, -0.12522000044206391,
    304.85650116575681, 2.9901000013571277, -10.651899999870379 }
};

//
// File trailer for generated code.
//
// [EOF]
//
