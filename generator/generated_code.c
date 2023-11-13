#include "generated_code.h"


car_data_t carData;

void init_carData() {
	carData.isAcquitted = 0;
	carData.isActivated = 0;
	carData.tramNumber = 0;
	carData.mileage = 0;
	carData.speed = 0;
	carData.chassisProblem = 0;
	carData.motorProblem = MOTOR_NONE;
	carData.fuelLevel = 0;
	carData.turnsPerMinute = 0;
	carData.batteryProblem = 0;
	carData.crc8 = 0;
	carData.positionLightMessage.id = 0x01;
	carData.positionLightMessage.lightState = TRUE;
	carData.rightIndicatorMessage.id = 0x04;
	carData.rightIndicatorMessage.lightState = FALSE;
	carData.leftIndicatorMessage.id = 0x05;
	carData.leftIndicatorMessage.lightState = FALSE;
	carData.lowBeamMessage.id = 0x02;
	carData.lowBeamMessage.lightState = FALSE;
	carData.highBeamMessage.id = 0x03;
	carData.highBeamMessage.lightState = FALSE;
	carData.comodoData.cmdWarning = FALSE;
	carData.comodoData.cmdPositionLights = FALSE;
	carData.comodoData.cmdLowBeam = FALSE;
	carData.comodoData.cmdHighBeam = FALSE;
	carData.comodoData.cmdRightIndicator = FALSE;
	carData.comodoData.cmdLeftIndicator = FALSE;
	carData.comodoData.cmdWipers = FALSE;
	carData.comodoData.cmdWasher = FALSE;
	carData.muxData.tramNumber = 0;
	carData.muxData.mileage = 0;
	carData.muxData.speed = 0;
	carData.muxData.chassisProblem = 0;
	carData.muxData.motorProblem = 0;
	carData.muxData.fuelLevel = 0;
	carData.muxData.turnsPerMinute = 0;
	carData.muxData.batteryProblem = 0;
	carData.muxData.crc8 = 0;
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
void set_mileage(uint8_t new_value) {
	carData.mileage = new_value;
}
uint8_t get_mileage() {
	return carData.mileage;
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
void set_crc8(uint8_t new_value) {
	carData.crc8 = new_value;
}
uint8_t get_crc8() {
	return carData.crc8;
}
void set_positionLightMessage(message_t new_value) {
	carData.positionLightMessage = new_value;
}
message_t get_positionLightMessage() {
	return carData.positionLightMessage;
}
void set_rightIndicatorMessage(message_t new_value) {
	carData.rightIndicatorMessage = new_value;
}
message_t get_rightIndicatorMessage() {
	return carData.rightIndicatorMessage;
}
void set_leftIndicatorMessage(message_t new_value) {
	carData.leftIndicatorMessage = new_value;
}
message_t get_leftIndicatorMessage() {
	return carData.leftIndicatorMessage;
}
void set_lowBeamMessage(message_t new_value) {
	carData.lowBeamMessage = new_value;
}
message_t get_lowBeamMessage() {
	return carData.lowBeamMessage;
}
void set_highBeamMessage(message_t new_value) {
	carData.highBeamMessage = new_value;
}
message_t get_highBeamMessage() {
	return carData.highBeamMessage;
}
void set_comodoData(comodo_message_t new_value) {
	carData.comodoData = new_value;
}
comodo_message_t get_comodoData() {
	return carData.comodoData;
}
void set_muxData(mux_message_t new_value) {
	carData.muxData = new_value;
}
mux_message_t get_muxData() {
	return carData.muxData;
}
