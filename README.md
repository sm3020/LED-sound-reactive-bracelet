# LED-sound-reactive-bracelet
A wearable LED bracelet that reacts to surrounding music in real time. The microphone detects changes in sound level (pitch and beat) which are processed by the microcontroller and used to control the brightness and behaviour of an addressable LED ring. 

## Overview 
A microphone module measures the surrounding sound level and sends an analogue signal to the microcontroller. The signal is processed in software and mapped to the brightness of the LEDs, allowing the bracelet to pulse in response to changes in volume and the beat of music.
The project combined embedded programming, analogue sensing, LED control and compact wearable electronics.

## Hardware
- Seeeduino XIAO SAMD21 microcontroller
- Microphone module
- Addressable RGB LED ring
- LiPo battery
- LiPo charging / power circuitry
- Jumper wires and soldered connections

## How it works 
The microphone produces an analogue voltage that varies with the surrounding sound level. This signal is read repeatedly by the microcontroller
which estimates the current sound intensity. This sound level is then used to control the LED ring:

1. The microphone detects the surrounding sound.
2. The microcontroller reads the microphone signal.
3. The readings are smoothed to reduce noise and sudden unwanted fluctuations.
4. The processed sound level is mapped to LED brightness.
5. The LEDs become brighter/change behaviour in response to louder sounds and music.

This process runs continuously, allowing the bracelet to react to music in real time.




https://github.com/user-attachments/assets/8a72894b-edc3-4afb-8231-8bde10092508






## Challenges & Debugging
Some of the main challenges I faced included:
- Preventing the LEDs from remaining permanently on
- Adjusting the microphone sensitivity so that normal background noise did not trigger the LEDs
- Smoothing noisy microphone measurements
- Making the LED response noticeable without being too sensitive
- Integrating the electronics into a compact wearable design

## Future Improvements
- Designing a custom PCB to make the electronics smaller & more robust
- Improving battery life
- Creating a more compact enclosure for the electronics











