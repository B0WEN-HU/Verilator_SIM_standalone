// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vflicker_H_
#define _Vflicker_H_

#include "verilated.h"

class Vflicker__Syms;

//----------

VL_MODULE(Vflicker) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(dout,4,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__rst_n,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vflicker__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vflicker& operator= (const Vflicker&);  ///< Copying not allowed
    Vflicker(const Vflicker&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vflicker(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vflicker();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vflicker__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vflicker__Syms* symsp, bool first);
  private:
    static QData _change_request(Vflicker__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vflicker__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vflicker__Syms* __restrict vlSymsp);
    static void _eval_settle(Vflicker__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vflicker__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
