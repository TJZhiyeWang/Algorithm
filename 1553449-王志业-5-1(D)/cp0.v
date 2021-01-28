`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/05/16 14:59:22
// Design Name: 
// Module Name: cp0
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`define   SYSCALL    4'b1000
`define   BREAK      4'b1001
`define   TEQ        4'b1101
`define   IE         0


module CP0(
       input clk, 
       input rst, 
       input mfc0, 
       input [4:0] addr, 
       output [31:0] CP0_out, 
       input mtc0, 
       input wcau, 
       input wsta, 
       input wepc, 
       input eret,
       input [31:0] data,  
       input [31:0]pc, 
       input [31:0]cause, 
       input exception,
       output [31:0] status, 
       output [31:0]epc_out
    );
    

    reg [31:0] cp0reg [0:31];
    assign status   =    cp0reg[12];
    reg [31:0] status_tmp;
  
    assign CP0_out = mfc0?cp0reg[addr]:32'b1;
    assign epc_out = cp0reg[14];
    always@(*) begin
        if(rst)begin
        cp0reg[0]<=0;
        cp0reg[1]<=0;
        cp0reg[2]<=0;
        cp0reg[3]<=0;
        cp0reg[4]<=0;
        cp0reg[5]<=0;
        cp0reg[6]<=0;
        cp0reg[7]<=0;
        cp0reg[8]<=0;
        cp0reg[9]<=0;
        cp0reg[10]<=0;
        cp0reg[11]<=0;
        cp0reg[12]<=32'h0000000f;
        cp0reg[13]<=0;
        cp0reg[14]<=32'h00400004;
        cp0reg[15]<=0;
        cp0reg[16]<=0;
        cp0reg[17]<=0;
        cp0reg[18]<=0;
        cp0reg[19]<=0;
        cp0reg[20]<=0;
        cp0reg[21]<=0;
        cp0reg[22]<=0;
        cp0reg[23]<=0;
        cp0reg[24]<=0;
        cp0reg[25]<=0;
        cp0reg[26]<=0;
        cp0reg[27]<=0;
        cp0reg[28]<=0;
        cp0reg[29]<=0;
        cp0reg[30]<=0;
        cp0reg[31]<=0;
        end
        else begin
            if(mtc0&&(wcau||wsta||wepc))
                cp0reg[addr]    <=    data;     
            else if(~mtc0 && wsta && wcau && wepc && exception)begin
                cp0reg[14]    <=    pc;
                cp0reg[12]    <=    status<<5;
				status_tmp	  <=    status;
                cp0reg[13]    <=    cause;
            end
            else if(eret&&~exception && ~mtc0 && wsta && wcau) begin
                cp0reg[12]    <=    status_tmp;
                cp0reg[14]    <=    32'h00400004;
                end
        end 
    end 
endmodule
