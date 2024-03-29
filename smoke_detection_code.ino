int red_led=12;//12 indicates gas
int green_led=11;//indicates normal
int buzz=10;//indicates gas13
int smokeA0 = A5;//indicates sensor is connected to A5
int sensorThres=50;//The threshold value
int gas_avalue;
void setup()
{
pinMode(red_led,OUTPUT);//red led as output
pinMode(buzz,OUTPUT);// buzz as output
pinMode(green_led,OUTPUT);//green led as output
pinMode(smokeA0,INPUT);//sensor as input
Serial.begin(9600);//starts the code
}
void loop()//loops
{
int gas_avalue=analogRead(smokeA0);//reads sensor value
if (gas_avalue > sensorThres)//sees if it reached threshold value
{
digitalWrite(red_led, HIGH);//turns on red led
digitalWrite(green_led, LOW);//turns off green led
digitalWrite( buzz, HIGH);//turns on buzzer
}
else//if it hasn't reached threshold value
{
digitalWrite(red_led, LOW);//turns red led off
digitalWrite(green_led, HIGH);//turn green led on
digitalWrite( buzz, LOW);//turns buzzer off
}
delay(100);//delay 0.1 sec
}