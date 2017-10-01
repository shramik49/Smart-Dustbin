
/***************************************************
 DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>
 
 ***************************************************
 This example shows the all the function of library for DFPlayer.
 
 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/
#include <NewPing.h>2
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
int step = 0;
#include <Servo.h>;
Servo myservo;
int pos = 0;
int dist1;
int dist2 ;
NewPing sonar1(5, 6, 100); 
NewPing sonar2(10, 11, 100);
int led1 = 13;
int led2 = 12;
int led3 =9;
unsigned long timer;
byte musicPlaying0 = false;
unsigned long musicStartMillis0 = 0;
byte musicPlaying1 = false;
unsigned long musicStartMillis1 = 0;
byte musicPlaying2 = false;
unsigned long musicStartMillis2 = 0;
byte musicPlaying3 = false;
unsigned long musicStartMillis3 = 0;
byte musicPlaying4 = false;
unsigned long musicStartMillis4 = 0;
byte musicPlaying5 = false;
unsigned long musicStartMillis5 = 0;
byte musicPlaying6 = false;
unsigned long musicStartMillis6 = 0;
byte musicPlaying7 = false;
unsigned long musicStartMillis7 = 0;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  myservo.attach(3);
  Serial.begin (9600);
  mp3_set_serial (Serial);     
  delay(1);                     
  mp3_set_volume (30);
}
void loop() {
 switch(step) {
    case 0: do_step_0(); break;
    case 1: do_step_1(); break;
    case 2: do_step_2(); break;
    case 3: do_step_3(); break;
    case 4: do_step_4(); break;
    case 5: do_step_5(); break;
    case 6: do_step_6(); break;
    case 7: do_step_7(); break;
    case 8: do_step_8(); break;
  }
}
void check(){
   timer = millis();   
  millis() - timer >= 50 ;                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  dist1 = (uS1 / US_ROUNDTRIP_CM);  // Convert ping time to cm and print result.
  Serial.print(dist1);                                          //print the distance.
  Serial.println("dist1cm");
  unsigned int uS2 = sonar2.ping(); // Send ping, get ping time in microseconds (uS).
  dist2 = (uS2 / US_ROUNDTRIP_CM);  // Convert ping time to cm and print result.
  Serial.print(dist2);                                          //print the distance.
  Serial.println("dist2cm");
}
  void do_step_0() {
    check();
 if (((dist1>0)&&(dist1<40))||((dist2>0)&&(dist2<40)))
 {
  step = 1;
 
 }
  }
 void do_step_1() {
    if (musicPlaying3 == false) {
            musicStartMillis3 = millis();
            musicPlaying3 = true;
            mp3_play (1);
    }
    else {
        if (millis() - musicStartMillis3 > 3200) {
            mp3_stop ();
            step = 3;
            musicPlaying3 = false;
        }
    }
}
 
  void do_step_2()
{
  if (musicPlaying4 == false) {
    musicStartMillis4 = millis();
    musicPlaying4 = true;
    mp3_play (8);
  }
  else {
    if (millis() - musicStartMillis4 > 3200) {
      mp3_stop ();
      step = 0;
      musicPlaying4 = false;
    }
  }
}
void do_step_3() {
    if (musicPlaying0 == false) {
      check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis0 = millis();
            musicPlaying0 = true;
            digitalWrite(led1,HIGH);
            mp3_play (2);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis0 > 6200) {
            mp3_stop ();
            digitalWrite(led1,LOW);
            step = 4;
            musicPlaying0 = false;
        }
    }
}
void do_step_4() {
    if (musicPlaying1 == false) {
      check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis1 = millis();
            musicPlaying1 = true;
            digitalWrite(led2,HIGH);
            mp3_play (3);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis1 > 6200) {
            mp3_stop ();
            digitalWrite(led2,LOW);
            step = 5;
            musicPlaying1 = false;
        }
    }
}
void do_step_5() {
 if (musicPlaying2 == false) {
  check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis2 = millis();
            musicPlaying2 = true;
            digitalWrite(led3,HIGH);
            mp3_play (4);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis2 > 5400) {
            mp3_stop ();
            digitalWrite(led3,LOW);
            step = 6;
            musicPlaying2 = false;
        }
    }
}
void do_step_6() {
    if (musicPlaying5 == false) {
      check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis5 = millis();
            musicPlaying5 = true;
            digitalWrite(led1,HIGH);
            mp3_play (5);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis5 > 7100) {
            mp3_stop ();
            digitalWrite(led1,LOW);
            step = 7;
            musicPlaying5 = false;
        }
    }
}
void do_step_7() {
    if (musicPlaying6 == false) {
      check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis6 = millis();
            musicPlaying6 = true;
            digitalWrite(led2,HIGH);
            mp3_play (6);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis6 > 7100) {
            mp3_stop ();
            digitalWrite(led2,LOW);
            step = 8;
            musicPlaying6 = false;
        }
    }
}
void do_step_8() {
 if (musicPlaying7 == false) {
   check();
        if (((dist1>0) && (dist1<50)) || ((dist2>0) && (dist2<50))) {
            musicStartMillis7 = millis();
            musicPlaying7 = true;
            digitalWrite(led3,HIGH);
            mp3_play (7);
        }
        else {
            step = 2;
        }
    }
    else {
        if (millis() - musicStartMillis7 > 8100) {
            mp3_stop ();
            digitalWrite(led3,LOW);
            step = 3;
            musicPlaying7 = false;
        }
    }
}
