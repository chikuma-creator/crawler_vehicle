#include <IRremote.h>

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 7;
const int IN4 = 6;
const int reciever  = 11;  // Signal pin of IR receiver to Arduino Digital Pin 11

IRrecv irrecv(reciever);
decode_results results;

void transrateIR() {
  switch (results.value) {
    case 0xFF30CF:
      Serial.println("1");
      leftForward();
      break;
    case 0xFF18E7:
      Serial.println("2");
      forward();
      break;
    case 0xFF7A85:
      Serial.println("3");
      rightForward();
      break;
    case 0xFF10EF:
      Serial.println("4");
      left();
      break;
    case 0xFF38C7:
      Serial.println("5");
      stop();
      break;
    case 0xFF5AA5:
      Serial.println("6");
      right();
      break;
    case 0xFF42BD:
      Serial.println("7");
      leftBack();
      break;
    case 0xFF4AB5:
      Serial.println("8");
      back();
      break;
    case 0xFF52AD:
      Serial.println("9");
      rightBack();
      break;
    default:
      Serial.println("Push other button.");
  }
  delay(5);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Tank move start.");
  irrecv.enableIRIn();
}

void stop() {
  Serial.println("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  Serial.println("forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  Serial.println("back");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  Serial.println("right");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightForward() {
  Serial.println("rightForward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rightBack() {
  Serial.println("rightBack");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void left() {
  Serial.println("left");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftForward() {
  Serial.println("leftForward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftBack() {
  Serial.println("leftBack");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    transrateIR();
    irrecv.resume();
  }
}
