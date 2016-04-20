// Includes
#include <p18f1220.h>

// Config

#pragma config OSC = XT
#pragma config FSCM = OFF
#pragma config IESO = OFF
#pragma config PWRT = ON
#pragma config BOR = OFF
#pragma config BORV = 45
#pragma config WDT = OFF
#pragma config MCLRE = OFF
#pragma config STVR = OFF
#pragma config LVP = OFF
#pragma config DEBUG = OFF
#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF
#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRTB = OFF
#pragma config WRTC = OFF
#pragma config WRTD = OFF
#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTRB = OFF

// Pins
#define BUTTON_1 	PORTBbits.RB0
#define BUTTON_2	PORTBbits.RB1
#define OPT_1 		LATAbits.LATA4
#define OPT_2		LATBbits.LATB3
#define OPT_3		LATAbits.LATA6
#define OPT_4		LATBbits.LATB5
#define OPT_5		LATBbits.LATB6
#define OPT_6		LATAbits.LATA1
#define OPT_7		LATAbits.LATA0
#define OPT_8		LATBbits.LATB2
#define OPT_9		LATAbits.LATA7
#define OPT_10		LATBbits.LATB7

#define HIGH		1
#define LOW		0

// Variables
int OPT[] = {OPT_1, OPT_2, OPT_3, OPT_4, OPT_5, OPT_6, OPT_7, OPT_8, OPT_9, OPT_10};
int LEFT[] = {OPT_1, OPT_2, OPT_3, OPT_4, OPT_5};
int RIGHT[] = {OPT_6, OPT_7, OPT_8, OPT_9, OPT_10};
int current_random = 1;		// Zählt dauerhaft hoch
int options = 10;		// Wieviele Möglichkeiten

void setup()[

	TRISA = 0;
	TRISB = 0x03;
	
	// TODO: Anzahl der Auswahlmöglichkeiten selbst zu beginn bestimmen (2. Button zwingend erforderlich?)
	
	while(BUTTON_1 != HIGH){
		delay(20);
		if (BUTTON_2 == HIGH){
			options++;
			if (options == 11){
				all(LOW);
				options = 1;
			}
			OPT[options] = HIGH;
			//digitalWrite(OPT[options], HIGH);
		}
	
	}
	
	
	delay(50);
	start_up();
	all(LOW);
}

void loop(){
	
	while(BUTTON_1 == HIGH){
		if(current_random == 1) select(1);
		else if(current_random == 2) select(2);
		else if(current_random == 3) select(3);
		else if(current_random == 4) select(4);
		else if(current_random == 5) select(5);
		else if(current_random == 6) select(6);
		else if(current_random == 7) select(7);
		else if(current_random == 8) select(8);
		else if(current_random == 9) select(9);
		else if(current_random == 10) select(10);
	}
	
	delay(20);
	current_random++;
	if (current_random == (options + 1)) current_random = 1;
}

void select(int value){
	all(LOW);
	
	// durchlauf bis zur auswahl
	for (int x = 0, x < 4, x++){
		for (int i = 0, i <= 5, i++){
			LEFT[i] = HIGH;
			RIGHT[i] = HIGH;
			LEFT[i-1] = LOW;
			RIGHT[i-1] = LOW);
			delay(20);
		}
	}
	
	int temp = value;
	
	if (temp > 5) temp = temp-5;
	
	for (int y = 0, y <= value, y++){
		LEFT[y] = HIGH;
		RIGHT[y] = HIGH;
		LEFT[y-1] = LOW;
		RIGHT[y-1] = LOW;
		delay(20);
	}
	
	all(LOW);
	OPT[value] = HIGH;
}

void all(int value){
	if (value != 0 && value != 1){
			OPT[] = LOW;
	}
	else{
		for (int i = 0, i < 10, i++){		
			OPT[i] = value;
		}
	}
}

void start_up(){
	all(LOW);
	delay(30);
	
	for (int i=0, i < 5, i++){
		LEFT[i] = HIGH;
		RIGHT[i] = HIGH;
		delay(250)
	}
	delay(100);
	all(LOW);
	delay(20);
	all(HIGH);
	delay(20);
}
