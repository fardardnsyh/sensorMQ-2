#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

const int sensorAsap = A0; // inisialisasi sensor asap pin pada A0
const int kipas = 7;      // inisialisasi kipas pin pada 7
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

int smokeValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
 pinMode(sensorAsap, INPUT); // Untuk menentukan pin sensor asap sebagai input
 pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
 pinMode(kipas, OUTPUT);  // Untuk menentukan pin kipas sebagai output
digitalWrite(buzzer,LOW);
digitalWrite(kipas,HIGH);
}

void loop() {
 //output Asap
 
smokeValue = analogRead(sensorAsap); // Membaca nilai sensor MQ-2
Serial.print("Asap: ");
Serial.println(smokeValue);

if (smokeValue > 300){
  digitalWrite(buzzer, HIGH); 
  digitalWrite(kipas, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Asap : ");
  lcd.print(smokeValue);
  lcd.setCursor(2, 1);
  lcd.print("Bahaya Asap");
  delay(4000);
  lcd.clear();
 
}

else {
  digitalWrite(buzzer, LOW);
  digitalWrite(kipas, HIGH);
  lcd.setCursor(3, 1);
  lcd.print("Ruangan Aman");
  delay(2000);
  lcd.clear();    
}
}
