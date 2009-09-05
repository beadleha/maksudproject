/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c 12526 2005-07-15 22:41:16Z rstory $
 *
 * $Id:$
 */
#ifndef WMANIFBSREGISTEREDSSTABLE_ENUMS_H
#define WMANIFBSREGISTEREDSSTABLE_ENUMS_H

#ifdef __cplusplus
extern          "C" {
#endif

    /*
     * NOTES on enums
     * ==============
     *
     * Value Mapping
     * -------------
     * If the values for your data type don't exactly match the
     * possible values defined by the mib, you should map them
     * below. For example, a boolean flag (1/0) is usually represented
     * as a TruthValue in a MIB, which maps to the values (1/2).
     *
     */
/*************************************************************************
 *************************************************************************
 *
 * enum definitions for table wmanIfBsRegisteredSsTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSsManagementSupport (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef WMANIFBSSSMANAGEMENTSUPPORT_ENUMS
#define WMANIFBSSSMANAGEMENTSUPPORT_ENUMS

#define WMANIFBSSSMANAGEMENTSUPPORT_UNMANAGEDSS  0
#define WMANIFBSSSMANAGEMENTSUPPORT_MANAGEDSS  1

#endif                          /* WMANIFBSSSMANAGEMENTSUPPORT_ENUMS */


/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSsIpManagementMode (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef WMANIFBSSSIPMANAGEMENTMODE_ENUMS
#define WMANIFBSSSIPMANAGEMENTMODE_ENUMS

#define WMANIFBSSSIPMANAGEMENTMODE_UNMANAGED  0
#define WMANIFBSSSIPMANAGEMENTMODE_IPMANAGED  1

#endif                          /* WMANIFBSSSIPMANAGEMENTMODE_ENUMS */


/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSs2ndMgmtArqEnable (TruthValue / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef TRUTHVALUE_ENUMS
#define TRUTHVALUE_ENUMS

#define TRUTHVALUE_TRUE  1
#define TRUTHVALUE_FALSE  2

#endif                          /* TRUTHVALUE_ENUMS */


/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSs2ndMgmtArqDeliverInOrder (TruthValue / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef TRUTHVALUE_ENUMS
#define TRUTHVALUE_ENUMS

#define TRUTHVALUE_TRUE  1
#define TRUTHVALUE_FALSE  2

#endif                          /* TRUTHVALUE_ENUMS */


/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSsAasBroadcastPermission (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef WMANIFBSSSAASBROADCASTPERMISSION_ENUMS
#define WMANIFBSSSAASBROADCASTPERMISSION_ENUMS

#define WMANIFBSSSAASBROADCASTPERMISSION_CONTBASEDBWREQPERMITTED  0
#define WMANIFBSSSAASBROADCASTPERMISSION_CONTBASEDBWREQNOTPERMITTED  1

#endif                          /* WMANIFBSSSAASBROADCASTPERMISSION_ENUMS */


/*************************************************************
 * constants for enums for the MIB node
 * wmanIfBsSsMacVersion (WmanIfMacVersion / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef WMANIFMACVERSION_ENUMS
#define WMANIFMACVERSION_ENUMS

#define WMANIFMACVERSION_IEEE802DOT16OF2001  1
#define WMANIFMACVERSION_IEEE802DOT16COF2002  2
#define WMANIFMACVERSION_IEEE802DOT16AOF2003  3
#define WMANIFMACVERSION_IEEE802DOT16OF2004  4

#endif                          /* WMANIFMACVERSION_ENUMS */




#ifdef __cplusplus
}
#endif
#endif                          /* WMANIFBSREGISTEREDSSTABLE_ENUMS_H */