library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity firConvolutionAXI_tb is
end firConvolutionAXI_tb;

architecture Behavioral of firConvolutionAXI_tb is

	component firConvolutionAXI_top is
		port(
			ap_clk : IN STD_LOGIC;
			ap_rst_n : IN STD_LOGIC;
			inputStreamFilter_TDATA : IN STD_LOGIC_VECTOR (31 downto 0);
			inputStreamFilter_TVALID : IN STD_LOGIC;
			inputStreamFilter_TREADY : OUT STD_LOGIC;
			inputStreamFilter_TKEEP : IN STD_LOGIC_VECTOR (3 downto 0);
			inputStreamFilter_TSTRB : IN STD_LOGIC_VECTOR (3 downto 0);
			inputStreamFilter_TUSER : IN STD_LOGIC_VECTOR (1 downto 0);
			inputStreamFilter_TLAST : IN STD_LOGIC_VECTOR (0 downto 0);
			inputStreamFilter_TID : IN STD_LOGIC_VECTOR (4 downto 0);
			inputStreamFilter_TDEST : IN STD_LOGIC_VECTOR (5 downto 0);
			outputStreamFilter_TDATA : OUT STD_LOGIC_VECTOR (31 downto 0);
			outputStreamFilter_TVALID : OUT STD_LOGIC;
			outputStreamFilter_TREADY : IN STD_LOGIC;
			outputStreamFilter_TKEEP : OUT STD_LOGIC_VECTOR (3 downto 0);
			outputStreamFilter_TSTRB : OUT STD_LOGIC_VECTOR (3 downto 0);
			outputStreamFilter_TUSER : OUT STD_LOGIC_VECTOR (1 downto 0);
			outputStreamFilter_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
			outputStreamFilter_TID : OUT STD_LOGIC_VECTOR (4 downto 0);
			outputStreamFilter_TDEST : OUT STD_LOGIC_VECTOR (5 downto 0)
		);
	end component;


	begin


end Behavioral;
