/*
 * Std_Types.h
 *
 * Created: 10/27/2023 3:49:10 PM
 *  Author: Acer
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8_t;

typedef unsigned char* ptr_uint8_t;

typedef char* ptr_sint8_t;

typedef void(*PTR_VoidFuncVoid_t)(void);
#define NULL_PTR				((void*)(0))

typedef unsigned char   Erorr_check;
#define E_ok           (Erorr_check)(0);
#define E_nok           (Erorr_check)(1);

#endif /* STD_TYPES_H_ */