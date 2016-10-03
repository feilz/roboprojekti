#define NOFIELD 300L    // Analog output with no applied field, calibrate this

// Uncomment one of the lines below according to device in use A1301 or A1302
// This is used to convert the analog voltage reading to milliGauss
// For A1301: 2.5mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 1953mG
// For A1302: 1.3mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 3756mG
#define toimiva 2
#define TOMILLIGAUSS 1.953125
// #define TOMILLIGAUSS 3.756010

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  float gauss1 = (analogRead(0) - NOFIELD) * TOMILLIGAUSS;
  float gauss2 = (analogRead(1) - NOFIELD) * TOMILLIGAUSS;
  int LEDR = 3;
  int LEDL = 10;
  Serial.print("gauss1:     ");
  Serial.print(gauss1, 2);
 // Serial.print(" Gauss ");

  if (gauss1 > 0)     Serial.println("(South pole)");
  else if (gauss1 < 0) Serial.println("(North pole)");
  else               Serial.println();

Serial.print("gauss2:     ");
Serial.print(gauss2, 2);
 // Serial.print(" Gauss ");

  if (gauss2 > 0)     Serial.println("(South pole)");
  else if (gauss2 < 0) Serial.println("(North pole)");
  else               Serial.println();

  }
