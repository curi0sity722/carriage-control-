int RPWM=5;
int LPWM=6;
int L_EN=3;
int R_EN=4;

const int ledPin = 13;
int relay_pin = 8;

int value = 0;         // Default PWM value
String direction_char;
int welding_status = 0;
int ascii_rep = 0;

char dir;
int speed, status;

void setup() {
  pinMode(ledPin, OUTPUT); // Corrected from HIGH to OUTPUT
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  pinMode(9, OUTPUT);

  // Enable motors
  digitalWrite(9, HIGH); // relay vcc 
  digitalWrite(relay_pin, HIGH); // relay IN2
  // digitalWrite(9, HIGH);
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    if (sscanf(input.c_str(), "%c %d %d", &dir, &speed, &status) == 3) {
      direction_char = dir;
      value = constrain(speed, 0, 255);
      welding_status = status;

      Serial.print("Direction: ");
      Serial.println(direction_char);
      Serial.print("Speed: ");
      Serial.println(value);
      Serial.print("Welding status: ");
      Serial.println(welding_status);

      ascii_rep = (int)direction_char[0];  

      if (ascii_rep == 82) {
        analogWrite(RPWM, value);
        analogWrite(LPWM, 0);
      } else {
        analogWrite(LPWM, value);
        analogWrite(RPWM, 0);
      }

      digitalWrite(relay_pin, welding_status == 0 ? HIGH : LOW);


    }
  }

}

