#include <Wire.h>
#include <Servo.h>
#include <HUSKYLENS.h>
#include <LiquidCrystal_I2C.h>
// กำหนดพอร์ตเชื่อมต่อเซอร์โว


// สร้างวัตถุเซอร์โว
Servo servoX;

// สร้างวัตถุ Huskylens
HUSKYLENS huskylens;
int R = 0, lastID;
void setup() {
  // เริ่มการสื่อสารกับ Huskylens
  Wire.begin();
  Serial.begin(9600);
  
  // เริ่มการทำงานของ Huskylens
 
  if (!huskylens.begin(Wire)) {
    Serial.println("Huskylens not connected!");
    while (1);
  }
  servoX.attach(9);// แนบเซอร์โวกับพอร์ต PWM

  
  servoX.write(90);// ตั้งค่ามุมเริ่มต้นของเซอร์โว
  
   huskylens.writeAlgorithm(ALGORITHM_FACE_RECOGNITION); //เริ่มฟังก์ชันเชคหน้าตา

 if (huskylens.learn(1)) //เรียนรู้วัตถุที่ 1 เป็นบุคคลปลอดถัย
 {
  
if(result.ID != 1 && lastID != 1) // ถ้าไม่ใช่คนที่1
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("GET OUT!!!");
          
              myDFPlayer.play(01);
              R++;
              delay(2000);
              lastID = 2;
            }
         if(result.ID == 1 && lastID != 1) //ถ้าใช่
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("GET IN ^_^");
          
             
              R++;
              delay(2000);
              lastID = 1;
            }
}

void loop() {    //**********************************************เริ่มเช็คหน้าตา****************************************************************

//  huskylens.writeAlgorithm(ALGORITHM_FACE_RECOGNITION); //เริ่มฟังก์ชันเชคหน้าตา
//
// if (huskylens.learn(1)) //เรียนรู้วัตถุที่ 1 เป็นบุคคลปลอดถัย
// {
//  
//if(result.ID != 1 && lastID != 1) // ถ้าไม่ใช่คนที่1
//            {
//              if(R>3) {  R = 0;   }
//
//              lcd.setCursor(0, R);
//              lcd.print("GET OUT!!!");
//          
//              myDFPlayer.play(01);
//              R++;
//              delay(2000);
//              lastID = 2;
//            }
//         if(result.ID == 1 && lastID != 1) //ถ้าใช่
//            {
//              if(R>3) {  R = 0;   }
//
//              lcd.setCursor(0, R);
//              lcd.print("GET IN ^_^");
//          
//             
//              R++;
//              delay(2000);
//              lastID = 1;
//            }
 } //*****************************จบการทำงานเชคหน้าตา*******************************************
 
   //*****************************เริ่มการทำงานติดตามวัตถุ*****************************************
huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING);  //กำหนดฟังชันที่ใช้ในกล้อง ติดตามวัตถุ
  
  if (huskylens.request()) {                          
    if (huskylens.isLearned() && huskylens.available()) {
      HUSKYLENSResult result = huskylens.read();
      
      // แปลงค่าพิกัด x จาก Huskylens เป็นมุมของเซอร์โว
      int x = result.xCenter; // รับค่า x จาก Huskylens

      // คำนวณมุมที่ต้องการของเซอร์โว
      int angleX = map(x, 320, 0, 45, 135); // ปรับค่าตามความกว้างของ Huskylens

      // สั่งให้เซอร์โวหมุนไปตามมุมที่คำนวณได้
      servoX.write(angleX-50);

      // แสดงผลข้อมูล
      Serial.print("X: ");
      Serial.print(x);
      Serial.print(" AngleX: ");
      Serial.println(angleX);
    }
  }
  delay(20); //หน่วงเวลาการอ่านข้อมูล

}
//*****************************จบการทำงานติดตามวัตถุ***************************************

//*****************************เริ่มการทำงานจำแนกท่าทาง***********************************
huskylens.writeAlgorithm(ALGORITHM_OBJECT_CLASSIFICATION);//ใช้งานฟังก์ชัน
if(result.ID == 1 && lastID != 1)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(1);
              R++;
              delay(2000);
              lastID = 1;
            }
        
        if(result.ID == 2 && lastID != 2)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(1);
              R++;
              delay(2000);
              lastID = 2;
            }
        if(result.ID == 3 && lastID != 3)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(2);
              R++;
              delay(2000);
              lastID = 3;
            }
        if(result.ID == 4 && lastID != 4)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(3);
              R++;
              delay(2000);
              lastID = 4;
            }
         if(result.ID == 5 && lastID != 5)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(4);
              R++;
              delay(2000);
              lastID = 5;
            }
       if(result.ID == 6 && lastID != 6)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(5);
              R++;
              delay(2000);
              lastID = 6;
            }
        if(result.ID == 7 && lastID != 7)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(6);
              R++;
              delay(2000);
              lastID = 7;
            }
       if(result.ID == 8 && lastID != 8)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(7);
              R++;
              delay(2000);
              lastID = 8;
            }
       if(result.ID == 9 && lastID != 9)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(8);
              R++;
              delay(2000);
              lastID = 9;
            }
        if(result.ID == 10 && lastID != 10)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R);
              lcd.print("Fall");
          
              myDFPlayer.play(9);
              R++;
              delay(2000);
              lastID = 10;
            }
       if(result.ID == 11 && lastID != 11)
            {
              if(R>3) {  R = 0;   }

              lcd.setCursor(0, R); 
              lcd.print("Fall");
          
              myDFPlayer.play(10);
              R++;
              delay(2000);
              lastID = 11;
}
