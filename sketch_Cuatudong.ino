#include <dummy.h>

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6zpttjpzL"
#define BLYNK_TEMPLATE_NAME "Cuatudong"
#define BLYNK_AUTH_TOKEN "w-57fdaDFucCIN8ND6P-FRbXWOwEzmpV"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial                                


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "conroi2024";
char pass[] = "hihihehe";

Servo servo;
int dieukhien = 0;
int tudong = 0;

// BLYNK_WRITE(V3)
// {
//   servo.write(param.asInt());
// }
BLYNK_WRITE(V0) {
  dieukhien = param.asInt();  // assigning incoming value from pin V1 to a variable

  // process received value
}
BLYNK_WRITE(V1) {
  tudong = param.asInt();  // assigning incoming value from pin V1 to a variable

  // process received value
}
void setup() {
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  servo.attach(D2);
  pinMode(D6, INPUT);
}

void loop() {
  Blynk.run();

  if (tudong == 1) {
    if (digitalRead(D6) == 1) {
      servo.write(0);
    } else if (digitalRead(D6) == 0) {
      servo.write(90);
    }
  } else if (tudong == 0) {
    if (dieukhien == 1) {
      servo.write(90);

    } else if (dieukhien == 0) {
      servo.write(0);
    }
  }
}