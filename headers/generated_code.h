#pragma once

#include <stdint.h>
#include <stddef.h>

typedef enum {INIT, TURNED_OFF, TURNED_ON, ACQUITTED, ERROR, ACTIVATED_AND_TURNED_ON, ACTIVATED_AND_TURNED_OFF, ALL_TURNED_OFF, WINDSHIELD_WIPER_AND_WINDSHIELD_WASHER_ACTIVATED, WINDSHIELD_WIPER_ACTIVATED, WINDSHIELD_WIPER_AND_WINDSHIELD_WASHER_ACTIVATED_TURNED_OFF} state_t;
typedef enum {FALSE, TRUE} enum_bool_t;
typedef enum {CHASSIS_NONE, WHEEL_PRESSURE, DEFAILLANCE_BRAKE} chassis_problem_t;
typedef enum {MOTOR_NONE, DEFAULT_PRESSURE, LDR_TEMPERATURE, OIL_OVERHEAT} motor_problem_t;
typedef enum {BATTERY_NONE, EMPTY_BATTERY, BREAKDOWN} battery_problem_t;
typedef struct { uint8_t id; state_t lightState;} message_t;
typedef uint8_t tram_number_t;
typedef struct {uint8_t tramNumber; uint8_t mileage; uint8_t speed; chassis_problem_t chassisProblem; motor_problem_t motorProblem; uint8_t fuelLevel; uint8_t turnsPerMinute; battery_problem_t batteryProblem; uint8_t crc8; } mux_message_t;
typedef struct { enum_bool_t cmdWarning; enum_bool_t cmdPositionLights; enum_bool_t cmdLowBeam; enum_bool_t cmdHighBeam; enum_bool_t cmdRightIndicator; enum_bool_t cmdLeftIndicator; enum_bool_t cmdWipers; enum_bool_t cmdWasher; } comodo_message_t;
typedef enum { NONE, COMMAND_ZERO, COMMAND_ONE, ACQUITTED_RECEIVED, ACQUITTED_NOT_RECEIVED } warning_lights_event_t;
typedef enum { WL_NONE, TO_TURNED_ON, TO_TURNED_OFF, TO_ERROR, TO_ACQUITTED, TO_ACTIVATED_AND_TURNED_OFF, TO_ACTIVATED_AND_TURNED_ON } warning_lights_transition_t;
typedef enum { EG_LG_ALL_OFF, EG_ACTIVE, EG_LG_ACTIVE, EG_TIMER_LG_OFF } eg_lg_state_t;
typedef enum { EG_LG_NONE, EG_LG_CMD_EG_0, EG_LG_CMD_EG_1, EG_LG_CMD_LG_0, EG_LG_CMD_LG_1, EG_LG_TIMER_EXPIRED } eg_lg_event_t;;

typedef struct {
	state_t isAcquitted;
	state_t isActivated;
	tram_number_t tramNumber;
	uint8_t mileage;
	uint8_t speed;
	chassis_problem_t chassisProblem;
	motor_problem_t motorProblem;
	uint8_t fuelLevel;
	uint8_t turnsPerMinute;
	battery_problem_t batteryProblem;
	uint8_t crc8;
	message_t positionLightMessage;
	message_t rightIndicatorMessage;
	message_t leftIndicatorMessage;
	message_t lowBeamMessage;
	message_t highBeamMessage;
	comodo_message_t comodoData;
	mux_message_t muxData;
} car_data_t;

void init_carData();
void set_isAcquitted(state_t new_value);
state_t get_isAcquitted();
void set_isActivated(state_t new_value);
state_t get_isActivated();
void set_tramNumber(tram_number_t new_value);
tram_number_t get_tramNumber();
void set_mileage(uint8_t new_value);
uint8_t get_mileage();
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
void set_crc8(uint8_t new_value);
uint8_t get_crc8();
void set_positionLightMessage(message_t new_value);
message_t get_positionLightMessage();
void set_rightIndicatorMessage(message_t new_value);
message_t get_rightIndicatorMessage();
void set_leftIndicatorMessage(message_t new_value);
message_t get_leftIndicatorMessage();
void set_lowBeamMessage(message_t new_value);
message_t get_lowBeamMessage();
void set_highBeamMessage(message_t new_value);
message_t get_highBeamMessage();
void set_comodoData(comodo_message_t new_value);
comodo_message_t get_comodoData();
void set_muxData(mux_message_t new_value);
mux_message_t get_muxData();
