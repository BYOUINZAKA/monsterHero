#ifndef ABILITY_H
#define ABILITY_H

#include "classes_tree.h"
#include <QObject>
#include <QString>

class base_ability : public QObject
{
    Q_OBJECT
public:
    explicit base_ability(QObject *parent = nullptr);
    virtual ~base_ability() = 0;

    virtual void initNameOrId();
    QString getName() const { return name; }

private:
    int id;
    QString name;
    QString message;

signals:
    virtual void ability_triggered() = 0;

public slots:
};

#endif // ABILITY_H
