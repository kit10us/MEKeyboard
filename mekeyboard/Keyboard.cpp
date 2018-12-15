// Copyright (c) 2002 - 2018, Evil Quail LLC
// All Rights Reserved

#include <mekeyboard/Keyboard.h>
#include <me/exception/DeviceFailure.h>
#include <dinput.h>

using namespace mekeyboard;
using namespace me;
using namespace input;

#pragma comment(lib,"dxguid")
#pragma comment(lib,"dinput8")

std::vector< std::string > g_Buttons
{
	{ "0" },
	{ "1" },
	{ "2" },
	{ "3" },
	{ "4" },
	{ "5" },
	{ "6" },
	{ "7" },
	{ "8" },
	{ "9" },
	{ "A" },
	{ "ABNT_C1" },
	{ "ABNT_C2" },
	{ "ADD" },
	{ "APOSTROPHE" },
	{ "APPS" },
	{ "AT" },
	{ "AX" },
	{ "B" },
	{ "BACK" },
	{ "BACKSLASH" },
	{ "C" },
	{ "CALCULATOR" },
	{ "CAPITAL" },
	{ "COLON" },
	{ "COMMA" },
	{ "CONVERT" },
	{ "D" },
	{ "DECIMAL" },
	{ "DELETE" },
	{ "DIVIDE" },
	{ "DOWN" },
	{ "E" },
	{ "END" },
	{ "EQUALS" },
	{ "ESCAPE" },
	{ "F" },
	{ "F1" },
	{ "F2" },
	{ "F3" },
	{ "F4" },
	{ "F5" },
	{ "F6" },
	{ "F7" },
	{ "F8" },
	{ "F9" },
	{ "F10" },
	{ "F11" },
	{ "F12" },
	{ "F13" },
	{ "F14" },
	{ "F15" },
	{ "G" },
	{ "GRAVE" },
	{ "H" },
	{ "HOME" },
	{ "I" },
	{ "INSERT" },
	{ "J" },
	{ "K" },
	{ "KANA" },
	{ "KANJI" },
	{ "L" },
	{ "LBRACKET" },
	{ "LCONTROL" },
	{ "LEFT" },
	{ "LMENU" },
	{ "LSHIFT" },
	{ "LWIN" },
	{ "M" },
	{ "MAIL" },
	{ "MEDIASELECT" },
	{ "MEDIASTOP" },
	{ "MINUS" },
	{ "MULTIPLY" },
	{ "MUTE" },
	{ "MYCOMPUTER" },
	{ "N" },
	{ "NEXT" },
	{ "NEXTTRACK" },
	{ "NOCONVERT" },
	{ "NUMLOCK" },
	{ "NUMPAD0" },
	{ "NUMPAD1" },
	{ "NUMPAD2" },
	{ "NUMPAD3" },
	{ "NUMPAD4" },
	{ "NUMPAD5" },
	{ "NUMPAD6" },
	{ "NUMPAD7" },
	{ "NUMPAD8" },
	{ "NUMPAD9" },
	{ "NUMPADCOMMA" },
	{ "NUMPADENTER" },
	{ "NUMPADEQUALS" },
	{ "O" },
	{ "OEM_102" },
	{ "P" },
	{ "PAUSE" },
	{ "PERIOD" },
	{ "PLAYPAUSE" },
	{ "POWER" },
	{ "PREVTRACK" },
	{ "PRIOR" },
	{ "Q" },
	{ "R" },
	{ "RBRACKET" },
	{ "RCONTROL" },
	{ "RETURN" },
	{ "RIGHT" },
	{ "RMENU" },
	{ "RSHIFT" },
	{ "RWIN" },
	{ "S" },
	{ "SCROLL" },
	{ "SEMICOLON" },
	{ "SLASH" },
	{ "SLEEP" },
	{ "SPACE" },
	{ "STOP" },
	{ "SUBTRACT" },
	{ "SYSRQ" },
	{ "T" },
	{ "TAB" },
	{ "U" },
	{ "UNDERLINE" },
	{ "UNLABELED" },
	{ "UP" },
	{ "V" },
	{ "VOLUMEDOWN" },
	{ "VOLUMEUP" },
	{ "W" },
	{ "WAKE" },
	{ "WEBBACK" },
	{ "WEBFAVORITES" },
	{ "WEBFORWARD" },
	{ "WEBHOME" },
	{ "WEBREFRESH" },
	{ "WEBSEARCH" },
	{ "WEBSTOP" },
	{ "X" },
	{ "Y" },
	{ "YEN" },
	{ "Z" },
	{ "BACKSPACE" },
	{ "CAPSLOCK" },
	{ "CIRCUMFLEX" },
	{ "DOWNARROW" },
	{ "LALT" },
	{ "LEFTARROW" },
	{ "NUMPADMINUS" },
	{ "NUMPADPERIOD" },
	{ "NUMPADPLUS" },
	{ "NUMPADSLASH" },
	{ "NUMPADSTAR" },
	{ "PGDN" },
	{ "PGUP" },
	{ "RALT" },
	{ "RIGHTARROW" },
	{ "UPARROW" }
};			  
  
