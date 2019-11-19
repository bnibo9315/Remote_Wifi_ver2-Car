#include <AFMotor.h>

int dir;
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor(2);
static char text_send ;
void setup() {

  Serial.begin(115200);           // mở cổng Serial monitor 9600 bps
  Serial.println("Hello my racing");
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  motor1.setSpeed(255);  // Set motor 1 to maximum speed
  motor2.setSpeed(255);
}

void loop() {
  if (Serial.available()) {
    text_send = Serial.read();
    Serial.println(text_send);
    dir = text_send;
    switch (dir) {
      case '1':
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        Serial.println("Up");
        break;
      case '2':
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        Serial.println("Down");
        break;
      case '3':
        motor1.run(FORWARD);
        motor2.run(RELEASE);
        Serial.println("Left");
        break;
      case '4':
        motor1.run(RELEASE);
        motor2.run(FORWARD);
        Serial.println("Right");
        break;
      case '5':
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        Serial.println("Stop");
        break;
      default:
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        break;
    }
  }

}
