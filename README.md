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

## How to Run

1. After extracting the .zip file downloaded from this repo, don't delete the .zip file.
2. Open Arduino IDE and open assets/secondArduino/secondArduino.ino with the IDE.
3. Configure the sketch to match your setup (Serial1, softwareserial.h, etc).
4. Upload the sketch to the Arduino other than the Uno Q.
5. Open Arduino App Lab, connect to your Uno Q, and import the .zip file.
6. Run the app.
7. Use the webUI to toggle the LED on the Arduino connected to the Uno Q through UART.
8. Use the Arduino IDE Serial Monitor to input `0` or `1` to toggle the LED on the Uno Q and observe the output from Uno Q's `Serial1`.

