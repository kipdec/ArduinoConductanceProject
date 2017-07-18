// SloppyTestFile.ino
// July 18, 2017
// Kip DeCastro
//
// This code is used for demonstrating the functioning of the Arduino's multiplexer
// board. It is not a finished product. For testing purposes only.

int totalChannels = 16;

int addressEN = 2;
int addressA = 7;
int addressB = 8;
int addressC = 9;
int addressD = 10;

int A = 0;      //Address pin A
int B = 0;      //Address pin B
int C = 0;      //Address pin C
int D = 0;
double x = 0;
double x2 = 0;
double timFunc = 0;

double mV = 0;

void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(addressEN, OUTPUT);
  pinMode(addressA, OUTPUT);
  pinMode(addressB, OUTPUT);
  pinMode(addressC, OUTPUT);
  pinMode(addressD, OUTPUT);
//  pinMode(7, OUTPUT);
//  // Prepare read pin 
  pinMode(A0, INPUT);
//    char filename[] = "LOGGER00.CSV";
//  for (uint8_t i = 0; i < 100; i++) {
//    filename[6] = i/10 + '0';
//    filename[7] = i%10 + '0';
//    if (! SD.exists(filename)) {
//      // only open a new file if it doesn't exist
//      logfile = SD.open(filename, FILE_WRITE); 
//      break;  // leave the loop!
//    }
//   logfile.println("channel, value, volts");
Serial.println("Channel, Value, Volts, TFunc");
}

void loop() {
  digitalWrite(addressEN, HIGH);
  //digitalWrite(7, HIGH);
  delay(500);
//  Select each pin and read value
  for(int i=0; i<totalChannels; i++){
    A = bitRead(i,0); //Take first bit from binary value of i channel.
    B = bitRead(i,1); //Take second bit from binary value of i channel.
    C = bitRead(i,2); //Take third bit from value of i channel.
    D = bitRead(i,3);
    //Write address to mux
    digitalWrite(addressA, A);
    digitalWrite(addressB, B);
    digitalWrite(addressC, C);
    digitalWrite(addressD, D);

    //Read and print value
   // Serial.print("Channel ");
    Serial.print(i);
    Serial.print(", ");
   // logfile.print(i);
    //Serial.print(" value: ");
    x = analogRead(A0);
    if (x < 20){
      x = 0; 
    }
    x2 = x; 
    //x= x*1000;
    //logfile.print(x);
    Serial.print(x);
    Serial.print(", ");
    //Serial.print(" volts: ");
    mV = (.00001*(pow(x,3)) - 0.0251*(pow(x,2)) +17.161*x + 32.738)/1000;
    //Serial.println(x);
    //logfile.print(mV);
    Serial.print(mV);
    Serial.print(", ");
    //Serial.print(" TimFunc: ");
    timFunc = ((((0.1* 1024)/analogRead(A0)) - 0.1) / 1000000); 
    Serial.println(timFunc);  
  }


//Serial.println(analogRead(A0));


  delay(500);
}
