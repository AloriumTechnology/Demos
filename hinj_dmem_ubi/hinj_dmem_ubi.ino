//--------------------------------------------------------------------
//  hinj_dmem_ubi.ino
//--------------------------------------------------------------------
// Copyright (c) 2019 Alorium Technology.  All rights reserved.
// Written by Jason Pecor of Alorium Technology (info@aloriumtech.com).
//  
// This program provides a simple examlple for demonstrating the 
// XLRDMem Xcelerator Block with the Hinj Board. It connects to the 
// Ubidots IoT platform, sends data for three valuables and gets data
// from Ubidots.
// 
// Alorium library requirements:
//   - UbidotsHinj
//   - XLR8HinjWifi101
//--------------------------------------------------------------------
#include <UbidotsHinj.h> 
#include <SPI.h>
#include <XLR8HinjWiFi101.h>

XLR8WiFiClient client;

// Ubidots Token
#define TOKEN ""

// Wi-Fi credentials
 char ssid[] = "";  // WiFi SSID
 char pass[] = "";  // WiFi Password

Ubidots ubidots(TOKEN);

float control0;
int sensor0, sensor1, sensor2;

void setup() {

  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  
  // Initialize and connect to Ubidots
  ubidots.initialize();
  ubidots.setDeviceName("Hinj_Dmem");
  ubidots.setDeviceLabel("Hinj_Dmem");
  ubidots.wifiConnection(ssid,pass);

}

void loop() {

  // Send random values for sensor variables
  sensor0 = random(100,199);
  sensor1 = random(100,199);
  sensor2 = random(100,199);
  
  Serial.println("Send sensor data");
  Serial.print("sensor0: "); Serial.println(sensor0);
  Serial.print("sensor1: "); Serial.println(sensor1);
  Serial.print("sensor2: "); Serial.println(sensor2);
  Serial.println("");

  ubidots.add("sensor0", sensor0);
  ubidots.add("sensor1", sensor1);
  ubidots.add("sensor2", sensor2);
  ubidots.sendAll();

  
  // Get values from ubidots control widget
  Serial.println("Get values");
  control0 = ubidots.getValueWithDeviceLabel("Hinj_Dmem", "control0");
  
  Serial.print("control0:");
  Serial.println(control0);
  Serial.println("");
  
  // Delay 
  delay(10000);  
  
}
