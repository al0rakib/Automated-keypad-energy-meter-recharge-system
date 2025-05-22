
# Automating Digital Prepaid Keypad Energy Meters via Mobile App Interface

This project presents a solution to automate the manual button-pressing process of prepaid keypad energy meters. The system integrates Arduino-controlled motors and a mobile app interface for wireless remote control. The project is ideal for improving accessibility and convenience in energy meter recharging.

## 📂 Project Files

- `Keypad Energy Meter.ino` – Arduino code for controlling motors and interpreting commands
- `Keypad Energy Meter Recharge.apk` – Android mobile app for remote operation
- `Circuit Diagram of Automatic Recharge Keypad Energy Meter.fzz` – Fritzing file for hardware layout
- `Automating Digital Prepaid Keypad Energy Meters via Mobile App Interface report.pdf` – Full project report and documentation
- `Automating Digital Prepaid Keypad Energy Meters via Mobile App Interface presentation.pptx` – Project slides
- `metadata.txt` – Project metadata and context

## 🛠 Hardware Used

- 12V Stepper Motor with slider
- SG90 Servo Motor
- Arduino Uno R3
- Bluetooth Module (HC-06)
- L298N Motor Driver

## 📱 Mobile App Interface

- Built with MIT App Inventor
- Connects to Arduino via Bluetooth (HC-06)
- Sends 5-digit token input for automated pressing

## ⚙️ System Workflow

1. User enters a 5-digit recharge token in the app
2. App sends token to Arduino via Bluetooth
3. Motors position themselves to each key
4. Servo presses each key in sequence
5. Motors reset to initial position

## 🌐 Future Improvements

- Add Wi-Fi module for better range and reliability
- Implement feedback system for missed steps
- Use compact precision linear actuators

## 🗓️ Project Timeline

- Developed and submitted in January 2024 by Abdullah Al Rakib (1931014)
