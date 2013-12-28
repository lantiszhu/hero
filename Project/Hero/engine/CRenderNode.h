#pragma once

namespace Free
{

class CRenderNode
{
public:
	CRenderNode(void);
	~CRenderNode(void);

	virtual void Render(){};
	
	//
	int GetType();

protected:
	int m_Type;
};

//!namespace
}
