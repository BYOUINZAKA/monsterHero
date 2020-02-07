#ifndef BASE_MONSTER_H
#define BASE_MONSTER_H

#include "interfaces.h"
#include "classes_tree.h"
#include "base_ability.h"
#include "base_skill.h"
#include "area.h"

#include <QObject>
#include <QString>
#include <QPixmap>

#include <memory>
#include "type.h"
#include "status.h"

#define _MONSTER_PARAMETER AsUser *user, AsTarget *target, AsTool *move
#define _MONSTER_PARAMETER_MESSAGES _SKILL_PARAMETER, QObject *message = nullptr

class base_monster : extends QObject,
                     implements AsUser,
                     implements AsTarget
{
    Q_OBJECT
public:
    using area_ptr = singlefield *;
    using ability_ptr = std::unique_ptr<base_ability>;
    using skill_ptr = std::unique_ptr<base_skill>;

    enum class STATUS_WORDS
    {
        Effects = 0,
        Leech_Seed,
        Protected,
        Substitute,
        Impregnable,
        Taunted,
        Helping_Handed,

        STATUS_WORDS_SIZE
    };

    enum class EFFECT_WORDS
    {
        Normal = 0,
        Burn,
        Freeze,
        Paralysis,
        Poison,
        Badly_Poison,
        Sleep,
        Fainting
    };

    using status = status<STATUS_WORDS, STATUS_WORDS::STATUS_WORDS_SIZE>;

    explicit base_monster(QObject *parent = nullptr);
    virtual ~base_monster() = 0;
    void connect_all();

    template <class WORD>
    tuple *find_status(WORD index);

    class values
    {
    public:
        enum
        {
            HP = 0,
            Armer,
            Atk,
            Def,
            SpA,
            SpD,
            Spe,
            WORDS_SIZE,
            MAX_LEVEL = 6
        };

        QString toString();
        bool haveArmer() { return real[Armer] != 0; }
        void reset(unsigned hp, unsigned armer, unsigned a, unsigned b, unsigned c, unsigned d, unsigned s);
        void computeReal();
        double health_perc() { return ((double)(real[HP] + real[Armer])) / (bases[HP] + bases[Armer]); }
        int set_level(unsigned n, int l);
        int damage(unsigned d);

    private:
        unsigned int bases[WORDS_SIZE] = {0};
        unsigned int real[WORDS_SIZE] = {0};
        int levels[WORDS_SIZE] = {0};
    };

    QString toString(void);
    bool binding(area_ptr target);
    bool unbinding();
    void force_binding(area_ptr target);

protected:
    unsigned int id;
    QString name;
    QPixmap picture;
    type type_a;
    type type_b;

    status statuses;
    values value;
    area_ptr area;
    ability_ptr ability;
    skill_ptr handle_move;

public:
    double multiple(const type &other) const
    {
        return type_a.def_multiple(other) * type_b.def_multiple(other);
    }
    double multiple(type_value t) const
    {
        return type_a.def_multiple(t) * type_b.def_multiple(t);
    }
    bool has_type(const type &other) const
    {
        return has_type(other.value);
    }
    bool has_type(type_value t) const
    {
        return type_a.value == t || type_b.value == t;
    }

signals:
    virtual void hit_by_a_move(_MONSTER_PARAMETER);
};

#endif // BASE_MONSTER_H
