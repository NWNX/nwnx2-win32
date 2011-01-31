#ifndef _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_
#define _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_

struct CGameObject_VTable_s {
    void                       *destructor;                                                             /* 00 */
    int                       (*SetId)(void *, uint32_t);                                               /* 04 */
    int                       (*ResetUpdateTimes)(void *, uint32_t, uint32_t);                          /* 08 */
    void *                    (*AsNWCObject)(void *);                                                   /* 0C */
    CNWSObject *              (*AsNWSObject)(void *);                                                   /* 10 */
    void *                    (*AsNWCDoor)(void *);                                                     /* 14 */
    CNWSDoor *                (*AsNWSDoor)(void *);                                                     /* 18 */
    void *                    (*AsNWCModule)(void *);                                                   /* 1C */
    CNWSModule *              (*AsNWSModule)(void *);                                                   /* 20 */
    void *                    (*AsNWCArea)(void *);                                                     /* 24 */
    CNWSArea *                (*AsNWSArea)(void *);                                                     /* 28 */
    void *                    (*AsNWCCreature)(void *);                                                 /* 2C */
    CNWSCreature *            (*AsNWSCreature)(void *);                                                 /* 30 */
    void *                    (*AsNWCItem)(void *);                                                     /* 34 */
    CNWSItem *                (*AsNWSItem)(void *);                                                     /* 38 */
    void *                    (*AsNWCTrigger)(void *);                                                  /* 3C */
    CNWSTrigger *             (*AsNWSTrigger)(void *);                                                  /* 40 */
    void *                    (*AsNWCProjectile)(void *);                                               /* 44 */
    void *                    (*AsNWSPlayerTURD)(void *);                                               /* 48 */
    CNWSPlaceable *           (*AsNWSPlaceable)(void *);                                                /* 4C */
    void *                    (*AsNWCPlaceable)(void *);                                                /* 50 */
    CNWSAreaOfEffectObject *  (*AsNWSAreaOfEffectObject)(void *);                                       /* 54 */
    void *                    (*AsNWCAreaOfEffectObject)(void *);                                       /* 58 */
    CNWSWaypoint *            (*AsNWSWaypoint)(void *);                                                 /* 5C */
    CNWSEncounter *           (*AsNWSEncounter)(void *);                                                /* 60 */
    void *                    (*AsNWCStore)(void *);                                                    /* 64 */
    CNWSStore *               (*AsNWSStore)(void *);                                                    /* 68 */
    CNWSSoundObject *         (*AsNWSSoundObject)(void *);                                              /* 6C */
    void *                    (*AsNWCSoundObject)(void *);                                              /* 70 */
    int                       (*AIUpdate)(void *);                                                      /* 74 */
    int                       (*ClearAction)(void *, void *, int);                                      /* 78 */
    int                       (*EventHandler)(void *, uint32_t, uint32_t, void *, uint32_t, uint32_t);  /* 7C */
    int                       (*SetAnimation)(void *, int);                                             /* 80 */
    int                       (*GetDialogResref)(void *);                                               /* 84 */
    int                       (*GetDialogInterruptable)(void *);                                        /* 88 */
    int                       (*GetGender)(void *);                                                     /* 8C */
    int                       (*GetFirstName)(void *);                                                  /* 90 */
    int                       (*GetLastName)(void *);                                                   /* 94 */
    int                       (*GetMaxHitPoints)(void *, int);                                          /* 98 */
    int16_t                   (*GetCurrentHitPoints)(void *, int);                                      /* 9C */
    int                       (*DoDamage)(void *, int);                                                 /* A0 */
    int                       (*DoDamageReduction)(void *, void *, int, uint8_t, int, int);             /* A4 */
    int                       (*DoDamageResistance)(void *, void *, int, uint16_t, int, int, int);      /* A8 */
    int                       (*GetMaximumDamageResistanceVsDamageFlag)(void *, uint16_t, int *);       /* AC */
    int                       (*DoDamageImmunity)(void *, void *, int, uint16_t, int, int);             /* B0 */
    int                       (*GetDamageImmunity)(void *, uint8_t);                                    /* B4 */
    int                       (*GetDamageImmunityByFlags)(void *, uint16_t);                            /* B8 */
};

#endif /* _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_ */

/* vim: set sw=4: */
