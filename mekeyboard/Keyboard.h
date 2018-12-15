// Copyright (c) 2002 - 2018, Evil Quail LLC
// All Rights Reserved

#pragma once

#include <me/input/InputDevice.h>
#include <me/game/IGame.h>

#define DIRECTINPUT_VERSION		0x0800
#include <dinput.h>
#include <atlbase.h>
#include <string>

namespace mekeyboard
{
	enum KeyStatus
	{
		Up,
		Pressed,	// same as STATUS_JUSTUP
		Down,
		JustDown,
		COUNT
	};

	class Keyboard : public me::input::InputDevice
	{
	public:
		Keyboard( me::game::IGame * gameInstance );
		virtual ~Keyboard();

		std::string GetName() const;

		void Acquire();

		void Update() override;

		size_t SubSourceCount() const override;

		size_t GetInputCount( size_t subSource ) const override;

		std::string GetInputName( size_t subSource, size_t index ) const override;

		size_t GetInputIndex( size_t subSource, std::string name ) const override;

		me::input::InputType GetInputType( size_t subSource, size_t index ) const override;

		me::input::IData::ptr GetInputData( size_t subSource, size_t index ) const override;

		me::input::IData::ptr GetInputData( size_t subSource, std::string name ) const override;

		void SetInputData( size_t subSource, size_t index, me::input::IData::ptr dataIn ) override;


	private:
		me::game::IGame * m_game;

		CComPtr< IDirectInput > m_pdi;
		CComPtr< IDirectInputDevice > m_pdiKeyboard;

		std::map< std::string, size_t, unify::CaseInsensitiveLessThanTest > m_nameToIndex;

		unsigned char				m_diKeyState[256];

		bool m_hasFocus; // Does our window have focus?

		unsigned int m_uKeyStatusCount[ KeyStatus::COUNT ];
		unsigned int m_uTheKey[ KeyStatus::COUNT ];	// VERY simplied - Keeps the LAST key of a given status
		int m_iKeyDown;				// Simple input (not directx)
		int m_iKeyPressTimes[256];
		KeyStatus m_KeyStatus[256];

		bool m_capslock;
		bool m_numlock;
		bool m_scrolllock;
		bool m_insert;
	};
}