# Child Safety System (nRF24L01 & Arduino) 

A wireless proximity alarm system designed to prevent children from wandering too far in crowded spaces. It acts as a "virtual leash" using radio frequency signals.

## How it Works
The system consists of two modules:
1.  **Child Module (Transmitter):** Continuously sends a "ping" signal via radio waves.
2.  **Parent Module (Receiver):** Listens for the signal. If the signal is lost (child goes out of range) or blocked for a specific duration, an alarm (buzzer/LED) is triggered.

## 🛠️ Hardware Required
* 2x Arduino Nano 
* 2x nRF24L01+ Wireless Transceiver Modules
* 1x Active Buzzer (for Parent module)
* 2x LED & Resistor (Optional visual indicator)
* Jumper wires & Breadboards

## Wiring Diagram (Pinout)

Based on the diagram provided in the `images` folder:

| nRF24L01 Pin | Arduino Nano Pin |
| :--- | :--- |
| VCC | 3.3V (Do NOT use 5V!) |
| GND | GND |
| CE | D9 |
| CSN | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| IRQ | Not Connected |

## Installation & Usage

1.  **Download:** Clone this repository or download the ZIP.
2.  **Libraries:** Install the `RF24` library by TMRh20 via the Arduino IDE Library Manager.
3.  **Upload Child Code:** Open `Transmitter_Child/Transmitter_Child.ino` and upload it to the first Arduino.
4.  **Upload Parent Code:** Open `Receiver_Parent/Receiver_Parent.ino` and upload it to the second Arduino.
5.  **Test:** Power both units. Separate them by distance. When the connection drops, the Parent unit should alarm.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
