# Auto Tank Filler System

## Description

The Auto Tank Filler system uses an ultrasonic distance sensor to automatically control a water pump for filling a tank. The system measures the distance between the sensor and the water level. When the water level is below a set point, the pump is activated to fill the tank until the desired level is reached.

## Components

- Arduino (e.g., Arduino Uno)
- Ultrasonic Distance Sensor (HC-SR04 or similar)
- Relay or Transistor (to control the pump)
- Water Pump
- Jumper Wires
- Breadboard (optional)

## Pin Configuration

| Component              | Pin Number |
| ---------------------- | ---------- |
| Ultrasonic Echo Pin    | 10         |
| Ultrasonic Trigger Pin | 11         |
| Pump Control Pin       | 12         |

## Code

```cpp
// Code for Auto Tank Filler System

#define ECHOPIN 10
#define TRIGPIN 11
#define POMPA 12

int H2, HT, H1, SetPoint;

void setup(){
  pinMode(ECHOPIN, INPUT);    // Set echo pin as input
  pinMode(TRIGPIN, OUTPUT);  // Set trigger pin as output
  pinMode(POMPA, OUTPUT);    // Set pump control pin as output
  delay(1000);               // Initial delay
  HT = 200;                  // Reference height
  SetPoint = 150;            // Desired water level
}

void loop(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  int distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58; // Convert to centimeters

  H2 = HT - distance;      // Calculate current water level

  // Control pump based on water level
  if (H2 > SetPoint) {
    digitalWrite(POMPA, HIGH); // Turn on pump
  } else {
    digitalWrite(POMPA, LOW);  // Turn off pump
  }

  delay(1000); // Update every second
}
```

## How It Works

1. Initialization:
   - The setup() function initializes the pins for the ultrasonic sensor and the pump.
   - It also sets a reference height (HT) and a set point (SetPoint) for the desired water level.
2. Distance Measurement:
   - The loop() function triggers the ultrasonic sensor to measure the distance.
   - The measured distance is converted to centimeters, and the current water level (H2) is calculated by subtracting the distance from the reference height.
3. Pump Control:
   - The pump is activated if the current water level is above the set point.
   - If the water level is at or below the set point, the pump is turned off.

## Usage

1. Connect the ultrasonic sensor and pump to the appropriate pins on the Arduino.
2. Upload the code to the Arduino board.
3. Power the Arduino and observe the automatic control of the pump based on the water level.

## Notes

- Ensure the ultrasonic sensor is properly positioned for accurate measurements.
- Adjust the reference height (HT) and set point (SetPoint) as needed based on your specific requirements.
- Use a relay or transistor to control the pump, as the Arduino cannot drive a pump directly.