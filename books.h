#ifndef BOOKS_H
#define BOOKS_H
#include <QString>
#include <QMap>

class books
{
public:
    static int monster_id;
    static QMap<size_t, QString> monsters_map;
    static int ability_id;
    static QMap<size_t, QString> abilities_map;
    static int skill_id;
    static QMap<size_t, QString> skills_map;

    books() {}
};

#endif // BOOKS_H
