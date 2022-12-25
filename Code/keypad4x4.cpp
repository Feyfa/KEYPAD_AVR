/*
 * keypad4x4.cpp
 *
 * Created: 15/12/2022 16.22.53
 *  Author: fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "keypad4x4.hpp"

//private method
void keypad4x4::keypadInit(uint8_t *row,uint8_t *column)
{
	keypadRowPin(row);
	keypadColumnPin(column);
}

//public method
keypad4x4::keypad4x4(KeypadPort keypadPort,uint8_t *row,uint8_t *column,char kmap[4][4]){
	keypad4x4::keypadPort = keypadPort;
	keypad4x4::keypadInit(row,column);
	
	for(uint8_t baris=0; baris<=3; baris++){
		for(uint8_t kolom=0; kolom<=3; kolom++){
			keypad4x4::kmap[baris][kolom] = kmap[baris][kolom];
		}
	}
}
void keypad4x4::keypadRowPin(uint8_t *a){
	keypad4x4::R1 = a[0];
	keypad4x4::R2 = a[1];
	keypad4x4::R3 = a[2];
	keypad4x4::R4 = a[3];
	if(keypad4x4::keypadPort == keypadUsingPB){
		DDRB |= ((1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4));
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		DDRD |= ((1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4));
	}
}
void keypad4x4::keypadColumnPin(uint8_t *a){
	keypad4x4::C1 = a[0];
	keypad4x4::C2 = a[1];
	keypad4x4::C3 = a[2];
	keypad4x4::C4 = a[3];
	
	if(keypad4x4::keypadPort == keypadUsingPB){
		DDRB &= ~((1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4));
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		DDRD &= ~((1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4));
	}
}
void keypad4x4::scanRow1(){
	if(keypad4x4::keypadPort == keypadUsingPB){
		PORTB &= ~(1<<keypad4x4::R1);
		PORTB |= (1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		PORTD &= ~(1<<keypad4x4::R1);
		PORTD |= (1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	_delay_ms(10);
}
void keypad4x4::scanRow2(){
	if(keypad4x4::keypadPort == keypadUsingPB){
		PORTB &= ~(1<<keypad4x4::R2);
		PORTB |= (1<<keypad4x4::R1)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		PORTD &= ~(1<<keypad4x4::R2);
		PORTD |= (1<<keypad4x4::R1)|(1<<keypad4x4::R3)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	_delay_ms(10);
}
void keypad4x4::scanRow3(){
	if(keypad4x4::keypadPort == keypadUsingPB){
		PORTB &= ~(1<<keypad4x4::R3);
		PORTB |= (1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		PORTD &= ~(1<<keypad4x4::R3);
		PORTD |= (1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R4)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	_delay_ms(10);
}
void keypad4x4::scanRow4(){
	if(keypad4x4::keypadPort == keypadUsingPB){
		PORTB &= ~(1<<keypad4x4::R4);
		PORTB |= (1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	if(keypad4x4::keypadPort == keypadUsingPD){
		PORTD &= ~(1<<keypad4x4::R4);
		PORTD |= (1<<keypad4x4::R1)|(1<<keypad4x4::R2)|(1<<keypad4x4::R3)|(1<<keypad4x4::C1)|(1<<keypad4x4::C2)|(1<<keypad4x4::C3)|(1<<keypad4x4::C4);
	}
	_delay_ms(10);
}
char keypad4x4::getValue(){
	char v=0;
	
	if(keypad4x4::keypadPort == keypadUsingPB){
		keypad4x4::scanRow1();
		if(bit_is_clear(PINB,keypad4x4::C1)){
			v=keypad4x4::kmap[0][0];
		}
		if(bit_is_clear(PINB,keypad4x4::C2)){
			v=keypad4x4::kmap[0][1];
		}
		if(bit_is_clear(PINB,keypad4x4::C3)){
			v=keypad4x4::kmap[0][2];
		}
		if(bit_is_clear(PINB,keypad4x4::C4)){
			v=keypad4x4::kmap[0][3];
		}
		
		keypad4x4::scanRow2();
		if(bit_is_clear(PINB,keypad4x4::C1)){
			v=keypad4x4::kmap[1][0];
		}
		if(bit_is_clear(PINB,keypad4x4::C2)){
			v=keypad4x4::kmap[1][1];
		}
		if(bit_is_clear(PINB,keypad4x4::C3)){
			v=keypad4x4::kmap[1][2];
		}
		if(bit_is_clear(PINB,keypad4x4::C4)){
			v=keypad4x4::kmap[1][3];
		}
		
		keypad4x4::scanRow3();
		if(bit_is_clear(PINB,keypad4x4::C1)){
			v=keypad4x4::kmap[2][0];
		}
		if(bit_is_clear(PINB,keypad4x4::C2)){
			v=keypad4x4::kmap[2][1];
		}
		if(bit_is_clear(PINB,keypad4x4::C3)){
			v=keypad4x4::kmap[2][2];
		}
		if(bit_is_clear(PINB,keypad4x4::C4)){
			v=keypad4x4::kmap[2][3];
		}
		
		keypad4x4::scanRow4();
		if(bit_is_clear(PINB,keypad4x4::C1)){
			v=keypad4x4::kmap[3][0];
		}
		if(bit_is_clear(PINB,keypad4x4::C2)){
			v=keypad4x4::kmap[3][1];
		}
		if(bit_is_clear(PINB,keypad4x4::C3)){
			v=keypad4x4::kmap[3][2];
		}
		if(bit_is_clear(PINB,keypad4x4::C4)){
			v=keypad4x4::kmap[3][3];
		}
	}
	
	if(keypad4x4::keypadPort == keypadUsingPD){
		keypad4x4::scanRow1();
		if(bit_is_clear(PIND,keypad4x4::C1)){
			v=keypad4x4::kmap[0][0];
		}
		if(bit_is_clear(PIND,keypad4x4::C2)){
			v=keypad4x4::kmap[0][1];
		}
		if(bit_is_clear(PIND,keypad4x4::C3)){
			v=keypad4x4::kmap[0][2];
		}
		if(bit_is_clear(PIND,keypad4x4::C4)){
			v=keypad4x4::kmap[0][3];
		}
		
		keypad4x4::scanRow2();
		if(bit_is_clear(PIND,keypad4x4::C1)){
			v=keypad4x4::kmap[1][0];
		}
		if(bit_is_clear(PIND,keypad4x4::C2)){
			v=keypad4x4::kmap[1][1];
		}
		if(bit_is_clear(PIND,keypad4x4::C3)){
			v=keypad4x4::kmap[1][2];
		}
		if(bit_is_clear(PIND,keypad4x4::C4)){
			v=keypad4x4::kmap[1][3];
		}
		
		keypad4x4::scanRow3();
		if(bit_is_clear(PIND,keypad4x4::C1)){
			v=keypad4x4::kmap[2][0];
		}
		if(bit_is_clear(PIND,keypad4x4::C2)){
			v=keypad4x4::kmap[2][1];
		}
		if(bit_is_clear(PIND,keypad4x4::C3)){
			v=keypad4x4::kmap[2][2];
		}
		if(bit_is_clear(PIND,keypad4x4::C4)){
			v=keypad4x4::kmap[2][3];
		}
		
		keypad4x4::scanRow4();
		if(bit_is_clear(PIND,keypad4x4::C1)){
			v=keypad4x4::kmap[3][0];
		}
		if(bit_is_clear(PIND,keypad4x4::C2)){
			v=keypad4x4::kmap[3][1];
		}
		if(bit_is_clear(PIND,keypad4x4::C3)){
			v=keypad4x4::kmap[3][2];
		}
		if(bit_is_clear(PIND,keypad4x4::C4)){
			v=keypad4x4::kmap[3][3];
		}
	}
	return v;
}



