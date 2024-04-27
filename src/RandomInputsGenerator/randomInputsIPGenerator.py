import random


class RandomInputsIPGenerator:
    
    @staticmethod
    def randInputsIP(path, clockFormat, noInputs, inputFormat, noBitsInput):
        with open(path, 'w') as file:
            for _ in range(noInputs):
                binaryInput = RandomInputsIPGenerator.generateBinary32(
                    noBitsInput=noBitsInput
                )
                RandomInputsIPGenerator.writeToFile(
                    file=file,
                    clockFormat=clockFormat,
                    inputFormat=inputFormat,
                    binaryInput=binaryInput
                )
                
    @staticmethod         
    def generateBinary32(noBitsInput):
        randInt32 = random.randint(0, 2**noBitsInput-1)
        format32Bits = '032b'
        return format(
            randInt32,
            format32Bits
        )
    
    @staticmethod
    def writeToFile(file, clockFormat, inputFormat, binaryInput):
        file.write(f'{inputFormat}"{binaryInput}";\n')
        file.write(f'{clockFormat};\n')
