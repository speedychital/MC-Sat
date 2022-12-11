#include <TroykaDHT.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, ll); //RX,TX
int measurePin = A0;
int ledPower = 12;
int pressure = A1;
DHT dht(4,DHT11);
unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
int pressu;
float temperature;

void setup() {
Serial.begin(9600);
mySerial.begin(9600);
pinMode(ledPower.OUTPUT);
dht.begin();
}

void loop() {
  pressure1();
  delat(2000);
  dust();
  delay(1000);
  temp();
  delay(1000);
}
  
void pressure1()
{
  pressu = analogRead(pressure);
  mySerial.println("Pressure value is:");
  mySerial.println(pressu);
  Serial.print("P");
  split(pressu);
 }
 
void dust() {
  digitalWrite(ledPwer.LOW);
  delayMicroseconds(sampingTime);
  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower.HIGH);
  delayMicroseconds(sleepTime);
  
  calcVoltage  voMeasured*(5.0/1024);
  dustDensity = 0.17*calcVoltage-0.1;
  if(dustDensity < 0) {
    dustDensity = 0.0;
  }
  
  mySerial.println("Raw Signal");
  mySerial.println(voMeasured);
  Seria.print("A");
  split(calcVoltage);
  mySerial.println("Dust Density:");
  mySerial.println(dustDensity);
  Serial.print("D");
  split(dustDensity);
  delay(1000);
}

void temp() {
  dht.read();
  temperature - dht.getTemperatureC();
  Serial.print("T");
  split(temperature);
  delay(2000);
}

void split(unsigned long int x) 
{
  unsigned long int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
  unsigned long int remainder;
  unsigned long int num;
  unsigned long int joined_value;
  num = x;
  d4 = num%10;
  num = num/10;
  d3 = num%10;
  num=num/10;
  d2=num%10;
  num=num/10;
  d1 = num%10;
  num=num/10;
  Serial.write(d1+0x30);
  Serial.write(d2+0x30);
  Serial.write(d3+0x30);
  Serial.write(d4+0x30);
  Serial.println("'");
  delay(300);
}
