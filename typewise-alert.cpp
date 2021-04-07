#include "typewise-alert.h"
#include <stdio.h>
#include <map>
using namespace std;

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

map<CoolingType, pair<double, double>> CoolingLimts = {
  {PASSIVE_COOLING, make_pair(0,35)},
  {HI_ACTIVE_COOLING, make_pair(0,45)},
  {MED_ACTIVE_COOLING, make_pair(0,40)}
};

BreachType classifyTemperatureBreach(CoolingType coolType, double temperatureInC) 
{
  return inferBreach(temperatureInC, CoolingLimts[coolType].first, CoolingLimts[coolType].second);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
   // case TO_CONSOLE:
     // sendToConsole(breachType);
      //break;
  }
}


void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

map<BreachType, char*> BreachMessage = {
  {NORMAL, "normal"},
  {TOO_LOW, "too Low"},
  {TOO_HIGH, "too High"}

};

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is : %s\n", BreachMessage[breachType]);
}

//void sendToConsole(BreachType breachType) 
//{
  //printf("Hi, the BMS temperature is %s\n", BreachMessage[breachType]);  
//}
