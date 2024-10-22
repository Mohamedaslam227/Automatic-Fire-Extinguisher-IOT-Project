# Fire Extinguisher System with Arduino

This project demonstrates a fire extinguisher system using an Arduino Uno. The system detects smoke and flame using sensors and responds by activating a fan to exhaust smoke and a water pump to extinguish fire. A buzzer is also triggered as an alert. The system is controlled through an L298N motor driver module, allowing simultaneous control of the fan and water pump.

## Components Used

- Arduino Uno
- L298N Motor Driver Module
- 12V Power Supply
- Flame Sensor
- Smoke Sensor (MQ-2)
- DC Motor Fan (Exhaust Fan)
- Water Pump
- Buzzer
- Jumper Wires
- Breadboard

## Circuit Diagram

![Circuit Diagram](Automatic-Fire-Extinguisher-IOT-project/1_Circuit Diagram.jpg)

## Project Description

The system operates as follows:
1. **Smoke Detected**: When the smoke sensor detects smoke, the fan is activated to exhaust the smoke from the area.
2. **Flame Detected**: When the flame sensor detects fire, the water pump is activated to extinguish the fire and the buzzer sounds an alert.
3. **Both Smoke and Flame Detected**: If both smoke and flame are detected, the fan, water pump, and buzzer are all activated simultaneously.

### System States
- **Smoke Detected Only**: The fan is activated to exhaust the smoke.
- **Flame Detected Only**: The water pump is activated to spray water, and the buzzer is triggered.
- **Both Smoke and Flame Detected**: All components (fan, pump, and buzzer) are activated.
- **No Detection**: All components are deactivated.

## Code Overview

The code uses digital pins to read sensor data and control the fan, water pump, and buzzer through the L298N motor module.

### Pin Configuration
- `smokePin` (2): Input from the smoke sensor
- `flamePin` (3): Input from the flame sensor
- `fanIN1`, `fanIN2` (5, 6): Control pins for the fan via the L298N motor driver
- `pumpIN3`, `pumpIN4` (7, 8): Control pins for the water pump via the L298N motor driver
- `buzzerPin` (9): Control pin for the buzzer

### Functions
- `activateFan()`, `deactivateFan()`: Functions to control the fan using the L298N motor driver
- `activatePump()`, `deactivatePump()`: Functions to control the water pump using the L298N motor driver
- `activateBuzzer()`, `deactivateBuzzer()`: Functions to control the buzzer

### Main Logic
In the `loop()`, the system continuously monitors the smoke and flame sensors. Depending on the sensor input, it activates or deactivates the fan, water pump, and buzzer as needed. Serial output is also included for debugging purposes.

## How to Use

1. **Hardware Setup**: Connect all components as per the circuit diagram.
2. **Code Upload**: Upload the Arduino code to the Arduino Uno board.
3. **Power Supply**: Connect the 12V power supply to the motor driver and the Arduino.
4. **Testing**: Test the system by simulating smoke and flame using a lighter or similar tool.

## Circuit Design

The system is designed to maintain a clean and well-organized layout. The power supply, motor driver, sensors, and actuators are all connected to the Arduino in an easy-to-follow manner. Ensure that the wiring is secure to avoid loose connections.

## Troubleshooting

- **Fan or Pump Not Working**: Ensure the motor driver is correctly powered and the components are properly connected.
- **No Sensor Detection**: Check the connections of the sensors to the Arduino and ensure they are receiving power.

## Future Improvements

- Add a more advanced sensor to detect the intensity of the flame.
- Integrate a GSM module for remote alerts via SMS in case of fire.
- Develop a web interface to monitor and control the system remotely.

## License

This project is licensed under the MIT License. Feel free to modify and use it for your own projects.

