/*
  Youtube Tutorial xr_arduino_02
  xr_ampel2
  Schaltet 3 leds in Funktion einer Ampel mit delay() als verzögerung. Test für Arduino.
  Änderung zu xr_ampel1: startmethode ist jetzt ledinit()
  This example code is in the public domain.
 
 */

// Getestet an folgenden Arduino Boards: uno,
 
// Pin 13 über Vorwiderstand an rote Led.
// Pin 12 über Vorwiderstand an gelbe Led.
// Pin 11 über Vorwiderstand an grüne Led.
// Pin 10 über Vorwiderstand an rote Led/Fussgaenger
// Pin 9  über Vorwiderstand an grüne Led/Fussgaenger
// 
int led_krot = 13;
int led_kgelb = 12;
int led_kgruen = 11;
int led_frot = 9;
int led_fgruen =10;

// Start nach Reset hier:
void setup() {                
  // initialisiere digitale output/input pins.
  // Initalisiere Ampel beim Start, kfz=rot, Fussgaenger=gruen
  pinMode(led_krot, OUTPUT);
  pinMode(led_kgelb,OUTPUT);
  pinMode(led_kgruen,OUTPUT);
  
  pinMode(led_frot,OUTPUT);
  pinMode(led_fgruen,OUTPUT);
  
  ledinit();
  
}

// Hauptschleife:
void loop() {
  delay(3000);               // 3 sekunden warten
  digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
  digitalWrite(led_fgruen, LOW);
  flashred();
  delay(3000);
  digitalWrite(led_kgelb, HIGH); //kfz bekommt gelb in richtung Grün
  delay(2000);
  digitalWrite(led_krot, LOW); //kfz bekommt grün
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_kgruen, HIGH);
  delay(3000);               
  digitalWrite(led_kgruen, LOW); //kfz bekommt gelb in richtung rot
  digitalWrite(led_kgelb, HIGH);
  delay(2000);
  digitalWrite(led_kgelb, LOW); //kfz bekommt rot
  digitalWrite(led_krot, HIGH);
  flashred();
  delay(3000);
  digitalWrite(led_frot, LOW); // Fussgänger bekommt grün
  digitalWrite(led_fgruen, HIGH);
}

void ledinit() {
  
  digitalWrite(led_krot, HIGH); //Nach Start Kfz auf rot
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_kgruen, LOW);
  
  digitalWrite(led_frot, LOW); //Nach Start Fussgänger auf grün
  digitalWrite(led_fgruen, HIGH);
  
  loop();
  
}

void flashred(){
   
 digitalWrite(led_krot, LOW); //Beide roten leds aus
 digitalWrite(led_frot, LOW); 
 delay(200);
 digitalWrite(led_krot, HIGH); //Beide roten leds aus
 digitalWrite(led_frot, HIGH); 
 delay(200);
 digitalWrite(led_krot, LOW); //Beide roten leds aus
 digitalWrite(led_frot, LOW); 
 delay(200);
 digitalWrite(led_krot, HIGH); //Beide roten leds aus
 digitalWrite(led_frot, HIGH); 
}
