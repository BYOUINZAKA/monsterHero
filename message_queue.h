#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <QObject>
#include <QWidget>
#include <QQueue>

class message_queue : public QObject
{
    Q_OBJECT
public:
    explicit message_queue(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MESSAGE_QUEUE_H
