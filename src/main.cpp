#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor (HC-SR04)
 * @author Vansh Saxena
 * @date 2026-02-28
 *
 * @details
 * This program measures distance using the HC-SR04 ultrasonic sensor.
 * It sends a 10µs trigger pulse, measures echo time using pulseIn(),
 * and calculates distance in centimeters.
 */

// Define TRIG and ECHO pins
#define TRIG_PIN 9
#define ECHO_PIN 10

// Variables to store duration and distance
long duration;
float distance;

/**
 * @brief Initializes serial communication and ultrasonic sensor pins.
 */
void setup() {

    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println("Ultrasonic Distance Measurement System Initialized");
}

/**
 * @brief Continuously measures and prints distance in cm.
 */
void loop() {

    // Ensure TRIG is LOW
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send 10 microsecond pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure echo duration
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate distance (cm)
    // Speed of sound = 0.0343 cm/µs
    distance = duration * 0.0343 / 2;

    // Print result
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}