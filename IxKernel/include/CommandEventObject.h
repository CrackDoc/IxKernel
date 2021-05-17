#ifndef CommandEventObject_h__
#define CommandEventObject_h__

#include "EventObject.h"

class KERNEL_EXPORT CCommandEventObject : public CEventObject
{
public:
	CCommandEventObject(const char* strCommand = "");
	~CCommandEventObject();

	void SetCommand(const char* strCmd);

	void* GetCommand();

	const char* GetCommand() const;

	CEventObject* Clone() const;

	void SetExclusive( bool bExclusive );

	bool IsExclusive() const;
protected:
	bool m_bExclusive;			//命令独占,同名命令将被清除
	char m_strCommadBuffer[256];
	//std::string m_strCommand;
};
#endif // CommandEventObject_h__
