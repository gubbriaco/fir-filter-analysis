import os
from properties import clockFormat, inputFormat, noBitsInput, noInputs, randomInputsDirPath, randomInputsFileName
from randomInputsIPGenerator import RandomInputsIPGenerator as riig


if __name__ == "__main__":
    riig.randInputsIP(
        path=os.path.join(randomInputsDirPath, randomInputsFileName),
        clockFormat=clockFormat,
        noInputs=noInputs,
        inputFormat=inputFormat,
        noBitsInput=noBitsInput
    )
