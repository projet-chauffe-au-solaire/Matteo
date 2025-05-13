#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// Broches des LEDs
int ledPins[] = {33, 32, 13, 25};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(115200);

  // Initialisation écran
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(4);
  tft.setTextColor(ILI9341_GREEN);
  tft.setCursor(30, 100);
  tft.println("Demarrage...");

  // Initialisation LEDs
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }

  delay(1000);
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    // Allume LED[i]
    digitalWrite(ledPins[i], LOW);
    
    // Affiche l'état LED ON
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(20, 100);
    tft.setTextColor(ILI9341_YELLOW);
    tft.print("LED ");
    tft.print(i + 1);
    tft.println(" ON");

    delay(500); // Temps LED allumée

    // Éteint LED[i]
    digitalWrite(ledPins[i], HIGH);
    delay(300); // Temps LED éteinte
  }
}
