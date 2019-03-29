/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2014 - 2019 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Файл libakrypt.h                                                                               */
/*  - содержит перечень экспортируемых интерфейсов библиотеки libakrypt                            */
/* ----------------------------------------------------------------------------------------------- */
#ifndef    __LIBAKRYPT_H__
#define    __LIBAKRYPT_H__

/* ----------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------------------------------------------------------------------------------- */
/* Для остальных операционных систем символ теряет свой смысл ;)                                   */
 #define dll_export

/* ----------------------------------------------------------------------------------------------- */
 #include <sys/types.h>
#ifndef LIBAKRYPT_LITTLE_ENDIAN
 #include <byteswap.h>
#endif

/* ----------------------------------------------------------------------------------------------- */
#ifdef __MINGW32__
 typedef __int32 ak_int32;
 typedef unsigned __int32 ak_uint32;
 typedef __int64 ak_int64;
 typedef unsigned __int64 ak_uint64;
#endif
#ifdef MSYS
 typedef int32_t ak_int32;
 typedef u_int32_t ak_uint32;
 typedef int64_t ak_int64;
 typedef u_int64_t ak_uint64;
 int snprintf(char *str, size_t size, const char *format, ... );
#endif
#if defined(__unix__) || defined(__APPLE__)
 typedef signed int ak_int32;
 typedef unsigned int ak_uint32;
 typedef signed long long int ak_int64;
 typedef unsigned long long int ak_uint64;
#endif

/* ----------------------------------------------------------------------------------------------- */
 typedef signed char ak_int8;
 typedef unsigned char ak_uint8;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Определение булева типа, принимающего значения либо истина, либо ложь. */
 typedef enum { ak_false, ak_true } ak_bool;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Указатель на произвольный объект библиотеки. */
 typedef void *ak_pointer;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Результат, говорящий об отсутствии ошибки. */
 #define ak_error_ok                            (0)
/*! \brief Ошибка выделения оперативной памяти. */
 #define ak_error_out_of_memory                (-1)
/*! \brief Ошибка, возникающая при доступе или передаче в качестве аргумента функции null указателя. */
 #define ak_error_null_pointer                 (-2)
/*! \brief Ошибка, возникащая при передаче аргументов функции или выделении памяти нулевой длины. */
 #define ak_error_zero_length                  (-3)
/*! \brief Ошибка, возникающая при обработке данных ошибочной длины. */
 #define ak_error_wrong_length                 (-4)
/*! \brief Использование неопределенного значения. */
 #define ak_error_undefined_value              (-5)
/*! \brief Использование неопределенного указателя на функцию (вызов null указателя). */
 #define ak_error_undefined_function           (-6)
/*! \brief Ошибка переполнения контролируемой переменной */
 #define ak_error_overflow                     (-7)
/*! \brief Попытка доступа к неопределенной опции библиотеки. */
 #define ak_error_wrong_option                 (-8)

/*! \brief Ошибка создания файла. */
 #define ak_error_create_file                 (-10)
/*! \brief Ошибка доступа к файлу (устройству). */
 #define ak_error_access_file                 (-11)
/*! \brief Ошибка открытия файла (устройства). */
 #define ak_error_open_file                   (-12)
/*! \brief Ошибка закрытия файла (устройства). */
 #define ak_error_close_file                  (-13)
/*! \brief Ошибка чтения из файла (устройства). */
 #define ak_error_read_data                   (-14)
/*! \brief Ошибка записи в файл (устройство). */
 #define ak_error_write_data                  (-15)
/*! \brief Ошибка записи в файл - файл существует */
 #define ak_error_file_exists                 (-16)

/*! \brief Ошибка при сравнении двух массивов данных. */
 #define ak_error_not_equal_data              (-20)
/*! \brief Ошибка выполнения библиотеки на неверной архитектуре. */
 #define ak_error_wrong_endian                (-21)
/*! \brief Ошибка чтения из терминала. */
 #define ak_error_terminal                    (-22)

/*! \brief Неверное значение дескриптора объекта. */
 #define ak_error_wrong_handle                (-30)
/*! \brief Попытка создания и/или использования ранее созданного менеджера контектстов */
 #define ak_error_context_manager_usage       (-31)
/*! \brief Ошибка, возникающая в случае неправильного значения размера структуры хранения контекстов. */
 #define ak_error_context_manager_size        (-32)
/*! \brief Ошибка, возникающая при превышении числа возможных элементов структуры хранения контекстов. */
 #define ak_error_context_manager_max_size    (-33)

/*! \brief Неверный тип криптографического механизма. */
 #define ak_error_oid_engine                  (-40)
/*! \brief Неверный режим использования криптографического механизма. */
 #define ak_error_oid_mode                    (-41)
/*! \brief Ошибочное или не определенное имя криптографического механизма. */
 #define ak_error_oid_name                    (-42)
/*! \brief Ошибочный или неопределенный идентификатор криптографического механизма. */
 #define ak_error_oid_id                      (-43)
/*! \brief Ошибочный индекс идентификатора криптографического механизма. */
 #define ak_error_oid_index                   (-44)
/*! \brief Ошибка с обращением к oid. */
 #define ak_error_wrong_oid                   (-45)

/*! \brief Ошибка, возникающая при использовании ключа, значение которого не определено. */
 #define ak_error_key_value                   (-51)
/*! \brief Ошибка, возникающая при использовании ключа для бесключевых функций. */
 #define ak_error_key_usage                   (-52)
