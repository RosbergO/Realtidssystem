/*ghe
 * LCD.c
 *
 * Created: 2019-03-06 16:31:41
 *  Author: oscros-7, linoss-7
 */

#include "LCD.h"
#include "TinyTimber.h"

// Struct used to return multiple values in getChar
struct numbers {
    uint8_t line1;
    uint8_t line2;
    uint8_t line3;
    uint8_t line4;
};

 void writeLong(long i) {
    uint8_t number = 0x30; // 0x30 is '0' in ASCII
    for(uint8_t pos = 5; pos > -1; pos = pos -1) { // loop the six segments for the correct positions on the LCD-screen
        if(i > 0 ){ // the numbers are shown on the screen, from right to left
            uint8_t index;
            index = i % 10;
            writeChar(index+number, pos); // index + 0x30 are the chars in ASCII
            i = i / 10;
        }
        else {
            break;
        }
    }
}
 
struct numbers getChar(char ch) {
    struct numbers numb; 
    switch(ch) {
        case '0':
            numb.line1 = 0x01;
            numb.line2 = 0x05;
            numb.line3 = 0x05;
            numb.line4 = 0x01;
            return numb;
        case '1':
            numb.line1 = 0x00;
            numb.line2 = 0x01;
            numb.line3 = 0x01;
            numb.line4 = 0x00;
            return numb;
        case '2':
            numb.line1 = 0x01;
            numb.line2 = 0x01;
            numb.line3 = 0x0E;
            numb.line4 = 0x01;
            return numb;       
        case '3':
            numb.line1 = 0x01;
            numb.line2 = 0x01;
            numb.line3 = 0x0B;
            numb.line4 = 0x01;
            return numb;
        case '4':
            numb.line1 = 0x00;
            numb.line2 = 0x05;
            numb.line3 = 0x0B;
            numb.line4 = 0x00;
            return numb;       
        case '5':
            numb.line1 = 0x01;
            numb.line2 = 0x04;
            numb.line3 = 0x0B;
            numb.line4 = 0x01;
            return numb;
        case '6':
            numb.line1 = 0x01;
            numb.line2 = 0x04;
            numb.line3 = 0x0F;
            numb.line4 = 0x01;
            return numb;
        case '7':
            numb.line1 = 0x01;
            numb.line2 = 0x01;
            numb.line3 = 0x01;
            numb.line4 = 0x00;
            return numb;
        case '8':
            numb.line1 = 0x01;
            numb.line2 = 0x05;
            numb.line3 = 0x0F;
            numb.line4 = 0x01;
            return numb;
        case '9':
            numb.line1 = 0x01;
            numb.line2 = 0x05;
            numb.line3 = 0x0B;
            numb.line4 = 0x01;
            return numb;
        default:
            numb.line1 = 0x00;
            numb.line2 = 0x00;
            numb.line3 = 0x00;
            numb.line4 = 0x00;
            return numb;   
    }    
}
 
