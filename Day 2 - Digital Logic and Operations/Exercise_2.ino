// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  digitalWrite(4, LOW);   // These make the default voltage level of the pins 0.
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  // This starts communications with the computer
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  
}

// the loop function runs over and over again forever
void loop() {

 int output;

 delay(1000);
 output = calculateOutput(4, 5, 6, 7);

 if(output <= 5)
 {
    digitalWrite(13, LOW);
 }
 if(output >8)
 {
   digitalWrite(13, HIGH);
 }

 Serial.println(output);
}

int calculateOutput(int a, int b, int c, int d)
{
  int result;

  result = digitalRead(a);
  result <<= 1;
  result |= digitalRead(b);
  result <<= 1;
  result |= digitalRead(c);
  result <<= 1;
  result |= digitalRead(d);

  return result;
}
