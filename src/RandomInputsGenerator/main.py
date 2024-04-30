import os
from properties import noBitsInput, noInputs, randomInputsDirPath, randomInputsFileName
from randomInputsIPGenerator import RandomInputsIPGenerator as riig


if __name__ == "__main__":
    riig.randInputsIP(
        path=os.path.join(randomInputsDirPath, randomInputsFileName),
        noInputs=noInputs,
        noBitsInput=noBitsInput
    )
