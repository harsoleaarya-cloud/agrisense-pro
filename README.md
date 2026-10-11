# AgriSense Pro 🌱

**A smart agriculture monitoring and advisory system.** An Arduino reads live soil and weather data, and a multilingual web dashboard turns it into a soil advisory report.

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-Web%20Serial%20API-F7DF1E?logo=javascript&logoColor=black)
![Chart.js](https://img.shields.io/badge/Chart.js-Visualisation-FF6384?logo=chartdotjs&logoColor=white)

## Overview

Farmers often make decisions about irrigation and fertilizer without current field data. AgriSense Pro reads soil moisture, humidity and temperature directly from sensors, combines them with soil nutrient values entered by the user, and compares everything against reference ranges for the selected soil type and season. The result is a clear report showing which parameters are fine and which need action.

This was a team project (team of four) built at Dr. D. Y. Patil Institute of Technology, Pimpri, Pune.

## Features

- **Live sensor readings** of temperature, humidity and soil moisture from an Arduino Uno
- **Advisory report** based on soil type and season
- **Observed vs ideal comparison** in a status table (GOOD / TAKE ACTION) and a bar chart
- **Per-parameter guidance** covering benefits, risks and precautions
- **Three languages:** English, Hindi and Marathi

## How it works

```
Sensors (DHT11, soil moisture)
        │
        ▼
Arduino Uno ── USB serial, 9600 baud ──► Browser (Web Serial API)
   prints "temp,humidity,moisture"              │
                                                ▼
                                    Dashboard fills the Auto fields
                                                │
                           User enters N, P, K, pH + crop, soil, season
                                                │
                                                ▼
                                  Report: table + chart + guidance
```

## Hardware

| Component | Purpose |
|---|---|
| Arduino Uno | Reads the sensors and sends data over USB serial |
| DHT11 sensor | Temperature and humidity |
| Soil moisture sensor | Soil moisture (analog input) |
| Breadboard and jumper wires | Connections |

**Default wiring** (change the pin numbers at the top of the sketch if yours differ):

| Sensor pin | Arduino pin |
|---|---|
| DHT11 data | D2 |
| Soil moisture analog out | A0 |
| VCC / GND (both sensors) | 5V / GND |

## Getting started

**1. Upload the firmware**
1. Open `arduino/agrisense.ino` in the Arduino IDE.
2. Install the **DHT sensor library** by Adafruit (Tools → Manage Libraries).
3. Select **Arduino Uno** and the correct port, then click **Upload**.
4. Close the Serial Monitor afterwards, because it blocks the port.

**2. Open the dashboard**
1. Open `index.html` in **Google Chrome or Microsoft Edge** (Web Serial is not available in Firefox or Safari).
2. Click **Connect Arduino**, choose the Arduino's port, and the three Auto fields start updating.
3. Select crop, soil and season, enter N, P, K and pH, then click **Generate Report**.

## Project structure

```
agrisense-pro/
├── index.html           # dashboard (UI, report logic, Web Serial)
├── arduino/
│   └── agrisense.ino    # sensor reading firmware
└── README.md
```

## Limitations

- Ideal ranges come from a simplified model based on soil type and season. They are reference values, not agronomic recommendations.
- Crop selection does not yet change the ranges.
- Soil moisture needs per-sensor calibration (`SOIL_DRY` and `SOIL_WET` in the sketch).
- The DHT11 has limited accuracy (about ±2 °C and ±5 % RH).

## Future improvements

- Crop-specific ranges from verified agronomy data
- Automatic irrigation using a relay and pump
- Data logging and history graphs
- Wireless transmission (ESP32 or Bluetooth) instead of USB
- Advice that distinguishes "too low" from "too high" values

## My contribution

- Hardware setup and sensor interfacing (DHT11 and soil moisture sensor with Arduino Uno)
- Testing sensor connections and verifying real-time data acquisition
- Integrating the sensor readings with the web dashboard

## Tech stack

Arduino (C/C++) · HTML, CSS, JavaScript · Chart.js · Web Serial API
