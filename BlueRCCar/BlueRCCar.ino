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
#include <SoftwareSerial.h>
#include "Protocol.h"
#include "RCDriver.h"

/**
 ATTiny 85 pinout

         +-\/-+
A0 PB5  1|    |8  Vcc
A3 PB3  2|    |7  PB2 D0 A1
A2 PB4  3|    |6  PB1 D1
   GND  4|    |5  PB0 D2
         +----+
*/

#define PIN_BLUETOOTH_RX		PB3
#define PIN_BLUETOOTH_TX		PB4
#define PIN_BLUETOOTH_STATE		PB1
#define PIN_PCF8564_SDA			PB0
#define PIN_PCF8564_SCL			PB2

//
SoftwareSerial bluetoothSerial(PIN_BLUETOOTH_TX, PIN_BLUETOOTH_RX); // RX, TX
Protocol bluetoothProtocol;
RCDriver rcDriver;

void setup()
{
	// Configure PIOs
	pinMode(PIN_BLUETOOTH_STATE, INPUT);

	// Enable Bluetooth Serial
	bluetoothSerial.begin(9600);

	// Enable rcDriver
	rcDriver.begin();
}

void loop()
{
	int data = 0x00;

	// Get
	if (digitalRead(PIN_BLUETOOTH_STATE) == LOW)
	{
		bluetoothProtocol.command(Stop_All);
	}
	// Data available from Bluetooth Serial
	else if (bluetoothSerial.available() > 0)
	{
		// Read the data
		data = bluetoothSerial.read();

		// Decode the protocol
		bluetoothProtocol.command(data);
	}
	else
	{

	}

	// Update driver based on received protocol
	rcDriver.setState(bluetoothProtocol.getSate());
	rcDriver.enableExtra(bluetoothProtocol.isExtraEnabled());
	rcDriver.setSpeed(bluetoothProtocol.getSpeed());

	rcDriver.run();
}
