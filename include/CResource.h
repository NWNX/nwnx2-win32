#ifndef _NX_NWN_STRUCT_CRESOURCE_
#define _NX_NWN_STRUCT_CRESOURCE_ 

struct CResource_s {
    unsigned __int32            field_00;
    unsigned __int8             id1;
    unsigned __int8             id2;
    unsigned __int8             id3;
    unsigned __int8             id4;
    unsigned __int32            field_08;

    void               *res_data;
    void               *res_name;
    unsigned __int32            res_size;
    unsigned __int32            res_loaded;

    unsigned __int32            field_1C;
    unsigned __int32            field_20;

    void               *res_list;
    void               *res_class;

    unsigned __int32            res_loaded_2;
    unsigned __int32            res_size_2;
    void               *res_data_2;
};

#endif