#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Déclaration des broches écran
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// Durée totale en secondes (60 minutes)
const unsigned long DURATION_SECONDS = 60 * 60;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);

  // Initialisation de l'écran
  tft.begin();
  tft.setRotation(1); // Paysage
  tft.fillScreen(ILI9341_BLACK);

  // Lancer le compteur
  startTime = millis();
}

void loop() {
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate >= 5000) { // Mise à jour chaque seconde
    lastUpdate = millis();

    unsigned long elapsed = (millis() - startTime) / 1000;
    if (elapsed > DURATION_SECONDS) elapsed = DURATION_SECONDS;

    unsigned long remaining = DURATION_SECONDS - elapsed;
    int percent = (elapsed * 100) / DURATION_SECONDS;

    int minutesLeft = remaining / 60;
    int secondsLeft = remaining % 60;

    // Efface l'ancienne zone
    tft.fillRect(0, 100, 320, 80, ILI9341_BLACK);

    // Affiche le pourcentage
    tft.setCursor(10, 110);
    tft.setTextColor(ILI9341_CYAN);
    tft.setTextSize(3);
    tft.print("MAJ CarteUG: ");
    tft.print(percent);
    tft.print(" % ");
    tft.print("Test en cours ... ");
  }
}
