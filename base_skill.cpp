#include "base_skill.h"
#include "base_monster.h"
#include <QtGlobal>

base_skill::base_skill(size_t _id,
                       const QString &_name,
                       const QString &_message,
                       size_t _power,
                       type_value _type,
                       size_t _acc,
                       flag_type _flags):
    QObject(nullptr),
    id(_id),
    name(_name),
    message(_message),
    power(_power),
    skill_type(_type),
    accuracy(_acc),
    flags(_flags)
{}

bool base_skill::isAccuracy(base_monster* atker, base_monster* defer){
    if(this->accuracy == 0 || this->accuracy == 100){
        emit defer->hit_by_a_move(atker, defer, this);
        return true;
    }
    else{
        if(qrand()%100 <= this->accuracy){
            emit defer->hit_by_a_move(atker, defer, this);
            return true;
        }
        else
            return false;
    }
}

void base_skill::move_sending(_SKILL_PARAMETER_MESSAGES){
    auto atker = dynamic_cast<base_monster*>(user);
    auto defer = dynamic_cast<base_monster*>(target);
    auto move = dynamic_cast<base_skill*>(tool);
    //accuracy test
    move->isAccuracy(atker, defer);
    ////////////////
}
