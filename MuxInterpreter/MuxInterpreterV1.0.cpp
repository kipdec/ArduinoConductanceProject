// Mux Interpreter V1.0
// July 18, 2017
// Kip DeCastro
//
// This code allows an Arduino Mega to read the value of 12 sensors connected to 
// 3 plants.

const int sensorNumber = 12;

// Digital pin numbers to control the functioning of the Mux
int pinA = 2; // Digital pin on the Arduino corresponding to A0 on the Mux
int pinB = 3; // Digital pin on the Arduino corresponding to A1 on the Mux
int pinC = 4; // Digital pin on the Arduino corresponding to A2 on the Mux
int pinD = 5; // Digital pin on the Arduino corresponding to A3 on the Mux

int A = 0; // Address pin A
int B = 0; // Address pin B
int C = 0; // Address pin C
int D = 0; // Address pin D

// Digital pin numbersfor providing power to the plants. 3 per Mux.
// Use the bottom set of digital pins. 22 - 53.
int plantA = 22;
int plantB = 23;
int plantC = 24;

// Set the time to wait between readings
int wait = 2000;

// setup analog value
double aPin = 0;


void setup(){
	// Set up the Baud channel which the Arduino will relay data over.
	Serial.begin(9600);

	// Prepare the digital pins for output to the mux
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);

	// Prepare the digital pins to power the plants
	pinMode(plantA, OUTPUT);
	pinMode(plantB, OUTPUT);
	pinMode(plantC, OUTPUT);

	// Prepare the analog pin to read the output of the mux
	pinMode(A0, INPUT);
	// Setup headers for Excel import
	Serial.print("A0,R0,A1,AR1,A2,AR2,A3,AR3,B0,BR0,B1,BR1,B2,BR2,B3,BR3,");
	Serial.println("C0,CR0,C1,CR1,C2,CR2,C3,CR3");
}

void loop() {
	// Turn on power to Plant A, B and D
	digitalWrite(plantA, HIGH);
	digitalWrite(plantB, HIGH);
	digitalWrite(plantC, HIGH);

	// Wait for charge to normalize
	delay(45);
	// Go through the pins and read their value
	for( int i = 0; i < sensorNumber; i++ ){
		A = bitRead(i,0);
		B = bitRead(i,1);
		C = bitRead(i,2);
		D = bitRead(i,3);

		// Write to multiplexer
		digitalWrite(pinA, A);
		digitalWrite(pinB, B);
		digitalWrite(pinC, C);
		digitalWrite(pinD, D);

		// Read the analog pin
		aPin = analogRead(A0);

		// Write values to serial output
		Serial.print(apin);
		Serial.print(", ");

		// Calculate resistance from arduino value
		Serial.print(rA(aPin));

		// Add another comma until the last calculation
		if( i < (sensorNumber - 1)){
			Serial.print(", ")
		}
	}

	// End the line
	Serial.println();

	// Turn off power to the plants
	digitalWrite(plantA, LOW);
	digitalWrite(plantB, LOW);
	digitalWrite(plantC, LOW);

	// Wait for the specified time to run again
	delay(wait);
}

double rA(double a){
	return 0.1 * 1024 / a - 0.1;
}