// Copyright (c) 2002 - 2018, Evil Quail LLC
// All Rights Reserved

#include "MEKeyboard.h"
#include <mekeyboard/Keyboard.h>
#include <me/game/IGame.h>

void DeleterKeyboard( mekeyboard::Keyboard * keyboard )
{
	delete keyboard;
}

extern "C" __declspec(dllexport) bool MELoader( me::game::IGame * gameInstance, const qxml::Element * element );
__declspec(dllexport) bool MELoader( me::game::IGame * gameInstance, const qxml::Element * element )
{
	gameInstance->GetInputManager()->AddInputDevice( me::input::IInputDevice::ptr( new  mekeyboard::Keyboard( gameInstance ), DeleterKeyboard ) );

	return true;
}

