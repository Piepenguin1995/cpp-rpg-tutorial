#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "entity_manager.hpp"
#include "item.hpp"

#include <string>
#include "JsonBox.h"

// Weapons are items, so they should inherit their properties
class Weapon : public Item
{
	public:

	int damage;

	// Pass inherited qualities to the normal item constructor
	Weapon(std::string id, std::string name, std::string description, int damage) :
		Item(id, name, description)
	{
		this->damage = damage;
	}

	Weapon() : Weapon("nullid", "", "", 0)
	{
	}

	Weapon(std::string id, JsonBox::Value v, EntityManager* mgr) : Item()
	{
		this->load(id, v);
	}

	void load(std::string id, JsonBox::Value v)
	{
		Item::load(id, v);
		JsonBox::Object o = v.getObject();
		this->damage = o["damage"].getInteger();

		return;
	}
};

#endif /* WEAPON_HPP */
