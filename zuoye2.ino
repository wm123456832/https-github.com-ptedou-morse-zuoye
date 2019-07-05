byte dalao[10][8] = { 
{0,1,1,1,1,0,1,1}，{0,1,1,0,0,0,0,0}，{0,0,1,1,0,1,1,1}，{0,1,1,1,0,1,0,1},{0,1,1,0,1,1,0,0},{0,1,0,1,1,1,0,1}，{0,1,0,1,1,1,1,1},{0,1,1,1,0,0,0,0},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,0,1} };
void setup() 
{ 
Serial.begin(9600);
for(int i=4;i<=11;i++){
pinMode(i, OUTPUT);
}
}
int income;
void loop()
{
if(Serial.available()>0)
{  
income = Serial.read();
}
int pin = 4;
switch(income)
{
  case '0':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[0][s]);
    pin++;
  }
  break;
  case '1':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[1][s]);
    pin++;
  }
  break;
  case '2':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[2][s]);
    pin++;
  }
  break;
  case '3':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[3][s]);
    pin++;
  }
  break;
  case '4':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[4][s]);
    pin++;
  }
  break;
  case '5':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[5][s]);
    pin++;
  }
  break;
  case '6':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, DIGITAL_DISPLAY[6][s]);
    pin++;
  }
  case '7':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[7][s]);
    pin++;
  }
  case '8':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[8][s]);
    pin++;
  }
  case '9':
  for (int s = 0; s < 8; s++)
  {
    digitalWrite(pin, dalao[9][s]);
    pin++;
  }
}
delay(1000);
}
