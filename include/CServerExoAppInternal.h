/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_
#define _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_

struct CServerExoAppInternal_s {
    uint32_t                   unknown[16384];

    void                       *vtable;                 /* 10000 (AppManager +0x20) */

    uint32_t                   field_10004;            /* 10004 */
    uint32_t                   field_10008;            /* 10008 */
    uint32_t                   *ServerInfo;            /* 1000C */
    uint32_t                   field_10010;            /* 10010 */
    uint32_t                   field_10014;            /* 10014 */

    CNWSMessage                *srv_client_messages;    /* 10018 */
    uint32_t                   srv_client_update;      /* 1001C */

    nwn_objid_t                *srv_player_list;        /* 10020 */

    uint32_t                   field_10024;            /* 10024 */
    uint32_t                   field_10028;            /* 10028 */

    CExoArrayList_uint32       *field_1002C;            /* 1002C */

    uint32_t                   field_10030;            /* 10030 */
    uint32_t                   field_10034;            /* 10034 */
    uint32_t                   field_10038;            /* 10038 */
    uint32_t                   field_1003C;            /* 1003C */
    uint32_t                   field_10040;            /* 10040 */
    uint32_t                   field_10044;            /* 10044 */
    uint32_t                   field_10048;            /* 10048 */
    uint32_t                   field_1004C;            /* 1004C */
    uint32_t                   field_10050;            /* 10050 */

    CExoString                 *field_10054;            /* 10054 */

    uint32_t                   field_10058;            /* 10058 */
    uint32_t                   field_1005C;            /* 1005C */

    CNetLayer                  *srv_network;            /* 10060 */ 

    CServerAIMaster            *srv_ai;                 /* 10064 */ 

    CWorldTimer                *srv_time_world;         /* 10068 */
    CWorldTimer                *srv_time_timestop;      /* 1006C */
    CWorldTimer                *srv_time_pause;         /* 10070 */ 

    CFactionManager				*srv_factions;           /* 10074 */

    uint32_t                   field_10078;            /* 10078 */
    uint32_t                   field_1007C;            /* 1007C */

    CGameObjectArray           *srv_objects;            /* 10080 */
    nwn_objid_t                 srv_obj_module;         /* 10084 */

    CExoLinkedList             *srv_client_list_1;      /* 10088 */
    CExoLinkedList             *srv_client_list_2;      /* 1008C */

    uint32_t                   field_10090;            /* 10090 */
    uint32_t                   field_10094;            /* 10094 */

    CExoLinkedList             *field_10098;            /* 10098 */
    CExoLinkedList             *field_1009C;            /* 1009C */

    uint32_t                   field_100A0;            /* 100A0 */
    uint32_t                   field_100A4;            /* 100A4 */
    uint32_t                   field_100A8;            /* 100A8 */

    CExoString                 *field_100AC;            /* 100AC */

    uint32_t                   field_100B0;            /* 100B0 */
    uint32_t                   field_100B4;            /* 100B4 */

    CExoString                 *field_100B8;            /* 100B8 */

    uint32_t                   field_100BC;            /* 100BC */
    uint32_t                   field_100C0;            /* 100C0 */
    uint32_t                   field_100C4;            /* 100C4 */
    uint32_t                   field_100C8;            /* 100C8 */
    uint32_t                   field_100CC;            /* 100CC */
    uint32_t                   srv_pc_export_pending;  /* 100D0 */
    uint32_t                   field_100D4;            /* 100D4 */
    uint32_t                   field_100D8;            /* 100D8 */
    uint32_t                   field_100DC;            /* 100DC */
    uint32_t                   field_100E0;            /* 100E0 */
    uint32_t                   field_100E4;            /* 100E4 */
    uint32_t                   field_100E8;            /* 100E8 */
    uint32_t                   field_100EC;            /* 100EC */

    CExoArrayList_uint32       *field_100F0;            /* 100F0 */

    CExoArrayList_ptr          *field_100FC;            /* 100FC (CExoString) */
    CExoArrayList_ptr          *field_10108;            /* 10108 (CExoString) */
    CExoArrayList_ptr          *field_10114;            /* 10114 (CExoString) */

    uint32_t                   field_10120;            /* 10120 */
    uint32_t                   field_10124;            /* 10124 */
    uint32_t                   field_10128;            /* 10128 */
    uint32_t                   field_1012C;            /* 1012C */

    CExoArrayList_ptr          *field_10130;            /* 10130 (SSubNetProfile *) */

    uint32_t                   field_1013C;            /* 1013C */
    uint32_t                   field_10140;            /* 10140 */
    uint32_t                   field_10144;            /* 10144 */
    uint32_t                   field_10148;            /* 10148 */
    uint32_t                   field_1014C;            /* 1014C */
    uint32_t                   field_10150;            /* 10150 */
    uint32_t                   field_10154;            /* 10154 */
    uint32_t                   field_10158;            /* 10158 */
};

#endif /* _NX_NWN_STRUCT_CSERVEREXOAPPINTERNAL_ */

/* vim: set sw=4: */
