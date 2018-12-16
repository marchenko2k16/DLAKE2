#pragma once
class Weapon
{
private:
	int amo;//number of bullets 
public:
	virtual void attack();
	virtual void reload();
	Weapon();
	~Weapon();
};

