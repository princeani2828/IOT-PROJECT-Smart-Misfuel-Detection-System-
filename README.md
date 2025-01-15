![PIC 2](https://github.com/user-attachments/assets/82a8e7d4-b066-4d19-bccd-b11229767175)
![PIC 1](https://github.com/user-attachments/assets/006f082b-4165-4e4c-8eee-a892f957e79f)
Here’s the updated README file idea with the title **"Smart Misfuel Detection System"**:

---

# **Smart Misfuel Detection System**

## **Overview**
The **Smart Misfuel Detection System** is designed to prevent misfueling incidents by identifying fuel types (Diesel or Petrol) using a TCS3200 color sensor. The system incorporates real-time monitoring, error detection, and automated alerts to ensure operational efficiency and safety in fuel stations or similar environments.

---

## **Features**
- **Accurate Fuel Detection**: Identifies Diesel and Petrol based on pre-calibrated sensor thresholds.
- **Misfuel Prevention**: Alerts users with a buzzer if the detected fuel type mismatches.
- **Automated Alerts**: 
  - Plays a warning buzzer if Diesel is detected.
  - Issues an error notification if the system is left open for more than 1 minute.
- **Energy-Efficient Operation**: Automatically powers down the sensor when idle.
- **Real-Time Monitoring**: Outputs sensor readings via Serial Monitor for live debugging and analytics.
- **Relay Integration**: Controls external devices like pumps based on the detected fuel type.

---

## **Components Used**
1. **TCS3200 Color Sensor**: Detects the color properties of the fuel.
2. **Arduino (Microcontroller)**: Processes data and controls the connected components.
3. **Magnetic Door Sensor**: Detects when the system is opened or closed.
4. **Relay Module**: Activates external devices based on the fuel type.
5. **Buzzers**: Alerts users in case of misfueling or errors.
6. **LED Indicators (Optional)**: Provides visual feedback for system status.

---

## **How It Works**
1. The system activates the TCS3200 sensor when the door is opened.
2. Reads Red, Green, and Blue pulse width values from the fuel.
3. Determines the fuel type using pre-set thresholds.
4. Actions:
   - **Diesel Detected**: Activates the relay and sounds a buzzer.
   - **Petrol Detected**: Keeps the relay inactive, no buzzer sound.
   - **No Fuel Detected**: Outputs an error message and turns off the relay.
5. Plays a warning tune if the door remains open for **1 minute**.

---

## **Setup Instructions**
1. Assemble the components as described in the `setup()` function.
2. Upload the code to the Arduino using the Arduino IDE.
3. Use the Serial Monitor (baud rate: 9600) to view real-time sensor readings.
4. Adjust the color thresholds in the `detectFuelType()` function if required.

---

## **Code Explanation**
- **Initialization**:
  - Pins, sensors, and communication are configured in `setup()`.
- **Core Logic**:
  - The `loop()` continuously monitors the door state, reads color values, and determines the fuel type.
- **Functions**:
  - `getRedPW()`, `getGreenPW()`, `getBluePW()` measure the color pulse widths.
  - `detectFuelType()` identifies the fuel type and activates relevant components.
  - `playErrorTune()` sounds a warning buzzer if the door is open too long.
- **Customization**:
  - Change the time interval for the warning in `errorBeepInterval`.

---

## **Applications**
- **Fuel Stations**: Prevents misfueling incidents automatically.
- **Industrial Automation**: Detects and categorizes liquids in production lines.
- **Smart Monitoring Systems**: Provides real-time analytics and error alerts.

---

## **Future Enhancements**
- Add a digital display for visual feedback of fuel type.
- Integrate IoT features for remote monitoring and control.
- Expand the system to detect additional fuel or liquid types.
- Enable data logging for analytics.

---
License
This project is licensed under the Apache License 2.0.
.

---
