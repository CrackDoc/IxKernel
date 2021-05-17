#ifndef KeyboardEventObject_h__
#define KeyboardEventObject_h__

#include "EventObject.h"
//#include "qnamespace.h"

class KERNEL_EXPORT CKeyboardEventObject : public CEventObject
{
public:
	enum E_KEY
	{
		E_KEY_NONE = 0,
		E_KEY_0 = '0',
		E_KEY_1 = '1',
		E_KEY_2 = '2',
		E_KEY_3 = '3',
		E_KEY_4 = '4',
		E_KEY_5 = '5',
		E_KEY_6 = '6',
		E_KEY_7 = '7',
		E_KEY_8 = '8',
		E_KEY_9 = '9',
		E_KEY_A = 'a',
		E_KEY_B = 'b',
		E_KEY_C = 'c',
		E_KEY_D = 'd',
		E_KEY_E = 'e',
		E_KEY_F = 'f',
		E_KEY_G = 'g',
		E_KEY_H = 'h',
		E_KEY_I = 'i',
		E_KEY_J = 'j',
		E_KEY_K = 'k',
		E_KEY_L = 'l',
		E_KEY_M = 'm',
		E_KEY_N = 'n',
		E_KEY_O = 'o',
		E_KEY_P = 'p',
		E_KEY_Q = 'q',
		E_KEY_R = 'r',
		E_KEY_S = 's',
		E_KEY_T = 't',
		E_KEY_U = 'u',
		E_KEY_V = 'v',
		E_KEY_W = 'w',
		E_KEY_X = 'x',
		E_KEY_Y = 'y',
		E_KEY_Z = 'z',

		E_KEY_Space = 0x20,
		E_KEY_Exclaim = 0x21,
		E_KEY_Quotedbl = 0x22,
		E_KEY_Hash = 0x23,
		E_KEY_Dollar = 0x24,
		E_KEY_Ampersand = 0x26,
		E_KEY_Quote = 0x27,
		E_KEY_Leftparen = 0x28,
		E_KEY_Rightparen = 0x29,
		E_KEY_Asterisk = 0x2A,
		E_KEY_Plus = 0x2B,
		E_KEY_Comma = 0x2C,
		E_KEY_Minus = 0x2D,
		E_KEY_Period = 0x2E,
		E_KEY_Slash = 0x2F,
		E_KEY_Colon = 0x3A,
		E_KEY_Semicolon = 0x3B,
		E_KEY_Less = 0x3C,
		E_KEY_Equals = 0x3D,
		E_KEY_Greater = 0x3E,
		E_KEY_Question = 0x3F,
		E_KEY_At = 0x40,
		E_KEY_Leftbracket = 0x5B,
		E_KEY_Backslash = 0x5C,
		E_KEY_Rightbracket = 0x5D,
		E_KEY_Caret = 0x5E,
		E_KEY_Underscore = 0x5F,
		E_KEY_Backquote = 0x60,

		E_KEY_BackSpace = 0xFF08,       
		E_KEY_Tab = 0xFF09,
		E_KEY_Linefeed = 0xFF0A,       
		E_KEY_Clear = 0xFF0B,
		E_KEY_Return = 0xFF0D,    
		E_KEY_Pause = 0xFF13,  
		E_KEY_Scroll_Lock = 0xFF14,
		E_KEY_Sys_Req = 0xFF15,
		E_KEY_Escape = 0xFF1B,
		E_KEY_Delete = 0xFFFF, 

		E_KEY_Home = 0xFF50,
		E_KEY_Left = 0xFF51,     
		E_KEY_Up = 0xFF52,    
		E_KEY_Right = 0xFF53,   
		E_KEY_Down = 0xFF54,   
		E_KEY_Prior = 0xFF55,  
		E_KEY_Page_Up = 0xFF55,
		E_KEY_Next = 0xFF56,
		E_KEY_Page_Down = 0xFF56,
		E_KEY_End = 0xFF57, 
		E_KEY_Begin = 0xFF58, 

