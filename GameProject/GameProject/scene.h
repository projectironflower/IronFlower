#pragma once

class CScene
{
private:


public:
	virtual void Initialize () = 0;
	virtual void Finalize ();
	virtual void Update ();
	virtual void Draw ();
};
