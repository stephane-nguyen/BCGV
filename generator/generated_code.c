#include "generated_code.h"

void init_carData() {
	carData.cmdWarning = 0;
	carData.cmdPositionLights = 0;
	carData.cmdLowBeam = 0;
	carData.cmdHighBeam = 0;
	carData.cmdRightIndicator = 0;
	carData.cmdLeftIndicator = 0;
	carData.cmdWipers = 0;
	carData.cmdWasher = 0;
	carData.message.id = 0x01;
	carData.message.lightState = TRUE;
	carData.isAcquitted = 0;
	carData.isActivated = 0;
	carData.tramNumber = 0;
	carData.kilometrage = 0;
	carData.speed = 0;
	carData.chassisProblem = CHASSIS_NONE;
	carData.motorProblem = MOTOR_NONE;
	carData.fuelLevel = 0;
	carData.turnsPerMinute = 0;
	carData.batteryProblem = BATTERY_NONE;
}
void set_cmdWarning(enum_bool_t new_value) {
	carData.cmdWarning = new_value;
}
enum_bool_t get_cmdWarning() {
	return carData.cmdWarning;
}
void set_cmdPositionLights(enum_bool_t new_value) {
	carData.cmdPositionLights = new_value;
}
enum_bool_t get_cmdPositionLights() {
	return carData.cmdPositionLights;
}
void set_cmdLowBeam(enum_bool_t new_value) {
	carData.cmdLowBeam = new_value;
}
enum_bool_t get_cmdLowBeam() {
	return carData.cmdLowBeam;
}
void set_cmdHighBeam(enum_bool_t new_value) {
	carData.cmdHighBeam = new_value;
}
enum_bool_t get_cmdHighBeam() {
	return carData.cmdHighBeam;
}
void set_cmdRightIndicator(enum_bool_t new_value) {
	carData.cmdRightIndicator = new_value;
}
enum_bool_t get_cmdRightIndicator() {
	return carData.cmdRightIndicator;
}
void set_cmdLeftIndicator(enum_bool_t new_value) {
	carData.cmdLeftIndicator = new_value;
}
enum_bool_t get_cmdLeftIndicator() {
	return carData.cmdLeftIndicator;
}
void set_cmdWipers(enum_bool_t new_value) {
	carData.cmdWipers = new_value;
}
enum_bool_t get_cmdWipers() {
	return carData.cmdWipers;
}
void set_cmdWasher(enum_bool_t new_value) {
	carData.cmdWasher = new_value;
}
enum_bool_t get_cmdWasher() {
	return carData.cmdWasher;
}
void set_message(message_t new_value) {
	carData.message = new_value;
}
message_t get_message() {
	return carData.message;
}
void set_isAcquitted(state_t new_value) {
	carData.isAcquitted = new_value;
}
state_t get_isAcquitted() {
	return carData.isAcquitted;
}
void set_isActivated(state_t new_value) {
	carData.isActivated = new_value;
}
state_t get_isActivated() {
	return carData.isActivated;
}
void set_tramNumber(tram_number_t new_value) {
	carData.tramNumber = new_value;
}
tram_number_t get_tramNumber() {
	return carData.tramNumber;
}
void set_kilometrage(uint8_t new_value) {
	carData.kilometrage = new_value;
}
uint8_t get_kilometrage() {
	return carData.kilometrage;
}
void set_speed(uint8_t new_value) {
	carData.speed = new_value;
}
uint8_t get_speed() {
	return carData.speed;
}
void set_chassisProblem(chassis_problem_t new_value) {
	carData.chassisProblem = new_value;
}
chassis_problem_t get_chassisProblem() {
	return carData.chassisProblem;
}
void set_motorProblem(motor_problem_t new_value) {
	carData.motorProblem = new_value;
}
motor_problem_t get_motorProblem() {
	return carData.motorProblem;
}
void set_fuelLevel(uint8_t new_value) {
	carData.fuelLevel = new_value;
}
uint8_t get_fuelLevel() {
	return carData.fuelLevel;
}
void set_turnsPerMinute(uint8_t new_value) {
	carData.turnsPerMinute = new_value;
}
uint8_t get_turnsPerMinute() {
	return carData.turnsPerMinute;
}
void set_batteryProblem(battery_problem_t new_value) {
	carData.batteryProblem = new_value;
}
battery_problem_t get_batteryProblem() {
	return carData.batteryProblem;
}