		E_KEY_Select = 0xFF60,   
		E_KEY_Print = 0xFF61,
		E_KEY_Execute = 0xFF62,
		E_KEY_Insert = 0xFF63,
		E_KEY_Undo = 0xFF65,
		E_KEY_Redo = 0xFF66,  
		E_KEY_Menu = 0xFF67,  
		E_KEY_Find = 0xFF68,  
		E_KEY_Cancel = 0xFF69,  
		E_KEY_Help  = 0xFF6A,  
		E_KEY_Break = 0xFF6B,
		E_KEY_Mode_switch = 0xFF7E,   
		E_KEY_Script_switch = 0xFF7E, 
		E_KEY_Num_Lock = 0xFF7F,

		E_KEY_KP_Space = 0xFF80, 
		E_KEY_KP_Tab = 0xFF89,
		E_KEY_KP_Enter = 0xFF8D, 
		E_KEY_KP_F1 = 0xFF91, 
		E_KEY_KP_F2 = 0xFF92,
		E_KEY_KP_F3 = 0xFF93,
		E_KEY_KP_F4 = 0xFF94,
		E_KEY_KP_Home = 0xFF95,
		E_KEY_KP_Left = 0xFF96,
		E_KEY_KP_Up = 0xFF97,
		E_KEY_KP_Right = 0xFF98,
		E_KEY_KP_Down = 0xFF99,
		E_KEY_KP_Prior = 0xFF9A,
		E_KEY_KP_Page_Up = 0xFF9A,
		E_KEY_KP_Next = 0xFF9B,
		E_KEY_KP_Page_Down = 0xFF9B,
		E_KEY_KP_End = 0xFF9C,
		E_KEY_KP_Begin = 0xFF9D,
		E_KEY_KP_Insert = 0xFF9E,
		E_KEY_KP_Delete = 0xFF9F,
		E_KEY_KP_Equal = 0xFFBD,   
		E_KEY_KP_Multiply = 0xFFAA,
		E_KEY_KP_Add = 0xFFAB,
		E_KEY_KP_Separator = 0xFFAC, 
		E_KEY_KP_Subtract = 0xFFAD,
		E_KEY_KP_Decimal = 0xFFAE,
		E_KEY_KP_Divide = 0xFFAF,

		E_KEY_KP_0 = 0xFFB0,
		E_KEY_KP_1 = 0xFFB1,
		E_KEY_KP_2 = 0xFFB2,
		E_KEY_KP_3 = 0xFFB3,
		E_KEY_KP_4 = 0xFFB4,
		E_KEY_KP_5 = 0xFFB5,
		E_KEY_KP_6 = 0xFFB6,
		E_KEY_KP_7 = 0xFFB7,
		E_KEY_KP_8 = 0xFFB8,
		E_KEY_KP_9 = 0xFFB9,

		E_KEY_F1 = 0xFFBE,
		E_KEY_F2 = 0xFFBF,
		E_KEY_F3 = 0xFFC0,
		E_KEY_F4 = 0xFFC1,
		E_KEY_F5 = 0xFFC2,
		E_KEY_F6 = 0xFFC3,
		E_KEY_F7 = 0xFFC4,
		E_KEY_F8 = 0xFFC5,
		E_KEY_F9 = 0xFFC6,
		E_KEY_F10 = 0xFFC7,
		E_KEY_F11 = 0xFFC8,
		E_KEY_F12 = 0xFFC9,
		E_KEY_F13 = 0xFFCA,
		E_KEY_F14 = 0xFFCB,
		E_KEY_F15 = 0xFFCC,
		E_KEY_F16 = 0xFFCD,
		E_KEY_F17 = 0xFFCE,
		E_KEY_F18 = 0xFFCF,
		E_KEY_F19 = 0xFFD0,
		E_KEY_F20 = 0xFFD1,
		E_KEY_F21 = 0xFFD2,
		E_KEY_F22 = 0xFFD3,
		E_KEY_F23 = 0xFFD4,
		E_KEY_F24 = 0xFFD5,
		E_KEY_F25 = 0xFFD6,
		E_KEY_F26 = 0xFFD7,
		E_KEY_F27 = 0xFFD8,
		E_KEY_F28 = 0xFFD9,
		E_KEY_F29 = 0xFFDA,
		E_KEY_F30 = 0xFFDB,
		E_KEY_F31 = 0xFFDC,
		E_KEY_F32 = 0xFFDD,
		E_KEY_F33 = 0xFFDE,
		E_KEY_F34 = 0xFFDF,
		E_KEY_F35 = 0xFFE0,

