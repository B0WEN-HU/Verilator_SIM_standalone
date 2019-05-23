# include <cstdlib>
# include "Vflicker.h"
# include "verilated.h"
# include <iostream>
# include <cstdio>

int main(int argc, char** argv) {
	// Initialize Verilators variables
    Verilated::commandArgs(argc, argv);
    
    // Create an instance of out module under test
    Vflicker* tb = new Vflicker;
    
    int cycles = 0;
    
    // Reset the module
    std::cout << "***SIMULATION START***" << std::endl;
    std::cout << "***RESET***" << std::endl;
    tb->clk = 0;
    tb->rst_n = 0;
    tb->eval();
    tb->clk = 1;
    tb->eval();
    tb->rst_n = 1;
    
    ++cycles;
    // Tick the clock until we are done
    std::cout << "******" << std::endl;
    while(!Verilated::gotFinish()) {
        tb->clk = 1;
        tb->eval();
        ++cycles;
        std::cout << "CYCLE[" << cycles << "]:" << (int)tb->dout << std::endl;
        tb->clk = 0;
        tb->eval();
        if('F' == getchar())
            break;
    }
    
    tb->final();
    delete tb;  
    std::cout << "***SIMULATION END***" << std::endl;
    exit(EXIT_SUCCESS);
}
