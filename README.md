# Square_Generation

The generation of a square pattern displayed via HDMI, using the PYNQ-Z1 FPGA development board. The system was designed and implemented using the Xilinx Vivado Design Suite and outputs a square video pattern to a connected HDMI display.

### Key Features:

##### 1. HDMI Display Output: 
The project generates and outputs a square pattern directly to a display via HDMI, showcasing real-time video generation capabilities.

##### 2.FPGA Platform: 
Built and tested on the PYNQ-Z1 FPGA kit.

##### 3. Vivado Design Suite: 
Engineered using the Vivado toolset, enabling the design, simulation, and verification of the FPGA-based system.

### System Components:

##### 1. ZYNQ Processing System: 
Controls and manages the overall system, responsible for generating the square pattern.

##### 2. AXI Interconnect: 
Facilitates communication between the processing system and peripherals for video output.

##### 3. HDMI Output: 
Transmits the generated square pattern to the HDMI display.

##### 4. Video Timing Controller: 
Ensures the square pattern is generated in sync with the display's frame timing.

##### 5. AXI Stream to Video Out: 
Converts the AXI stream data into HDMI-compatible video output.
