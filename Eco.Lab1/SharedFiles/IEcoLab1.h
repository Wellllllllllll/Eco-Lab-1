/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLab1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOLAB1_H__
#define __I_ECOLAB1_H__

#include "IEcoBase1.h"

/* IEcoLab1 IID = {277FC00C-3562-4096-AFCF-C125B94EEC90} */
#ifndef __IID_IEcoLab1
static const UGUID IID_IEcoLab1 = {0x01, 0x10, 0x27, 0x7F, 0xC0, 0x0C, 0x35, 0x62, 0x40, 0x96, 0xAF, 0xCF, 0xC1, 0x25, 0xB9, 0x4E, 0xEC, 0x90};
#endif /* __IID_IEcoLab1 */

typedef struct IEcoLab1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IEcoLab1* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IEcoLab1* me);

    /* IEcoLab1 */
    void    (ECOCALLMETHOD *QuickSort )(/* in */ struct IEcoLab1* me, /* in */ uint32_t n, /* in | out */ int32_t** arr);
    void    (ECOCALLMETHOD *QuickSortl)(/* in */ struct IEcoLab1* me, /* in */ uint32_t n, /* in | out */ int64_t** arr);
    void    (ECOCALLMETHOD *QuickSortd)(/* in */ struct IEcoLab1* me, /* in */ uint32_t n, /* in | out */ double_t** arr);
    void    (ECOCALLMETHOD *QuickSortf)(/* in */ struct IEcoLab1* me, /* in */ uint32_t n, /* in | out */ float_t** arr);

    /* IEcoLab1 Private methods */
    int32_t (ECOCALLMETHOD *__partition )(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in */ int32_t* arr);
    int32_t (ECOCALLMETHOD *__partitionl)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in */ int64_t* arr);
    int32_t (ECOCALLMETHOD *__partitiond)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in */ double_t* arr);
    int32_t (ECOCALLMETHOD *__partitionf)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in */ float_t* arr);

    void    (ECOCALLMETHOD *__quickSort )(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int32_t* arr);
    void    (ECOCALLMETHOD *__quickSortl)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int64_t* arr);
    void    (ECOCALLMETHOD *__quickSortd)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ double_t* arr);
    void    (ECOCALLMETHOD *__quickSortf)(/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ float_t* arr);

} IEcoLab1VTbl, *IEcoLab1VTblPtr;

interface IEcoLab1 {
    struct IEcoLab1VTbl *pVTbl;
} IEcoLab1;


#endif /* __I_ECOLAB1_H__ */
