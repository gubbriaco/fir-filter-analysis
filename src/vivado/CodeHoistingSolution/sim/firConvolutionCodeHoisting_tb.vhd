library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity firConvolutionCodeHoisting_tb is
end firConvolutionCodeHoisting_tb;



architecture Behavioral of firConvolutionCodeHoisting_tb is
    
  -- Components declaration
  component firConvolutionCodeHoisting_top is
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


	begin
	
		uut : firConvolutionCodeHoisting_top port map(
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
				wait for 125ns;
				ap_rst <= '0';
				wait for clk_period;
				ap_start <= '1';
				
        inputFilter <= "01001010111000001011001001101011";
        wait for 43*clk_period;
        inputFilter <= "01111111110010010101101100001000";
        wait for 43*clk_period;
        inputFilter <= "11000010010111001100100000010011";
        wait for 43*clk_period;
        inputFilter <= "00010101100101111101011111011001";
        wait for 43*clk_period;
        inputFilter <= "00101100100001000111010101001111";
        wait for 43*clk_period;
        inputFilter <= "11101101110010110111110111100110";
        wait for 43*clk_period;
        inputFilter <= "10110001010010001000001110000100";
        wait for 43*clk_period;
        inputFilter <= "11011111111010111010110000000010";
        wait for 43*clk_period;
        inputFilter <= "10001101010110010101101110001101";
        wait for 43*clk_period;
        inputFilter <= "10000000000011010101100110011101";
        wait for 43*clk_period;
        inputFilter <= "01000000100011010000111111101111";
        wait for 43*clk_period;
        wait;
		end process uut_process;

end Behavioral;
