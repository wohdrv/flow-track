# Flow Track: Leakage and Water Level Sensor 🌊

A "Smart City" solution designed to monitor water levels in sewer collectors and prevent flooding in residential buildings through automated intervention and remote notifications.

## 📌 Project Overview
The "Flow Track" system addresses the increasing problem of flooded streets in Astana caused by overcrowded sewer collectors and domestic apartment leaks. Our team developed a low-cost, multifunctional sensor to minimize financial losses and improve urban safety.

<img width="1009" height="556" alt="image" src="https://github.com/user-attachments/assets/abf1e10f-9178-4797-b7eb-5b0a62a43793" />

## ✨ Key Features
* **Automation:** Automatically shuts off the water supply when a leak is detected
* **Remote Notification:** Instant alerts via Telegram bot
* **Cost-Effective:** Built using available materials and the Arduino set
* **Scalability:** Easy to deploy in residential buildings or city sewer infrastructure

## ⚙️ System Architecture & Logic
The project uses a dual-controller architecture for maximum reliability:

### 1. NodeMCU ESP8266 (Communication & Monitoring)
* **Status:** Upon activation, sends "Flow track activated" to the Telegram bot
* **Detection:** Monitors the water sensor for any sign of a leak
* **Action:** When water is detected, it immediately sends "Water detected!!!" to Telegram.
* **Command:** Sends a signal `1` via Serial Port to the Arduino Uno.
* **Confirmation:** Once the process is initiated, it notifies the user: "Tap is closed."

### 2. Arduino Uno (Physical Actuator)
* **Role:** Manages the 28BYJ-48 Stepper Motor (acting as a water valve)
* **Logic:** Waits for signal `1` from the NodeMCU through the Serial Port
* **Operation:** Upon receiving the signal, it performs one full rotation (360°)
* **Performance:** Optimized for maximum torque at low speed to ensure the valve closes firmly even with resistance.

## 🛠 Technical Components
* **Sensors:** Water sensor for surface/area detection
* **Controllers:** NodeMCU ESP8266 and Arduino Uno
* **Actuator:** Stepper motor (28BYJ-48) with ULN2003 driver
* **Communication:** SoftwareSerial for inter-board data exchange

## 🏗 Prototype Construction
Our experimental model was built using:
* **Body:** Plywood, plastic sheets, and a transparent tube for visualization.
* **Plumbing:** A barrel with a tap and a plastic container to simulate a sewer.
* **Assembly:** Parts were sealed with sealant and finished with spray paint for a professional look.

## 🎥 Video and Documents
* YouTube: https://youtu.be/KJfUqRttfNI?si=GH6daGcRL6ctcmSR
* Full Documentation: [Full Project PDF](./Flow_track_Leakage_and_water_level_sensor_in_the_sewer.pdf)

## 👥 Team & Acknowledgments
**School-Lyceum No. 60, Astana**
* **Authors:** Madina Satualdypova, Alikhan Kozybay, and Zhanibek Nurmukhambet (10th-grade IT students).
* **Project Lead:** Elmira Kurmetovna (Computer Science Teacher).

![WhatsApp Image 2026-01-23 at 18 15 53](https://github.com/user-attachments/assets/9368d2fd-71f4-4574-82bb-e7bcc6ef8b2a)
