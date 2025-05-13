// Définition des 6 broches de commande LED/Relais
const int ledPins[5] = {33, 32, 13, 2, 25};

void setup() {
  // Initialiser toutes les broches en sortie
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Éteindre tout au démarrage
  }
}

void loop() {
  // Allumer les LED une par une
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(300);  // Pause pour voir l'effet
  }

  // Éteindre les LED une par une
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(300);
  }
}
