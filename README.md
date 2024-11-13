# FIR Filter Analysis

This repository contains code and resources for the analysis and implementation of Finite Impulse Response (FIR) filters, with a specific focus on High Level Synthesis (HLS) using Xilinx tools. The project includes documentation, simulations, and reports that explore the design, performance, and application of FIR filters in signal processing.

## Table of Contents

- [Overview](#overview)
- [Directory Structure](#directory-structure)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Reports](#reports)

## Overview

Finite Impulse Response (FIR) filters are a fundamental component in digital signal processing, often used for applications requiring linear-phase filtering. This repository leverages **Xilinx High Level Synthesis (HLS)** for FIR filter design and analysis, allowing for efficient hardware implementations on FPGA platforms. The repository includes:
- Source code for FIR filter design and analysis via HLS
- Simulation files for testing and validating filter performance
- Technical documentation on filter properties and FPGA implementation considerations

## Directory Structure

- `src/`: Source code and scripts for filter design and simulation using Xilinx HLS.
- `report/`: Technical documentation and analysis reports on FIR filter characteristics and design choices.
- `reports/`: Additional reports, plots, and resources generated during analysis.

## Dependencies

Ensure you have the following dependencies installed:
- [Xilinx Vivado HLS](https://www.xilinx.com/products/design-tools/vivado.html) (required for HLS-based synthesis)
- [Python 3.x](https://www.python.org/) (for additional script execution)
- Additional Python packages as listed in `requirements.txt`

## Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/gubbriaco/fir-filter-analysis.git
    ```
2. Navigate to the repository:
    ```bash
    cd fir-filter-analysis
    ```
3. Install required Python packages:
    ```bash
    pip install -r requirements.txt
    ```

## Usage

To analyze or design an FIR filter using Xilinx HLS:
1. Open Xilinx Vivado HLS and import the project files from the `src/` directory.
2. Follow the instructions in individual scripts and documentation files for configuration and execution.
3. After synthesis, use the provided testbenches to validate functionality.

Refer to the `src/` directory for specific example scripts, and consult the `report/` folder for additional information on parameter tuning and optimization techniques.

## Reports

Detailed reports on FIR filter design, performance, and applications are available in the `report/` directory. These documents provide insights into filter theory, FPGA implementation details, and simulation results using Xilinx HLS.
