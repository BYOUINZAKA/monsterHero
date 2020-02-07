#include "base_monster.h"
#include "base_ability.h"
#include "area.h"

base_monster::base_monster(QObject *parent)
    : QObject(parent),
      type_a(type_value::NONE),
      type_b(type_value::NONE)
{
    this->connect_all();
}

QString base_monster::toString()
{
    /*
    QString str = str.sprintf("%s(%s):%d/%d/%d/%d/%d/%d",
                              name,
                              ability->getName(),
                              hp.real,
                              atk.real,
                              def.real,
                              spa.real,
                              spd.real,
                              spe.real);*/
    QString str = "";
    return str;
}

bool base_monster::binding(area_ptr target)
{
    if (!target->has_monster())
    {
        target->reset_monster(this);
        this->area = target;
        return true;
    }
    else
        return false;
}

void base_monster::force_binding(area_ptr target)
{
    target->reset_monster(this);
    this->area = target;
}

bool base_monster::unbinding()
{
    if (this->area == nullptr || !this->area->has_monster())
    {
        this->area->reset_monster(nullptr);
        this->area = nullptr;
        return false;
    }
    else
    {
        this->area->reset_monster(nullptr);
        this->area = nullptr;
        //emit area_monster_leaveed(this);
        return true;
    }
}

template<>
tuple* base_monster::find_status<base_monster::STATUS_WORDS>(base_monster::STATUS_WORDS index){
    return this->statuses.find(index);
}

template<>
tuple* base_monster::find_status<singlefield::STATUS_WORDS>(singlefield::STATUS_WORDS index){
    if(area != nullptr)
        return this->area->statuses.find(index);
    else return nullptr;
}

