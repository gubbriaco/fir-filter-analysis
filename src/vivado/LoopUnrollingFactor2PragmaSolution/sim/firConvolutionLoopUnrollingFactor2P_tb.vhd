library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity firConvolutionLoopUnrollingFactor2P_tb is
end firConvolutionLoopUnrollingFactor2P_tb;



architecture Behavioral of firConvolutionLoopUnrollingFactor2P_tb is
    
  -- Components declaration
  component firConvolutionLoopUnrollingFactor2P_top is
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
    
  -- Signals declaration
  constant clk_period : Time := 10 ns;
	signal ap_clk :  STD_LOGIC := '0';
	signal ap_rst :  STD_LOGIC;
	signal ap_start :  STD_LOGIC;
	signal ap_done :  STD_LOGIC;
	signal ap_idle :  STD_LOGIC;
	signal ap_ready :  STD_LOGIC;
	signal inputFilter :  STD_LOGIC_VECTOR (31 DOWNTO 0);
	signal outputFilter :  STD_LOGIC_VECTOR (31 DOWNTO 0);
	signal outputFilter_ap_vld :  STD_LOGIC;

	signal cycles: integer := 39;


	begin
	
		uut : firConvolutionLoopUnrollingFactor2P_top port map(
				ap_clk,
				ap_rst,
				ap_start,
				ap_done,
				ap_idle,
				ap_ready,
				inputFilter,
				outputFilter,
				outputFilter_ap_vld
		);
		
		clk_process : process
        begin
				wait for clk_period/2;
          ap_clk <= not ap_clk;
     end process clk_process;
		
		uut_process : process
			begin
				ap_rst <= '1';
				ap_start <= '0';
				wait for 250ns;
				ap_rst <= '0';
				wait for clk_period;
				ap_start <= '1';

          inputFilter <= "01101100011111000000011010001110";
          wait for cycles*clk_period;
          inputFilter <= "10101100001011101011101101100010";
          wait for cycles*clk_period;
          inputFilter <= "11110000011100010010110001111100";
          wait for cycles*clk_period;
          inputFilter <= "01101101000111100000010100000100";
          wait for cycles*clk_period;
          inputFilter <= "11000100010011111001010011011001";
          wait for cycles*clk_period;
          inputFilter <= "01101001100110010111101010010010";
          wait for cycles*clk_period;
          inputFilter <= "10110101110111110100000101110011";
          wait for cycles*clk_period;
          inputFilter <= "11110011001101000000001100001010";
          wait for cycles*clk_period;
          inputFilter <= "01010001001110100111010101001001";
          wait for cycles*clk_period;
          inputFilter <= "10100010011110110010000010011000";
          wait for cycles*clk_period;
          inputFilter <= "11101000110011101001011101010001";
          wait for cycles*clk_period;
          wait;
		  
		end process uut_process;

end Behavioral;