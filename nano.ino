#include <SPI.h>
#include <SD.h>

// Motor A connections
int in1 = 8;
int in2 = 9;
// Motor B connections
int in3 = 10;
int in4 = 11;


int IR1 = A4;
// int IR2=7;//
int IR3 = 4;
// int IR4=A4;//
int IR5 = A5;


const int trigPin = A3;
const int echoPin = A2;
long duration;
int distance;

//sd card
File myFile;

// change this to match your SD shield or module;
const int chipSelect = 10;

void setup() {
  Serial.begin(9600);
  //  forward();
  //  delay(2000);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  pinMode(IR1, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR5, INPUT);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("MES2.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    myFile.println("ADIOS !!!!");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop() {
  int distance;
  distance = Ultra();

  int value1, value3, value5;
  value1 = digitalRead(IR1);
  value3 = digitalRead(IR3);
  value5 = digitalRead(IR5);

// if (myFile) {
      if (value1 == 0 && value3 == 1 && value5 == 0) {
      forward();
      myFile.println("FORWARD");

    } else if (value1 == 1 && value3 == 0 && value5 == 0) {
  
          right();
      myFile.println("LEFT");

    } else if (value1 == 0 && value3 == 0 && value5 == 1) {
    left();
      myFile.println("RIGHT");

    } else if (value1 == 0 && value3 == 0 && value5 == 0) {
      rev();
      myFile.println("STOP");
    }
    if (distance < 13) {
      stop();

      // right();
      // right();
      myFile.println("REVERSE BECAUSE THERE WAS OBSTACLE OBSERVED");
    }
    myFile.close();
// }
  
}
