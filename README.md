# Motion-Activated-LED-Control-System


Welcome to the Motion-Activated LED Control System project! This project aims to design and implement an interactive lighting system that dynamically adjusts LED intensity based on detected motion proximity. By using a PIC microcontroller and integrating motion sensors with LED arrays, this system provides an energy-efficient and user-friendly lighting solution for indoor spaces.

## Project Objectives
- Design a system that adjusts LED lighting intensity based on motion proximity.
- Incorporate user-centric design principles for a seamless and intuitive user experience.
- Enhance safety and awareness with warnings displayed on an LCD interface.
- Ensure efficient energy utilization.

## System Overview
The system consists of the following key components:
- PIC18F4525 Microcontroller: Acts as the central control unit.
- LED Arrays: Provides dynamic lighting based on detected motion.
- HC-SR04 Ultrasonic Sensor: Detects motion and calculates distance.
- SunFounder IIC I2C TWI 1602 Serial LCD Module Display: Displays warnings and system status.
- PWM Control: Adjusts LED brightness.
- I2C Communication: Interfaces with the LCD.
- Timer1: Calculates distance from the ultrasonic sensor.

## Hardware Components
| Name/Model | Price | Quantity | Source |
| --- | --- | --- | --- |
| PIC18F4525 | x | 1 | Microchip |
| LEDs | $5.99 | 12 | Amazon |
| Resistors | $3.99 | 15 | Amazon |
| Capacitors | $2.99 | 2 | Amazon |
| Wires | $5.99 | x | Amazon |
| Breadboards (ELEGOO 3pcs Breadboard 830 Point Solderless Prototype PCB Board) | $8.99 | 3 | Amazon |
| SunFounder IIC I2C TWI 1602 Serial LCD Module Display | $9.99 | 1 | Amazon |
| HC-SR04 Ultrasonic Sensor Module | $6.99 | 1 | Amazon |

## Software Tools
- MPlabs IDE: Version: 2.46, Project Type: Standalone C project
- Smart Draw: Used for creating circuit diagrams

## Implementation Highlights
- The system uses a PIC microcontroller to control LED brightness and interact with the LCD display.
- PWM control adjusts the LED lighting intensity based on occupancy and ambient light levels.
- I2C communication interfaces with the LCD display.
- Timer1 calculates distance from the ultrasonic sensor.

## Experimental Results
- The project successfully utilized a PIC microcontroller as the central control unit.
- Hardware was built from scratch, meeting the requirement of not using premade PIC circuit boards.
- Peripheral components such as PWM control, I2C communication, and Timer1 were effectively integrated.

## Discussion and Conclusion
The project demonstrates the practical application of embedded systems engineering principles. Despite challenges such as switching PIC microcontrollers and adapting an Arduino-tailored LCD, the project successfully achieved its objectives. The development process enhanced our understanding of embedded systems and provided valuable hands-on experience.

## How to Use
1. Setup the Hardware: Connect the components according to the schematic provided in the project report.
2. Upload the Code: Use MPlabs IDE to upload the provided code to the PIC18F4525 microcontroller.
3. Power the System: Once the hardware is set up and the code is uploaded, power the system to begin operation.
4. Monitor the LCD: Observe the LCD for system warnings and status updates.
5. Interact with the System: Approach the ultrasonic sensor to see the LED intensity adjust based on your proximity.
