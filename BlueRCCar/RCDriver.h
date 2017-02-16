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

#ifndef _RCDRIVER_H
#define _RCDRIVER_H

#include "PCF8574.h"

#define SPEED_MIN		  0
#define SPEED_MAX		100

class RCDriver
{
public:
	RCDriver();
	~RCDriver();

	void begin();
	void run();
	void setState(unsigned char ucState);
	void setSpeed(unsigned char ucSpeed);
	void enableExtra(bool bExtraEnable);

private:
	PCF8574 gpioExpander;
	unsigned char ucCurrentSate;
	unsigned char ucSpeed;

};

#endif // _RCDRIVER_H