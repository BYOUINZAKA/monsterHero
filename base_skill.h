#ifndef BASE_SKILL_H
#define BASE_SKILL_H

#include "classes_tree.h"
#include "interfaces.h"
#include "type.h"
#include <QObject>
#include <QString>

#define FLAGS_BUILDER(_NAME_, _NUM_) \
    (_NAME_) = (((__int64)(0x1)) << (_NUM_))

#define _SKILL_PARAMETER AsUser *user, AsTarget *target, AsTool *tool
#define _SKILL_PARAMETER_MESSAGES _SKILL_PARAMETER, QObject *message

class base_skill : public QObject , implements AsTool
{
    Q_OBJECT
public:
    using flag_type = unsigned __int64;
    enum class character : flag_type
    {
        NULL_SKILL = 0x0,
        CHECK_POINT,

        STATUS_MOVE = CHECK_POINT << 0,
        SPECIAL_MOVE = CHECK_POINT << 1,
        PHYSICAL_MOVE = CHECK_POINT << 2,
        RENZOKU = CHECK_POINT << 3,
        KOUTAI = CHECK_POINT << 4,
        ONE_HIT_KO = CHECK_POINT << 5,
        MANYTURN = CHECK_POINT << 6,
        DIRECT = CHECK_POINT << 7,
        ULTRA = CHECK_POINT << 8,
        FOUCE = CHECK_POINT << 9,
        KILLSELF = CHECK_POINT << 10,
        VOICE = CHECK_POINT << 11,
        CRITICAL = CHECK_POINT << 12,
        PUNCH = CHECK_POINT << 13,
        LIMITTHEIR = CHECK_POINT << 14,
        RECOVER = CHECK_POINT << 15,
        CRUNCH = CHECK_POINT << 16,
        POWDER = CHECK_POINT << 17,
        BOMB = CHECK_POINT << 18,
        PULSE = CHECK_POINT << 19,
        PROTECT = CHECK_POINT << 20,
        NOFREEZ = CHECK_POINT << 21,
        SELF_TARGET = CHECK_POINT << 22,
        SELFPART_TARGET = CHECK_POINT << 23,
        SINGLEFIELD_TARGET = CHECK_POINT << 24,
        PARTFIELD_TARGET = CHECK_POINT << 25
    };

    base_skill(size_t _id,
               const QString &_name,
               const QString &_message,
               size_t _power = 0,
               type_value _type = type_value::NORMAL,
               size_t _acc = 100,
               flag_type _flags = (flag_type)character::NULL_SKILL);

    virtual ~base_skill() = 0;

    bool isDirect()
    {
        return flags & (flag_type)character::DIRECT;
    }
    //bool isCrunch();
private:
    size_t id;
    QString name;
    QString message;
    size_t power;
    type skill_type;
    size_t accuracy;
    flag_type flags;

public:
    inline size_t getAccuracy() const{return accuracy;}
    void add_character(character value)
    {
        flags |= (flag_type)value;
    }

    template <class Value, class... Args>
    void add_character(Value value, Args... args)
    {
        add_character(value);
        add_character(args...);
    }
signals:
    void move_used(_SKILL_PARAMETER_MESSAGES = nullptr);
    void move_missed(_SKILL_PARAMETER);

public slots:
    virtual void move_sending(_SKILL_PARAMETER_MESSAGES = nullptr);
    virtual void move_effect_triggering(_SKILL_PARAMETER_MESSAGES = nullptr){}
public:
    virtual bool isAccuracy(base_monster* atker, base_monster* defer);
};

#endif // BASE_SKILL_H
