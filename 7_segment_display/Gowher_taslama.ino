int a = 6;
int b = 5;
int c = 2;
int d = 3;
int e = 4;
int f = 7;
int g = 8;
int dp = 9;

void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case '1':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(dp, HIGH);
        break;
      case '2':
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '3':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '4':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '5':
        digitalWrite(b, LOW);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '6':
        digitalWrite(b, LOW);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '7':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(dp, HIGH);
        break;
      case '8':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '9':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(dp, HIGH);
        break;
      case '0':
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(a, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(dp, HIGH);
        break;
    }
  }
}
