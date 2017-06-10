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

// RC Commands Electrical Logic
// Forward Active Low
// Backward Active Low
// Left Active Low
// Right Active Low

// RC Commands
#define CMD_FORWARD			PCF8574_PIO_0
#define CMD_BACKWARD		PCF8574_PIO_1
#define CMD_LEFT			PCF8574_PIO_2
#define CMD_RIGHT			PCF8574_PIO_3
#define CMD_FRONT_LIGHT		PCF8574_PIO_4
#define CMD_REAR_LIGHT		PCF8574_PIO_5
#define CMD_HORN			PCF8574_PIO_6
#define CMD_ALL_STOP		(0x00 | CMD_FORWARD | CMD_BACKWARD | CMD_LEFT | CMD_RIGHT)

// Helper Macro
#define SET_BIT(variable, mask) 		variable |= mask
#define CLR_BIT(variable, mask) 		variable &= ~mask
#define SET_BIT_INV(variable, mask) 	variable &= ~mask
#define CLR_BIT_INV(variable, mask) 	variable |= mask


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

	// Exclusively handle Forward and Backward (Inverted logic)
	if (ucState & STATE_FORWARD)
	{
		// Set Forward and Clear Backward (inverted logic)
		SET_BIT_INV(ucCommand, CMD_FORWARD);
		CLR_BIT_INV(ucCommand, CMD_BACKWARD);
	} 
	else if (ucState & STATE_BACKWARD)
	{
		// Clear Forward and Set Backward (inverted logic)
		CLR_BIT_INV(ucCommand, CMD_FORWARD);
		SET_BIT_INV(ucCommand, CMD_BACKWARD);
	}

	// Exclusively handle Left and Right (inverted logic)
	if (ucState & STATE_LEFT)
	{
		// Set Left and Clear Right (inverted logic)
		SET_BIT_INV(ucCommand, CMD_LEFT);
		CLR_BIT_INV(ucCommand, CMD_RIGHT);

	}
	else if (ucState & STATE_RIGHT)
	{
		// Clear Left and Set Right (inverted logic)
		CLR_BIT_INV(ucCommand, CMD_LEFT);
		SET_BIT_INV(ucCommand, CMD_RIGHT);
	}

	// Handle Front Light
	if (ucState & STATE_FRONTLIGHT)
	{
		SET_BIT(ucCommand, CMD_FRONT_LIGHT);
	}

	// Handle Rear Light
	if (ucState & STATE_REARLIGHT)
	{
		SET_BIT(ucCommand, CMD_REAR_LIGHT);
	}

	// Handle Horn
	if (ucState & STATE_HORN)
	{
		SET_BIT(ucCommand, CMD_HORN);
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
