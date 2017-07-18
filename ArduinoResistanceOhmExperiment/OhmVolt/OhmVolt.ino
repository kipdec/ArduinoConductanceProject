// Arduino Ohm Voltage Experiment
// Kip DeCastro
// July 18th
//
// This program is designed to compare the equations gleaned from the Arduino 
// ohm voltage experiment to each other.

// Initialize variables...
double a = 0; // Our value read from the arduino
double va = 0; // Arduino to volt
double ra = 0; // Arduino to resistance
double rv = 0; // va to resistance
double rt = 0; // Tim's resistance equation

void setup(){
	// Set up our baud signal
	Serial.begin(9600);
	// Get the first analog pin ready to read data.
	pinMode(A0, INPUT);
	// Set up the header for our data. NOTE: This data is much easier if imported
	// into excel.
	// Value = Arduino 5 bit value
	// Volts = Volts calculated by the VA equation
	// Resistance 1 = Resistance calculated by the RA equation
	// Resistance 2 = Resistance calculated by combining VA + RV
	// Resistance 3 = Tim's Resistance equation
	Serial.println("Value, Volts, Resistance 1 (MOhm), Resistance 2 (MOhm), Resistance 3 (MOhm)");

}

void loop(){
	a = analogRead(A0);
	va = 1.1742*(log(a)) - 2.8236;
  double ma = a/100;
	ra = 0.8633*(pow(ma, -1.202));
	rv = 0.1828*(pow(va, 2)) - 1.7136*va + 4.1463;
	rt = ((0.1*1024)/a)-0.1;
	Serial.print(a);
	Serial.print(", ");
	Serial.print(va);
	Serial.print(", ");
	Serial.print(ra);
	Serial.print(", ");
	Serial.print(rv);
	Serial.print(", ");
	Serial.println(rt);

  delay(2000);
}
