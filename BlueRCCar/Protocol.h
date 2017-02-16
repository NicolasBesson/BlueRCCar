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

#ifndef _PROTOCOL_H
#define _PROTOCOL_H


#define STATE_BIT(x) ((0x01 << x) & 0xFF)

#define STATE_STOP          (0x00)
#define STATE_FORWARD       STATE_BIT(0)
#define STATE_BACKWARD      STATE_BIT(1)
#define STATE_LEFT          STATE_BIT(2)
#define STATE_RIGHT         STATE_BIT(3)
#define STATE_FRONTLIGHT    STATE_BIT(4)
#define STATE_REARLIGHT     STATE_BIT(5)
#define STATE_HORN          STATE_BIT(6)
#define STATE_UNUSED		STATE_BIT(7)

#define STATE_STOP_MOVE_MASK (STATE_FORWARD | STATE_BACKWARD | STATE_LEFT | STATE_RIGHT)
#define STATE_STOP_ALL_MASK  (STATE_FORWARD | STATE_BACKWARD | STATE_LEFT | STATE_RIGHT | STATE_FRONTLIGHT | STATE_REARLIGHT | STATE_HORN)


typedef enum
{
	Stop = 'S',
	Forward = 'F',
	Backward = 'B',
	Left = 'L',
	Right = 'R',
	ForwardLeft = 'G',
	ForwardRight = 'I',
	BackwardLeft = 'H',
	BackwardRight = 'J',
	FrontLights_ON = 'W',
	FrontLights_OFF = 'w',
	RearLights_ON = 'U',
	RearLights_OFF = 'u',
	Horn_ON = 'V',
	Horn_OFF = 'v',
	Extra_ON = 'X',
	Extra_OFF = 'x',
	Speed_0 = '0',
	Speed_10 = '1',
	Speed_20 = '2',
	Speed_30 = '3',
	Speed_40 = '4',
	Speed_50 = '5',
	Speed_60 = '6',
	Speed_70 = '7',
	Speed_80 = '8',
	Speed_90 = '9',
	Speed_100 = 'q',
	Stop_All = 'D'
} PROTOCOL_CMD;


class Protocol
{
public:
	Protocol();
	~Protocol();

	void command(unsigned char cmd);
	unsigned char getSate();
	unsigned char getSpeed();
	bool isExtraEnabled();

private:
	bool bExtraEnabled;
	unsigned char ucState;
	unsigned char ucSpeed;
};

#endif // _PROTOCOL_H