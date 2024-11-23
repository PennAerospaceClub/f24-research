#include <Wire.h>               //OLED/LUX
#include <SPI.h>                //SD/ATM
#include <SD.h>                 //SD
#include <TinyGPS++.h>          //GPS
#include <Adafruit_SSD1306.h>   //OLED
#include <Adafruit_Sensor.h>    //ATM/LUX
#include <Adafruit_BME680.h>    //ATM
#include "Adafruit_TSL2591.h"   //LUX
#include "Adafruit_SHT31.h"     // TEMP/HU
#include <MKRIMU.h>             // IMU

#include <IridiumSBD.h>
#define IridiumSerial Serial3
#define DIAGNOSTICS false // Change this to see diagnostics

//=====================================
//ATM =================================
#define SEALEVELPRESSURE_HPA (1013.2)
#define BME_SCK 40
#define BME_MISO 41
#define BME_MOSI 42
#define BME_CS 43
Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

//Rockblock variables =======================
IridiumSBD modem(IridiumSerial);

uint8_t buffer[200] = 
{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

int buzzerPin = 11;

int sq;

//=====================================

//ATM variables =======================
float pascals;
float altm;
float humidity;
float gas;
float tempC;

//=====================================
//LUX =================================
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

//LUX variables =======================
uint32_t lum;
int16_t ir, full;
float lux;

 TinyGPSPlus gps;
double latit;   //degrees
double longit;  //degrees
double alt;     //meters
double alto;
double velDiff;
double vel[] = {0, 0, 0, 0, 0}; //meters
long gpstime;   //HHMMSSCC
long gpsdate;   //DDMMYY
int numsats;
double course;  //degrees
double speed;   //mph

double voltage1;
double voltage2;

//SD Card ==================================
#define chipSelect 53

//TEMP/HU ==================================
Adafruit_SHT31 sht31 = Adafruit_SHT31();
double sht31_temp;
double sht31_humidity;

//IMU ====================
float xG;
float yG;
float zG;
float xA;
float yA;
float zA;

void setup() {
  //Serial
  Serial.begin(115200); //Computer

}

void loop() {
  // put your main code here, to run repeatedly:
  sanity();
  String data = mkdata();
  Serial.println(data);

}
