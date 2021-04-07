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

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  //TO_CONSOLE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

class AlertTargets
{
public:
	virtual void sendAlert(BreachType) = 0;
};

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
//void sendAlert(AlertTarget alertTarget, BreachType breachType);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
//void sendToConsole(BreachType breachType);
