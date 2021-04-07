#pragma once
#include<map>
#include<string>
using namespace std;

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);



typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

class AlertTarget
{
public:
	virtual string sendAlert(BreachType) = "";
};

class SendToEmailAlert : public AlertTarget
{
public:
	string sendAlert(BreachType);
};

class SendToControllerAlert : public AlertTarget
{
public:
	string sendAlert(BreachType);
};

class SendToConsoleAlert : public AlertTarget
{
public:
	string sendAlert(BreachType);
};

string checkAndAlert(
  AlertTarget* alertTarget, BatteryCharacter batteryChar, double temperatureInC);
//void sendAlert(AlertTarget alertTarget, BreachType breachType);

string sendToController(BreachType breachType);
string sendToEmail(BreachType breachType);
string sendToConsole(BreachType breachType);
