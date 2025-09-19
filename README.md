# Carriage Control

A software + hardware system for controlling a **welding carriage**.
Features include:

* Change of direction
* Variable speed control using **PWM**
* Pre-programmed carriage movements for traveling known distances

---

## UI Preview

![Carriage Control UI](https://github.com/curi0sity722/carriage-control-/blob/main/carriage_control_UI.png?raw=true)

---

## Hardware Overview

* **Motor Driver:** BTS7960 high-power H-bridge DC motor driver module
* **Controller:** XIAO ESP32S3 (sends control signals)
* **Motors:** 24V DC motors, \~200mA each
* **Power Supply:** WX-DC2412 (24V, 4A) 
* **Relay Module:** Two-channel 24V HL-52S relay (customizable output trigger)

---

## Key Highlights

* Smooth and precise motor control with PWM
* Reliable power delivery to handle multiple motors
* Custom relay triggers for user-defined actions
* Compact and efficient design for welding carriage applications
