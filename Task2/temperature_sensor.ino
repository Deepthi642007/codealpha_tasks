// Temperature Controlled LED using TMP36

int sensorPin = A0;    // TMP36 middle pin connected to A0
int ledPin = 13;       // LED connected to Digital Pin 13

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read sensor value
  int sensorValue = analogRead(sensorPin);

  // Convert ADC value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature (TMP36 formula)
  float temperatureC = (voltage - 0.5) * 100.0;

  // Display temperature in Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Control LED
  if (temperatureC > 30)
  {
    digitalWrite(ledPin, HIGH);  // LED ON
    Serial.println("LED ON");
  }
  else
  {
    digitalWrite(ledPin, LOW);   // LED OFF
    Serial.println("LED OFF");
  }

  delay(1000); // Wait 1 second
}
