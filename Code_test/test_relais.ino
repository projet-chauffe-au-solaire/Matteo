#define RELAIS_PIN 14  // Broche connectée à l'entrée du relais

void setup() {
  pinMode(RELAIS_PIN, OUTPUT);  // Déclare la broche en sortie
  digitalWrite(RELAIS_PIN, HIGH); // État initial : relais désactivé
}

void loop() {
  digitalWrite(RELAIS_PIN, HIGH);  // Active le relais
  delay(2000);                     // Attente 2 secondes
  digitalWrite(RELAIS_PIN, LOW);   // Désactive le relais
  delay(2000);                     // Attente 2 secondes
}
