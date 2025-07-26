# 🐠 Aquarium Automation System

An Arduino-based smart aquarium system that automatically monitors water levels and feeds the fish. The project uses a servo motor, ultrasonic sensor, water level sensor, and buzzer for alerting and automation.

## 📌 Features

- 📏 **Water Level Monitoring**: Alerts when water level drops below a threshold using analog water level sensor and buzzer.
- 🔊 **Buzzer Alert**: Notifies users with a buzzer when the water level is low.
- 🐟 **Automatic Feeding**: Uses a servo motor and ultrasonic sensor to detect proximity and trigger the feeding mechanism.
- 🧠 Built with Arduino C/C++.

## 🧰 Hardware Used

- Arduino Uno
- Water Level Sensor
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90)
- Buzzer
- Breadboard, Jumper Wires

## 🛠️ How It Works

- **Water Level**: Analog readings from a sensor determine if the level is below a safe range.
- **Feeding**: If a presence is detected via the ultrasonic sensor, the servo rotates to release food.
- **Buzzer**: Beeps when water level is dangerously low.

## 🧪 Code

Check the `aquarium.ino` file for the full implementation.

---

Feel free to fork or suggest improvements!
