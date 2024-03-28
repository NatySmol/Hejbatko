// SPDX-FileCopyrightText: 2023 Carter Nelson for Adafruit Industries
//
// SPDX-License-Identifier: MIT
// --------------------------------------
// i2c_scanner
//
// Modified from https://playground.arduino.cc/Main/I2cScanner/
// --------------------------------------


#include <Arduino.h>
#include "PCF8574.h"

PCF8574 ex1(0x20);

// čísla pinů pro digitální výstupy
int in1 = P0;
int in2 = P1;
int in3 = P2;
int in4 = P3;

// proměnná pro nastavení rychlosti,
// se zvětšujícím se číslem se rychlost zmenšuje
int rychlost = 500;
//
int uhel = 360;
uint8_t pins[8] = {P0, P1, P2, P3, P4, P5, P6, P7};
/*
ex1.pinMode(P0, OUTPUT);
ex1.pinMode(P1, OUTPUT);
ex1.pinMode(P2, OUTPUT);
ex1.pinMode(P3, OUTPUT); */

void setup(){
  
  //něco tam doplnit
  Serial.begin(115200);
  ex1.begin();
  for (int i = 0; i < 8; i++)
    ex1.pinMode(pins[i], OUTPUT);
}

void setupHigh(int j) {
  //delayMicroseconds(200);
  ex1.digitalWrite(pins[j], HIGH);
}

void setupLow(int j) {
  //delayMicroseconds(200);
  ex1.digitalWrite(pins[j], LOW);
}

void krok1(){
  setupHigh(0);
  setupLow(1);
  setupLow(2);
  setupLow(3);
  
  setupHigh(4);
  setupLow(5);
  setupLow(6);
  setupLow(7);
  delayMicroseconds(rychlost);

}
void krok2(){
  setupHigh(0);
  setupHigh(1);
  setupLow(2);
  setupLow(3);
  setupHigh(4);
  setupHigh(5);
  setupLow(6);
  setupLow(7);
  delayMicroseconds(rychlost);
}
void krok3(){
  setupLow(0);
  setupHigh(1);
  setupLow(2);
  setupLow(3);

  setupLow(4);
  setupHigh(5);
  setupLow(6);
  setupLow(7);
  delayMicroseconds(rychlost);
}

void krok4(){
  setupLow(0);
  setupHigh(1);
  setupHigh(2);
  setupLow(3);

  setupLow(4);
  setupHigh(5);
  setupHigh(6);
  setupLow(7);
  delayMicroseconds(rychlost);
}

void krok5(){
  setupLow(0);
  setupLow(1);
  setupHigh(2);
  setupLow(3);

  setupLow(4);
  setupLow(5);
  setupHigh(6);
  setupLow(7);
  delayMicroseconds(rychlost);
}

void krok6(){
  setupLow(0);
  setupLow(1);
  setupHigh(2);
  setupHigh(3);

  setupLow(4);
  setupLow(5);
  setupHigh(6);
  setupHigh(7);
  delayMicroseconds(rychlost);
}

void krok7(){
  setupLow(0);
  setupLow(1);
  setupLow(2);
  setupHigh(3);
  
  setupLow(4);
  setupLow(5);
  setupLow(6);
  setupHigh(7);
  delayMicroseconds(rychlost);
}

void krok8(){
  setupHigh(0);
  setupLow(1);
  setupLow(2);
  setupHigh(3);
  setupHigh(4);
  setupLow(5);
  setupLow(6);
  setupHigh(7);
  delayMicroseconds(rychlost);
}

void rotacePoSmeru() {
  krok1();
  krok2();
  krok3();
  krok4();
  krok5();
  krok6();
  krok7();
  krok8();
}
void rotaceProtiSmeru() {
  krok8();
  krok7();
  krok6();
  krok5();
  krok4();
  krok3();
  krok2();
  krok1();
}


void loop() {

  // plná rotace o 360 stupňů = 512 volání
  // funkce rotacePoSmeru() či rotaceProtiSmeru()
  
  for(int i=0;i<(uhel*64/45);i++){
    rotacePoSmeru();
    
  }
  delay(1000);
  
  // pauza po dobu 1 vteřiny
  
  /*
  for(int i=0;i<(uhel*64/45);i++){
    rotaceProtiSmeru();
  } */
  // pauza po dobu 1 vteřiny
  }


