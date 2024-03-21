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
int rychlost = 1;
//
int uhel = 360;

/*
ex1.pinMode(P0, OUTPUT);
ex1.pinMode(P1, OUTPUT);
ex1.pinMode(P2, OUTPUT);
ex1.pinMode(P3, OUTPUT); */

void setup(){
  //něco tam doplnit
  //Serial.begin(115200);
  pinMode(P0, OUTPUT);
  ex1.pinMode(P1, OUTPUT);
  ex1.pinMode(P2, OUTPUT);
  ex1.pinMode(P3, OUTPUT);
  ex1.pinMode(P4, OUTPUT);
  ex1.pinMode(P5, OUTPUT);
  ex1.pinMode(P6, OUTPUT);
  ex1.pinMode(P7, OUTPUT);
  ex1.begin();
}

void setupHigh(int pinik) {
	delay(200);
  ex1.pinMode(pinik, OUTPUT);
	ex1.digitalWrite(pinik, HIGH);
}

void setupLow(int pinik) {
	delay(200);
  ex1.pinMode(pinik, OUTPUT);
	ex1.digitalWrite(pinik, LOW);
}


void krok1(){
  setupHigh(in1);
  setupLow(in2);
  setupLow(in3);
  setupLow(in4);
  delay(rychlost);
}
void krok2(){
  setupHigh(in1);
  setupHigh(in2);
  setupLow(in3);
  setupLow(in4);
  delay(rychlost);
}
void krok3(){
  setupLow(in1);
  setupHigh(in2);
  setupLow(in3);
  setupLow(in4);
  delay(rychlost);
}

void krok4(){
  setupLow(in1);
  setupHigh(in2);
  setupHigh(in3);
  setupLow(in4);
  delay(rychlost);
}

void krok5(){
  setupLow(in1);
  setupLow(in2);
  setupHigh(in3);
  setupLow(in4);
  delay(rychlost);
}

void krok6(){
  setupLow(in1);
  setupLow(in2);
  setupHigh(in3);
  setupHigh(in4);
  delay(rychlost);
}

void krok7(){
  setupLow(in1);
  setupLow(in2);
  setupLow(in3);
  setupHigh(in4);
  delay(rychlost);
}

void krok8(){
  setupHigh(in1);
  setupLow(in2);
  setupLow(in3);
  setupHigh(in4);
  delay(rychlost);
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
  digitalWrite(P0, LOW);
  delay(1000);
  ex1.digitalWrite(P1, LOW);
  delay(1000);
  ex1.digitalWrite(P2, LOW);
  delay(1000);
  ex1.digitalWrite(P3, LOW);
  delay(1000);
  ex1.digitalWrite(P4, LOW);
  delay(1000);
  ex1.digitalWrite(P5, LOW);
  delay(1000);
  ex1.digitalWrite(P6, LOW);
  delay(1000);
  ex1.digitalWrite(P7, LOW);


  delay(1000);
  /*
  delay(1000);
  // plná rotace o 360 stupňů = 512 volání
  // funkce rotacePoSmeru() či rotaceProtiSmeru()
  for(int i=0;i<(uhel*64/45);i++){
    rotacePoSmeru();
  }
  // pauza po dobu 1 vteřiny
  delay(1000);
  
  for(int i=0;i<(uhel*64/45);i++){
    rotaceProtiSmeru();
  }
  // pauza po dobu 1 vteřiny
  delay(1000);*/
  }


