#include<Wire.h>
#include<MPU9250.h>
MPU9250 accelgyro(0x68);
int16_t ax,ay,az;
int16_t gx,gy,gz;
int16_t mx,my,mz;


void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Initializing I2C devices....");
  accelgyro.initialize();
  Serial.println("Testing device connectings....");
}

//서브루틴:메인루틴에 기생해서 돌아가는 형태
unsigned long timer;
void loop() {
  accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  mySerial.print("[a,");
  mySerial.print((double)ax / 16384);
  mySerial.print(",");
  mySerial.print((double)ay /16384);
  mySerial.print(",");
  mySerial.print((double)az /16384);
  Serial.print("]");
  Serial.println("");
  Serial.print((double) gx *250 / 32768);
  Serial.print(",");
  Serial.print((double) gy *250 / 32768);
  Serial.print(",");
  Serial.print((double) gz *250 / 32768);
  delay(1000);
  if(millis() - timer > 499) // millis함수: 아두이누의 전원이 인가된후 지금까지 돌아간 시간을 millisec단위로 반환
  {  timer = millis();
  }
}
