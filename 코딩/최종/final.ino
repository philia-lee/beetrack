#include <SoftwareSerial.h>
#include<Wire.h>
#include<MPU9250.h>
MPU9250 accelgyro(0x68);
int16_t ax,ay,az;
int16_t gx,gy,gz;
int16_t mx,my,mz;

int RX = 3;
int TX = 2;
SoftwareSerial mySerial(RX, TX);
int dir_l = 4;
int dir_r = 7;
int pwm_l = 6;
int pwm_r = 5;

void moving(int dirl, int dirr, int pwml, int pwmr)
{
  digitalWrite(dir_l, dirl);
  digitalWrite(dir_r, dirr);
  analogWrite(pwm_l, pwml);
  analogWrite(pwm_r, pwmr);
}
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(dir_l, OUTPUT);
  pinMode(dir_r, OUTPUT);
  pinMode(pwm_l, OUTPUT);
  pinMode(pwm_r, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

char btbuf;
unsigned long timer;
unsigned long timer1;
bool flag1 = false;
unsigned long timer3;
unsigned long count;
bool flagc = false;
unsigned long timer2;
void loop() {
  accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  mySerial.print("[a,");
  mySerial.print((double)ax / 16384);
  mySerial.print(",");
  mySerial.print((double)ay /16384);
  mySerial.print(",");
  mySerial.print((double)az /16384);
  mySerial.print("]");
  mySerial.println("");
  
  if(millis() - timer > 499) // millis함수: 아두이누의 전원이 인가된후 지금까지 돌아간 시간을 millisec단위로 반환
  {  timer = millis();
  }
  if (flagc)
  {
    if((millis() - timer3)>3999)
    {
      timer3 = millis();
      mySerial.println(count);
      count++;
    }
  }
  // put your main code here, to run repeatedly:
  if (mySerial.available())
  {
    btbuf = mySerial.read();
    Serial.println(btbuf);//dubugging
    if (btbuf > 96)
    {
      Serial.println("Stop");
      moving(HIGH, HIGH, 0, 0);
    }
    else
    { 
      if ('S' == btbuf)
      {
        moving(1, 1, 0, 0);
      }
      if ('F' == btbuf)
      {
        Serial.println("Forward");
        moving(1, 1, 100, 100);
        flagc = true;
      }
      else if ('D' == btbuf)
      {
        
        Serial.println("backward");
        moving(0, 0, 100, 100);
      }
      else if ('L' == btbuf)
      {
        Serial.println("leftward");
        moving(1, 1, 50, 100);
      }
      else if ('R' == btbuf)
      {
        Serial.println("rightward");
        moving(1, 1, 100, 50);
      }
      
    }
  }
  if ((millis() - timer > 499))
  {
    timer = millis();
    digitalWrite(9, !digitalRead(9));
    if (flag1)
    {
      analogWrite(9, 200);
      analogWrite(10, 145);
      analogWrite(11, 57);
    }
    else
    {
      flag1 = true;
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 255);
    }
  }
  if ((millis() - timer1 > 799))
  {
    timer1 = millis();
    digitalWrite(10, !digitalRead(10));
  }
}
