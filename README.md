# Vibration-Activated Relay with Button Reset

This project controls a relay based on the detection of vibration and a button press. It uses a vibration sensor to trigger the relay when a vibration is detected and also allows the relay to be manually activated by pressing a button. Additionally, the relay can be reset via a hardware reset button.

## Features
- **Vibration-based activation**: Trigger the relay when vibration is detected by the sensor.
- **Button press activation**: Trigger the relay via a button press (with debounce logic to prevent multiple activations).
- **Relay reset**: Reset the system using a dedicated reset button.
- **Relay on-time**: The relay stays active for a defined duration (900ms or 2 seconds).
- **Debounce logic**: Implemented to avoid false triggering from the vibration sensor or button presses.

## Hardware Requirements
- **Vibration sensor** (e.g., SW-420)
- **Button** (for manual triggering and reset)
- **Relay module** (e.g., 5V relay module)
- **Arduino or compatible microcontroller**
- **Jumper wires** for wiring the components

## Pin Configuration
- **Vibration Sensor Pin**: Pin 2 (input pin for vibration sensor)
- **Button Pin**: Pin 3 (input pin for manual triggering button)
- **Relay Pin**: Pin 9 (output pin to control relay)
- **Reset Button Pin**: Pin 5 (input pin for software reset button)

## How to Use
1. **Upload the code** to your Arduino board.
2. **Wire the vibration sensor**, button, and relay to the designated pins as per the pin configuration.
3. **Press the button** or cause a vibration to trigger the relay.
4. The relay will turn on for 900ms (2 seconds), then turn off automatically.
5. If you want to **reset the system**, press the **reset button**.

### Behavior:
- **Vibration Sensor**: When a vibration is detected (sensor reads HIGH), the relay is activated for 900ms.
- **Button Press**: If the button is pressed, the relay is also activated for 900ms.
- **Reset Button**: Pressing the reset button resets the Arduino via software.

## Code Overview
- **Pin Initialization**: The input and output pins are configured at the beginning of the `setup()` function.
- **Vibration Trigger**: The `loop()` function checks the state of the vibration sensor and activates the relay when vibration is detected.
- **Button Trigger**: The code checks for button presses and activates the relay with debounce logic to avoid accidental multiple activations.
- **Reset**: If the reset button is pressed, the Arduino will be reset using assembly code (`asm volatile ("  jmp 0")`), effectively restarting the system.

## License
This project is open-source and available under the MIT License.

## Acknowledgements
- This project uses simple logic to interface with basic hardware components such as a vibration sensor, relay, and button.
- For more information on working with relays and sensors, visit the [Arduino Documentation](https://www.arduino.cc/en/Guide/HomePage).

---

Enjoy building your vibration-triggered relay system with the added functionality of manual reset!
 
