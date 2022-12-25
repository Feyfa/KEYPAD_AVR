/*
 * KEYPAD4X4 LCD16X2(4BIT) ATMEGA8A (C++).cpp
 *
 * Created: 25/12/2022 13.18.00
 * Author : fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "keypad4x4.hpp"
#include "lm016l.hpp"
#define F_CPU 8000000

int main(void)
{
	uint8_t rowPin[4] = {0,1,2,3};//pins for rows
	uint8_t columnPin[4] = {4,5,6,7};//pins for columns
	char keyMap[4][4] =
	{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
	};//map on the keypad
	keypad4x4 keypad = keypad4x4(keypadUsingPD,rowPin,columnPin,keyMap);
	lm016l lcd = lm016l(lcdUsingPB);
	lcd.location(0,0);
	while(1)
	{
		switch(keypad.getValue()){
			case '7': lcd.print('7'); _delay_ms(300); break;
			case '8': lcd.print('8'); _delay_ms(300); break;
			case '9': lcd.print('9'); _delay_ms(300); break;
			case '/': lcd.print('/'); _delay_ms(300); break;
			
			case '4': lcd.print('4'); _delay_ms(300); break;
			case '5': lcd.print('5'); _delay_ms(300); break;
			case '6': lcd.print('6'); _delay_ms(300); break;
			case '*': lcd.print('*'); _delay_ms(300); break;
			
			case '1': lcd.print('1'); _delay_ms(300); break;
			case '2': lcd.print('2'); _delay_ms(300); break;
			case '3': lcd.print('3'); _delay_ms(300); break;
			case '-': lcd.print('-'); _delay_ms(300); break;
			
			case 'C': lcd.clear();    _delay_ms(300); break;
			case '0': lcd.print('0'); _delay_ms(300); break;
			case '=': lcd.print('='); _delay_ms(300); break;
			case '+': lcd.print('p'); _delay_ms(300); break;
		}
	}
	
	
}

