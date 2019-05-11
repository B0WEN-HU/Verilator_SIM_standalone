// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vflicker.h for the primary calling header

#include "Vflicker.h"          // For This
#include "Vflicker__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vflicker) {
    Vflicker__Syms* __restrict vlSymsp = __VlSymsp = new Vflicker__Syms(this, name());
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vflicker::__Vconfigure(Vflicker__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vflicker::~Vflicker() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vflicker::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vflicker::eval\n"); );
    Vflicker__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vflicker::_eval_initial_loop(Vflicker__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vflicker::_sequent__TOP__1(Vflicker__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_sequent__TOP__1\n"); );
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__dout,4,0);
    // Body
    __Vdly__dout = vlTOPp->dout;
    // ALWAYS at flicker.v:6
    __Vdly__dout = (0x1fU & ((IData)(vlTOPp->rst_n)
			      ? (~ (IData)(vlTOPp->dout))
			      : 0U));
    vlTOPp->dout = __Vdly__dout;
}

void Vflicker::_eval(Vflicker__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_eval\n"); );
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vflicker::_eval_initial(Vflicker__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_eval_initial\n"); );
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vflicker::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::final\n"); );
    // Variables
    Vflicker__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vflicker::_eval_settle(Vflicker__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_eval_settle\n"); );
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vflicker::_change_request(Vflicker__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_change_request\n"); );
    Vflicker* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vflicker::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
	Verilated::overWidthError("rst_n");}
}
#endif // VL_DEBUG

void Vflicker::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vflicker::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    dout = VL_RAND_RESET_I(5);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__rst_n = VL_RAND_RESET_I(1);
}
