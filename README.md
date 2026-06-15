# Blink with UI and Serial

This app is modified from the example "Blink LED with UI".

This is an experiment to test if the `Serial1` of the Arduino Uno Q can be used as an UART interface for UART sensors or modules.

## Description

This app uses a simple webUI interface (just like the original example) to toggle an LED.

Being different from the example, it sends a signal to another Arduino through Serial1. That Arduino will toggle its LED after receiving the signal.

Also, the LED (MPU LED1) can be toggled from another Arduino's Serial Monitor through the same UART interface.

## Hardware and Software Requirements

### Hardware

- Arduino UNO Q (x1)
- Another Arduino of any type (x1)
- USB-C cable (for power and programming) (x2)

### Software

- Arduino App Lab
- Arduino IDE


