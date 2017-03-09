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

/// <summary>
/// Racing Card Driver class
/// </summary>
class RCDriver
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="RCDriver"/> class.
	/// </summary>
	RCDriver();

	/// <summary>
	/// Finalizes an instance of the <see cref="RCDriver"/> class.
	/// </summary>
	~RCDriver();

	/// <summary>
	/// Begins this instance.
	/// </summary>
	void begin();

	/// <summary>
	/// Runs this instance.
	/// Used to update the 
	/// </summary>
	void run();

	/// <summary>
	/// Sets the RC state.
	/// </summary>
	/// <param name="ucState">New state of the RC.</param>
	void setState(unsigned char ucState);

	/// <summary>
	/// Sets the RC speed.
	/// </summary>
	/// <param name="ucSpeed">The RC speed.</param>
	void setSpeed(unsigned char ucSpeed);

	/// <summary>
	/// Enables the extra feature
	/// </summary>
	/// <param name="bExtraEnable">if set to <c>true</c> [enable the extrat features].</param>
	void enableExtra(bool bExtraEnable);

private:
	/// <summary>
	/// The gpio expander device
	/// </summary>
	PCF8574 gpioExpander;

	/// <summary>
	/// The RC current state
	/// </summary>
	unsigned char ucCurrentSate;
	
	/// <summary>
	/// The RC speed
	/// </summary>
	unsigned char ucSpeed;
};

#endif // _RCDRIVER_H