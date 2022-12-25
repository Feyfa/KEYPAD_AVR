/*
 * keypad4x4.h
 *
 * Created: 15/12/2022 16.22.40
 *  Author: fisikamodern
 */ 


#ifndef KEYPAD4X4_H_
#define KEYPAD4X4_H_

typedef enum{keypadUsingPB,keypadUsingPD}KeypadPort;
	
class keypad4x4{
	private:
		uint8_t R1;
		uint8_t R2;
		uint8_t R3;
		uint8_t R4;
		uint8_t C1;
		uint8_t C2;
		uint8_t C3;
		uint8_t C4;
		char kmap[4][4];
		KeypadPort keypadPort;
		void keypadInit(uint8_t *row,uint8_t *column);
	public:
		keypad4x4(KeypadPort keypadPort,uint8_t *row,uint8_t *column,char kmap[4][4]);
		void keypadRowPin(uint8_t *a);
		void keypadColumnPin(uint8_t *a);
		void scanRow1();
		void scanRow2();
		void scanRow3();
		void scanRow4();
		char getValue();
};

#endif /* KEYPAD4X4_H_ */