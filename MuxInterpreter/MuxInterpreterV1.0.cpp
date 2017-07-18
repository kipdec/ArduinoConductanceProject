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

// Setup analog reading pin
int aPin = 0;


void setup(){
	// Set up the Baud channel which the Arduino will relay data over.
	Serial.begin(9600);
	// Prepare pins for output


}