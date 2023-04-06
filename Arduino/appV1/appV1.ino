#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <Wire.h>

//SUHU && LCD
//SDA - G21
//SCL - G22
//
//RFID
//RST - G4
//MISO - G19
//MOSI - G23
//SDA - G5
//SCK - G18
//
//IR
//OUT - G25
//
//BUTTON
//1 - G26
//2 - G27
//
//BUZZ
//+ - G0


#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14 //D5
#define RelayPin4 12 //D6

#define SwitchPin1 0  //D3
#define SwitchPin2 2   //D4
#define SwitchPin3 13  //D7
#define SwitchPin4 3   //RX

#define wifiLed   16   //D0

int Led_OnBoard = 2;
const int buzz = 0;
const int ir = 25;

bool quit = 0;
String iData1 = "1";
String iData2 = "2";
String iData3 = "3";
String iData4 = "36";

float temp;
String stats = "";
String sendMode = "absen";
String postData;
String Data1;
String Data2;
String Data3;
String Data4;
//String host = "192.168.43.135";
//String host = "testingstarproject.000webhostapp.com";
//String host = "wirapustaka.ninapst.com";
//String host = "rizalscompanylab.my.id";
String host = "api.rizalscompanylab.my.id";

//const char* ssid = "LIMITED";
//const char* password = "12344321";
//const char* ssid = "Redmi Note 10S";
//const char* password = "11111111";
//const char* ssid = "STAR";
//const char* password = "skansawira";

const char* ssid = "Adit";
const char* password = "11011111";


//String url = "http://" + host + "/Krenova/GitFolder/Peminjaman-Buku-1/PHP/admin/fungsiAdmin.php";
//String url = "http://" + host + "/SmartHomeRCL/CodeIgniter/req/";
//String url = "https://" + host + "/index.php";
//String url = "https://" + host + "/admin/fungsiAdmin.php";
String url = "http://" + host + "/SmartHome/req";
String dataUpload[10];

void setup() {
  Serial.begin(115200);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  
  Serial.println("OK.");
  digitalWrite(Led_OnBoard, HIGH);
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    reqGET(iData1, iData2, sendMode, iData4);
    delay(1000);
}

void reqGET(String satu,String dua, String tiga, String empat) {
  HTTPClient http;
  Data1 = String(satu);
  Data2 = String(dua);
  Data3 = String(tiga);
  Data4 = String(empat);
 
//  postData = "Data1=" + Data1 + "&Data2=" + Data2 + "&Data3=" + Data3 + "&Data4=" + Data4 ;
  postData = "id=1";
  Serial.println(postData);
//  postData = "/index/id/1" ;
//  Serial.println(postData);
  
  http.begin(url);
  Serial.println(url);
  
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  Serial.println("uploading..");

  int httpCode = http.GET();
//  int httpCode = http.PUT(postData);
  
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.print("py :");
  Serial.println(payload);
  
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, payload);
  for (size_t i = 0; i < doc.size(); i++) {
//    bool statusDevice = doc[i]["status"].as<bool>(); //mengambil status dari objek ke-i
//    int pin = doc[i]["pin"];
//    Serial.print("Status dari id ");
//    Serial.print(doc[i]["id"].as<String>());
//    
//    Serial.print(": ");
//    Serial.println(statusDevice);
//    digitalWrite(pin, statusDevice);
    String statusStr = doc[i]["status"].as<String>(); //mengambil status dari objek ke-i sebagai nilai boolean
    bool statusDevice = statusStr.toInt();; //mengambil status dari objek ke-i sebagai nilai boolean
    int pin = doc[i]["id"];
    Serial.print("Status dari id ");
    Serial.print(doc[i]["id"].as<String>()); //mengambil nilai id sebagai string dan mencetaknya
    Serial.print(": ");
    Serial.print(statusDevice);
    Serial.print(" - ");
    Serial.println(statusDevice ? "ON" : "OFF");
    if (pin == 1){
      digitalWrite(RelayPin1, statusDevice);
    } else if (pin == 2) {
      digitalWrite(RelayPin2, statusDevice);
    } else if (pin == 3) {
      digitalWrite(RelayPin3, statusDevice);
    } else if (pin == 4) {
      digitalWrite(RelayPin4, statusDevice);
    }
  }
  
//  bool id    = doc["id"][0];
//  String nameD   = doc["name"][0];

//  Serial.println(id);
//  Serial.println(nameD);
  
  http.end();
}
