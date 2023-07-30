int Lred = 13;//port no.
int Lgreen = 12;
int Lblue = 11;
int Mred=10;
int Mgreen=9;
int Sred=8;
int Sgreen=7;
int Sun_red=6;
int Sun_green=5;
int temp = 0;//temp sensor pin
int moisture=1;
int smoke=2;
int light=3;

void setup() {
  Serial.begin (9600); //data transfer speed
  pinMode (Lred, OUTPUT);
  pinMode (Lblue, OUTPUT);
  pinMode (Lgreen, OUTPUT);
  pinMode (temp, INPUT);

  pinMode (Mred, OUTPUT);
  pinMode (Mgreen, OUTPUT);
  pinMode (moisture, INPUT);

  pinMode (Sred, OUTPUT);
  pinMode (Sgreen, OUTPUT);
  pinMode (smoke, INPUT);

  pinMode (Sun_red, OUTPUT);
  pinMode (Sun_green, OUTPUT);
  pinMode (light, INPUT);
}


void loop()
{
  //Temperature
  float Real_Voltage = analogRead(temp) * 0.004882814; // reading the sensor value and convert it to voltage
  float Temp_C = Real_Voltage * 100.0;   // changing the voltage into Celsius
  Serial.print("Temp in C: ");
  Serial.println(Temp_C);
  
  if ( Temp_C > 40.0)
  {
    Serial.println("Very Hot");
    digitalWrite(Lred, HIGH);
    digitalWrite(Lgreen,LOW);
    digitalWrite(Lblue,LOW);
  }
  else if (Temp_C>30.0 && Temp_C<=40.0)
  {
    Serial.println("Getting Hot");
    digitalWrite(Lred, HIGH);
    digitalWrite(Lgreen, HIGH);
    digitalWrite(Lblue,LOW);
  }
  else if(Temp_C>15.0 && Temp_C<=30.0)
  {
    Serial.println("Comfortable");
    digitalWrite(Lred, LOW);
    digitalWrite(Lgreen, HIGH);
    digitalWrite(Lblue, LOW);
  }
  else if(Temp_C>8.0 && Temp_C<=15.0)
  {
    Serial.println("Getting Cold");
    digitalWrite(Lred, HIGH);
    digitalWrite(Lgreen, HIGH);
    digitalWrite(Lblue, LOW);
  }
  else if(Temp_C<=8.0)
  {
    Serial.println("Too Cold");
    digitalWrite(Lred, LOW);
    digitalWrite(Lgreen, LOW);
    digitalWrite(Lblue, HIGH);
  }

  //Moisture
  float moist=analogRead(moisture);
  if (moist>=20.0 && moist<=60.0)
  {
    digitalWrite(Mred,LOW);
    digitalWrite(Mgreen,HIGH);
  }
  else
  {
    digitalWrite(Mred,HIGH);
    digitalWrite(Mgreen,LOW);
  }
  
  //Gas or Smoke
  float smokey=analogRead(smoke);
  if (smokey<400)//threshhold=400ppm
  {
    digitalWrite(Sred,LOW);
    digitalWrite(Sgreen,HIGH);
  }
  else
  {
    digitalWrite(Sred,HIGH);
    digitalWrite(Sgreen,LOW);
  }
  
  //Light
  float sun=analogRead(light);//Lumens
  float area=500;//in sq. foot
  float candle_foot=sun/500;
  
  if (candle_foot>500 && candle_foot<1000)//threshhold=400ppm
  {
    digitalWrite(Sun_red,LOW);
    digitalWrite(Sun_green,HIGH);
  }
  else
  {
    digitalWrite(Sun_red,HIGH);
    digitalWrite(Sun_green,LOW);
  }

  delay(2000);//wait 2sec before collecting data again
}

