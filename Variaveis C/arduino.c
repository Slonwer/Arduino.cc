const int LED_PIN = 13;
const int BUTTON_PIN = 2;

int buttonState = 0;
float temperature = 25.5;

void setup() {
  
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);

    Serial.print("Temperature: ");
    Serial.println(temperature);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);

  temperature += 0.1;
}