#include <Servo.h>

#define FLAME_LEFT 2
#define FLAME_RIGHT 3
#define RELAY_PIN 8
#define SERVO_PIN 9

Servo fireServo;

void setup() {
  pinMode(FLAME_LEFT, INPUT);
  pinMode(FLAME_RIGHT, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF (most modules are active LOW)

  fireServo.attach(SERVO_PIN);
  fireServo.write(90); // Center position

  Serial.begin(9600);
}

void loop() {
  int leftFlame = digitalRead(FLAME_LEFT);
  int rightFlame = digitalRead(FLAME_RIGHT);

  Serial.print("Left: ");
  Serial.print(leftFlame);
  Serial.print(" | Right: ");
  Serial.println(rightFlame);

  // 🔥 Flame on LEFT
  if (leftFlame == LOW && rightFlame == HIGH) {
    fireServo.write(40);          // Turn LEFT
    digitalWrite(RELAY_PIN, LOW); // Pump ON
  }
  // 🔥 Flame on RIGHT
  else if (rightFlame == LOW && leftFlame == HIGH) {
    fireServo.write(140);         // Turn RIGHT
    digitalWrite(RELAY_PIN, LOW); // Pump ON
  }
  // 🔥 Flame on BOTH sides
  else if (leftFlame == LOW && rightFlame == LOW) {
    fireServo.write(90);          // Center
    digitalWrite(RELAY_PIN, LOW); // Pump ON
  }
  // ❌ No flame
  else {
    fireServo.write(90);          // Center
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
  }

  delay(200);
}
