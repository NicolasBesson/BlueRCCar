/////////////////////////////////   License  //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Nicolas BESSON - BeeAtHome
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////
#include "RCDriver.h"
#include "Protocol.h"


// RC Commands
#define CMD_ALL_STOP		0x00
#define CMD_FORWARD			PCF8574_PIO_0
#define CMD_BACKWARD		PCF8574_PIO_1
#define CMD_LEFT			PCF8574_PIO_2
#define CMD_RIGHT			PCF8574_PIO_3
#define CMD_FRONT_LIGHT		PCF8574_PIO_4
#define CMD_REAR_LIGHT		PCF8574_PIO_5
#define CMD_HORN			PCF8574_PIO_6


RCDriver::RCDriver()
{}

RCDriver::~RCDriver()
{}

void RCDriver::begin()
{
	gpioExpander.begin(PCF8574A_ADDRESS_000);
	gpioExpander.write(CMD_ALL_STOP);

	ucCurrentSate = STATE_STOP;
	ucSpeed = SPEED_MAX;
}

void RCDriver::run()
{
	// TODO : Space holder for extra handling
}

void RCDriver::setState(unsigned char ucState)
{
	unsigned char ucCommand = CMD_ALL_STOP;

	// Detect State transition
	if (ucCurrentSate == ucState)
	{
		return;
	}

	// Exclusively handle Forward and Backward
	if (ucState & STATE_FORWARD)
	{
		ucCommand |= CMD_FORWARD;
	} 
	else if (ucState & STATE_BACKWARD)
	{
		ucCommand |= CMD_BACKWARD;
	}

	// Exclusively handle Left and Right
	if (ucState & STATE_LEFT)
	{
		ucCommand |= CMD_LEFT;
	}
	else if (ucState & STATE_RIGHT)
	{
		ucCommand |= CMD_RIGHT;
	}

	// Handle Front Ligth
	if (ucState & STATE_FRONTLIGHT)
	{
		ucCommand |= CMD_FRONT_LIGHT;
	}

	// Handle Rear Ligth
	if (ucState & STATE_REARLIGHT)
	{
		ucCommand |= CMD_REAR_LIGHT;
	}

	// Handle Horn
	if (ucState & STATE_HORN)
	{
		ucCommand |= CMD_HORN;
	}

	// Update 
	gpioExpander.write(ucCommand);

	// Save Sate
	ucCurrentSate = ucState;
}

void RCDriver::setSpeed(unsigned char ucSpeed)
{

}

void RCDriver::enableExtra(bool bExtraEnable)
{

}
