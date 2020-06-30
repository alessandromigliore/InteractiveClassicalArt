# Architecture

## 1 Hardware components

### 1.1 Smartphone

![smartphone](/images/smartphone.png)

The smartphone is the key point of the entire system, it shows all the author’s works in 3D graphics, and the user through the use of sensors on the device (accelerometer and gyroscope) can rotate the image that is projected on the platform.


### 1.2 The Arduino Uno R3

![arduino](/images/arduino.jpg)

The Arduino Uno is a microcontroller board based on the ATmega328. It has 14 digital input/output pins, 6 analog inputs, a 16 MHz resonator, a USB connection, a power jack, an in-circuit system programming (ICSP) header, and a reset button. It contains everything needed to support the microcontroller; simply connecting it to a computer with a USB cable or powering it with a battery to get started.
The Uno differs from all preceding Arduino boards in that it does not use the FTDI USB-to-serial driver chip. Instead, it features an ATmega16U2 programmed as a USB-to-serial converter. This auxiliary microcontroller has its USB bootloader, which allows advanced users to reprogram it.


### 1.3 WiFi Module - ESP8266

![wifi](/images/wifi.jpg)

The ESP8266 is a low-cost WiFi microchip, with a full TCP/IP stack that can give any microcontroller access to your WiFi network. The ESP8266 is capable of either hosting an application or offloading all WiFi networking functions from another application processor. Each ESP8266 module comes pre-programmed with an AT command set firmware, meaning, you can simply hook this up to your Arduino device and get about as much WiFi-ability as a WiFi Shield offers! The ESP8266 module is an extremely cost effective board with a huge, and ever growing, community. This module has a powerful enough on-board processing and storage capability that allows it to be integrated with the sensors and other application specific devices through its GPIOs with minimal development up-front and minimal loading during runtime. 

### 1.4 LED

![led](/images/yellowLed.jpg)

An average 5mm Yellow LED has a 2V forward voltage drop and a forward current of 20mA. Bright Yellow LEDs can have a forward voltage as high as 3.4V.

### 1.5 Arduino schematics
The LED is connected to a GPIO pin of the ESP8266 WiFi module, and the power is taken from the Arduino Uno board

![sketch](/images/SmartMuseumSketch_bb.png)


## 2 Software components

### 2.1 Generic Sensor API

![orientationGIF](/images/orientationGIF.gif)

The Generic Sensor API is a set of interfaces that expose sensor devices to the web platform. The API consists of the base Sensor interface and a set of concrete sensor classes built on tops, such as Accelerometer, LinearAccelerationSensor, Gyroscope, AbsoluteOrientationSensor, and RelativeOrientationSensor.

The Generic Sensor API is very simple and easy-to-use. The Sensor interface has start() and stop() methods to control sensor state and several event handlers for receiving notifications about sensor activation, errors, and newly available readings. The concrete sensor classes usually add their specific reading attributes to the base class.


### 2.2 Thingsboard

![thingsboard1](/images/thingsboard.jpg)

ThingsBoard is an open-source IoT platform for
data collection, processing, visualization, and
device management.
It enables device connectivity via industry
standard IoT protocols - MQTT, CoAP and, HTTP
and supports both cloud and on-premises
deployments. ThingsBoard combines scalability,
fault-tolerance and performance so you will never lose your data.

### 2.3 Three.js

![three](/images/three.png)

Three.js is a 3D library that tries to make it as easy as possible to get 3D content on a webpage.
Three.js is often confused with WebGL since more often than not, but not always, three.js uses WebGL to draw 3D. WebGL is a very low-level system that only draws points, lines, and triangles. To do anything useful with WebGL generally requires quite a bit of code and that is where three.js comes in. It handles stuff like scenes, lights, shadows, materials, textures, 3d math, all things that you'd have to write yourself if you were to use WebGL directly.


### 2.4 MQTT

![mqtt1](/images/mqtt.jpg)

MQTT is one of the most commonly used protocols
in IoT projects. It stands for Message Queuing
Telemetry Transport.
Also, it is designed as a lightweight messaging
protocol that uses publish/subscribe operations to
exchange data between clients and the server.
Furthermore, its small size, low power usage, minimized data packets and ease of


implementation make the protocol ideal of the “machine-to-machine” or “Internet of
Things” world.

### 2.5 Arduino IDE

![IDE3](/images/IDE.jpg)

Arduino IDE is an open source software that is mainly used for writing and compiling the code into the Arduino Module. It is an official Arduino software, making code compilation too easy that even a common person with no prior technical knowledge can get their feet wet with the learning process. It is easily available for operating systems like MAC, Windows, Linux and runs on the Java Platform that comes with inbuilt functions and commands that play a vital role in debugging, editing, and compiling the code in the environment. A range of Arduino modules available including Arduino Uno, Arduino Mega, Arduino Leonardo, Arduino Micro, and many more. Each of them contains a microcontroller on the board that is programmed and accepts the information in the form of code. The main code, also known as a sketch, created on the IDE platform will ultimately generate a Hex File which is then transferred and uploaded in the controller on the board. The IDE environment mainly contains two basic parts: Editor and Compiler where the former is used for writing the required code, and the later is used for compiling and uploading the code into the given Arduino Module. This environment supports both C and C++ languages.

### 2.6 Eclipse Mosquitto

![mosquitto](/images/Mosquitto.png)

Eclipse Mosquitto is an open source (EPL/EDL licensed) message broker that implements the MQTT protocol versions 5.0, 3.1.1, and 3.1. Mosquitto is lightweight and is suitable for use on all devices from low power single board computers to full servers.
The MQTT protocol provides a lightweight method of carrying out messaging using a publish/subscribe model. This makes it suitable for Internet of Things messaging such as with low power sensors or mobile devices such as phones, embedded computers or microcontrollers.

### 2.7 Eclipse Paho

![paho](/images/paho.png)

The Eclipse Paho project provides open-source client implementations of MQTT and MQTT-SN messaging protocols aimed at new, existing, and emerging applications for the Internet of Things.
Paho focuses on reliable implementations that will integrate with a wide range of middleware, programming, and messaging models.


## 3 Network architecture

![schema](/images/architecture3.png)

Using the Generic Sensor API we collect the data of the device sensors (accelerometer and gyroscope) and transfer them via MQTT to the Mosquitto MQTT broker connected to Thingsboard. Finally, a web page receives the values of the sensors passed by Thingsboard and use them to dynamically rotate the 3D graphic models of the sculpture (created with Three.js) in order to realize the images to be projected as a hologram.
Also, through the ESP8266 WiFi module, connected to the Arduino UNO board, we receive the values analyzed by Thingsboard and a yellow LED, connected to the board, lights up when the user is observing the most appreciated artwork.


# Useful Links

- Architecture [version 1](https://github.com/alessandromigliore/InteractiveClassicalArt/blob/master/First%20delivery/Architecture.md)
- Architecture [version 2](https://github.com/alessandromigliore/InteractiveClassicalArt/blob/master/Second%20delivery/Architecture.md)
