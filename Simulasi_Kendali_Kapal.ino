#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define ledR 6
#define ledL 7
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define pwm 9
#define dir 10

int kemudi = A1;  // analog pin used to connect the potentiometer
int gas = A0;
int slide,pot;    // variable to read the value from the analog pin

void setup() {
	myservo.attach(8);  // attaches the servo on pin 9 to the servo object
	pinMode(ledR, OUTPUT);
	pinMode(ledL, OUTPUT);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(pwm, OUTPUT);
	pinMode(dir, OUTPUT);
	analogWrite(pwm,0);
}

void loop() {
	pot = analogRead(kemudi);            // reads the value of the potentiometer (value between 0 and 1023)
	slide = analogRead(gas);
	
	//BAGIAN KEMUDI KAPAL
	if (pot >= 767){
		myservo.write(180);   
		digitalWrite(ledR, HIGH);
		digitalWrite(ledL, LOW);
	}else if (pot >=341 && pot< 767){
		myservo.write(0);   
		digitalWrite(ledL, HIGH);
		digitalWrite(ledR, LOW);
	}else{
		myservo.write(90);   
		digitalWrite(ledR, LOW);
		digitalWrite(ledL, LOW);
	} 	
	delay(15);    
	
	//BAGIAN KECEPATAN KAPAL
	int val  = map (slide, 0, 1023, 0, 255);
	analogWrite(pwm,val);
	delay(100);
	
	if (slide>0 && slide<255){
		digitalWrite(led1, HIGH);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
	}else if (slide>=255 && slide<510){
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
	}else if (slide>=510 && slide<765){
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, LOW);
	}else if (slide >=765){
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
	}else{
		digitalWrite(led1, LOW);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
	}
		
	
	
}