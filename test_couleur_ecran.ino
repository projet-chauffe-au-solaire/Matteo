#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// Broches à adapter selon ton branchement
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4  // ou -1 si non utilisé

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.begin();
  tft.setRotation(3);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

}

void loop() {
  
   // Affiche plein écran en rouge
  tft.fillScreen(ILI9341_RED);
  delay(1000);

  // Affiche plein écran en vert
  tft.fillScreen(ILI9341_GREEN);
  delay(1000);

  // Affiche plein écran en bleu
  tft.fillScreen(ILI9341_BLUE);
  delay(1000);

  // Écrit du texte
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 30);
  tft.print("Vive FC Nantes");
  delay(1000);
}
