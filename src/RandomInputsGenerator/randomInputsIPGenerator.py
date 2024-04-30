import random


class RandomInputsIPGenerator:
    
    @staticmethod
    def randInputsIP(path, noInputs, noBitsInput):
        with open(path, 'w') as file:
            for _ in range(noInputs):
                binaryInput = RandomInputsIPGenerator.generateBinary32(
                    noBitsInput=noBitsInput
                )

                RandomInputsIPGenerator.writeToFile(
                    file=file,
                    binaryInput=binaryInput
                )
            file.write(f"          wait;\n")
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
    def writeToFile(file, binaryInput):
        file.write(f'          inputFilter <= "{binaryInput}";\n')
        file.write(f'          wait for cycles*clk_period;\n')
