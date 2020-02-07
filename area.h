#ifndef AREA_H
#define AREA_H

#ifndef ISDEBUGING
//#define ISDEBUGING true
#endif

#include "interfaces.h"
#include "classes_tree.h"
#include "tuple.h"
#include "status.h"

#include <QObject>

#ifdef ISDEBUGING
#include <QDebug>
#endif

class base_area : extends QObject, implements AsTarget
{
    Q_OBJECT
public:
    constexpr static const char *const BATTLE_FIELD = "battlefield";
    constexpr static const char *const PART_FIELD = "partfield";
    constexpr static const char *const SINGLE_FIELD = "singlefield";
    //Children object names used for identification.
    constexpr static const size_t _SIZE_ = 0;

    virtual base_area *leader() = 0;
    virtual base_area *employee_left() = 0;
    virtual base_area *employee_right() = 0;
    virtual base_area *opponent() = 0;
    //Some interfacees to get the area to which the area belongs and depended.
    virtual size_t size() = 0;
    //This is an interface that identifies the type of area.
    //  battlefield = 4
    //  partfield   = 2
    //  area        = 1
    explicit base_area(QObject *parent = nullptr) : QObject(parent)
    {
    }
    virtual ~base_area() = 0;
};

enum
{
    NONE = 0,
    FULL,
    LEFT,
    LEFT_LEFT,
    LEFT_RIGHT,
    RIGHT,
    RIGHT_LEFT,
    RIGHT_RIGHT
};

class battlefield final : extends base_area
{
    Q_OBJECT
public:
    constexpr const static size_t _SIZE_ = 4;
    explicit battlefield() : base_area(nullptr)
    {
        setObjectName(base_area::BATTLE_FIELD);
    }

    ~battlefield()
    {
#ifdef ISDEBUGING
        qDebug() << "~battlefield()";
#endif
    }

    size_t size() override
    {
        return _SIZE_;
    }

    const char *get_target_name() override
    {
        return BATTLE_FIELD;
    }

    base_area *leader() override
    {
        return qobject_cast<base_area *>(this);
    }

    base_area *employee_left() override
    {
        if (this->children().size() <= 2 && this->children().size() != 0)
            return qobject_cast<base_area *>(this->children().at(0));
        else
            return nullptr;
    }
    base_area *employee_right() override
    {
        if (this->children().size() == 2)
            return qobject_cast<base_area *>(this->children().at(1));
        else
            return nullptr;
    }

    base_area *opponent() override
    {
        return qobject_cast<base_area *>(this);
    }

    enum class STATUS_WORDS
    {
        Weather = 0,
        Trick_Room,
        Terrains,

        STATUS_WORDS_SIZE
    };

    using status = status<STATUS_WORDS, STATUS_WORDS::STATUS_WORDS_SIZE>;
    status statuses;

    enum class STRENGTH_WORDS
    {
        NONE = 0,
        Sunny,
        Rain,
        Sandstorm,
        Hail,

        Electric_Terrain = 1,
        Psychic_Terrain,
        Grassy_Terrain,
        Misty_Terrain,
        Darkest_Terrain,
        Mystery_Terrain
    };
};

class partfield final : extends base_area
{
    Q_OBJECT
public:
    constexpr const static size_t _SIZE_ = 2;
    explicit partfield(base_area *parent) : base_area(parent)
    {
        setObjectName(base_area::PART_FIELD);
    }

    ~partfield()
    {
#ifdef ISDEBUGING
        qDebug() << "~partfield()";
#endif
    }

    size_t size() override
    {
        return _SIZE_;
    }

    const char *get_target_name() override
    {
        return PART_FIELD;
    }

    base_area *leader() override
    {
        if (this->parent())
            return qobject_cast<base_area *>(this->parent());
        else
            return nullptr;
    }

    base_area *employee_left() override
    {
        if (this->children().size() <= 2 && this->children().size() != 0)
            return qobject_cast<base_area *>(this->children().at(0));
        else
            return nullptr;
    }
    base_area *employee_right() override
    {
        if (this->children().size() == 2)
            return qobject_cast<base_area *>(this->children().at(1));
        else
            return nullptr;
    }
    base_area *opponent() override
    {
        if (this->leader() && this->parent()->children().size() == 2)
            return this == this->leader()->employee_left() ? this->leader()->employee_right() : this->leader()->employee_left();
        //return qobject_cast<base_area *>(this);
        else
            return nullptr;
    }

    enum class STATUS_WORDS
    {
        Spikes,
        Toxic_Spikes,
        Stealth_Rock,
        Sticky_Web,
        Reflect,
        Light_Screen,
        Tailwind,
        Aurora_Veil,

        STATUS_WORDS_SIZE
    };
    using status = status<STATUS_WORDS, STATUS_WORDS::STATUS_WORDS_SIZE>;
    status statuses;
};

class singlefield final : extends base_area
{
    Q_OBJECT
public:
    using monster_ptr = base_monster *;
    constexpr const static size_t _SIZE_ = 1;

    explicit singlefield(base_area *parent) : base_area(parent)
    {
        setObjectName(base_area::SINGLE_FIELD);
    }

    ~singlefield()
    {
#ifdef ISDEBUGING
        qDebug() << "~singlefield()";
#endif
    }

    size_t size() override
    {
        return _SIZE_;
    }

    const char *get_target_name() override
    {
        return SINGLE_FIELD;
    }

    base_area *leader() override
    {
        if (this->parent())
            return qobject_cast<base_area *>(this->parent());
        else
            return nullptr;
    }

    base_area *employee_left() override
    {
        return qobject_cast<base_area *>(this);
    }
    base_area *employee_right() override
    {
        return qobject_cast<base_area *>(this);
    }

    base_area *opponent() override
    {
        if (this->parent() && this->parent()->parent() && this->parent()->parent()->children().size() == 2)
            return this->leader() == this->leader()->leader()->employee_left() ? this->leader()->leader()->employee_right() : this->leader()->leader()->employee_left();
        else
            return nullptr;
    }

    bool has_monster()
    {
        return monster != nullptr;
    }

    const monster_ptr get_const_monster() const
    {
        return monster;
    }

    void reset_monster(base_monster *target)
    {
        monster = target;
    }

    enum class STATUS_WORDS
    {
        Leech_Seed,

        STATUS_WORDS_SIZE
    };
    using status = status<STATUS_WORDS, STATUS_WORDS::STATUS_WORDS_SIZE>;
    status statuses;

private:
    monster_ptr monster;
};

#endif // AREA_H
