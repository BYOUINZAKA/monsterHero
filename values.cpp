#include "base_monster.h"

QString base_monster::values::toString()
{
    QString str;
    str.sprintf("[[(%u + %u) / (%u + %u)] - Atk:%u(%+d), Def:%u(%+d), SpA:%u(%+d), SpD:%u(%+d), Spe:%u(%+d)]",
                real[HP],bases[HP],
                real[Armer],bases[Armer],
                real[Atk], levels[Atk],
                real[Def], levels[Def],
                real[SpA], levels[SpA],
                real[SpD], levels[SpD],
                real[Spe], levels[Spe]);
    return str;
}

void base_monster::values::reset(unsigned hp, unsigned armer, unsigned a, unsigned b, unsigned c, unsigned d, unsigned s)
{
    bases[HP] = hp;
    bases[Armer] = armer;
    bases[Atk] = a;
    bases[Def] = b;
    bases[SpA] = c;
    bases[SpD] = d;
    bases[Spe] = s;
    for (int i = 0; i < WORDS_SIZE; i++)
    {
        real[i] = 0;
        levels[i] = 0;
    }
}

void base_monster::values::computeReal()
{
    for (int i = 0; i < WORDS_SIZE; i++)
    {
        int il = levels[i];
        if (il == 0)
            continue;
        if (il > 0)
        {
            real[i] = real[i] * (il / 2.0 + 1.0);
        }
        else
        {
            real[i] = real[i] / (il / 2.0 + 1.0);
        }
    }
}

int base_monster::values::set_level(unsigned n, int l)
{
    if (l > MAX_LEVEL || l < -MAX_LEVEL || n >= WORDS_SIZE)
        return 0;
    levels[n] = l;
    computeReal();
    return real[n];
}

int base_monster::values::damage(unsigned d)
{
    if(d >= real[Armer]){
        d -= real[Armer];
        real[Armer] = 0;

        if(d >= real[HP])
            real[HP] = 0;
        else real[HP] -= d;

    }else{
        real[Armer] -= d;
    }
    return real[HP] + real[Armer];
}
