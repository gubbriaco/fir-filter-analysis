library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity firConvolutionAXI_tb is
end firConvolutionAXI_tb;

architecture Behavioral of firConvolutionAXI_tb is

  -- Components declaration
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

	-- Signals declaration
  constant clk_period : Time := 10 ns;
  signal ap_clk : STD_LOGIC := '0';
  signal ap_rst_n : STD_LOGIC;
  signal inputStreamFilter_TDATA : STD_LOGIC_VECTOR (31 downto 0);
  signal inputStreamFilter_TVALID : STD_LOGIC;
  signal inputStreamFilter_TREADY : STD_LOGIC;
  signal inputStreamFilter_TKEEP : STD_LOGIC_VECTOR (3 downto 0);
  signal inputStreamFilter_TSTRB : STD_LOGIC_VECTOR (3 downto 0);
  signal inputStreamFilter_TUSER : STD_LOGIC_VECTOR (1 downto 0);
  signal inputStreamFilter_TLAST : STD_LOGIC_VECTOR (0 downto 0);
  signal inputStreamFilter_TID : STD_LOGIC_VECTOR (4 downto 0);
  signal inputStreamFilter_TDEST : STD_LOGIC_VECTOR (5 downto 0);
  signal outputStreamFilter_TDATA : STD_LOGIC_VECTOR (31 downto 0);
  signal outputStreamFilter_TVALID : STD_LOGIC;
  signal outputStreamFilter_TREADY : STD_LOGIC;
  signal outputStreamFilter_TKEEP : STD_LOGIC_VECTOR (3 downto 0);
  signal outputStreamFilter_TSTRB : STD_LOGIC_VECTOR (3 downto 0);
  signal outputStreamFilter_TUSER : STD_LOGIC_VECTOR (1 downto 0);
  signal outputStreamFilter_TLAST : STD_LOGIC_VECTOR (0 downto 0);
  signal outputStreamFilter_TID : STD_LOGIC_VECTOR (4 downto 0);
  signal outputStreamFilter_TDEST : STD_LOGIC_VECTOR (5 downto 0);
  
  signal cycles: integer := 11;
	
	
	begin
		uut : firConvolutionAXI_top port map (
			ap_clk,
			ap_rst_n,
			inputStreamFilter_TDATA,
			inputStreamFilter_TVALID,
			inputStreamFilter_TREADY,
			inputStreamFilter_TKEEP,
			inputStreamFilter_TSTRB,
			inputStreamFilter_TUSER,
			inputStreamFilter_TLAST,
			inputStreamFilter_TID,
			inputStreamFilter_TDEST,
			outputStreamFilter_TDATA,
			outputStreamFilter_TVALID,
			outputStreamFilter_TREADY,
			outputStreamFilter_TKEEP,
			outputStreamFilter_TSTRB,
			outputStreamFilter_TUSER,
			outputStreamFilter_TLAST,
			outputStreamFilter_TID,
			outputStreamFilter_TDEST
		);

		clk_process : process
        begin
				wait for clk_period/2;
          ap_clk <= not ap_clk;
     end process clk_process;
	 
		rst_n_process : process
			begin
				ap_rst_n <= '0';
				wait for 125ns;
				ap_rst_n <= '1';
				wait;
		end process rst_n_process;
		
		user_process : process
			begin
				inputStreamFilter_TUSER <= "00";
				wait;
		end process user_process;
		
		id_process : process
			begin
				inputStreamFilter_TID <= "00000";
				wait;
		end process id_process;
		
		dest_process : process
			begin
				inputStreamFilter_TDEST <= "000000";
				wait;
		end process dest_process;
		
		ready_process : process
			begin
				outputStreamFilter_TREADY <= '0';
				wait for 125ns;
				outputStreamFilter_TREADY <= '1';
				wait;
		end process ready_process;
	 
		keep_strb_process : process
			begin
				inputStreamFilter_TKEEP <= "0000";
				inputStreamFilter_TSTRB <= "0000";
				wait for 135ns;
				inputStreamFilter_TKEEP <= "1111";
				inputStreamFilter_TSTRB <= "1111";
				wait for cycles*clk_period;
				inputStreamFilter_TKEEP <= "0000";
				inputStreamFilter_TSTRB <= "0000";
				wait for clk_period/2;
				inputStreamFilter_TKEEP <= "1111";
				inputStreamFilter_TSTRB <= "1111";
				wait;
		end process keep_strb_process;
		
		valid_proces : process
			begin
				inputStreamFilter_TVALID <= '0';
				wait for 135ns;
				inputStreamFilter_TVALID <= '1';
				wait for cycles*clk_period;
				inputStreamFilter_TVALID <= '0';
				wait for clk_period/2;
				inputStreamFilter_TVALID <= '1';
				wait;
		end process valid_proces;
		
		last_process : process
			begin
				inputStreamFilter_TLAST <= "0";
				wait for 145ns;
				wait for (cycles-1)*clk_period;
				inputStreamFilter_TLAST <= "1";
				wait for clk_period;
				inputStreamFilter_TLAST <= "0";
				wait;
		end process last_process;
		
		data_process : process
			begin
				inputStreamFilter_TDATA <= "01101100011111000000011010001110";
				wait for 135ns;
				inputStreamFilter_TDATA <= "10101100001011101011101101100010";
				wait for clk_period;
          inputStreamFilter_TDATA <= "11110000011100010010110001111100";
				wait for clk_period;
          inputStreamFilter_TDATA <= "01101101000111100000010100000100";
				wait for clk_period;
          inputStreamFilter_TDATA <= "11000100010011111001010011011001";
				wait for clk_period;
          inputStreamFilter_TDATA <= "01101001100110010111101010010010";
				wait for clk_period;
          inputStreamFilter_TDATA <= "10110101110111110100000101110011";
				wait for clk_period;
          inputStreamFilter_TDATA <= "11110011001101000000001100001010";
				wait for clk_period;
          inputStreamFilter_TDATA <= "01010001001110100111010101001001";
				wait for clk_period;
          inputStreamFilter_TDATA <= "10100010011110110010000010011000";
				wait for clk_period;
				
				wait for clk_period;
				inputStreamFilter_TDATA <= "00000000000000000000000000000000";
				
				wait for clk_period/2;
				inputStreamFilter_TDATA <= "11101000110011101001011101010001";
				wait;
		end process data_process;

end Behavioral;
