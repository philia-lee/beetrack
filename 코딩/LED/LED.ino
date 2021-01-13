#define LED_R 10
#define LED_G 9
#define LED_B 11
bool flag = false;
void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_R, 0);
  digitalWrite(LED_G, 0);
  digitalWrite(LED_B, 0);

}
unsigned long timer;
void loop() {
  if (millis() - timer > 499) // millis함수: 아두이누의 전원이 인가된후 지금까지 돌아간 시간을 millisec단위로 반환
  {
    timer = millis();
    flag = !flag; // flag = !digitalRead(LED_R)
    digitalWrite(LED_R, flag);
    digitalWrite(LED_R, flag);
    digitalWrite(LED_R, flag);
    /*
      digitalWrite(LED_R,flag);
      digitalWrite(LED_R,flag);
      digitalWrite(LED_R,flag);
    */
    /*  if (flag == false)
      {
        digitalWrite(LED_R, 0);
        digitalWrite(LED_G, 0);
        digitalWrite(LED_B, 0);
        flag = true;
      }
      else
      {
        digitalWrite(LED_R, 1);
        digitalWrite(LED_G, 1);
        digitalWrite(LED_B, 1);
        flag = false;
      }
    */

  }


}
