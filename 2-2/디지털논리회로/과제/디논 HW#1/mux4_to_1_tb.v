`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/10/18 14:15:51
// Design Name: 
// Module Name: mux4_to_1_tb
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


module mux4_to_1_tb();  //포트가 없으면 테스트용 코드라는 것을 알 수 있다.
 
 //입력으로 연결되는 변수들의 정의
 reg IN0, IN1, IN2, IN3;
 reg S1, S0; 

 wire OUTPUT; //출력 wire선언

 mux4_to_1 mymux (OUTPUT, IN0, IN1, IN2, IN3, S1, S0); //멀티플렉서의 파생
    
initial begin
     IN0 = 1; IN1 = 0; IN2 = 1; IN3 = 0;
     S1 = 0; S0 = 0;
     #1 $display("S1 = %b, S0 = %b, OUTPUT = %b \n", S1, S0, OUTPUT);
     S1 = 0; S0 = 1;
     #1 $display("S1 = %b, S0 = %b, OUTPUT = %b \n", S1, S0, OUTPUT);
     S1 = 1; S0 = 0;
     #1 $display("S1 = %b, S0 = %b, OUTPUT = %b \n", S1, S0, OUTPUT);
     S1 = 1; S0 = 1;
     #1 $display("S1 = %b, S0 = %b, OUTPUT = %b \n", S1, S0, OUTPUT);
end

endmodule
