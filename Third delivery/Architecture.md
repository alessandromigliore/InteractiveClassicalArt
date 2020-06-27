# Architecture

## 1 Hardware components

### 1.1 Smartphone ( Web App )

![smartphone](/images/smartphone.png)

The smartphone is the key point of the entire system, it shows all the author’s works in 3D graphics, and the user through the use of sensors on the device ( accelerometer, magnetometer, gyroscope) can rotate the image that is projected on the platform.


### 1.2 Accelerometer

![accelerometer](/images/accelerometer.png)

An accelerometer is a device that measures changes in gravitational acceleration in a device it may be installed in. Accelerometers are used to measure acceleration, tilt and vibration in numerous devices.


### 1.3 Magnetometer

![magnetometer](/images/magnetometer.png)

The magnetometer sensor measures the magnetic field for all three physical axes (x, y, z) in μT (micro Tesla). The magnetic field is a field that exerts magnetic force on magnetometer sensor due to the magnetic effect generated by electric currents, magnetic materials or Earth’s magnetic force that is attributed to the combined effects of the planetary rotation and the movement of molten iron in the Earth’s core.

### 1.4 Gyroscope

![gyroscope](/images/gyroscope.png)


## 2 Software components

### 2.1 Generic Sensor API

![GSA](/images/GSA.gif)

The Generic Sensor API is a set of interfaces which expose sensor devices to the web platform. The API consists of the base Sensor interface and a set of concrete sensor classes built on top, such as Accelerometer, LinearAccelerationSensor, Gyroscope, AbsoluteOrientationSensor and RelativeOrientationSensor.

The Generic Sensor API is very simple and easy-to-use. The Sensor interface has start() and stop() methods to control sensor state and several event handlers for receiving notifications about sensor activation, errors and newly available readings. The concrete sensor classes usually add their specific reading attributes to the base class.


### 2.2 Thingsboard

![thingsboard1](/images/thingsboard.jpg)

ThingsBoard is an open-source IoT platform for
data collection, processing, visualization, and
device management.
It enables device connectivity via industry
standard IoT protocols - MQTT, CoAP and HTTP
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
In addition, it is designed as a lightweight messaging
protocol that uses publish/subscribe operations to
exchange data between clients and the server.
Furthermore, its small size, low power usage, minimized data packets and ease of


implementation make the protocol ideal of the “machine-to-machine” or “Internet of
Things” world.

## 3 Network architecture

![schema](/images/architecture2.png)

Each **hologram platform** will have a device with **accelerometer**, **magnetometer** and **gyroscope** sensors. Using the **Generic Sensor API**  we collect the data of the sensors and transfer them via MQTT to the **Mosquitto** MQTT broker connected to **Thingsboard**. Finally, a web page receives the values of the sensors passed by Thingsboard and use them to dynamically rotate the 3D graphic models of the sculpture (created with **Three.js**) in order to realize the images to be projected as a hologram.