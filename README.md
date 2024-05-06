LifeLaneGuardian
Description
LifeLaneGuardian is an embedded project aimed at reducing the latency period of ambulances in heavy traffic situations by providing real-time alerts to the police and implementing voice note indications in traffic signals. The project also incorporates a Bluetooth MP3 decoding board module with inbuilt SD card slot, USB support, FM radio, and remote control capabilities.

Table of Contents
Introduction
Features
Hardware Components
Getting Started
Usage
License
Introduction
LifeLaneGuardian is designed to enhance emergency response times by leveraging embedded technology to provide timely alerts to authorities, communicate with traffic signals, and offer additional features through the Bluetooth MP3 decoding board module.

Features
Real-Time Alert to Police: LifeLaneGuardian sends alert messages to the police in advance, along with a live location link, when an ambulance is approaching heavy traffic areas.
Voice Note Indication: Utilizing RF communication between ambulances and traffic signals, LifeLaneGuardian enables voice note indications at traffic signals to alert drivers to clear the lane for approaching emergency vehicles.
Bluetooth MP3 Decoding Board Module: The project incorporates a Bluetooth MP3 decoding board module with inbuilt SD card slot, USB support, FM radio, and remote control capabilities, providing additional functionality and entertainment options.
Hardware Components
LifeLaneGuardian utilizes the following hardware components:

Arduino microcontroller for system control and data processing.
GPS NEO-7M module for obtaining real-time location information.
GSM SIM900A module for sending alert messages to the police.
RF 433MHz module for communication between ambulances and traffic signals.
Bluetooth MP3 decoding board module with inbuilt SD card slot, USB support, FM radio, and remote control capabilities.
Getting Started
To get started with LifeLaneGuardian, follow these steps:

Connect the hardware components (Arduino, GPS module, GSM module, RF module, Bluetooth MP3 decoding board module) according to the provided schematic.
Upload the Arduino sketch (provided in the project repository) to the Arduino board.
Configure the system parameters, including GPS and GSM settings.
Test the system in a controlled environment to ensure proper functionality.
Usage
Alert to Police: When an ambulance equipped with LifeLaneGuardian approaches heavy traffic, the system automatically sends alert messages to the police, providing real-time information about the emergency vehicle's location and route.
Voice Note Indication: LifeLaneGuardian establishes RF communication between ambulances and traffic signals. When an ambulance is approaching, traffic signals broadcast voice notes to alert drivers to clear the lane, facilitating the smooth passage of emergency vehicles.
Bluetooth MP3 Decoding Board Module: Users can utilize the additional features provided by the Bluetooth MP3 decoding board module for entertainment and audio playback.
License
LifeLaneGuardian is licensed under the MIT License.

