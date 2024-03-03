/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция QuickSort
 * </сводка>
 *
 * <описание>
 *   Функция - декоратор для вызова приватной функций быстрой сортировки для дефолтного типа данных (int32_t).
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1_QuickSort (/* in */ struct IEcoLab1* me, /* in */ int32_t n, /* in | out */ int32_t** arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe->m_pVTblIEcoLab1->__quickSort(me, 0, n - 1, *arr);
    pCMe->m_pVTblIEcoLab1->Release(pCMe);
}

/*
 *
 * <сводка>
 *   Функция QuickSortl
 * </сводка>
 *
 * <описание>
 *   Функция - декоратор для вызова приватной функций быстрой сортировки для типа данных int64_t.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1_QuickSortl (/* in */ struct IEcoLab1* me, /* in */ int32_t n, /* in | out */ int64_t** arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe->m_pVTblIEcoLab1->__quickSortl(me, 0, n - 1, *arr);
    pCMe->m_pVTblIEcoLab1->Release(pCMe);
}

/*
 *
 * <сводка>
 *   Функция QuickSortd
 * </сводка>
 *
 * <описание>
 *   Функция - декоратор для вызова приватной функций быстрой сортировки для типа данных double_t.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1_QuickSortd (/* in */ struct IEcoLab1* me, /* in */ int32_t n, /* in | out */ double_t** arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe->m_pVTblIEcoLab1->__quickSortd(me, 0, n - 1, *arr);
    pCMe->m_pVTblIEcoLab1->Release(pCMe);
}

/*
 *
 * <сводка>
 *   Функция QuickSortf
 * </сводка>
 *
 * <описание>
 *   Функция - декоратор для вызова приватной функций быстрой сортировки для типа данных flot_t.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1_QuickSortf (/* in */ struct IEcoLab1* me, /* in */ int32_t n, /* in | out */ float_t** arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe->m_pVTblIEcoLab1->__quickSortf(me, 0, n - 1, *arr);
    pCMe->m_pVTblIEcoLab1->Release(pCMe);
}

/*
 *
 * <сводка>
 *   Функция __partition
 * </сводка>
 *
 * <описание>
 *   Приватная функция, которая берёт значение pivot (последний элемент массива),
 *   находит элементы, которые меньше и больше, чем pivot, кладёт их слева и справа соответсвенно.
 *   Возвращает индекс, под которым находится pivot.
 * </описание>
 *
 */
