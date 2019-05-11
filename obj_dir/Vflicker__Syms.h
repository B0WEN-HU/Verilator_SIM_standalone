// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vflicker__Syms_H_
#define _Vflicker__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vflicker.h"

// SYMS CLASS
class Vflicker__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vflicker*                      TOPp;
    
    // CREATORS
    Vflicker__Syms(Vflicker* topp, const char* namep);
    ~Vflicker__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
