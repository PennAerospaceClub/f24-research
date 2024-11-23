// void writeSD(String dataString){
//   File dataFile = SD.open("datalog.csv", FILE_WRITE);
//   if (dataFile) {
//     dataFile.println(dataString);
//     dataFile.close();
//   }
// }

String mkdata(){
  String data = 
  //ATM data
  "pascals:" + String(pascals, 4) + "," +
  "humidity:" + String(humidity, 2) + "," +
  "gas:" + String(gas, 2) + "," +
  "altm:" + String(altm, 2) + "," +
  "tempC:" + String(tempC, 2) + "," +
  //LUX data
  "lum:" + String(lum, 4) + "," +
  "ir:" + String(ir, 4) + "," +
  "lux:" + String(lux, 4) + "," + 
  "voltage1:" + String(voltage1) + "," + 
  "voltage1:" + String(voltage2);
  return data;
}
