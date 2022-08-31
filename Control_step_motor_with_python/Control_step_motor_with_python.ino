const int stepPin = 8;
const int dirPin  = 9;
const int enPin  = 10;

int currentAngle = 0;
int angle = 0;
float stepPerAngle = 1.8; // full step = 1.8
int   numstep;
int musur;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  digitalWrite(dirPin, HIGH);
}

void loop() {
  while (!Serial.available());
  musur = Serial.readString().toInt();
  switch (musur) {
    case '1':
      owrum_1();
      break;
    case '2':
      owrum_2();
      break;
    case '3':
      owrum_3();
      break;
  }
}


void owrum_1() {
  int n;
  angle = 1500;
  if ( currentAngle != angle ) {
    if ( currentAngle < angle) {
      digitalWrite(dirPin, HIGH);
      n = angle - currentAngle;
      numstep = n / stepPerAngle;
    }

    else if ( currentAngle > angle) {
      digitalWrite(dirPin, LOW);
      n = currentAngle - angle;
      if ( angle == 0) {
        n = currentAngle;
      }

      numstep = n / stepPerAngle;
    }
    for (int x = 0; x < numstep; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);

    }
    currentAngle = angle;
  }
  delay(500);
}

void owrum_2() {
  int n;
  angle = 1125;
  if ( currentAngle != angle ) {
    if ( currentAngle < angle) {
      digitalWrite(dirPin, HIGH);
      n = angle - currentAngle;
      numstep = n / stepPerAngle;
    }

    else if ( currentAngle > angle) {
      digitalWrite(dirPin, LOW);
      n = currentAngle - angle;
      if ( angle == 0) {
        n = currentAngle;
      }

      numstep = n / stepPerAngle;
    }
    for (int x = 0; x < numstep; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);

    }
    currentAngle = angle;
  }
  delay(500);
}

void owrum_3() {
  int n;
  angle = 750;
  if ( currentAngle != angle ) {
    if ( currentAngle < angle) {
      digitalWrite(dirPin, HIGH);
      n = angle - currentAngle;
      numstep = n / stepPerAngle;
    }

    else if ( currentAngle > angle) {
      digitalWrite(dirPin, LOW);
      n = currentAngle - angle;
      if ( angle == 0) {
        n = currentAngle;
      }

      numstep = n / stepPerAngle;
    }
    for (int x = 0; x < numstep; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);

    }
    currentAngle = angle;
  }
  delay(500);
}
