#ifndef _NX_NWN_STRUCT_CGAMEEFFECT_
#define _NX_NWN_STRUCT_CGAMEEFFECT_

struct CGameEffect_s {
    uint32_t            eff_id;                 /* 00 */
    uint32_t            eff_id_02;              /* 04 */

    uint16_t            eff_type;               /* 08 */
    uint16_t            eff_dursubtype;         /* 0A */

    float               eff_duration;           /* 0C */

    uint32_t            eff_expire_day;         /* 10 */
    uint32_t            eff_expire_time;        /* 14 */

    nwn_objid_t         eff_creator;            /* 18 */
    int32_t             eff_spellid;            /* 1C */

    uint32_t            eff_is_exposed;         /* 20 */
    uint32_t            eff_is_iconshown;       /* 24 */

    uint32_t            field_28;               /* 28 */

    CGameEffect         *eff_link_id1;          /* 2C */
    CGameEffect         *eff_link_id2;          /* 30 */

    uint32_t            eff_num_integers;       /* 34 */
    int32_t            *eff_integers;           /* 38 */

    float               eff_floats[4];          /* 3C */
    CExoString          eff_strings[6];         /* 40 */
    nwn_objid_t         eff_objects[4];         /* 44 */

    uint32_t            eff_skiponload;         /* 48 */

	int	GetScriptEffectType();
};

#endif