/*
  Youtube Tutorial xr_arduino_02
  xr_ampel4
  Schaltet 3 leds in Funktion einer Ampel mit delay() als verzögerung. Test für Arduino.
  Änderung zu xr_ampel1: startmethode ist jetzt ledinit()
  Änderung zu xr_ampel2: Alle Funktionen der ampel jetzt per polling
  Änderung zu xr_ampel4: Zum Beweis das gepollt wird pulse auf grüne led
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

long led_start_time; //speichert aktuellen Zeitpunkt
int led_delay;  //nimmt die delayzeit auf
int led_funktion; //speichert den aktuellen status der ampel

long dimmtime;
int dimmcount;
int dimmrichtung;

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
  
} //void setup

// Hauptschleife:
void loop() {
  
  if (millis()-led_start_time > led_delay) {
    led_funktion++;
    if (led_funktion > 6) led_funktion=1;
    setleds(led_funktion);
  } //if millis
  
  dimmdasteil();
  
} //void loop

void ledinit() {
  
  dimmcount=0;
  dimmrichtung=5;
  led_funktion=1;
  setleds(led_funktion); //Nach Start Kfz auf rot
                        //Nach Start Fussgänger auf grün
  
  loop();    //zur eigentlichen hauptschleife
  
}

void setleds(int xf){

  digitalWrite(led_frot, LOW); //Alle LEDs ausschalten
  //digitalWrite(led_fgruen, LOW); temprär weg wegen dimm
  digitalWrite(led_krot, LOW); 
  digitalWrite(led_kgelb, LOW);
  digitalWrite(led_kgruen, LOW);
  
  led_start_time=millis();
  
  switch (xf) {
    case 9:                          //temporär weg wegen dimm
      digitalWrite(led_krot, HIGH); // Kfz auf rot
      digitalWrite(led_fgruen, HIGH); //Fussgänger auf grün
      led_delay=3000;
      break;
    case 2:
      digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
      digitalWrite(led_krot, HIGH); // Kfz auf rot
      led_delay=3000;
      break;
    case 3:
      digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
      digitalWrite(led_krot, HIGH); // Kfz auf rot
      digitalWrite(led_kgelb, HIGH);// Kfz gelb an richtung grün
      led_delay=2000;
      break;
    case 4:
      digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
      digitalWrite(led_kgruen, HIGH); // Kfz auf grün
      led_delay=3000;
      break;
    case 5:
      digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
      digitalWrite(led_kgelb, HIGH);// Kfz gelb an richtung rot
      led_delay=2000;
      break;
    case 6:
      digitalWrite(led_frot, HIGH); //Fussgänger bekommt rot
      digitalWrite(led_krot, HIGH); // Kfz auf rot
      led_delay=3000;
      break;
         
  }  //switch

} //void setleds

void dimmdasteil() {
  
  if (millis()-dimmtime>25) {  
    analogWrite(led_fgruen,dimmcount);     //setze alle 25ms neuen analogwert
    if (dimmrichtung==5 && dimmcount<250){ //erhöhen wenn dimmrichtung nach oben 
      dimmrichtung=5;  
    }
    else{
      dimmrichtung=-5;                    //Dimmrichtung umkehren
    }
    
    if (dimmrichtung==-5 && dimmcount>5){ //verringern wenn dimmrichtung nach unten
      dimmrichtung=-5;  
    }
    else{
      dimmrichtung=5;                     //dimmrichtung umkehren
    }
    
    dimmcount=dimmcount+dimmrichtung;
    dimmtime=millis();
  }
  
} //void dimmdasteil


