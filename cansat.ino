#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SoftwareSerial.h>
 
// Connect VCC of the BMP180 sensor to 3.3V
// Connect GND to Ground
// Connect SCL to i2c clock  thats A5
// Connect SDA to i2c data  thats A4

int RX  = 0;
int TX  = 1;
 
Adafruit_BMP085 bmp;
SoftwareSerial apc220(RX, TX);

void setup()
{
  apc220.begin(9600);
  Serial.begin(9600);
  if (!bmp.begin())
  {
	Serial.println("sensor BMP180 nao encontrado");
	while (1) {}
  }
}
 
void loop() {
    serie();
    radio();
    delay(1000);
}

void serie(){
    Serial.print("Temperatura = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" ºC");
 
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
 
    Serial.println();
}

void radio(){
    apc220.print("Temperatura = ");
    apc220.print(bmp.readTemperature());
    apc220.println(" ºC");
 
    apc220.print("Pressure = ");
    apc220.print(bmp.readPressure());
    apc220.println(" psi");
 
    acp220.println()
}
