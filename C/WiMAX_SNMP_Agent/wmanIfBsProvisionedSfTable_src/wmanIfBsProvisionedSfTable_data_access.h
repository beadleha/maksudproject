/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef WMANIFBSPROVISIONEDSFTABLE_DATA_ACCESS_H
#define WMANIFBSPROVISIONEDSFTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern          "C" {
#endif


    /*
     *********************************************************************
     * function declarations
     */

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table wmanIfBsProvisionedSfTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * WMAN-IF-MIB::wmanIfBsProvisionedSfTable is subid 1 of wmanIfBsPacketCs.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.10.184.1.1.1.1, length: 12
     */


    int            
        wmanIfBsProvisionedSfTable_init_data
        (wmanIfBsProvisionedSfTable_registration *
         wmanIfBsProvisionedSfTable_reg);


    void           
        wmanIfBsProvisionedSfTable_container_init(netsnmp_container **
                                                  container_ptr_ptr);
    void           
        wmanIfBsProvisionedSfTable_container_shutdown(netsnmp_container *
                                                      container_ptr);

    int            
        wmanIfBsProvisionedSfTable_container_load(netsnmp_container *
                                                  container);
    void           
        wmanIfBsProvisionedSfTable_container_free(netsnmp_container *
                                                  container);

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     *********************************************************************
     * Since we have no idea how you really access your data, we'll go with
     * a worst case example: a flat text file.
     */
#define MAX_LINE_SIZE 256
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/
    int            
        wmanIfBsProvisionedSfTable_row_prep
        (wmanIfBsProvisionedSfTable_rowreq_ctx * rowreq_ctx);

    int            
        wmanIfBsProvisionedSfTable_validate_index
        (wmanIfBsProvisionedSfTable_registration *
         wmanIfBsProvisionedSfTable_reg,
         wmanIfBsProvisionedSfTable_rowreq_ctx * rowreq_ctx);
    int             wmanIfBsProvisionedSfTable_ifIndex_check_index(wmanIfBsProvisionedSfTable_rowreq_ctx * rowreq_ctx); /* external */
    int             wmanIfBsSfId_check_index(wmanIfBsProvisionedSfTable_rowreq_ctx * rowreq_ctx);       /* internal */


#ifdef __cplusplus
}
#endif
#endif                          /* WMANIFBSPROVISIONEDSFTABLE_DATA_ACCESS_H */