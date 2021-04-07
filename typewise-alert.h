#pragma once

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
	virtual void sendAlert(BreachType) = 0;
};

class SendToEmailAlert : public AlertTarget
{
public:
	void sendAlert(BreachType);
};

class SendToControllerAlert : public AlertTarget
{
public:
	void sendAlert(BreachType);
};

class SendToConsoleAlert : public AlertTarget
{
public:
	void sendAlert(BreachType);
};

void checkAndAlert(
  AlertTarget* alertTarget, BatteryCharacter batteryChar, double temperatureInC);
//void sendAlert(AlertTarget alertTarget, BreachType breachType);

string sendToController(BreachType breachType);
string sendToEmail(BreachType breachType);
string sendToConsole(BreachType breachType);