std::vector< int > g_KeyCodes
{
{ DIK_0 },
{ DIK_1 },
{ DIK_2 },
{ DIK_3 },
{ DIK_4 },
{ DIK_5 },
{ DIK_6 },
{ DIK_7 },
{ DIK_8 },
{ DIK_9 },
{ DIK_A },
{ DIK_ABNT_C1 },
{ DIK_ABNT_C2 },
{ DIK_ADD },
{ DIK_APOSTROPHE },
{ DIK_APPS },
{ DIK_AT },
{ DIK_AX },
{ DIK_B },
{ DIK_BACK },
{ DIK_BACKSLASH },
{ DIK_C },
{ DIK_CALCULATOR },
{ DIK_CAPITAL },
{ DIK_COLON },
{ DIK_COMMA },
{ DIK_CONVERT },
{ DIK_D },
{ DIK_DECIMAL },
{ DIK_DELETE },
{ DIK_DIVIDE },
{ DIK_DOWN },
{ DIK_E },
{ DIK_END },
{ DIK_EQUALS },
{ DIK_ESCAPE },
{ DIK_F },
{ DIK_F1 },
{ DIK_F2 },
{ DIK_F3 },
{ DIK_F4 },
{ DIK_F5 },
{ DIK_F6 },
{ DIK_F7 },
{ DIK_F8 },
{ DIK_F9 },
{ DIK_F10 },
{ DIK_F11 },
{ DIK_F12 },
{ DIK_F13 },
{ DIK_F14 },
{ DIK_F15 },
{ DIK_G },
{ DIK_GRAVE },
{ DIK_H },
{ DIK_HOME },
{ DIK_I },
{ DIK_INSERT },
{ DIK_J },
{ DIK_K },
{ DIK_KANA },
{ DIK_KANJI },
{ DIK_L },
{ DIK_LBRACKET },
{ DIK_LCONTROL },
{ DIK_LEFT },
{ DIK_LMENU },
{ DIK_LSHIFT },
{ DIK_LWIN },
{ DIK_M },
{ DIK_MAIL },
{ DIK_MEDIASELECT },
{ DIK_MEDIASTOP },
{ DIK_MINUS },
{ DIK_MULTIPLY },
{ DIK_MUTE },
{ DIK_MYCOMPUTER },
{ DIK_N },
{ DIK_NEXT },
{ DIK_NEXTTRACK },
{ DIK_NOCONVERT },
{ DIK_NUMLOCK },
{ DIK_NUMPAD0 },
{ DIK_NUMPAD1 },
{ DIK_NUMPAD2 },
{ DIK_NUMPAD3 },
{ DIK_NUMPAD4 },
{ DIK_NUMPAD5 },
{ DIK_NUMPAD6 },
{ DIK_NUMPAD7 },
{ DIK_NUMPAD8 },
{ DIK_NUMPAD9 },
{ DIK_NUMPADCOMMA },
{ DIK_NUMPADENTER },
{ DIK_NUMPADEQUALS },
{ DIK_O },
{ DIK_OEM_102 },
{ DIK_P },
{ DIK_PAUSE },
{ DIK_PERIOD },
{ DIK_PLAYPAUSE },
{ DIK_POWER },
{ DIK_PREVTRACK },
{ DIK_PRIOR },
{ DIK_Q },
{ DIK_R },
{ DIK_RBRACKET },
{ DIK_RCONTROL },
{ DIK_RETURN },
{ DIK_RIGHT },
{ DIK_RMENU },
{ DIK_RSHIFT },
{ DIK_RWIN },
{ DIK_S },
{ DIK_SCROLL },
{ DIK_SEMICOLON },
{ DIK_SLASH },
{ DIK_SLEEP },
{ DIK_SPACE },
{ DIK_STOP },
{ DIK_SUBTRACT },
{ DIK_SYSRQ },
{ DIK_T },
{ DIK_TAB },
{ DIK_U },
{ DIK_UNDERLINE },
{ DIK_UNLABELED },
{ DIK_UP },
{ DIK_V },
{ DIK_VOLUMEDOWN },
{ DIK_VOLUMEUP },
{ DIK_W },
{ DIK_WAKE },
{ DIK_WEBBACK },
{ DIK_WEBFAVORITES },
{ DIK_WEBFORWARD },
{ DIK_WEBHOME },
{ DIK_WEBREFRESH },
{ DIK_WEBSEARCH },
{ DIK_WEBSTOP },
{ DIK_X },
{ DIK_Y },
{ DIK_YEN },
{ DIK_Z },
{ DIK_BACKSPACE },
{ DIK_CAPSLOCK },
{ DIK_CIRCUMFLEX },
{ DIK_DOWNARROW },
{ DIK_LALT },
{ DIK_LEFTARROW },
{ DIK_NUMPADMINUS },
{ DIK_NUMPADPERIOD },
{ DIK_NUMPADPLUS },
{ DIK_NUMPADSLASH },
{ DIK_NUMPADSTAR },
{ DIK_PGDN },
{ DIK_PGUP },
{ DIK_RALT },
{ DIK_RIGHTARROW },
{ DIK_UPARROW }
};

