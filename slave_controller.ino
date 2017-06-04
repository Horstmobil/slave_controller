/*
  -Serial: 0 (RX) and 1 (TX). Used to receive (RX) and transmit (TX) TTL serial data. These pins are connected to the TX-0 and RX-1 pins of the six pin header.
  External Interrupts: 2 and 3. These pins can be configured to trigger an interrupt on a low value, a rising or falling edge, or a change in value. See the attachInterrupt function for details.
  -PWM: 3, 5, 6, 9, 10, and 11. Provide 8-bit PWM output with the analogWrite function.
  -SPI: 10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK). These pins support SPI communication, which, although provided by the underlying hardware, is not currently included in the Arduino language.


  outputs:
  2
  3
  4
  5
  6
  7

  inputs:
  8
  9



  ADC:
  A0
  A1
  A2
  A3








*/


byte registers[12];






void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(2, i2b(registers[0]));
  digitalWrite(3, i2b(registers[1]));
  digitalWrite(4, i2b(registers[2]));
  digitalWrite(5, i2b(registers[3]));
  digitalWrite(6, i2b(registers[4]));
  digitalWrite(7, i2b(registers[5]));
  registers[6] = digitalRead(8);
  registers[7] = digitalRead(9);
  registers[8] = ten2eight(analogRead(A0));
  registers[9] = ten2eight(analogRead(A1));
  registers[10] = ten2eight(analogRead(A2));
  registers[11] = ten2eight(analogRead(A3));
}


byte ten2eight(int zahl) {
  return map(zahl, 0, 1023, 0, 255);

}

bool i2b(byte zahl) {
  if (zahl >= 1) {
    return 1;
  }
  else {
    return 0;
  }
}



