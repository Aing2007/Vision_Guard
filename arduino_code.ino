// เรียกใช้งานฟังก์ชั่นจากภายนอก
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#include <SoftwareSerial.h>

// กำหนดค่าคงที่ที่จะใช้ในโปรแกรม
#define OLED_RESET -1

// ตั้งค่าสำหรับการใช้งาน WIFI
#define BLYNK_PRINT Serial

#define WIFI_SSID "Aingza"                   //  ชื่อ wifi hotspot
#define WIFI_PASSWORD "aing1234"        //   password

//#define LINE_TOKEN "S2HeRnFkrXO6QDOCQGbmnqxULp6uN9XKq8Lx4it1Q3S"           // Line  token
#define LINE_TOKEN "mThaWDjFqJlzzl11CASrAsGASrp7nl1G80ccWGhp6Sc"           // Line  token

SoftwareSerial arduinocon(5, 4);    // เชื่อมต่อกับบอร์ด ESP8266

void setup() 
{
  Serial.begin(115200);
    arduinocon.begin(57600);     // เชื่อมต่อกับบอร์ด ESP8266
    
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
//  SPI.begin();          // Initiate  SPI bus
    
// กำหนดพอร์ต ที่จะใช้งาน  
  pinMode(D4, INPUT);
  pinMode(D0, OUTPUT);

}
//************************************************************************************

void loop() 
{
  LINE.setToken(LINE_TOKEN);  
    int a = arduinocon.parseInt();
    Serial.print("Data : ");
    Serial.println(a);       //   แสดงข้อความที่ได้รับ

  
  if(a == 0 )     //  ถ้า......  เงื่อนไขให้ส่ง ไลน์
   {
    Serial.println("ส่งไลน์ ");

    digitalWrite(D0,1);
    delay(500);
   
//   Send line
   LINE.notify("พบคนแปลกหน้า!!!!");           // ส่งข้อความไปที่ Line
      
//   LINE.notify(name1);                       // ส่งชื่อ  (ถ้ามี)
//  LINE.notify(....);                         // ส่งข้อมูลอื่นๆ
  
// เลือก Line Sticker 
  LINE.notifySticker(2, 512);               // ส่ง Line Sticker 
  delay(3000);
}
if(a == 1 )     //  ถ้า......  เงื่อนไขให้ส่ง ไลน์
   {
    Serial.println("ส่งไลน์ ");

    digitalWrite(D0,1);
    delay(500);
   
//   Send line
   LINE.notify("พบคนล้ม!!!");           // ส่งข้อความไปที่ Line
      
//   LINE.notify(name1);                       // ส่งชื่อ  (ถ้ามี)
//  LINE.notify(....);                         // ส่งข้อมูลอื่นๆ
  
// เลือก Line Sticker 
  LINE.notifySticker(2, 512);               // ส่ง Line Sticker 
  delay(3000);
}
else
{
  digitalWrite(D0, 0);                  // ถ้าไม่มีเหตุการณ์ใดๆ  ให้ไฟแดงดับ
}
 
}

//*********************************************************
