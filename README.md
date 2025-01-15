![PIC 2](https://github.com/user-attachments/assets/82a8e7d4-b066-4d19-bccd-b11229767175)
![PIC 1](https://github.com/user-attachments/assets/006f082b-4165-4e4c-8eee-a892f957e79f)
# **Fuel Type Detection System**

## **Overview**
This project is an intelligent fuel detection system that uses a TCS3200 color sensor and additional components like a magnetic door sensor, relays, and buzzers to identify fuel types (Diesel or Petrol) and provide appropriate alerts. It is designed for automation in fuel stations or similar applications.

---

## **Features**
- **Fuel Detection**: Detects whether the input fuel is Diesel or Petrol based on color sensor readings.
- **Automatic Alerts**: 
  - Plays a buzzer sound if Diesel is detected.
  - Issues a warning if the system remains open for more than a minute.
- **Efficient Power Control**: Turns the sensor off when the system is idle.
- **Relay Control**: Automatically controls relays based on detected fuel type.
- **Real-Time Monitoring**: Displays pulse width readings for Red, Green, and Blue components in the Serial Monitor for debugging and analytics.

---

## **Components Used**
1. **TCS3200 Color Sensor**: Detects the color properties of the fuel.
2. **Arduino (Microcontroller)**: Processes the sensor data and controls the components.
3. **Magnetic Door Sensor**: Detects the opening and closing of the system.
4. **Relay Module**: Manages external components (e.g., pumps or alarms).
5. **Buzzers**: For error and fuel type notification.
6. **LED Indicators (optional)**: To provide visual feedback.

---

## **How It Works**
1. When the system detects the door is open, the TCS3200 sensor is activated.
2. The sensor reads the pulse width values of Red, Green, and Blue components.
3. The program determines the fuel type based on pre-calibrated thresholds.
4. Actions:
   - If **Diesel** is detected: Relay is activated, and a buzzer sounds.
   - If **Petrol** is detected: Relay remains inactive, and no buzzer sounds.
   - If no fuel is detected: An error message is displayed, and the relay is turned off.
5. If the door remains open for more than **1 minute**, a warning beep tune is played.

---

## **Setup Instructions**
1. Connect the components as described in the `setup()` function or the circuit diagram (add one if available).
2. Upload the code to the Arduino using the Arduino IDE.
3. Monitor real-time readings via the Serial Monitor at a baud rate of `9600`.
4. Adjust the threshold values in the code (`detectFuelType()` function) if required, based on your environment or sensor calibration.

---

## **Code Explanation**
- `setup()`: Initializes pins, sensors, and Serial communication.
- `loop()`: Continuously checks the door state, reads sensor values, and detects fuel type.
- `getRedPW()`, `getGreenPW()`, `getBluePW()`: Functions to measure pulse widths for the color components.
- `detectFuelType()`: Determines the fuel type and activates relays accordingly.
- `playErrorTune()`: Plays an alert sound if the door remains open too long.
- **Constants**:
  - `errorBeepInterval`: Warning time duration (set to 1 minute).

---

## **Applications**
- **Fuel Stations**: Automates the fuel type detection process.
- **Industrial Automation**: Useful for detecting and distinguishing between liquid types.
- **Smart Monitoring Systems**: Provides real-time data for analytics.

---

## **Future Enhancements**
- Add a display to show fuel type visually.
- Integrate with IoT platforms for remote monitoring and control.
- Expand the system to detect additional liquid types.

