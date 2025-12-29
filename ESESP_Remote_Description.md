Hardware Components

ESP32 or ESP8266 (2 units)

One board acts as the Sender (Command Node)

One board acts as the Receiver (Execution Node)

Stable Power Supply for ESP Boards

USB power (5V) or external regulated power source

Power bank or adapter for long-term operation

Actuator / Load (for Receiver Node)

LED (for testing)

Relay module (for controlling real devices)

Motor, buzzer, or any digital output device

Current-Limiting Resistor (220Ω – 330Ω)

Required when using an LED

Breadboard and Jumper Wires

For rapid prototyping and testing

Network and Infrastructure

Wi-Fi Internet Connection

Required for both ESP devices

Devices can be located in different cities or countries

MQTT Broker with Public Access

Public broker (e.g., HiveMQ, Mosquitto test server)

OR private broker hosted on a VPS with a static public IP

Static Public IP (Optional but Recommended)

Provided by a VPS for running a private MQTT broker

Improves reliability and security

Software Tools

Arduino IDE

Used for programming ESP boards

ESP Board Support Package

ESP32 or ESP8266 core installed in Arduino IDE

MQTT Client Library

PubSubClient library

Serial Monitor

For debugging and monitoring communication

Optional (Advanced / Security)

TLS Certificates

For encrypted MQTT communication (MQTT over SSL/TLS)

Authentication Credentials

Username and password for broker access
