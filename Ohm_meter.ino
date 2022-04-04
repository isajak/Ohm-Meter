// Defines pin
int analogPin = 0;

// Values for calculations
int read = 0;
int Vin = 5;
float Vout = 0;
float R1 = 10000;
float R2 = 0;
float buffer = 0;

void setup(){
Serial.begin(9600);
}

void loop(){
  
  // Reads voltage in 10 bits (0-1023)
  read = analogRead(analogPin);
  
  // Calculates the resistance of the unknown resistor
  if(read){
    buffer = read * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    Serial.printf("Vout: %d \n", Vout);
    Serial.printf("R2: %d \n", R2);
    delay(1000);
  }
}
