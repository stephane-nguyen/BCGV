#pragma once

#include <stdint.h>
#include <stddef.h>

typedef enum {TURNED_OFF, TURNED_ON} state_t;
typedef enum {FALSE, TRUE} enum_bool_t;
typedef enum {CHASSIS_NONE, WHEEL_PRESSURE, DEFAILLANCE_BRAKE} chassis_problem_t;
typedef enum {MOTOR_NONE, DEFAULT_PRESSURE, LDR_TEMPERATURE, OIL_OVERHEAT} motor_problem_t;
typedef enum {BATTERY_NONE, EMPTY_BATTERY, BREAKDOWN} battery_problem_t;
typedef struct { uint8_t id; state_t lightState;} message_t;
typedef uint8_t tram_number_t;

typedef struct {
	enum_bool_t cmdWarning;
	enum_bool_t cmdPositionLights;
	enum_bool_t cmdLowBeam;
	enum_bool_t cmdHighBeam;
	enum_bool_t cmdRightIndicator;
	enum_bool_t cmdLeftIndicator;
	enum_bool_t cmdWipers;
	enum_bool_t cmdWasher;
	message_t message;
	state_t isAcquitted;
	state_t isActivated;
	tram_number_t tramNumber;
	uint8_t kilometrage;
	uint8_t speed;
	chassis_problem_t chassisProblem;
	motor_problem_t motorProblem;
	uint8_t fuelLevel;
	uint8_t turnsPerMinute;
	battery_problem_t batteryProblem;
} car_data_t;


car_data_t carData;

void init_carData();
void set_cmdWarning(enum_bool_t new_value);
enum_bool_t get_cmdWarning();
void set_cmdPositionLights(enum_bool_t new_value);
enum_bool_t get_cmdPositionLights();
void set_cmdLowBeam(enum_bool_t new_value);
enum_bool_t get_cmdLowBeam();
void set_cmdHighBeam(enum_bool_t new_value);
enum_bool_t get_cmdHighBeam();
void set_cmdRightIndicator(enum_bool_t new_value);
enum_bool_t get_cmdRightIndicator();
void set_cmdLeftIndicator(enum_bool_t new_value);
enum_bool_t get_cmdLeftIndicator();
void set_cmdWipers(enum_bool_t new_value);
enum_bool_t get_cmdWipers();
void set_cmdWasher(enum_bool_t new_value);
enum_bool_t get_cmdWasher();
void set_message(message_t new_value);
message_t get_message();
void set_isAcquitted(state_t new_value);
state_t get_isAcquitted();
void set_isActivated(state_t new_value);
state_t get_isActivated();
void set_tramNumber(tram_number_t new_value);
tram_number_t get_tramNumber();
void set_kilometrage(uint8_t new_value);
uint8_t get_kilometrage();
void set_speed(uint8_t new_value);
uint8_t get_speed();
void set_chassisProblem(chassis_problem_t new_value);
chassis_problem_t get_chassisProblem();
void set_motorProblem(motor_problem_t new_value);
motor_problem_t get_motorProblem();
void set_fuelLevel(uint8_t new_value);
uint8_t get_fuelLevel();
void set_turnsPerMinute(uint8_t new_value);
uint8_t get_turnsPerMinute();
void set_batteryProblem(battery_problem_t new_value);
battery_problem_t get_batteryProblem();
