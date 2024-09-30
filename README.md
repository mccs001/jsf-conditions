# jsf-conditions
Simple code to work with temperature/pressure/humidity readings on ESP32

## Overview
This repository contains the beginnings of a code project, intended to run on a LILYGO ESP32 development board, working with BME280 sensors.
Initially, the readings will be saved and displayed on the device itself. Eventually, they may be made available via the web.

## Requirements
- LILYGO T-Diplay-S3 ESP32-S3 device with ST7789 LCD display (170x320) or similar
- BlueDot BME280 Weather Station board
- Visual Studio Code with PlatformIO extension installed

## Inspiration
Most of the initial code here has been taken from existing example Arduino/ESP32 code and then reorganised a little.
- BME280 Sensor reading code and summary page: TBC
- Graph code:   [VolosR/bitCoinTTGO](https://github.com/VolosR/bitCoinTTGO)

## Disclaimer
None of this code is intended to be production quality. Please feel free to use any of it, but without any support or warranty.
