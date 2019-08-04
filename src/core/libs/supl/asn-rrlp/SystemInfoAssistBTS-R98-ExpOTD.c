/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 * 	found in "../rrlp-components.asn"
 */

#include "SystemInfoAssistBTS-R98-ExpOTD.h"

static asn_per_constraints_t ASN_PER_TYPE_SYSTEM_INFO_ASSIST_BTS_R98_EXP_OTD_CONSTR_1 = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_SystemInfoAssistBTS_R98_ExpOTD_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SystemInfoAssistBTS_R98_ExpOTD, choice.notPresent),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"notPresent"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SystemInfoAssistBTS_R98_ExpOTD, choice.present),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AssistBTSData_R98_ExpOTD,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"present"
		},
};
static asn_TYPE_tag2member_t asn_MAP_SystemInfoAssistBTS_R98_ExpOTD_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* notPresent at 927 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* present at 929 */
};
static asn_CHOICE_specifics_t asn_SPC_SystemInfoAssistBTS_R98_ExpOTD_specs_1 = {
	sizeof(struct SystemInfoAssistBTS_R98_ExpOTD),
	offsetof(struct SystemInfoAssistBTS_R98_ExpOTD, _asn_ctx),
	offsetof(struct SystemInfoAssistBTS_R98_ExpOTD, present),
	sizeof(((struct SystemInfoAssistBTS_R98_ExpOTD *)0)->present),
	asn_MAP_SystemInfoAssistBTS_R98_ExpOTD_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_SystemInfoAssistBTS_R98_ExpOTD = {
	"SystemInfoAssistBTS-R98-ExpOTD",
	"SystemInfoAssistBTS-R98-ExpOTD",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&ASN_PER_TYPE_SYSTEM_INFO_ASSIST_BTS_R98_EXP_OTD_CONSTR_1,
	asn_MBR_SystemInfoAssistBTS_R98_ExpOTD_1,
	2,	/* Elements count */
	&asn_SPC_SystemInfoAssistBTS_R98_ExpOTD_specs_1	/* Additional specs */
};

