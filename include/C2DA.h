struct C2DA_s {
    unsigned __int32            field_00;

    CResource          *tda_resource;
    char                tda_name[16];
    void               *tda_class;

    unsigned __int32            field_1C;
    unsigned __int32            field_20;

    CExoString         *tda_ids;
    CExoString         *tda_cols;
    CExoString        **tda_rows;

    int             tda_rows_len;
    int             tda_cols_len;

    unsigned __int32            field_38;
};