void writeChar(char ch, int pos){  
    struct numbers numb = getChar(ch);
    if ((pos%2) != 0) {
		numb.line1 = numb.line1 << 4;
		numb.line2 = numb.line2 << 4;
		numb.line3 = numb.line3 << 4;
		numb.line4 = numb.line4 << 4;
    }
   
    switch(pos) {
        case 0:
            LCDDR0 = (0xF6 & LCDDR0) | (numb.line1 & 0x6F);
            LCDDR5 = (0xF0 & LCDDR5) | (numb.line2 & 0x0F);
            LCDDR10 = (0xF0 & LCDDR10) | (numb.line3 & 0x0F);
            LCDDR15 = (0xF0 & LCDDR15) | (numb.line4 & 0x0F);
            break;
        case 1:
            LCDDR0 = (0x6F & LCDDR0) | (numb.line1 & 0xF6);
            LCDDR5 = (0x0F & LCDDR5) | (numb.line2 & 0xF0);
            LCDDR10 = (0x0F & LCDDR10) | (numb.line3 & 0xF0);
            LCDDR15 = (0x0F & LCDDR15) | (numb.line4 & 0xF0);
            break;
        case 2:
            LCDDR1 = (0xF6 & LCDDR1) | (numb.line1 & 0x6F);
            LCDDR6 = (0xF0 & LCDDR6) | (numb.line2 & 0x0F);
            LCDDR11 = (0xF0 & LCDDR11) | (numb.line3 & 0x0F);
            LCDDR16 = (0xF0 & LCDDR16) | (numb.line4 & 0x0F);
            break;
        case 3:
            LCDDR1 = (0x6F & LCDDR1) | (numb.line1 & 0xF6);
            LCDDR6 = (0x0F & LCDDR6) | (numb.line2 & 0xF0);
            LCDDR11 = (0x0F & LCDDR11) | (numb.line3 & 0xF0);
            LCDDR16 = (0x0F & LCDDR16) | (numb.line4 & 0xF0);
            break;
        case 4:
            LCDDR2 = (0xF6 & LCDDR2) | (numb.line1 & 0x6F);
            LCDDR7 = (0xF0 & LCDDR7) | (numb.line2 & 0x0F);
            LCDDR12 = (0xF0 & LCDDR12) | (numb.line3 & 0x0F);
            LCDDR17 = (0xF0 & LCDDR17) | (numb.line4 & 0x0F);
            break;
        case 5:
			LCDDR2 = (0x6F & LCDDR2) | (numb.line1 & 0xF6);
            LCDDR7 = (0x0F & LCDDR7) | (numb.line2 & 0xF0);
            LCDDR12 = (0x0F & LCDDR12) | (numb.line3 & 0xF0);
            LCDDR17 = (0x0F & LCDDR17) | (numb.line4 & 0xF0);
            break;     
    }
}

void LCD_Init() {
	/*
	//LCD init
	CLKPR = 0x80;
	CLKPR = 0x00;
	LCDFRR = 0x07;
	LCDCRB = 0xB7;
	LCDCRA = 0xC0;
	LCDCCR = 0x0F;
	
	//Joystick stuff
	PORTB =	(1 << PINB7) | (1 << PINB6) | (1 << PINB4); // PINB7 is joystick pull-down, PINB6 is pull-up and PINB4 is down-press
	PORTE =	(1 << PINE3) | (1 << PINE2); // PINE3 is joystick pull-right and PINE2 is pull-left
	PCMSK1 = 1 << PCINT15;
	EIMSK = 1 << PCIE1;
	*/
		CLKPR = 0x80;
		CLKPR = 0x00;
		
		// enables the logical interrupt sources
		EIMSK = 0xC0;
		EIFR = 0xC0;
		PCMSK1 |= 0xD0;
		PCMSK0 |= 0x0C;
		
		PORTB |= 0xD0;
		PORTE |= 0x0C;
		
		// LCD
		LCDCRA = 0xC0;			// LCD ENABLE and LOW POWER WAVEFORM
		LCDCRB = 0xB7;			// AsyncClock, 1/3 Bias, 1/4 Duty, 25 Segments
		LCDFRR = 0x07;			// LCD Clock Divide 32 Hz
		LCDCCR = 0x0F;			// 3.35 Volt
		
		LCDDR13 = 0x1;			// init left pulse
}

void printTest(LCD *self, int num) {
	int pp = 0;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}

void printAt(long num, int pos) {
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}

/*
	2 or 5 is displayed above the selected pulsegen.
*/
void indicatePulseGen(int selected) {
	if(selected == 0) {
		LCDDR0 |= 0x40;
		LCDDR1 &= 0xDF;
	}
	else {
		LCDDR1 |= 0x20;
		LCDDR0 &= 0xBF;
	}
}

void updateLCD(LCD *self, int arg) {
	printAt(self->pulseGenerator[0]->frequency, 0);
	printAt(self->pulseGenerator[1]->frequency, 4);
	indicatePulseGen(arg);
	
	
	}