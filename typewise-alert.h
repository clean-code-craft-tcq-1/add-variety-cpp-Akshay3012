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
	virtual bool sendAlert(BreachType) = 0;
};

class SendToEmailAlert : public AlertTarget
{
public:
	bool sendAlert(BreachType);
};

class SendToControllerAlert : public AlertTarget
{
public:
	bool sendAlert(BreachType);
};

class SendToConsoleAlert : public AlertTarget
{
public:
	bool sendAlert(BreachType);
};

void checkAndAlert(
  AlertTarget* alertTarget, BatteryCharacter batteryChar, double temperatureInC);
//void sendAlert(AlertTarget alertTarget, BreachType breachType);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void sendToConsole(BreachType breachType);