std::vector< std::string > g_Toggles
{
	"CapslockToggle",
	"NumLockToggle",
	"ScrollLockToggle",
	"InsertToggle"
};
	   
Keyboard::Keyboard( me::game::IGame * gameInstance )
	: m_game( gameInstance )
	, m_pdi( 0 )
	, m_pdiKeyboard( 0 )
	, m_iKeyDown( 0 )
	, m_hasFocus( false )
{
	// Set input buffers to defaults...
	size_t index = 0;
	for ( auto && name : g_Buttons )
	{
		m_nameToIndex[ name ] = index;
		m_iKeyPressTimes[index] = 0;
		m_KeyStatus[index] = KeyStatus::Up;
		index++;
	}
				
	for ( auto && name : g_Toggles )
	{
		m_nameToIndex[ name ] = index++;
	}

	for ( size_t k = 0; k < KeyStatus::COUNT; k++ )
	{
		m_uKeyStatusCount[k] = 0;
	}

	Acquire();
}

Keyboard::~Keyboard()
{
	m_pdiKeyboard = 0;
	m_pdi = 0;
}

std::string Keyboard::GetName() const
{
	return "Keyboard";
}

void Keyboard::Acquire()
{
	auto parameters = m_game->GetOSParameters();
	HWND handle = (HWND)parameters.hWnd;
	HINSTANCE hInstance = (HINSTANCE)parameters.hInstance;

	// Create the Direct Input device...
	if ( ! m_pdi )
	{
		if ( FAILED( DirectInput8Create( hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pdi, 0 ) ) )
		{
			throw exception::DeviceFailure( "DirectInput", "Couldn't Create a device!" );
		}
	}

	// Create the Direct Input Keyboard device...
	m_pdiKeyboard = 0;

	if ( FAILED( m_pdi->CreateDevice( GUID_SysKeyboard, &m_pdiKeyboard, 0 ) ) )
	{
		throw exception::DeviceFailure( "DirectInput.Keyboard", "Couldn't create device!" );
	}

	if ( m_pdiKeyboard->SetCooperativeLevel( handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE ) != DI_OK )
	{
		throw exception::DeviceFailure( "DirectInput.Keyboard", "Couldn't set cooperative level!" );
	}

	if ( m_pdiKeyboard->SetDataFormat( &c_dfDIKeyboard ) != DI_OK )
	{
		throw exception::DeviceFailure( "DirectInput.Keyboard", "Couldn't set data format!" );
	}

	if ( m_pdiKeyboard->Acquire() != DI_OK )
	{
		throw exception::DeviceFailure( "DirectInput.Keyboard", "Failed to acquire!" );
	}
}

