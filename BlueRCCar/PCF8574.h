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

#ifndef _PCF8574_H
#define _PCF8574_H

#include <USI_TWI_Master.h>
#include <TinyWireM.h>

// Device Addresses
#define PCF8574_ADDRESS_000		0x20
#define PCF8574_ADDRESS_001		0x21
#define PCF8574_ADDRESS_010		0x22
#define PCF8574_ADDRESS_011		0x23
#define PCF8574_ADDRESS_100		0x24
#define PCF8574_ADDRESS_101		0x25
#define PCF8574_ADDRESS_110		0x26
#define PCF8574_ADDRESS_111		0x27

#define PCF8574A_ADDRESS_000	0x38
#define PCF8574A_ADDRESS_001	0x39
#define PCF8574A_ADDRESS_010	0x3A
#define PCF8574A_ADDRESS_011	0x3B
#define PCF8574A_ADDRESS_100	0x3C
#define PCF8574A_ADDRESS_101	0x3D
#define PCF8574A_ADDRESS_110	0x3E
#define PCF8574A_ADDRESS_111	0x3F


#define PCF8574_PIO(x) (0x1 << x)

#define PCF8574_PIO_0 PCF8574_PIO(0)
#define PCF8574_PIO_1 PCF8574_PIO(1)
#define PCF8574_PIO_2 PCF8574_PIO(2)
#define PCF8574_PIO_3 PCF8574_PIO(3)
#define PCF8574_PIO_4 PCF8574_PIO(4)
#define PCF8574_PIO_5 PCF8574_PIO(5)
#define PCF8574_PIO_6 PCF8574_PIO(6)
#define PCF8574_PIO_7 PCF8574_PIO(7)

#define PCF8574_PIO_MASK(x) (x)

class PCF8574
{
public:
	PCF8574();
	~PCF8574();
	void begin(unsigned char ucDeviceAddress);
	void write(unsigned char data);
	unsigned char read();

private:
	unsigned char ucDeviceAddress;
};


#endif // __PCF8574_H__