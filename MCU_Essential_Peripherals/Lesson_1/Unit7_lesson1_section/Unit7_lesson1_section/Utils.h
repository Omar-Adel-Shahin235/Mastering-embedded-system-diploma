/*
 * Utils.h
 *
 * Created: 9/6/2023 3:21:19 AM
 *  Author: Acer
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg,bit) (reg|=(1<<bit))

#define CLR_BIT(reg,bit) (reg&=~(1<<bit))

#define READ_BIT(reg,bit) ((reg>>bit)&1)



#endif /* UTILS_H_ */