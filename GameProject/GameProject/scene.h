#pragma once

#include<list>

class CScene
{
private:
	CScene ();
	virtual ~CScene ();

public:
	virtual void Initialize () = 0;
	virtual void Finalize ();
	virtual void Update ();
	virtual void Draw ();
};
