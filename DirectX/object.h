#pragma once
#include "esshead.h"
#include "node.h"

class object
{
public:
	object(void);
	virtual ~object(void);
	HRESULT virtual Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
public:
	node mNode;
};
