#include <Arduino.h>
unsigned long lastflash;
int RPM;

void sens() 
{
  RPM = 60 / ((float)(micros() - lastflash) / 1000000); // расчет
  lastflash = micros();                                 // запомнить время последнего оборота
}

void setup() 
{
	Serial.begin(9600);  //открыть порт
	attachInterrupt(0, sens, FALLING); //подключить прерывание на 2 пин при понижении сигнала
}

void loop() 
{
  if ((micros() - lastflash) > (250*1000))
  {          // если сигнала нет больше секунды
    RPM = 0; // считаем что RPM 0
  }

  Serial.println(RPM);  // вывод в порт
  delay(100);           // задержка для стабильности
}