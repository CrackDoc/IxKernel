#ifndef DatagramEventObject_h__
#define DatagramEventObject_h__

#include "EventObject.h"
#include "Cache.h"

class KERNEL_EXPORT CDatagramEventObject : public CEventObject
{
public:
	enum E_EVENT_FORMAT
	{
		E_EVENT_FORMAT_NONE = 0,	//未定义
		E_EVENT_FORMAT_XML = 1,		//XML
		E_EVENT_FORMAT_BIN = 2,		//二进制
		E_EVENT_FORMAT_JSON = 3,	//JSON
	};

	enum	//hacker
	{
		NUM_INVALID_IDENTITY_CODE = -1,
	};
public:
	CDatagramEventObject();
	~CDatagramEventObject();

	CEventObject* Clone() const;

	void SetEventFormat(E_EVENT_FORMAT eEventFormat);

	E_EVENT_FORMAT GetEventFormat() const;

	void SetDescription(const char* strDescription);

	const char* GetDescription() const;

	void SetCache(const CCache& rhs);

	void SetCache(unsigned char* pBufferLen, int nLen);

	CCache& GetCache();

	const CCache& GetCache() const;

	void SetUserData1(void* pUserData);

	void* GetUserData1() const;

	void SetUserData2(void* pUserData);

	void* GetUserData2() const;

	void SetIdentityCode(int nID);

	int GetIdentityCode() const;

protected:
	CCache m_Cache;
	void* m_pUserData1;
	void* m_pUserData2;
	int m_nIdentityCode;
	E_EVENT_FORMAT m_eEventFormat;
	char m_strDescription[256];
	//std::string m_strDescription;
};
#endif // DatagramEventObject_h__
