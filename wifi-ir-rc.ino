/*
   IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend.

   An IR LED circuit *MUST* be connected to ESP8266 pin 4 (D2).

   TL;DR: The IR LED needs to be driven by a transistor for a good result.

   Suggested circuit:
       https://github.com/markszabo/IRremoteESP8266/wiki#ir-sending

   Common mistakes & tips:
 *   * Don't just connect the IR LED directly to the pin, it won't
       have enough current to drive the IR LED effectively.
 *   * Make sure you have the IR LED polarity correct.
       See: https://learn.sparkfun.com/tutorials/polarity/diode-and-led-polarity
 *   * Typical digital camera/phones can be used to see if the IR LED is flashed.
       Replace the IR LED with a normal LED if you don't have a digital camera
       when debugging.
 *   * Avoid using the following pins unless you really know what you are doing:
 *     * Pin 0/D3: Can interfere with the boot/program mode & support circuits.
 *     * Pin 1/TX/TXD0: Any serial transmissions from the ESP8266 will interfere.
 *     * Pin 3/RX/RXD0: Any serial transmissions to the ESP8266 will interfere.
 *   * ESP-01 modules are tricky. We suggest you use a module with more GPIOs
       for your first time. e.g. ESP-12 etc.

   Version 1.0 April, 2017
   Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009, Copyright 2009 Ken Shirriff, http://arcfn.com
*/

#include <IRremoteESP8266.h>

IRsend irsend(16); //an IR led is connected to GPIO pin 4 (D2)

void setup()
{
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
  //  Serial.println("SAMSUNG");
  ////  irsend.sendSAMSUNG(0xE0E040BF, 32);
  ////  delay(2000);
  //
  //  irsend.sendDenon(0x1828, 15);
  //  delay(2000);





  for (int i = 0; i < 3; i++) {
  unsigned int  rawData1[31] = {400, 700, 400, 700, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400}; // UNKNOWN 1BD7
    irsend.sendRaw(rawData1, 31, 38);
    delay(75);
    unsigned int  rawData2[10] = {750, 350, 1800, 350, 750, 350, 750, 350, 750, 350 };
    irsend.sendRaw(rawData2, 11, 38);
    delay(64);
  }

}

void doDenon(

//
//Encoding  : UNKNOWN
//Code      : 1BD7 (14 bits)
//Timing[31]:
//     + 350, - 750     + 350, - 750     + 350, -1800     + 350, -1800
//     + 350, - 750     + 350, -1800     + 350, -1800     + 350, -1800
//     + 350, -1800     + 350, - 750     + 350, -1800     + 350, - 750
//     + 350, -1800     + 350, -1800     + 350, -1800     + 350
//unsigned int  rawData[31] = {350,750, 350,750, 350,1800, 350,1800, 350,750, 350,1800, 350,1800, 350,1800, 350,1800, 350,750, 350,1800, 350,750, 350,1800, 350,1800, 350,1800, 350};  // UNKNOWN 1BD7
//unsigned int  data = 0x1BD7;
//
//Encoding  : UNKNOWN
//Code      : C8E75C44 (32 bits)
//Timing[11]:
//     + 350, - 750     + 350, -1800     + 350, - 750     + 350, - 750
//     + 350, - 750     + 350
//unsigned int  rawData[11] = {350,750, 350,1800, 350,750, 350,750, 350,750, 350};  // UNKNOWN C8E75C44



//VOL DOWN:
unsigned int  rawData[31] = {350,750, 350,750, 350,1800, 350,1800, 350,750, 350,750, 350,750, 350,1800, 350,1800, 350,750, 350,750, 350,1800, 350,750, 350,750, 350,750, 350};  // UNKNOWN 18C8
unsigned int  rawData[19] = {350,1800, 350,750, 350,750, 350,1800, 350,1800, 350,750, 350,1800, 350,1800, 350,1800, 350};  // UNKNOWN CBF358E

//VOL UP:
unsigned int  rawData[31] = {350,750, 350,750, 350,1800, 350,1800, 350,750, 350,1800, 350,750, 350,1800, 350,1800, 350,750, 350,750, 350,1800, 350,750, 350,750, 350,750, 350};  // UNKNOWN 1AC8
unsigned int  data = 0x1AC8;
unsigned int  rawData[17] = {350,750, 350,750, 350,1800, 350,1800, 350,750, 350,1800, 350,1800, 350,1800, 350};  // UNKNOWN B9AB2517











//E0E040BF
