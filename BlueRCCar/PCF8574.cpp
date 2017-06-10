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
#include "PCF8574.h"


PCF8574::PCF8574(): 
	ucDeviceAddress(PCF8574_ADDRESS_000)
{
}

PCF8574::~PCF8574()
{
}

void PCF8574::begin(unsigned char ucDeviceAddress)
{
	this->ucDeviceAddress = ucDeviceAddress;
	TinyWireM.begin();
}

void PCF8574::write(unsigned char data)
{
	TinyWireM.beginTransmission(ucDeviceAddress);
	TinyWireM.send(data);                 // Access Command Register
	TinyWireM.endTransmission();          // Send to the slave
}

unsigned char PCF8574::read()
{
	unsigned char data = 0x00;

	TinyWireM.requestFrom(ucDeviceAddress, 1);
	while (TinyWireM.available() == 0);
	data = TinyWireM.receive();

	return data;
}