int64_t ECOCALLMETHOD CEcoLab1___partition (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int32_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    int64_t i, j;
    int32_t pivot, temp;

    pivot = arr[r];
    i = l - 1;

    for (j = l; j < r; ++j) {
      if (arr[j] <= pivot) {
        ++i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    ++i;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

/*
 *
 * <сводка>
 *   Функция __partitionl (для int64_t)
 * </сводка>
 *
 * <описание>
 *   Приватная функция, которая берёт значение pivot (последний элемент массива),
 *   находит элементы, которые меньше и больше, чем pivot, кладёт их слева и справа соответсвенно.
 *   Возвращает индекс, под которым находится pivot.
 * </описание>
 *
 */
int64_t ECOCALLMETHOD CEcoLab1___partitionl (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int64_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    int64_t i, j;
    int32_t pivot;
    int64_t temp;

    pivot = arr[r];
    i = l - 1;

    for (j = l; j < r; ++j) {
      if (arr[j] <= pivot) {
        ++i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    ++i;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

/*
 *
 * <сводка>
 *   Функция __partitiond (для double_t)
 * </сводка>
 *
 * <описание>
 *   Приватная функция, которая берёт значение pivot (последний элемент массива),
 *   находит элементы, которые меньше и больше, чем pivot, кладёт их слева и справа соответсвенно.
 *   Возвращает индекс, под которым находится pivot.
 * </описание>
 *
 */
int64_t ECOCALLMETHOD CEcoLab1___partitiond (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ double_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    int64_t i, j;
    int32_t pivot;
    double_t temp;

    pivot = arr[r];
    i = l - 1;

    for (j = l; j < r; ++j) {
      if (arr[j] <= pivot) {
        ++i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    ++i;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

/*
 *
 * <сводка>
 *   Функция __partitionf (для float_t)
 * </сводка>
 *
 * <описание>
 *   Приватная функция, которая берёт значение pivot (последний элемент массива),
 *   находит элементы, которые меньше и больше, чем pivot, кладёт их слева и справа соответсвенно.
 *   Возвращает индекс, под которым находится pivot.
 * </описание>
 *
 */
int64_t ECOCALLMETHOD CEcoLab1___partitionf (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ float_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    int64_t i, j;
    int32_t pivot;
    float_t temp;

    pivot = arr[r];
    i = l - 1;

    for (j = l; j < r; ++j) {
      if (arr[j] <= pivot) {
        ++i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    ++i;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

/*
 *
 * <сводка>
 *   Функция __quickSort
 * </сводка>
 *
 * <описание>
 *   Функция, которая производит саму сортировку,
 *   вызывая себя рекурсивно.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1___quickSort (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int32_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    CEcoLab1* pCMe1 = (CEcoLab1*)me;
    CEcoLab1* pCMe2 = (CEcoLab1*)me;

    int64_t q;

    /* Добавляем к счетчику референсов, чтобы в рекурсии было нормальное поведение */
    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe1->m_pVTblIEcoLab1->AddRef(pCMe1);
    pCMe2->m_pVTblIEcoLab1->AddRef(pCMe2);

    /* Находим pivot и рекурсивно вызываем эту функцию */
    if (l < r) {
      q = pCMe->m_pVTblIEcoLab1->__partition(me, l, r, arr);
      pCMe1->m_pVTblIEcoLab1->__quickSort(me, l,  q - 1, arr);
      pCMe2->m_pVTblIEcoLab1->__quickSort(me, q + 1,  r, arr);
    }

    pCMe->m_pVTblIEcoLab1->Release(pCMe);
    pCMe1->m_pVTblIEcoLab1->Release(pCMe1);
    pCMe2->m_pVTblIEcoLab1->Release(pCMe2);
}

/*
 *
 * <сводка>
 *   Функция __quickSortl (для int64_t)
 * </сводка>
 *
 * <описание>
 *   Функция, которая производит саму сортировку,
 *   вызывая себя рекурсивно.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1___quickSortl (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ int64_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    CEcoLab1* pCMe1 = (CEcoLab1*)me;
    CEcoLab1* pCMe2 = (CEcoLab1*)me;

    int64_t q;

    /* Добавляем к счетчику референсов, чтобы в рекурсии было нормальное поведение */
    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe1->m_pVTblIEcoLab1->AddRef(pCMe1);
    pCMe2->m_pVTblIEcoLab1->AddRef(pCMe2);

    /* Находим pivot и рекурсивно вызываем эту функцию */
    if (l < r) {
      q = pCMe->m_pVTblIEcoLab1->__partitionl(me, l, r, arr);
      pCMe1->m_pVTblIEcoLab1->__quickSortl(me, l,  q - 1, arr);
      pCMe2->m_pVTblIEcoLab1->__quickSortl(me, q + 1,  r, arr);
    }

    pCMe->m_pVTblIEcoLab1->Release(pCMe);
    pCMe1->m_pVTblIEcoLab1->Release(pCMe1);
    pCMe2->m_pVTblIEcoLab1->Release(pCMe2);
}

/*
 *
 * <сводка>
 *   Функция __quickSortd (для double_t)
 * </сводка>
 *
 * <описание>
 *   Функция, которая производит саму сортировку,
 *   вызывая себя рекурсивно.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1___quickSortd (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ double_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    CEcoLab1* pCMe1 = (CEcoLab1*)me;
    CEcoLab1* pCMe2 = (CEcoLab1*)me;

    int64_t q;

    /* Добавляем к счетчику референсов, чтобы в рекурсии было нормальное поведение */
    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe1->m_pVTblIEcoLab1->AddRef(pCMe1);
    pCMe2->m_pVTblIEcoLab1->AddRef(pCMe2);

    /* Находим pivot и рекурсивно вызываем эту функцию */
    if (l < r) {
      q = pCMe->m_pVTblIEcoLab1->__partitiond(me, l, r, arr);
      pCMe1->m_pVTblIEcoLab1->__quickSortd(me, l,  q - 1, arr);
      pCMe2->m_pVTblIEcoLab1->__quickSortd(me, q + 1,  r, arr);
    }

    pCMe->m_pVTblIEcoLab1->Release(pCMe);
    pCMe1->m_pVTblIEcoLab1->Release(pCMe1);
    pCMe2->m_pVTblIEcoLab1->Release(pCMe2);
}

/*
 *
 * <сводка>
 *   Функция __quickSortf (для float_t)
 * </сводка>
 *
 * <описание>
 *   Функция, которая производит саму сортировку,
 *   вызывая себя рекурсивно.
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoLab1___quickSortf (/* in */ struct IEcoLab1* me, /* in */ int64_t l, /* in */ int64_t r, /* in | out */ float_t* arr) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    CEcoLab1* pCMe1 = (CEcoLab1*)me;
    CEcoLab1* pCMe2 = (CEcoLab1*)me;

    int64_t q;

    /* Добавляем к счетчику референсов, чтобы в рекурсии было нормальное поведение */
    pCMe->m_pVTblIEcoLab1->AddRef(pCMe);
    pCMe1->m_pVTblIEcoLab1->AddRef(pCMe1);
    pCMe2->m_pVTblIEcoLab1->AddRef(pCMe2);

    /* Находим pivot и рекурсивно вызываем эту функцию */
    if (l < r) {
      q = pCMe->m_pVTblIEcoLab1->__partitionf(me, l, r, arr);
      pCMe1->m_pVTblIEcoLab1->__quickSortf(me, l,  q - 1, arr);
      pCMe2->m_pVTblIEcoLab1->__quickSortf(me, q + 1,  r, arr);
    }

    pCMe->m_pVTblIEcoLab1->Release(pCMe);
    pCMe1->m_pVTblIEcoLab1->Release(pCMe1);
    pCMe2->m_pVTblIEcoLab1->Release(pCMe2);
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_QuickSort,
    CEcoLab1_QuickSortl,
    CEcoLab1_QuickSortd,
    CEcoLab1_QuickSortf,
    CEcoLab1___partition,
    CEcoLab1___partitionl,
    CEcoLab1___partitiond,
    CEcoLab1___partitionf,
    CEcoLab1___quickSort,
    CEcoLab1___quickSortl,
    CEcoLab1___quickSortd,
    CEcoLab1___quickSortf
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
