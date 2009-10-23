/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
/*
 * standard Net-SNMP includes
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header
 */
#include "wmanIfBsRegisteredSsTable.h"


#include "wmanIfBsRegisteredSsTable_data_access.h"

/** @ingroup interface
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table wmanIfBsRegisteredSsTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * WMAN-IF-MIB::wmanIfBsRegisteredSsTable is subid 1 of wmanIfBsCps.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.10.184.1.1.2.1, length: 12
 */

/**
 * initialization for wmanIfBsRegisteredSsTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param wmanIfBsRegisteredSsTable_reg
 *        Pointer to wmanIfBsRegisteredSsTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
wmanIfBsRegisteredSsTable_init_data(wmanIfBsRegisteredSsTable_registration
                                    * wmanIfBsRegisteredSsTable_reg)
{
    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_init_data", "called\n"));

    /*
     * TODO:303:o: Initialize wmanIfBsRegisteredSsTable data.
     */
	char *mac[] = { "ABCDE", "FGHIJ", "KLMNO", "12345", "asdfg" };
	int kk;
	for(kk=0; kk<MY_ROW_SIZE; kk++)
	{
		//Indices
		index_tmp[kk].ifIndex = 2;
		strcpy(index_tmp[kk].wmanIfBsSsMacAddress, mac[kk]);
		index_tmp[kk].wmanIfBsSsMacAddress_len = 5;

		//Data portions
		data_tmp[kk].wmanIfBsSsMacVersion = kk;
		data_tmp[kk].wmanIfBsSs2ndMgmtArqBlockLifetime = 100*kk;
	}

    return MFD_SUCCESS;
}                               /* wmanIfBsRegisteredSsTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
wmanIfBsRegisteredSsTable_container_init(netsnmp_container **
                                         container_ptr_ptr,
                                         netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_container_init", "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to wmanIfBsRegisteredSsTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    //*container_ptr_ptr = NULL;
    *container_ptr_ptr = netsnmp_container_find("wmanIfBsRegisteredSsTable:table_container");
    wmanIfBsRegisteredSsTable_container_load(*container_ptr_ptr);



    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to wmanIfBsRegisteredSsTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up wmanIfBsRegisteredSsTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = WMANIFBSREGISTEREDSSTABLE_CACHE_TIMEOUT;   /* seconds */
}                               /* wmanIfBsRegisteredSsTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before wmanIfBsRegisteredSsTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
wmanIfBsRegisteredSsTable_container_shutdown(netsnmp_container *
                                             container_ptr)
{
    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to wmanIfBsRegisteredSsTable_container_shutdown\n");
        return;
    }

}                               /* wmanIfBsRegisteredSsTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement wmanIfBsRegisteredSsTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  wmanIfBsRegisteredSsTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
wmanIfBsRegisteredSsTable_container_load(netsnmp_container * container)
{
    wmanIfBsRegisteredSsTable_rowreq_ctx *rowreq_ctx;
    size_t          count = 0;

    /*
     * temporary storage for index values
     */
    /*
     * ifIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
     */
    long            ifIndex;
    /*
     * wmanIfBsSsMacAddress(1)/MacAddress/ASN_OCTET_STR/char(char)//L/a/w/e/R/d/H
     */
    char            wmanIfBsSsMacAddress[6];
    size_t          wmanIfBsSsMacAddress_len;


    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_container_load", "called\n"));


    printf("\n\nWHY\n\n");

    /*
     * TODO:351:M: |-> Load/update data in the wmanIfBsRegisteredSsTable container.
     * loop over your wmanIfBsRegisteredSsTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */


    int kk2;
    for(kk2=0; kk2<MY_ROW_SIZE; kk2++)
    {
    	rowreq_ctx = wmanIfBsRegisteredSsTable_allocate_rowreq_ctx(NULL);
		if (NULL == rowreq_ctx) {
			snmp_log(LOG_ERR, "memory allocation failed\n");
			return MFD_RESOURCE_UNAVAILABLE;
		}
		if (MFD_SUCCESS !=
			wmanIfBsRegisteredSsTable_indexes_set(rowreq_ctx, index_tmp[kk2].ifIndex,
					index_tmp[kk2].wmanIfBsSsMacAddress,
												  6))
		{
			snmp_log(LOG_ERR,
					 "error setting index while loading "
					 "wmanIfBsRegisteredSsTable data.\n");
			wmanIfBsRegisteredSsTable_release_rowreq_ctx(rowreq_ctx);
			continue;
		}

		rowreq_ctx->data.wmanIfBsSs2ndMgmtArqBlockLifetime = data_tmp[kk2].wmanIfBsSs2ndMgmtArqBlockLifetime;
		rowreq_ctx->data.wmanIfBsSsMacVersion = data_tmp[kk2].wmanIfBsSsMacVersion;

		CONTAINER_INSERT(container, rowreq_ctx);
    }
    printf("\n\nWHY2\n\n");

