#include "Vflicker_sim_dll.h"

void init()
{
  tb = new Vflicker;
  cycles = 0;
}

void reset()
{
  tb->clk = 0;
  tb->rst_n = 0;
  tb->eval();
  tb->clk = 1;
  tb->eval();
  tb->rst_n = 1;
  tb->clk = 0;
  tb->eval();

  ++cycles;
}

unsigned char tic()
{
  unsigned char dout;
  tb->clk = 1;
  tb->eval();
  ++cycles;
  dout = (unsigned char) tb->dout;
  tb->clk = 0;
  tb->eval();

  return dout;
}

void release()
{
  tb->final();
  delete tb;
}