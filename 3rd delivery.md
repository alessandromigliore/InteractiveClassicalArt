# 3nd Delivery
## 1 Comments received and decisions made
_"I don’t see any embedded system"_ 

After the discussion we decided to add an LED connected to a Wi-Fi module via Arduino.
 
## 2 Changes made
### Design: 
By looking at the various opinions, we understood that a messaging service is not optimal for an IoT project. To avoid that problem, we decided to change the main idea of the service. Now, near an artwork, the visitor will find an hologram of another work of the same author and can rotate it to admire it from every point of view. Simply moving a mobile phone to one direction, the hologram will rotate from the same direction. Moreover, only by shaking the phone, the visitor will discover other  hologram-artworks of that author.
### Architecture: 
We replace the remote control and the Arduino board with the mobile phone sensors, so the new architecture is the following:


![architecture](/images/architecture2.png)

### Evaluation plan: 
We have adapted the criteria used for the evaluation, and the main changes are present in the section of costs and software required.
 
## 3 Technical work
- Collect data using Generic Sensor API ✔
- MQTT bridge ✘
- Three.js ✔
- Web page ✘
- Hologram platform ✔
 
## 4 Evaluation done
### User experience evaluation
- Task Success Rate ✔
- Task Time ✔
- Accessibility ✔
- Usability ✘
### Technical evaluation
- Required software ✔
- Accuracy ✘
- Latency ✘
- Costs ✔
## 5 What we expect to evaluate
- The perceived usability of the product through System Usability Scale
- Accuracy
- Latency
- Improve the evaluation of the Task Success Rate by measuring it with real data
