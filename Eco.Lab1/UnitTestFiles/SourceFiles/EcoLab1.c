/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;

    uint16_t i    = 0;
    uint16_t n    = 0;
    int32_t*  arr;
    int64_t*  arrl;
    double_t* arrd;
    float_t*  arrf;
    


    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    n = 128;

    /* Выделение блока памяти */
    arr   = (int32_t *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(int32_t));
    arrl  = (int64_t *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(int64_t));
    arrd  = (double_t *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(double_t));
    arrf  = (float_t *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(float_t));

    /* Заполнение блока памяти */
    for (i = 0; i < n; ++i) {
      arr[i]  = n - i;
      arrl[i] = n - i;
      arrd[i] = (double_t)n - i;
      arrf[i] = (float_t)n - i;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIEcoLab1->pVTbl->QuickSort(pIEcoLab1, n, &arr);
    pIEcoLab1->pVTbl->QuickSortl(pIEcoLab1, n, &arrl);
    pIEcoLab1->pVTbl->QuickSortd(pIEcoLab1, n, &arrd);
    pIEcoLab1->pVTbl->QuickSortf(pIEcoLab1, n, &arrf);
  
    for(i = 0; i < n; ++i) {
        if (arr[i]  != i + 1            || arrl[i] != i + 1 ||
            arrd[i] != (double_t) i + 1 || arrf[i] != (float_t) i + 1)
        {
          printf("Incorrect result !");
          break;
        }
    }

    /* Освлбождение блока памяти */
    pIMem->pVTbl->Free(pIMem, arr);
    pIMem->pVTbl->Free(pIMem, arrl);
    pIMem->pVTbl->Free(pIMem, arrd);
    pIMem->pVTbl->Free(pIMem, arrf);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

