# Verilator_SIM_standalone

This is a Verilator simulation demo, it shows how to work with Verilator in a main program.

flicker.v is a verilog module, which flips all its bits per cycle.

``` Verilog
//flicker.v
module flicker(clk,rst_n,dout);
parameter WIDTH = 5;
input clk,rst_n;
output reg [WIDTH-1:0] dout;

always@(posedge clk or negedge rst_n)

    if(!rst_n)
        dout <= {WIDTH{1'b0}};
    else
        dout <= ~dout;

endmodule
```

Here WIDTH is 5, so output port `dout` would be `0``(00000)_2` after reset by input signal `rst_n`, then switch between `0``(00000)_2` and `31``(11111)_2`.

Use this line to call Verilator compile the flicker.v
``` Bash
$ verilator -Wall --cc flicker.v --exe simulation.cpp 
```
Then, make the project
``` Bash
make -j -C obj_dir/ -f Vflicker.mk Vflicker
```
Run the executable.
``` Bash
obj_dir/Vflicker 
```

