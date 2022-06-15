#define ENA   9          // Enable/speed motors Right        GPIO14(D5)
#define IN_1 10          // L298N in1 motors Right           GPIO15(D8)
#define IN_2  11          // L298N in2 motors Right           GPIO13(D7)
const int IR = 8;
int Ir_sensor_val;

String command;             //String to store app command state.
int speedCar = 400;         // 400 - 1023.
int speed_Coeff = 3;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IR, INPUT);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
}

void loop() {
  Ir_sensor_val = digitalRead(IR);
  if (Ir_sensor_val == 0) {
    delay(9000);
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, speedCar);
    delay(300);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    delay(25rdca<000);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    analogWrite(ENA, speedCar);
    delay(300);
  }
  else {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
  }
}
