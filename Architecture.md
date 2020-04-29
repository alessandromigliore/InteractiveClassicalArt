# Architecture

## 1 Hardware components

### 1.1 The Arduino Uno R
![arduino](/images/arduino.jpg)
The Arduino Uno is a microcontroller board based on the ATmega328. It has 14
digital input/output pins, 6 analog inputs, a 16 MHz resonator, a USB connection, a
power jack, an in-circuit system programming (ICSP) header, and a reset button. It
contains everything needed to support the microcontroller; simply connecting it to a
computer with a USB cable or powering it with a battery to get started.
The Uno differs from all preceding Arduino boards in that it does not use the FTDI
USB-to-serial driver chip. Instead, it features an ATmega16U2 programmed as a
USB-to-serial converter. This auxiliary microcontroller has its own USB bootloader,
which allows advanced users to reprogram it.


### 1.2 IR Transmitter and Receiver Kit

IR, or infrared communication, is one of the
most common methods of wireless
communication due to being easy to use and
having an affordable price. Infrared light, with
a wavelength longer than visible light, is not
within the range of human vision. That’s why
it’s a good option for wireless
communications. When you press a button on
your TV control, an LED on your control turns on and off continuously and causes a
modulated infrared signal to send from the control to your TV. The command will
execute after the signal is demodulated. IR receiver modules are used to receive IR
signals. These modules work in 3, 8 KHz frequency. When the sensor is not exposed
to any light at its working frequency, the Vout output has a value equal to VS (power
supply). With exposing to a 38 kHz infrared light, this output will be zero.

### 1.3 WiFi Module - ESP

The ESP8266 is a low-cost WiF​i microchip,
with a full TCP/IP stack that can give any
microcontroller access to your WiFi
network. The ESP8266 is capable of
either hosting an application or
offloading all WiFi networking functions
from another application processor. Each
ESP8266 module comes pre-programmed
with an AT command set firmware,
meaning, you can simply hook this up to your Arduino device and get about as much


WiFi-ability as a WiFi Shield offers! The ESP8266 module is an extremely cost
effective board with a huge, and ever growing, community. This module has a
powerful enough on-board processing and storage capability that allows it to be
integrated with the sensors and other application specific devices through its GPIOs
with minimal development up-front and minimal loading during runtime.

## 2 Software components

### 2.1 Arduino IDE

Arduino IDE is an open source software that is mainly used
for writing and compiling the code into the Arduino
Module. It is an official Arduino software, making code
compilation too easy that even a common person with no
prior technical knowledge can get their feet wet with the learning process. It is easily
available for operating systems like MAC, Windows, Linux and runs on the Java
Platform that comes with inbuilt functions and commands that play a vital role for
debugging, editing and compiling the code in the environment. A range of Arduino
modules available including Arduino Uno, Arduino Mega, Arduino Leonardo, Arduino
Micro and many more. Each of them contains a microcontroller on the board that is
actually programmed and accepts the information in the form of code. The main
code, also known as a sketch, created on the IDE platform will ultimately generate a
Hex File which is then transferred and uploaded in the controller on the board. The
IDE environment mainly contains two basic parts: Editor and Compiler where former
is used for writing the required code and later is used for compiling and uploading
the code into the given Arduino Module. This environment supports both C and C++
languages.


### 2.2 Thingsboard

ThingsBoard is an open-source IoT platform for
data collection, processing, visualization, and
device management.
It enables device connectivity via industry
standard IoT protocols - MQTT, CoAP and HTTP
and supports both cloud and on-premises
deployments. ThingsBoard combines scalability,
fault-tolerance and performance so you will never lose your data.

### 2.3 Telegram Bot Platform

Bots are third-party applications that run inside Telegram.
Users can interact with bots by sending them messages,
commands and inline requests. You control your bots using
HTTPS requests to our Bot API.
They can do anything – teach, play, search, broadcast, remind,
connect, integrate with other services, or even pass commands to the Internet of
Things.

### 2.4 MQTT

MQTT is one of the most commonly used protocols
in IoT projects. It stands for Message Queuing
Telemetry Transport.
In addition, it is designed as a lightweight messaging
protocol that uses publish/subscribe operations to
exchange data between clients and the server.
Furthermore, its small size, low power usage, minimized data packets and ease of


implementation make the protocol ideal of the “machine-to-machine” or “Internet of
Things” world.

## 3 Network architecture

**Arduino UNO R3** board is connected to the infrared receiver (​ **IR Receiver Module** ​).
When the IR receives a signal from a remote control, the board sends these signals to
the ​ **Arduino application** which begins to interact with the specific ​ **Telegram bot** (the
one available to the user which has send the signal with that remote control), via the
**Telegram API** ​. Through the ​ **ESP8266 WiFi module** the data are sent to ​ **Thingsboard**
using the ​ **MQTT** messaging protocol, and stored in a connected database. Finally, all
the data are displayed in a ​ **web page** ​.
