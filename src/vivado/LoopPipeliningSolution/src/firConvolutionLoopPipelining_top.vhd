library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity firConvolutionLoopPipelining_top is
	port (
			ap_clk : IN STD_LOGIC;
			ap_rst : IN STD_LOGIC;
			ap_start : IN STD_LOGIC;
			ap_done : OUT STD_LOGIC;
			ap_idle : OUT STD_LOGIC;
			ap_ready : OUT STD_LOGIC;
			inputFilter : IN STD_LOGIC_VECTOR (31 downto 0);
			outputFilter : OUT STD_LOGIC_VECTOR (31 downto 0);
			outputFilter_ap_vld : OUT STD_LOGIC 
  );
end firConvolutionLoopPipelining_top;

architecture Behavioral of firConvolutionLoopPipelining_top is
	
	component firConvolutionLoopPipelining_0 is
		port (
			ap_clk : IN STD_LOGIC;
			ap_rst : IN STD_LOGIC;
			ap_start : IN STD_LOGIC;
			ap_done : OUT STD_LOGIC;
			ap_idle : OUT STD_LOGIC;
			ap_ready : OUT STD_LOGIC;
			inputFilter : IN STD_LOGIC_VECTOR (31 downto 0);
			outputFilter : OUT STD_LOGIC_VECTOR (31 downto 0);
			outputFilter_ap_vld : OUT STD_LOGIC 
    );
  end component;
	
	
	begin
	
		firConvolutionLoopPipelining_IP : firConvolutionLoopPipelining_0 port map(
				ap_clk => ap_clk,
				ap_rst => ap_rst,
				ap_start => ap_start,
				ap_done => ap_done,
				ap_idle => ap_idle,
				ap_ready => ap_ready,
				inputFilter => inputFilter,
				outputFilter => outputFilter,
				outputFilter_ap_vld => outputFilter_ap_vld
		);

end Behavioral;
