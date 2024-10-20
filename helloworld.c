#include <stdio.h>
#include "platform.h"
#include "xvideo_pattern_generator.h"
#include "xil_assert.h"

int main()
{
    XVideo_pattern_generator ptpg;
    XVideo_pattern_generator_Config *ptpg_config;

    init_platform();
    ptpg_config =  XVideo_pattern_generator_LookupConfig(XPAR_VIDEO_PATTERN_GENERA_0_DEVICE_ID);
    XVideo_pattern_generator_CfgInitialize(&ptpg, ptpg_config);

    xil_printf("TPG Initialization\r\n");

    u32 status;

    status = XVideo_pattern_generator_IsReady(&ptpg);
    xil_printf("Status %u \n\r", (unsigned int) status);

    status = XVideo_pattern_generator_IsIdle(&ptpg);
    xil_printf("Status %u \n\r", (unsigned int) status);

    xil_printf("Status %x \n\r", (unsigned int) status);

    XVideo_pattern_generator_EnableAutoRestart(&ptpg);

    XVideo_pattern_generator_Start(&ptpg);

    status = XVideo_pattern_generator_IsIdle(&ptpg);
    xil_printf("Status %u \n\r", (unsigned int) status);

    return 0;
}