/*! \brief Ошибка, возникающая при неверном заполнении полей структуры bckey. */
 #define ak_error_wrong_block_cipher          (-53)
/*! \brief Ошибка, возникающая при зашифровании/расшифровании данных, длина которых не кратна длине блока. */
 #define ak_error_wrong_block_cipher_length   (-54)
/*! \brief Ошибка, возникающая при неверном значении кода целостности ключа. */
 #define ak_error_wrong_key_icode             (-55)
/*! \brief Ошибка, возникающая при неверном значении длины ключа. */
 #define ak_error_wrong_key_length            (-57)
/*! \brief Ошибка, возникающая при недостаточном ресурсе ключа. */
 #define ak_error_low_key_resource            (-58)
/*! \brief Ошибка, возникающая при использовании синхропосылки (инициализационного вектора) неверной длины. */
 #define ak_error_wrong_iv_length             (-59)
/*! \brief Ошибка, возникающая при неправильном использовании функций зашифрования/расшифрования данных. */
 #define ak_error_wrong_block_cipher_function (-60)

/*! \brief Ошибка, возникающая когда параметры кривой не соотвествуют алгоритму, в котором они используются. */
 #define ak_error_curve_not_supported         (-70)
/*! \brief Ошибка, возникающая если точка не принадлежит заданной кривой. */
 #define ak_error_curve_point                 (-71)
/*! \brief Ошибка, возникающая когда порядок точки неверен. */
 #define ak_error_curve_point_order           (-72)
/*! \brief Ошибка, возникающая если дискриминант кривой равен нулю (уравнение не задает кривую). */
 #define ak_error_curve_discriminant          (-73)
/*! \brief Ошибка, возникающая когда неверно определены вспомогательные параметры эллиптической кривой. */
 #define ak_error_curve_order_parameters      (-74)
/*! \brief Ошибка, возникающая когда простой модуль кривой задан неверно. */
 #define ak_error_curve_prime_modulo          (-75)

/*! \brief Ошибка, возникающая при кодировании ASN1 структуры (перевод в DER-кодировку). */
 #define ak_error_wrong_asn1_encode           (-90)
/*! \brief Ошибка, возникающая при декодировании ASN1 структуры (перевод из DER-кодировки в ASN1 структуру). */
 #define ak_error_wrong_asn1_decode           (-91)

/* ----------------------------------------------------------------------------------------------- */
 struct hash;
 typedef struct hash *ak_hash;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Функция очистки контекста хеширования. */
 typedef int ( ak_function_mac_clean )( ak_pointer );
/*! \brief Итерационная функция хеширования. */
 typedef int ( ak_function_mac_update )( ak_pointer, const ak_pointer , const size_t );
/*! \brief Функция завершения вычислений и получения конечного результата. */
 typedef int ( ak_function_mac_finalize ) ( ak_pointer, const ak_pointer , const size_t, ak_pointer );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура для хранения внутренних данных контекста функции хеширования Стрибог          */
 struct streebog {
 /*! \brief вектор h - временный */
  ak_uint64 H[8];
 /*! \brief вектор n - временный */
  ak_uint64 N[8];
 /*! \brief вектор  \f$ \Sigma \f$ - контрольная сумма */
  ak_uint64 SIGMA[8];
};

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Класс, реализующий контекст алгоритима хеширования. */
/*! Класс предоставляет интерфейс для реализации различных бесключевых алгоритмов хеширования
    информации, построенных с использованием итеративных сжимающих отображений. В настоящее время
    с использованием класса \ref hash реализованы следующие отечественные алгоритмы хеширования
     - Стрибог256,
     - Стрибог512,
     - ГОСТ Р 34.11-94 (в настоящее время стандарт выведен из обращения).

    Подробное описание методов использования
    объектов класса \ref hash содержится в разделе \ref guide_hash.                                */
/* ----------------------------------------------------------------------------------------------- */
 struct hash {
  /*! \brief размер обрабатываемого блока входных данных */
   size_t bsize;
  /*! \brief размер выходного блока (хеш-кода) */
   size_t hsize;
  /*! \brief указатель на внутренние данные контекста */
   struct streebog data;
  /*! \brief функция очистки контекста */
   ak_function_mac_clean *clean;
  /*! \brief функция обновления состояния контекста */
   ak_function_mac_update *update;
  /*! \brief функция завершения вычислений и получения конечного результата */
   ak_function_mac_finalize *finalize;
 };

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация контекста функции бесключевого хеширования ГОСТ Р 34.11-2012 (Стрибог256). */
 int ak_hash_context_create_streebog256( ak_hash );
/*! \brief Инициализация контекста функции бесключевого хеширования ГОСТ Р 34.11-2012 (Стрибог512). */
 int ak_hash_context_create_streebog512( ak_hash );
/*! \brief Хеширование заданной области памяти. */
 int ak_hash_context_ptr( ak_hash , const ak_pointer , const size_t , ak_pointer );
/*! \brief Уничтожение контекста функции хеширования. */
 int ak_hash_context_destroy( ak_hash );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Проверка корректной работы функции хеширования Стрибог-256 */
 ak_bool ak_hash_test_streebog256( void );

#ifdef __cplusplus
} /* конец extern "C" */
#endif
#endif

/* ----------------------------------------------------------------------------------------------- */
/*                                                                                     libakrypt.h */
/* ----------------------------------------------------------------------------------------------- */