#ifndef MIDDLE_SKILL_H
#define MIDDLE_SKILL_H

#include "base_skill.h"

#define _SKILL_CONSTRUCTOR_PARAMETER \
    size_t _id,\
    const QString &_name,\
    const QString &_message,\
    size_t _power,\
    type_value _typ,\
    size_t _acc,\
    flag_type _flags
#define _SKILL_CONSTRUCTOR_PASS_PARAMETER \
    _id, _name, _message, _power , _typ, _acc, _flags

class status_skill : public base_skill{
    status_skill(_SKILL_CONSTRUCTOR_PARAMETER):
        base_skill(_SKILL_CONSTRUCTOR_PASS_PARAMETER){
        this->add_character(character::STATUS_MOVE);
    }
};

class special_skill : public base_skill{
    status_skill(_SKILL_CONSTRUCTOR_PARAMETER):
        base_skill(_SKILL_CONSTRUCTOR_PASS_PARAMETER){
        this->add_character(character::SPECIAL_MOVE);
    }
};

class physical_skill : public base_skill{
    status_skill(_SKILL_CONSTRUCTOR_PARAMETER):
        base_skill(_SKILL_CONSTRUCTOR_PASS_PARAMETER){
        this->add_character(character::PHTSICAL_MOVE);
    }
};


class self_target_skill : public base_skill{

}
#endif // MIDDLE_SKILL_H
