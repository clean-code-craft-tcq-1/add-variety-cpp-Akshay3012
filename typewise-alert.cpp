#include "typewise-alert.h"
#include <stdio.h>
#include <map>
#include <iostream>
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

void checkAndAlert( AlertTarget *alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach( batteryChar.coolingType, temperatureInC);

  alertTarget->sendAlert(breachType);

}

void SendToEmailAlert::sendAlert(BreachType breachType)
{
    sendToEmail(breachType);
}


void SendToControllerAlert::sendAlert(BreachType breachType)
{
    sendToController(breachType);
}

void SendToConsoleAlert::sendAlert(BreachType breachType)
{
    sendToConsole(breachType);
}

map<BreachType, string> BreachMessage = {
  {NORMAL, "The Temperature is Normal"},
  {TOO_LOW, "The Temperature is Too Low"},
  {TOO_HIGH, "The Temperature is Too High"}

};

string sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  cout << "To: " << recepient << "\n" << endl;
  cout << BreachMessage[breachType] << endl;
  return BreachMessage[breachType];
}

string sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  cout << BreachMessage[breachType] << endl;
  return BreachMessage[breachType];
}

string sendToConsole(BreachType breachType) 
{
  cout << BreachMessage[breachType] << endl;
  return BreachMessage[breachType];
}
