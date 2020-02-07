#ifndef TUPLE_H
#define TUPLE_H

#define INFINITY_TURN ((int)(-1))

struct tuple
{
    tuple() : strength(0),
        turn(0) {}
    tuple(int s) : strength(s),
        turn(INFINITY_TURN) {}
    tuple(int s, int t) : strength(s),
        turn(t) {}
    int count()
    {
        if (strength > 0 && turn > -1)
            if(--turn <= 0)
                strength = 0;
        return strength;
    }

    int strength;
    int turn;
};

#endif // TUPLE_H
