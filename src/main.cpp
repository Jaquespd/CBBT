#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 14

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


int msg=0;
int resistencia = 5;
int bomba = 4;
int ledverde = 12;
int ledvermelho = 13;

float tempDesejada = 0;
float tempAtual = 0;
int modo = 0;

float currentTemperature ();
void printCurrentTemperature ();


void setup()
{
Serial.begin(9600);
sensors.begin();
pinMode(resistencia, OUTPUT);
pinMode(bomba, OUTPUT);
pinMode(ledverde, OUTPUT);
pinMode(ledvermelho, OUTPUT);

digitalWrite(resistencia, 1);
digitalWrite(bomba, 1);
digitalWrite(ledverde, 1);
digitalWrite(ledvermelho, 1);

}

void loop()
{

msg = Serial.read();

if (msg > 0) {
  modo = msg;
}

tempAtual = currentTemperature();
printCurrentTemperature();

if (modo == 1){
  digitalWrite(resistencia, 0);
  digitalWrite(ledverde, 0);
}

if (modo == 2){
  digitalWrite(resistencia, 1);
  digitalWrite(ledverde, 0);
}

if (modo == 3){
  digitalWrite(bomba, 0);
  digitalWrite(ledverde, 0);
}

if (modo == 4){
  digitalWrite(bomba, 1);
  digitalWrite(ledverde, 0);
}

if (modo == 5){
  tempDesejada = 66.7;
  digitalWrite(ledverde, 0);
  if (tempAtual >= tempDesejada ) {
    digitalWrite(resistencia, 1);
  }

  if (tempAtual < tempDesejada ) {
    digitalWrite(resistencia, 0);
  }
}

if (modo == 6){
  tempDesejada = 71.2;
  digitalWrite(ledverde, 0);
  if (tempAtual >= tempDesejada ) {
    digitalWrite(resistencia, 1);
  }

  if (tempAtual < tempDesejada ) {
    digitalWrite(resistencia, 0);
  }
}

if (modo == 7){
  tempDesejada = 75.6;
  digitalWrite(ledverde, 0);
  if (tempAtual >= tempDesejada ) {
    digitalWrite(resistencia, 1);
  }

  if (tempAtual < tempDesejada ) {
    digitalWrite(resistencia, 0);
  }
}

if (modo == 8){
  tempDesejada = 100;
  digitalWrite(ledverde, 0);
  if (tempAtual >= tempDesejada ) {
    digitalWrite(resistencia, 1);
  }

  if (tempAtual < tempDesejada ) {
    digitalWrite(resistencia, 0);
  }
}

delay(1000);
// msg = Serial.read();
// Serial.println(msg);
}


float currentTemperature ()
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.print("Temperature for the device 1 (index 0) is: ");
  //Serial.println(sensors.getTempCByIndex(0));
  return sensors.getTempCByIndex(0);
}

void printCurrentTemperature ()
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  delay(10);
  Serial.print("Temp : ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(10);
}
