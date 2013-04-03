/*
  xr_ampel
  Schaltet 3 leds in Funktion einer Ampel mit delay() als verzögerung. Test für Arduino.
  Benutzt weitere Methoden und loop() ist nicht mehr start-hauptmethode.
 
  This example code is in the public domain.
 */

// Getestet an folgenden Arduino Boards: uno,
 
// Pin 13 über Vorwiderstand an rote Led.
// Pin 12 über Vorwiderstand an gelbe Led.
// Pin 11 über Vorwiderstand an grüne Led.
// give it a name:
int led_krot = 13;
int led_kgelb = 12;
int led_kgruen = 11;
int led_frot = 9;
int led_fgruen =10;

// Start nach Reset hier:
void setup() {                
  // initialisiere digitale output/input pins.
  pinMode(led_krot, OUTPUT);
  pinMode(led_kgelb,OUTPUT);
  pinMode(led_kgruen,OUTPUT);
  
  pinMode(led_frot,OUTPUT);
  pinMode(led_fgruen,OUTPUT);
  
  ledinit(); 
}

// Hauptschleife:
void loop() {
  delay(3000);               // wait for a second
  digitalWrite(led_frot, HIGH);
  digitalWrite(led_fgruen, LOW);
  delay(3000);
  digitalWrite(led_kgelb, HIGH);
  delay(2000);
  digitalWrite(led_krot, LOW);
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_kgruen, HIGH);
  delay(3000);               // wait for a second
  digitalWrite(led_kgruen, LOW);
  digitalWrite(led_kgelb, HIGH);
  delay(2000);
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_krot, HIGH);
  delay(3000);
  digitalWrite(led_frot, LOW);
  digitalWrite(led_fgruen, HIGH);
}

//Led Initalisierung
void ledinit(){

  digitalWrite(led_krot, HIGH);
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_kgruen, LOW);
  
  digitalWrite(led_frot, LOW);
  digitalWrite(led_fgruen, HIGH);

  loop();  
}  
