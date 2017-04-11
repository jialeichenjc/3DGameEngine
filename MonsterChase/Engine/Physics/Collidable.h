#pragma once
#include <string>
class Collidable
{
public:
	Collidable();

	inline std::string GetName() const { return name; }
	inline std::string SetName(const std::string & i_str) { name = i_str; }
	inline bool operator == (const Collidable & i_col) { return this->name == i_col.GetName(); }
	~Collidable();

private:
	std::string name;
};

