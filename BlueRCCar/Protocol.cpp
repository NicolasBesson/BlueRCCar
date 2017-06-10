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
#include "Protocol.h"


Protocol::Protocol()
{
	bExtraEnabled = false;
	ucState = STATE_STOP;
	ucSpeed = 100;
}

Protocol::~Protocol()
{}


void Protocol::command(unsigned char cmd)
{

	switch (cmd)
	{
	case Stop_All:
		ucState &= ~STATE_STOP_ALL_MASK;
		bExtraEnabled = false;
		break;

	case Stop:
		ucState &= ~STATE_STOP_MOVE_MASK;
		break;

	case Forward:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_FORWARD;
		break;

	case Backward:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_BACKWARD;
		break;

	case Left:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_LEFT;
		break;

	case Right:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_RIGHT;
		break;

	case ForwardLeft:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_FORWARD | STATE_LEFT;
		break;

	case ForwardRight:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_FORWARD | STATE_RIGHT;
		break;

	case BackwardLeft:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_BACKWARD | STATE_LEFT;
		break;

	case BackwardRight:
		ucState &= ~STATE_STOP_MOVE_MASK;
		ucState |= STATE_BACKWARD | STATE_RIGHT;
		break;

	case FrontLights_ON:
		ucState |= STATE_FRONTLIGHT;
		break;

	case FrontLights_OFF:
		ucState &= ~STATE_FRONTLIGHT;
		break;

	case RearLights_ON:
		ucState |= STATE_REARLIGHT;
		break;

	case RearLights_OFF:
		ucState &= ~STATE_REARLIGHT;
		break;

	case Horn_ON:
		ucState |= STATE_HORN;
		break;

	case Horn_OFF:
		ucState &= ~STATE_HORN;
		break;

	case Extra_ON:
		bExtraEnabled = true;
		break;

	case Extra_OFF:
		bExtraEnabled = false;
		break;

	case Speed_0:
	case Speed_10:
	case Speed_20:
	case Speed_30:
	case Speed_40:
	case Speed_50:
	case Speed_60:
	case Speed_70:
	case Speed_80:
	case Speed_90:
		ucSpeed = (cmd - (unsigned char)Speed_90) * 10;
		break;

	case Speed_100:
		ucSpeed = 100;
		break;

	}
}

unsigned char Protocol::getState()
{
	return ucState;
}

unsigned char Protocol::getSpeed()
{
	return ucSpeed;
}

bool Protocol::isExtraEnabled()
{
	return bExtraEnabled;
}
