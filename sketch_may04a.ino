// Arduino EKG monitor srdeční aktivity
// Arduino IDE ukázkový kód

// nastavení čísel propojovacích pinů
#define LOplus 10
#define LOminus 11
#define output A0

void setup() {
  // komunikace po sériové lince rychlostí 9600 baud
  Serial.begin(9600);
  // nastavení směru vstupních pinği
  pinMode(LOplus, INPUT);
  pinMode(LOminus, INPUT);
  pinMode(output, INPUT);
}

void loop() {
  // pokud je alespoň jeden z LO pinů aktivní, vytiskneme
  // po sériové lince znak vykřičníku
  if ((digitalRead(LOplus) == 1) || (digitalRead(LOminus) == 1)) {
    Serial.println('!');
    
  }
  // v opačném případě vytiskneme načtenou hodnotu
  // z analogového pinu
  else {
    Serial.println(analogRead(output));
  }
  // krátká pauza před odesláním dalších dat
  delay(1);
}