		E_KEY_Shift_L = 0xFFE1,       
		E_KEY_Shift_R = 0xFFE2,     
		E_KEY_Control_L = 0xFFE3,     
		E_KEY_Control_R = 0xFFE4,     
		E_KEY_Caps_Lock = 0xFFE5,    
		E_KEY_Shift_Lock = 0xFFE6,     

		E_KEY_Meta_L = 0xFFE7, 
		E_KEY_Meta_R = 0xFFE8,  
		E_KEY_Alt_L = 0xFFE9,    
		E_KEY_Alt_R = 0xFFEA, 
		E_KEY_Super_L = 0xFFEB,  
		E_KEY_Super_R = 0xFFEC, 
		E_KEY_Hyper_L = 0xFFED, 
		E_KEY_Hyper_R = 0xFFEE 
	};

	enum E_MOD_KEY
	{
		E_MOD_KEY_NONE		  = 0x0000,
		E_MOD_KEY_LEFT_SHIFT  = 0x0001,
		E_MOD_KEY_RIGHT_SHIFT = 0x0002,
		E_MOD_KEY_LEFT_CTRL   = 0x0004,
		E_MOD_KEY_RIGHT_CTRL  = 0x0008,
		E_MOD_KEY_LEFT_ALT    = 0x0010,
		E_MOD_KEY_RIGHT_ALT   = 0x0020,
		E_MOD_KEY_LEFT_META   = 0x0040,
		E_MOD_KEY_RIGHT_META  = 0x0080,
		E_MOD_KEY_LEFT_SUPER  = 0x0100,
		E_MOD_KEY_RIGHT_SUPER = 0x0200,
		E_MOD_KEY_LEFT_HYPER  = 0x0400,
		E_MOD_KEY_RIGHT_HYPER = 0x0800,
		E_MOD_KEY_NUM_LOCK    = 0x1000,
		E_MOD_KEY_CAPS_LOCK   = 0x2000,
		E_MOD_KEY_CTRL        = (E_MOD_KEY_LEFT_CTRL|E_MOD_KEY_RIGHT_CTRL),
		E_MOD_KEY_SHIFT       = (E_MOD_KEY_LEFT_SHIFT|E_MOD_KEY_RIGHT_SHIFT),
		E_MOD_KEY_ALT         = (E_MOD_KEY_LEFT_ALT|E_MOD_KEY_RIGHT_ALT),
		E_MOD_KEY_META        = (E_MOD_KEY_LEFT_META|E_MOD_KEY_RIGHT_META),
		E_MOD_KEY_SUPER       = (E_MOD_KEY_LEFT_SUPER|E_MOD_KEY_RIGHT_SUPER),
		E_MOD_KEY_HYPER       = (E_MOD_KEY_LEFT_HYPER|E_MOD_KEY_RIGHT_HYPER)
	};

	enum E_KEY_EVENT_TYPE
	{
		E_KEY_EVENT_TYPE_KEYDOWN = 0,
		E_KEY_EVENT_TYPE_KEYUP = 1,
	};
public:
	CKeyboardEventObject();
	~CKeyboardEventObject();

	CEventObject* Clone() const;

	void SetKey(E_KEY eKey);

	E_KEY GetKey();

	void SetModifier(E_MOD_KEY eModifier);

	E_MOD_KEY GetModifier();

	E_KEY_EVENT_TYPE GetKeyEventType();

	void SetKeyEventType(E_KEY_EVENT_TYPE eKeyEventType);

	//static E_KEY ConvertOsgKey(int nOsgKey);

	//static E_MOD_KEY ConvertOsgModKey(int nOsgModKey);

	//static E_KEY ConvertQtKey(int nQtKey);

	//static E_MOD_KEY ConvertQtModKey(Qt::KeyboardModifiers eQtModKey);

protected:
	E_KEY m_eKey;
	E_MOD_KEY m_eModifier;
	E_KEY_EVENT_TYPE m_eKeyEventType;
};

#endif // KeyboardEventObject_h__
