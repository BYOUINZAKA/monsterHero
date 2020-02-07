#ifndef TEST_H
#define TEST_H

#ifndef ISTESTING
#define ISTESTING true
#endif

#ifdef ISTESTING
#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QThread>

class A: public QObject{
    Q_OBJECT
public:
    QMutex mutex;
    bool l = false;
public:
    A():QObject(nullptr)
    {
        l = true;
    }
signals:
    void sign(QObject* b, int n);
public slots:
    void take_A(QObject* b, int n){
        QMutexLocker locker(&mutex);
        if(l == true){
            qDebug() << "A:" << n;
        }
    }
};

class B: public QObject{
    Q_OBJECT
signals:
    void stop();
    void agree();
    void refuse();
public slots:
    void take_B(QObject* b, int n){
        if(n == 5){
            emit agree();
        }
        else{
            emit refuse();
        }
    }
};

#endif

#endif // TEST_H
