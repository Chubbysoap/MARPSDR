// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Thu Feb  5 05:38:13 2026
// Host        : chubbysoapComputer running 64-bit Ubuntu 22.04.5 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/chubbysoap/Documents/ADgit/hdl/projects/fmcomms2/zed/fmcomms2_zed.gen/sources_1/bd/system/ip/system_util_ad9361_divclk_0/system_util_ad9361_divclk_0_stub.v
// Design      : system_util_ad9361_divclk_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "util_clkdiv,Vivado 2023.2" *)
module system_util_ad9361_divclk_0(clk, clk_sel, clk_out)
/* synthesis syn_black_box black_box_pad_pin="clk,clk_sel" */
/* synthesis syn_force_seq_prim="clk_out" */;
  input clk;
  input clk_sel;
  output clk_out /* synthesis syn_isclock = 1 */;
endmodule
