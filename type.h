#ifndef TYPE_H
#define TYPE_H

#include "classes_tree.h"
#include <QObject>

enum class type_value{
    NONE = 0,
    NORMAL  ,
    FIGHTING,
    FLYING  ,
    POISON  ,
    GROUND  ,
    ROCK    ,
    BUG     ,
    GHOST   ,
    STEEL   ,
    FIRE    ,
    WATER   ,
    GRASS   ,
    ELECTRIC,
    PSYCHIC ,
    ICE     ,
    DRAGON  ,
    DARK    ,
    FAIRY   ,
    TYPE_NUMBER
};

class type
{
public:
    static const double type_table[(unsigned)type_value::TYPE_NUMBER][(unsigned)type_value::TYPE_NUMBER];
    type_value value;

public:
    type(type_value tv):value(tv){}
    type():value(type_value::NORMAL){}

    double def_multiple(const type& other) const{
        return type_table[(unsigned)(other.value)][(unsigned)(this->value)];
    }
    double def_multiple(type_value other) const{
        return type_table[(unsigned)other][(unsigned)(this->value)];
    }
    double atk_multiple(const type& other) const{
        return type_table[(unsigned)(this->value)][(unsigned)(other.value)];
    }
    double atk_multiple(type_value other) const{
        return type_table[(unsigned)(this->value)][(unsigned)other];
    }
};

#endif // TYPE_H
