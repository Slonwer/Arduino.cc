// C++ code
//
int butaum = 0;

int butaum2 = 0;

void setup()
{
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
}

void loop()
{
  butaum = digitalRead(7);
  if (butaum == HIGH) {
    digitalWrite(13, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  butaum2 = digitalRead(3);
  if (butaum2 == HIGH) {
    digitalWrite(13, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }

  HIGH;
}