void Keyboard::Update()
{
	if ( !m_pdi )
	{
		Acquire();
		return;
	}

	// Pole Keyboard...
	if ( m_pdiKeyboard->GetDeviceState( 256, m_diKeyState ) != DI_OK )
	{
		throw exception::DeviceFailure( "DirectInput.Keyboard", "Couldn't get device state!" );
	}

	unsigned int u;
	for ( u = 0; u < KeyStatus::COUNT; u++ )
	{
		m_uKeyStatusCount[u] = 0;
	}

	auto diKeyPressed = []( auto x ) { return  ((x & 0x80) != 0); };

	// Key Pressed...
	for ( int i = 0; i < 256; ++i )
	{
		// Check if a key is being pressed..
		if ( diKeyPressed( m_diKeyState[ i ] ) )
		{
			m_iKeyPressTimes[i]++;

			if ( m_KeyStatus[i] == KeyStatus::Up )
			{
				m_KeyStatus[i] = KeyStatus::JustDown;
			}
			else
			{
				m_KeyStatus[i] = KeyStatus::Down;
			}

			if ( m_iKeyPressTimes[i] >= 2 ) m_iKeyPressTimes[i] = 2;
		}
		else
		{
			if ( m_KeyStatus[i] == KeyStatus::Down || m_KeyStatus[i] == KeyStatus::JustDown )
			{
				m_KeyStatus[i] = KeyStatus::Pressed;
			}
			else
			{
				m_KeyStatus[i] = KeyStatus::Up;
			}

			// Check if a key is flaged as repeating, if it is and is currently not pressed, clear it
			m_iKeyPressTimes[i] = 0;
		}

		m_uKeyStatusCount[m_KeyStatus[i]]++;
	}

	// Capslock, Scrolllock, Numlock, Insert...
	m_capslock = GetKeyState( VK_CAPITAL ) & 0x0001;
	m_numlock = GetKeyState( VK_NUMLOCK ) & 0x0001;
	m_scrolllock = GetKeyState( VK_SCROLL ) & 0x0001;
	m_insert = GetKeyState( VK_INSERT ) & 0x0001;
}

size_t Keyboard::SubSourceCount() const
{
	return 1;
}

size_t Keyboard::GetInputCount( size_t subSource ) const
{
	return m_nameToIndex.size();
}

std::string Keyboard::GetInputName( size_t subSource, size_t index ) const
{
	if ( index < g_Buttons.size() )
	{
		return g_Buttons[ index ];
	}
	else if ( index < (g_Buttons.size() + 4) )
	{
		switch ( index - g_Buttons.size() )
		{
		case 0:
			return "Capslock";
		case 1:
			return "NumLock";
		case 2:
			return "ScrollLock";
		case 3:
			return "Insert";
		default: 
			return std::string();
		};
	}
	else
	{
		return std::string();
	}
}

size_t Keyboard::GetInputIndex( size_t subSource, std::string name ) const
{	
	auto && itr = m_nameToIndex.find( name );
	if ( itr == m_nameToIndex.end() )
	{
		return MAXSIZE_T;
	}
	else
	{
		return itr->second;
	}
}

input::InputType Keyboard::GetInputType( size_t subSource, size_t index ) const
{
	if ( index < g_Buttons.size() )
	{
		return input::InputType::Button;
	}
	else if ( index < (g_Buttons.size() + 4 ) )
	{
		return input::InputType::Toggle;
	}
	else
	{
		return input::InputType::Invalid;
	}
}																	 

input::IData::ptr Keyboard::GetInputData( size_t subSource, size_t index ) const
{
	if ( subSource > 0 ) return nullptr;
	if ( m_game->IsUpdateLocked( false ) || ! m_game->GetOS()->GetHasFocus() ) return nullptr;

	if ( index < g_Buttons.size() )
	{
		auto diKeyPressed = []( auto x ) { return  ((x & 0x80) != 0); };

		int key = g_KeyCodes[ index ];
		input::ButtonData * data = new input::ButtonData();
		data->down = diKeyPressed( m_diKeyState[ key ] );
		data->pressed = (m_KeyStatus[ key ] == KeyStatus::Pressed);
		return IData::ptr( data );
	}
	else if ( index < (g_Buttons.size() + g_Toggles.size()) )
	{
		input::ToggleData * data = new input::ToggleData();
		
		switch( index - g_Buttons.size() )
		{
		case 0:	 
			data->on = m_capslock;
			break;
		case 1:
			data->on = m_numlock;
			break;
		case 2:
			data->on = m_scrolllock;
			break;
		case 3:
			data->on = m_insert;
			break;
		}
		return input::IData::ptr( data );
	}
	else
	{
		return IData::ptr();
	}
}

me::input::IData::ptr Keyboard::GetInputData( size_t subSource, std::string name ) const
{
	size_t index = GetInputIndex( subSource, name );
	return GetInputData( subSource, index );
}

void Keyboard::SetInputData( size_t subSource, size_t index, me::input::IData::ptr dataIn )
{
	throw std::exception( "Error! Attempted to SetInputData on Keyboard, which is read-only!" );
}
