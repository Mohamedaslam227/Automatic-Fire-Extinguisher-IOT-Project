# 🔥 Fire Extinguisher System with Arduino

This project demonstrates an innovative **Fire Extinguisher System** utilizing an **Arduino Uno** to detect smoke and flame, activating an exhaust fan and water pump in response. A buzzer serves as an alert system, and all components are controlled through an **L298N motor driver module**, allowing simultaneous operation.

## 📦 Components Used

- **Arduino Uno**
- [**L298N Motor Driver Module**](https://www.electronicwings.com/nodemcu/l298n-dual-h-bridge-motor-driver-module)
- **12V Power Supply**
- [**Flame Sensor**](https://www.sparkfun.com/products/14015)
- [**Smoke Sensor (MQ-2)**](https://www.electronicwings.com/sensors/mq-2-gas-sensor-module)
- **DC Motor Fan (Exhaust Fan)**
- **Water Pump**
- **Buzzer**
- **Jumper Wires**
- **Breadboard**

## 🛠️ Circuit Diagram

![Circuit Diagram](1_Circuit%20Diagram.jpg)

## 🧿 Block Diagram

![Block Diagram](1_Block%20Diagram.png)

## 🚀 Project Description

The system operates as follows:

1. **Smoke Detected**: The smoke sensor triggers the fan to exhaust smoke.
2. **Flame Detected**: The flame sensor activates the water pump to extinguish the fire, and the buzzer sounds an alert.
3. **Both Smoke and Flame Detected**: All components (fan, water pump, and buzzer) are activated simultaneously.

### 📊 System States

| **State**                | **Action**                                     |
|--------------------------|------------------------------------------------|
| Smoke Detected Only      | Activate the fan to exhaust smoke              |
| Flame Detected Only      | Activate the water pump and sound the buzzer   |
| Both Smoke and Flame     | Activate fan, pump, and buzzer simultaneously   |
| No Detection             | Deactivate all components                       |

## 💻 Code Overview

### Pin Configuration

- `smokePin` (2): Input from the smoke sensor
- `flamePin` (3): Input from the flame sensor
- `fanIN1`, `fanIN2` (5, 6): Control pins for the fan via the L298N motor driver
- `pumpIN3`, `pumpIN4` (7, 8): Control pins for the water pump via the L298N motor driver
- `buzzerPin` (9): Control pin for the buzzer

### 📜 Functions

- `activateFan()`, `deactivateFan()`: Control the fan
- `activatePump()`, `deactivatePump()`: Control the water pump
- `activateBuzzer()`, `deactivateBuzzer()`: Control the buzzer

### 🔄 Main Logic

The `loop()` function continuously monitors the smoke and flame sensors, activating or deactivating components based on the input. Serial output aids in debugging.

## 🏗️ How to Use

1. **Hardware Setup**: Connect all components as shown in the circuit diagram.
2. **Code Upload**: Upload the provided Arduino code to the Arduino Uno board.
3. **Power Supply**: Connect the 12V power supply to the motor driver and the Arduino.
4. **Testing**: Simulate smoke and flame using a lighter or similar tool to test the system.

## ⚙️ Troubleshooting

- **Fan or Pump Not Working**: Check motor driver power and component connections.
- **No Sensor Detection**: Ensure sensors are properly connected and powered.

## 🚀 Future Improvements

- Incorporate advanced flame intensity detection.
- Integrate a [**GSM module**](https://www.electronicwings.com/nodemcu/gsm-sim800l-module) for SMS alerts during a fire event.
- Develop a web interface for remote monitoring and control.

## 📜 License

This project is licensed under the [MIT License](LICENSE). Feel free to modify and use it for your projects!
