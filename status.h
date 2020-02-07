#ifndef STATUS_H
#define STATUS_H

#include "tuple.h"
#include <QVector>

template<class WORDS_TYPE, WORDS_TYPE SIZE = WORDS_TYPE::STATUS_WORDS_SIZE>
class status
{
public:
    using type = status<WORDS_TYPE, SIZE>;
    using list = tuple[(size_t)SIZE];

    void countall()
    {
        for(auto &i : statuses)
            i.count();
    }

    void set(WORDS_TYPE word, int strength = true, int turn = INFINITY_TURN)
    {
        statuses[(size_t)word].strength = strength;
        statuses[(size_t)word].turn = turn;
    }

    tuple* find(WORDS_TYPE index)
    {
        if(index < SIZE)
            return &statuses[(size_t)index];
        else
            return nullptr;
    }

private:
    list statuses;

public:
    status()
            = default;
    status(const type& other)
            = default;
    ~status()
            = default;
};

#endif // STATUS_H
