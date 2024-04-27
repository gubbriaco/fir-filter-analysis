import random


class RandomInputsIPGenerator:
    
    @staticmethod
    def randInputsIP(path, cycles, noInputs, noBitsInput):
        with open(path, 'w') as file:
            for _ in range(noInputs):
                binaryInput = RandomInputsIPGenerator.generateBinary32(
                    noBitsInput=noBitsInput
                )

                RandomInputsIPGenerator.writeToFile(
                    file=file,
                    cycles=cycles,
                    binaryInput=binaryInput
                )
            file.write(f"        ap_start <= '0';\n")
            file.close()
                
    @staticmethod         
    def generateBinary32(noBitsInput):
        randInt32 = random.randint(0, 2**noBitsInput-1)
        format32Bits = '032b'
        return format(
            randInt32,
            format32Bits
        )
    
    @staticmethod
    def writeToFile(file, cycles, binaryInput):
        file.write(f'        inputFilter <= "{binaryInput}";\n')
        file.write(f'        wait for {cycles}*clk_period;\n')
        file.write(f"        outputFilter_ap_vld <= '1';\n")
        file.write(f"        ap_done <= '1';\n")
        file.write(f"        ap_ready <= '1';\n")
        file.write(f'        wait for clk_period;\n')
        file.write(f"        outputFilter_ap_vld <= '0';\n")
        file.write(f"        ap_done <= '0';\n")
        file.write(f"        ap_ready <= '0';\n")
