/*
 * utils.h
 *
 * Created: 10/27/2023 3:49:43 PM
 *  Author: Acer
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define set_bit(port,bit)      port |= (1<<bit)
#define reset_bit(port,bit)    port &= ~(1<<bit)
#define toggle_bit(port,bit)   port ^= (1<<bit)
#define get_bit(port,bit)      ((port>>bit)&1)


#endif /* UTILS_H_ */