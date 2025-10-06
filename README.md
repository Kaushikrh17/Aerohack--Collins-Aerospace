# 🐦 Hybrid, Dual-Mode Bird Deterrence System for Delivery Drones

## Project Overview

This project presents an **intelligent, hybrid, dual-mode system** designed to protect autonomous delivery drones from bird strikes, particularly from birds of prey like eagles and crows, which pose a threat in challenging environments like hilly regions. The solution adheres strictly to constraints, demonstrating high feasibility.

The design challenge was to create a deterrence system for a drone delivering medicines over a 10 km flight path, where attacks are prone to occur around the 5 km mark. The system must not exceed a weight of **1.5 kg** and a cost of **Rs. 50,000/-**, and must be robust against drizzles and wind gust.

---

## 🏗️ System Architecture: Sense -> Think -> Act

The system is built on a clear, robust **Sense -> Think -> Act** control flow, enabling intelligent and energy-efficient responses to threats.

### 1. SENSE (Inputs)
The detection mechanism is a dual-mode, layered approach for both long-range and close-proximity threats.

| Component | Function | Mode |
| :--- | :--- | :--- |
| **YOLO (Camera/ESP32-CAM)** | High-precision visual detection for **long-range** threats. Used to detect the bird, its bounding box, and the angle for precise targeting. | Proactive |
| **PIR Sensors** | Low-power passive infrared (PIR) sensors for **close-range** proximity and blind-spot coverage by detecting heat/motion. | Reactive |
| **Push Button & Potentiometer** | Manual controls (used for simulation and calibration). | Control |

### 2. THINK (Control Unit)

* **ESP32 Microcontroller:** Serves as the **"brain"** of the system. It processes sensor data from the YOLO vision model and PIR sensors to make real-time decisions, executing state-based logic to differentiate between real threats and environmental noise.

### 3. ACT (Outputs)

The deterrence mechanism is a layered defense to prevent bird habituation.

| Component | Deterrence Type | Function |
| :--- | :--- | :--- |
| **Piezo Buzzers (x4)** | **Close-Range Defense (Acoustic Bubble)**. Emits loud, irritating, omnidirectional sound signals (2-5 kHz) to startle and disorient birds during close-proximity/surprise attacks. Provides an immediate, **360-degree defense**. | Reactive |
| **Servo Motor & Directional Speaker** | **Long-Range Defense (LRAD-inspired)**. The speaker array, mounted on a servo, aims a focused sound beam (2-10 kHz sweep or 25-30 kHz ultrasonic burst) directly at the detected threat. This targeted approach is more energy-efficient and proactive. | Proactive |
| **Status LED** | Provides visual feedback on the system's status. | Feedback |

---

## 💡 Key Design Principles & USP

* **Hybrid, Multi-Layered Deterrence:** The combination of long-range, targeted defense (Directional Speaker) and immediate, omnidirectional defense (Piezo Buzzers) is the system's **Unique Selling Proposition (USP)**, making it less prone to bird habituation.
* **Intelligent & Efficient:** The state-based logic on the ESP32 ensures the system avoids energy-wasting false positives and only activates the most appropriate deterrence mechanism.
* **Compliance:** The entire system is designed as a **modular and self-contained unit** that is lightweight and robust for easy integration.

---

## 🧪 Validation & Simulation

To validate the core logic and component integration, a multi-platform simulation approach was used (excluding the MATLAB model).

### 1. Interactive Web Demo
**Objective:** Provide a dynamic and interactive demonstration of the system's core logic.
* The demo displayed a drone model with a servo arm.
* Simulated user clicks represented a bird's position.
* The **servo arm instantly rotated** to point at the clicked location, with a red sound ray simulating the directional speaker.
* Buzzers flashed based on proximity (closer, brighter).

### 2. Tinkercad Hardware Prototype (Hardware-in-the-Loop Simulation)
**Objective:** Validate circuit logic and component integration before physical assembly.
* **Components:** Arduino Uno (for simplicity in simulation), PIR Sensor, Push Button (simulating YOLO output), Potentiometer, Servo Motor, Buzzers, and LED.
* **Logic:** The circuit tested the control flow: PIR/Push Button input triggers the activation of the Servo and Buzzers/LED.

---

## 📏 Weight & Cost Analysis

The design successfully meets the project constraints. The system components are housed in a custom-fabricated unit (Custom PCB, 3D Printed ABS Housing) on a drone base (e.g., F450 frame).

| Metric | Estimated Value | Project Constraint | Compliance |
| :--- | :--- | :--- | :--- |
| **Total Estimated Weight** | $\approx 0.62 \text{ kg}$ | $\le 1.5 \text{ kg}$ | **PASS** |
| **Total Estimated Cost** | $\approx \text{Rs. } 9,200$ | $\le \text{Rs. } 50,000$ | **PASS** |

The system is highly feasible, costing a small fraction of the budget and using less than half the maximum allowed weight.

---

## 🚀 Future Scope & Enhancements

* **Advanced Sensor Fusion:** Integrate a **microphone array** for audio-based bird detection and localization to supplement vision and motion data.
* **Bio-Acoustic Deterrence:** Develop a dynamic library of **bio-acoustic tones and distress calls** to prevent bird habituation.
* **Predictive Analytics:** Implement an on-board machine learning model to **predict bird flight patterns**, shifting from a purely reactive to a proactive deterrence strategy.
* **Increased Durability:** Design a **fully weather-sealed and wind-resistant housing** for maximum robustness in diverse environments.
