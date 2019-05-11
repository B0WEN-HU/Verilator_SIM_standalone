module flicker(clk, rst_n, dout);
parameter WIDTH = 5;
input clk, rst_n;
output reg [WIDTH-1:0] dout;

always@(posedge clk or negedge rst_n)

    if(!rst_n)
        dout <= { WIDTH{ 1'b0 } };
    else
        dout <= ~dout;

endmodule
