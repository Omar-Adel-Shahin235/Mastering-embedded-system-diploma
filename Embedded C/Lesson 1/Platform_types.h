/*
 * platform_types.h
 *
 *  Created on: ١٢‏/٠٧‏/٢٠٢٣
 *      Author: omar shahin
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#ifndef _Bool
#define _Bool            unsigned char
#endif

#define CPU_TPE                      CPU_TYPE_32
#define CPU_BIT_ORDER                MSB_FIRST
#define CPU_BYTE_ORDER               HIGH_BYTE_FIRST

#ifndef False
#define False                        (boolean)false
#endif

#ifndef True
#define True                         (boolean)true
#endif

typedef _Bool                        booalean;
typedef unsigned char                uint8;
typedef unsigned short               uint16;
typedef unsigned int                 uint32;
typedef unsigned long long           uint64;

typedef signed char                  sint8;
typedef signed short                 sint16;
typedef signed int                   sint32;
typedef signed long long             sint64;  

typedef volatile unsigned char       vuint8;
typedef volatile unsigned short      vuint16;
typedef volatile unsigned int        vuint32;
typedef volatile unsigned long long  vuint64;

typedef volatile signed char         vsint8;
typedef volatile signed short        vsint16;
typedef volatile signed int          vsint32;
typedef volatile signed long long    vsint64;

#endif /* PLATFORM_TYPES_H_ */
