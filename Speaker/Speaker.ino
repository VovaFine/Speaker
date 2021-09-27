#include "DFRobotDFPlayerMini.h"
// библиотека для эмуляции Serial порта
#include <SoftwareSerial.h>
// создаём объект mySoftwareSerial и передаём номера управляющих пинов RX и TX
// RX - цифровой вывод 10, необходимо соединить с выводом TX дисплея
// TX - цифровой вывод 11, необходимо соединить с выводом RX дисплея
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX для плеера DFPlayer Mini 
DFRobotDFPlayerMini myDFPlayer;

int button1 = 6;
int button2 = 7;
int button3 = 8;
boolean flag;

void setup() {
  flag = false;
  pinMode(button1, INPUT_PULLUP); 
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  mySoftwareSerial.begin(9600); 
  Serial.begin(9600);

  delay(100);

  Serial.println();
  Serial.println("DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(300);

  //----Set volume----
  myDFPlayer.volume(20); //Set volume value (0~30).

  //myDFPlayer.play(1); //Воспроизведение первого mp3
  //Serial.println("Playing..");
  //----Читать информацию----
  //Serial.println(myDFPlayer.readState()); //читать состояние mp3
  Serial.println(myDFPlayer.readVolume()); //Текущая громкость 
  //Serial.println(myDFPlayer.readEQ()); // читаем настройку эквалайзера
  Serial.println(myDFPlayer.readFileCounts()); // читать все файлы на SD-карте
  Serial.println(myDFPlayer.readCurrentFileNumber()); // текущий номер файла воспроизведения

  pinMode(4, OUTPUT);
}

void loop() {

int i = digitalRead(5);
Serial.println(i);
digitalWrite(4,!i);
//digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
 // delay(1000);                       // wait for a second
  //digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);
  
if (digitalRead(button1) == LOW) {
      myDFPlayer.play(1); //Воспроизведение 0001 mp3
    //delay(500);
  }
if (digitalRead(button2) == LOW) {
      myDFPlayer.play(2); //Воспроизведение 0002 mp3
    //delay(500);
  }
if (digitalRead(button3) == LOW) {
      myDFPlayer.play(3); //Воспроизведение 0003 mp3
    //delay(500);
  }
}
