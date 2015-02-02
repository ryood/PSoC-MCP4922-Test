/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    SPIM_Start();
    
    for(;;)
    {
        int i = 4096 / 2;
        
        /* Place your application code here. */
        LDAC_Pin_Write(1u);
        SPIM_SpiUartWriteTxData((i >> 8) | 0x30);
        SPIM_SpiUartWriteTxData(i & 0xff);
        LDAC_Pin_Write(0u);
        
        while(0u == (SPIM_GetMasterInterruptSource() & SPIM_INTR_MASTER_SPI_DONE))
        {
            /* Wait while Master completes transfer */
        }
    
        /* Clear interrupt source after transfer completion */
        SPIM_ClearMasterInterruptSource(SPIM_INTR_MASTER_SPI_DONE);
    }
}

/* [] END OF FILE */