//    while (1) {
//
//        /*
//         * TODO:352:M: |   |-> set indexes in new wmanIfBsRegisteredSsTable rowreq context.
//         * data context will be set from the param (unless NULL,
//         *      in which case a new data context will be allocated)
//         */
//        rowreq_ctx = wmanIfBsRegisteredSsTable_allocate_rowreq_ctx(NULL);
//        if (NULL == rowreq_ctx) {
//            snmp_log(LOG_ERR, "memory allocation failed\n");
//            return MFD_RESOURCE_UNAVAILABLE;
//        }
//        if (MFD_SUCCESS !=
//            wmanIfBsRegisteredSsTable_indexes_set(rowreq_ctx, ifIndex,
//                                                  wmanIfBsSsMacAddress,
//                                                  wmanIfBsSsMacAddress_len))
//        {
//            snmp_log(LOG_ERR,
//                     "error setting index while loading "
//                     "wmanIfBsRegisteredSsTable data.\n");
//            wmanIfBsRegisteredSsTable_release_rowreq_ctx(rowreq_ctx);
//            continue;
//        }
//
//        /*
//         * TODO:352:r: |   |-> populate wmanIfBsRegisteredSsTable data context.
//         * Populate data context here. (optionally, delay until row prep)
//         */
//        /*
//         * TRANSIENT or semi-TRANSIENT data:
//         * copy data or save any info needed to do it in row_prep.
//         */
//        /*
//         * setup/save data for wmanIfBsSsBasicCid
//         * wmanIfBsSsBasicCid(2)/WmanIfCidType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsBasicCid = wmanIfBsSsBasicCid;
//
//        /*
//         * setup/save data for wmanIfBsSsPrimaryCid
//         * wmanIfBsSsPrimaryCid(3)/WmanIfCidType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsPrimaryCid = wmanIfBsSsPrimaryCid;
//
//        /*
//         * setup/save data for wmanIfBsSsSecondaryCid
//         * wmanIfBsSsSecondaryCid(4)/WmanIfCidType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsSecondaryCid = wmanIfBsSsSecondaryCid;
//
//        /*
//         * setup/save data for wmanIfBsSsManagementSupport
//         * wmanIfBsSsManagementSupport(5)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsManagementSupport =
//            wmanIfBsSsManagementSupport;
//
//        /*
//         * setup/save data for wmanIfBsSsIpManagementMode
//         * wmanIfBsSsIpManagementMode(6)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsIpManagementMode =
//            wmanIfBsSsIpManagementMode;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqEnable
//         * wmanIfBsSs2ndMgmtArqEnable(7)/TruthValue/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqEnable =
//            wmanIfBsSs2ndMgmtArqEnable;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqWindowSize
//         * wmanIfBsSs2ndMgmtArqWindowSize(8)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqWindowSize =
//            wmanIfBsSs2ndMgmtArqWindowSize;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqDnLinkTxDelay
//         * wmanIfBsSs2ndMgmtArqDnLinkTxDelay(9)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqDnLinkTxDelay =
//            wmanIfBsSs2ndMgmtArqDnLinkTxDelay;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqUpLinkTxDelay
//         * wmanIfBsSs2ndMgmtArqUpLinkTxDelay(10)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqUpLinkTxDelay =
//            wmanIfBsSs2ndMgmtArqUpLinkTxDelay;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqDnLinkRxDelay
//         * wmanIfBsSs2ndMgmtArqDnLinkRxDelay(11)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqDnLinkRxDelay =
//            wmanIfBsSs2ndMgmtArqDnLinkRxDelay;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqUpLinkRxDelay
//         * wmanIfBsSs2ndMgmtArqUpLinkRxDelay(12)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqUpLinkRxDelay =
//            wmanIfBsSs2ndMgmtArqUpLinkRxDelay;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqBlockLifetime
//         * wmanIfBsSs2ndMgmtArqBlockLifetime(13)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/D/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqBlockLifetime =
//            wmanIfBsSs2ndMgmtArqBlockLifetime;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqSyncLossTimeout
//         * wmanIfBsSs2ndMgmtArqSyncLossTimeout(14)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/D/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqSyncLossTimeout =
//            wmanIfBsSs2ndMgmtArqSyncLossTimeout;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqDeliverInOrder
//         * wmanIfBsSs2ndMgmtArqDeliverInOrder(15)/TruthValue/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqDeliverInOrder =
//            wmanIfBsSs2ndMgmtArqDeliverInOrder;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqRxPurgeTimeout
//         * wmanIfBsSs2ndMgmtArqRxPurgeTimeout(16)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/D/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqRxPurgeTimeout =
//            wmanIfBsSs2ndMgmtArqRxPurgeTimeout;
//
//        /*
//         * setup/save data for wmanIfBsSs2ndMgmtArqBlockSize
//         * wmanIfBsSs2ndMgmtArqBlockSize(17)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSs2ndMgmtArqBlockSize =
//            wmanIfBsSs2ndMgmtArqBlockSize;
//
//        /*
//         * setup/save data for wmanIfBsSsVendorIdEncoding
//         * wmanIfBsSsVendorIdEncoding(18)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/h
//         */
//    /** no mapping */
//        /*
//         * make sure there is enough space for wmanIfBsSsVendorIdEncoding data
//         */
//        if ((NULL == rowreq_ctx->data.wmanIfBsSsVendorIdEncoding) ||
//            (rowreq_ctx->data.wmanIfBsSsVendorIdEncoding_len <
//             (wmanIfBsSsVendorIdEncoding_len *
//              sizeof(wmanIfBsSsVendorIdEncoding[0])))) {
//            snmp_log(LOG_ERR, "not enough space for value\n");
//            return MFD_ERROR;
//        }
//        rowreq_ctx->data.wmanIfBsSsVendorIdEncoding_len =
//            wmanIfBsSsVendorIdEncoding_len *
//            sizeof(wmanIfBsSsVendorIdEncoding[0]);
//        memcpy(rowreq_ctx->data.wmanIfBsSsVendorIdEncoding,
//               wmanIfBsSsVendorIdEncoding,
//               wmanIfBsSsVendorIdEncoding_len *
//               sizeof(wmanIfBsSsVendorIdEncoding[0]));
//
//        /*
//         * setup/save data for wmanIfBsSsAasBroadcastPermission
//         * wmanIfBsSsAasBroadcastPermission(19)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsAasBroadcastPermission =
//            wmanIfBsSsAasBroadcastPermission;
//
//        /*
//         * setup/save data for wmanIfBsSsMaxTxPowerBpsk
//         * wmanIfBsSsMaxTxPowerBpsk(20)/WmanIfMaxTxPowerType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsMaxTxPowerBpsk =
//            wmanIfBsSsMaxTxPowerBpsk;
//
//        /*
//         * setup/save data for wmanIfBsSsMaxTxPowerQpsk
//         * wmanIfBsSsMaxTxPowerQpsk(21)/WmanIfMaxTxPowerType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsMaxTxPowerQpsk =
//            wmanIfBsSsMaxTxPowerQpsk;
//
//        /*
//         * setup/save data for wmanIfBsSsMaxTxPower16Qam
//         * wmanIfBsSsMaxTxPower16Qam(22)/WmanIfMaxTxPowerType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsMaxTxPower16Qam =
//            wmanIfBsSsMaxTxPower16Qam;
//
//        /*
//         * setup/save data for wmanIfBsSsMaxTxPower64Qam
//         * wmanIfBsSsMaxTxPower64Qam(23)/WmanIfMaxTxPowerType/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsMaxTxPower64Qam =
//            wmanIfBsSsMaxTxPower64Qam;
//
//        /*
//         * setup/save data for wmanIfBsSsMacVersion
//         * wmanIfBsSsMacVersion(24)/WmanIfMacVersion/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
//         */
//    /** no mapping */
//        rowreq_ctx->data.wmanIfBsSsMacVersion = wmanIfBsSsMacVersion;
//
//
//        /*
//         * insert into table container
//         */
//        CONTAINER_INSERT(container, rowreq_ctx);
//        ++count;
//    }


    DEBUGMSGT(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_container_load", "inserted %d records\n", kk2));

    return MFD_SUCCESS;
}                               /* wmanIfBsRegisteredSsTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
wmanIfBsRegisteredSsTable_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_container_free", "called\n"));

    /*
     * TODO:380:M: Free wmanIfBsRegisteredSsTable container data.
     */
}                               /* wmanIfBsRegisteredSsTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
wmanIfBsRegisteredSsTable_row_prep(wmanIfBsRegisteredSsTable_rowreq_ctx *
                                   rowreq_ctx)
{
    DEBUGMSGTL(("verbose:wmanIfBsRegisteredSsTable:wmanIfBsRegisteredSsTable_row_prep", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */


    //rowreq_ctx->data.wmanIfBsSs2ndMgmtArqBlockLifetime = rowreq_ctx->ata_tmp[rowreq_ctx->tbl_idx.mibtestIndex];
    //rowreq_ctx->data.mibtestColumn2 = mibtestColumn2_cache[rowreq_ctx->tbl_idx.mibtestIndex];

    return MFD_SUCCESS;
}                               /* wmanIfBsRegisteredSsTable_row_prep */

/** @} */