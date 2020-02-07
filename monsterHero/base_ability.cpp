#include "base_ability.h"
#include "books.h"

base_ability::base_ability(QObject *parent) : QObject(parent)
{
}

void base_ability::initNameOrId()
{
    if (books::abilities_map.find(typeid(*this).hash_code()) != books::abilities_map.end())
    {
        this->name = books::abilities_map.value(typeid(*this).hash_code());
        this->id = books::ability_id++;
    }
    else
    {
    }
}
