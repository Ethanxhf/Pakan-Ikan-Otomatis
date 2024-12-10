#include "RTClib.h"
RTC_DS3231 rtc;
int jam, menit, detik;

#include <Servo.h>
Servo mekanik;

void setup() {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }
  // GUNAKAN KODE DI BAWAH INI PADA UPLOAD YANG PERTAMA, LALU UPLOAD LAGI TANPA KODE DI BAWAH
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  mekanik.attach(4);
  mekanik.write(90);
}

void loop() {

  DateTime now = rtc.now();
  jam     = now.hour();
  menit   = now.minute();
  detik   = now.second();
  Serial.println(String() + jam + ":" + menit + ":" + detik);
  Serial.println();

  //KONDISI (SETTING WAKTU SERVO BERPUTAR)
  if ( (jam == 7) && (menit == 30) && (detik == 1) ) {
    kasih_pakan(20);
  }
  if ( (jam == 16) && (menit == 30) && (detik == 1) ) {
    kasih_pakan(20);
  }

}

void kasih_pakan(int jumlah) {
  for (int i = 1; i <= jumlah; i++) {
    mekanik.write(150);
    delay(100);
    mekanik.write(90);
    delay(100);
  }
}
