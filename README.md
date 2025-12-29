🚒 Automatic Fire-Fighting System using Arduino

An Arduino-based Automatic Fire-Fighting System designed to detect fire direction and autonomously suppress it using a servo-controlled water spraying mechanism. The system ensures quick response, minimal human intervention, and improved safety.

📌 Project Overview

Fire accidents require immediate action. This project demonstrates a direction-aware fire detection and suppression system using dual flame sensors. Based on the detected flame location, the system intelligently rotates a servo-mounted water nozzle toward the fire source and activates a water pump via a relay module to extinguish it.

This project focuses on embedded system fundamentals, sensor interfacing, actuator control, and real-time automation logic.

🎯 Objectives

Detect fire presence and direction (Left / Right)

Automatically rotate the nozzle toward the fire source

Activate a water pump without human intervention

Build a low-cost, scalable fire safety prototype

Gain practical experience in embedded systems

⚙️ System Working

Two flame sensors continuously monitor the surroundings.

When a flame is detected:

The Arduino determines the direction of the fire.

The servo motor rotates toward the detected flame.

The relay module activates the water pump.

Water is sprayed directly onto the fire source.

If no flame is detected, the system remains idle.

🛠️ Components Used

Arduino UNO

Flame Sensor Module × 2

Servo Motor (SG90)

Relay Module (5V)

Mini Water Pump

External Power Supply

Jumper Wires

Water Pipe

Base Structure (Prototype Mount)

🔌 Pin Connections
Flame Sensors
Sensor	Arduino Pin
Left Flame Sensor (DO)	D2
Right Flame Sensor (DO)	D3
VCC	5V
GND	GND
Servo Motor
Servo Wire	Arduino
Signal	D9
VCC	External 5V
GND	Common GND
Relay Module
Relay Pin	Arduino
IN	D8
VCC	5V
GND	GND
🧠 Logic Summary
Condition	Action
Fire on Left	Servo rotates left + Pump ON
Fire on Right	Servo rotates right + Pump ON
Fire on Both	Servo centers + Pump ON
No Fire	Pump OFF
💻 Arduino Code
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

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF
  fireServo.attach(SERVO_PIN);
  fireServo.write(90); // Center position

  Serial.begin(9600);
}

void loop() {
  int leftFlame = digitalRead(FLAME_LEFT);
  int rightFlame = digitalRead(FLAME_RIGHT);

  if (leftFlame == LOW && rightFlame == HIGH) {
    fireServo.write(40);
    digitalWrite(RELAY_PIN, LOW);
  }
  else if (rightFlame == LOW && leftFlame == HIGH) {
    fireServo.write(140);
    digitalWrite(RELAY_PIN, LOW);
  }
  else if (leftFlame == LOW && rightFlame == LOW) {
    fireServo.write(90);
    digitalWrite(RELAY_PIN, LOW);
  }
  else {
    fireServo.write(90);
    digitalWrite(RELAY_PIN, HIGH);
  }

  delay(200);
}

🧪 Testing & Calibration

Adjust flame sensor potentiometers to detect flame accurately

Use external 5V power for servo motor

Ensure common ground between Arduino and external power

Test each module individually before full integration

📈 Skills Demonstrated

Embedded C programming

Sensor interfacing

Servo motor control

Relay-based load switching

Real-time automation logic

Hardware debugging & integration

🚀 Future Enhancements

Buzzer or GSM alert system

IoT-based fire monitoring (ESP32 + Cloud)

Automatic fire location tracking (180° scan)

Fire intensity measurement

Mobile app integration

👤 Author

Karthik Arjun Kalavakunta
Electronics & Communication Engineering (ECE)
Embedded Systems & Automation Enthusiast

📌 Open to internships, research opportunities, and collaborations.

⭐ Acknowledgment

This project was developed as part of self-learning and practical exploration in embedded systems and automation.
