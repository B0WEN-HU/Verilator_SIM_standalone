#pragma once

# include "Vflicker.h"
# include "verilated.h"

#ifdef __cplusplus
extern "C"
{
#endif

static Vflicker* tb;
static unsigned int cycles = 0;

void init();

void reset();

unsigned char tic();

void release();

#ifdef __cplusplus
}
#endif