#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

static Vflicker* tb;

void init();

void reset();

unsigned char tic();

void release();

#ifdef __cplusplus
}
#endif