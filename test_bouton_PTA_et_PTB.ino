#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

// === TFT ILI9341 ===
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// === Écran tactile XPT2046 ===
#define TOUCH_CS  5
#define TIRQ_PIN  255
XPT2046_Touchscreen ts(TOUCH_CS, TIRQ_PIN);

// === Taille bouton ===
#define BTN_X 60
#define BTN_Y 100
#define BTN_W 120
#define BTN_H 50

int compteur = 0;

void drawButton() {
  tft.fillRect(BTN_X, BTN_Y, BTN_W, BTN_H, ILI9341_BLUE);
  tft.drawRect(BTN_X, BTN_Y, BTN_W, BTN_H, ILI9341_WHITE);
  tft.setCursor(BTN_X + 20, BTN_Y + 15);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("Appuie");
}

void drawCounter() {
  tft.fillRect(0, 30, 240, 20, ILI9341_BLACK); // Efface zone du compteur
  tft.setCursor(80, 30);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.print("Clics: ");
  tft.print(compteur);
}

void setup() {
  Serial.begin(115200);
  tft.begin();
  ts.begin();
  ts.setRotation(1);
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  drawButton();
  drawCounter();
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();

    // Corrige les axes si nécessaire
    int16_t x = map(p.y, 200, 3900, 0, tft.width());
    int16_t y = map(p.x, 300, 3800, 0, tft.height());

    if (x > BTN_X && x < (BTN_X + BTN_W) && y > BTN_Y && y < (BTN_Y + BTN_H)) {
      // Effet de clic visuel
      tft.fillRect(BTN_X, BTN_Y, BTN_W, BTN_H, ILI9341_RED);
      tft.setCursor(BTN_X + 10, BTN_Y + 15);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(2);
      tft.print("CLIC !");
      compteur++;
      drawCounter();
      delay(300); // Anti-rebond tactile
      drawButton();
    }
  }
}
