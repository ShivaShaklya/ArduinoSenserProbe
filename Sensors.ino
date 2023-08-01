int Lred = 13;//port no.
int Lgreen = 12;
int Lblue = 11;
int Mred=10;
int Mgreen=9;
int Mblue=8;
int Sred=7;
int Sgreen=6;
int Sblue=5;
int Sun_red=4;
int Sun_green=3;
int Sun_blue=2;
int temp = A0;//temp sensor pin
int moisture=A1;
int smoke=A2;
int light=A3;

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
  float Temp_C = (Real_Voltage-0.5) * 100.0;   // changing the voltage into Celsius
  //float Temp_C=analogRead(temp);
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
  Serial.print("Moisture: ");
  Serial.println(moist);
  if (moist>=6.0 && moist<=400.0)
  {
    digitalWrite(Mred,LOW);
    digitalWrite(Mgreen,HIGH);
    digitalWrite(Mblue,LOW);
  }
  else
  {
    digitalWrite(Mred,HIGH);
    digitalWrite(Mgreen,LOW);
    digitalWrite(Mblue,LOW);
  }
  
  //Gas or Smoke
  float smokey=analogRead(smoke);
  Serial.print("Gas/Smoke: ");
  Serial.println(smokey);
  if (smokey<250)//threshhold=250ppm
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
  float candle_foot=sun;
  Serial.println(candle_foot);
  
  if (candle_foot>200 && candle_foot<1000)
  {
    digitalWrite(Sun_red,LOW);
    digitalWrite(Sun_green,HIGH);
    digitalWrite(Sun_blue,LOW);
  }
  else
  {
    digitalWrite(Sun_red,HIGH);
    digitalWrite(Sun_green,LOW);
    digitalWrite(Sun_blue,LOW);
  }

  delay(2000);//wait 2sec before collecting data again
}

