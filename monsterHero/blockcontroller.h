#ifndef BLOCKCONTROLLER_H
#define BLOCKCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <tuple>
#include <string>

class BlockController: public QThread{
    Q_OBJECT
private:
    QMutex _mutex;
    QWaitCondition _condition;
    QObject* _sender;
    const char* _signal;
    unsigned _count = 0, _agree = 0, _refuse = 0;
public:
    BlockController(QObject* sender, const char* sign, QObject* reciver, const char* method):
        _sender(sender),
        _signal(sign)
    {
        connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
        connect(_sender, _signal, this, SLOT(run()));
        connect(_sender, _signal, reciver, method);
        this->start();
    }

    static BlockController* createBlock(QObject* sender, const char* sign, QObject* reciver, const char* method){
        return new BlockController(sender, sign, reciver, method);
    }

    template<class R>
    unsigned registers(R* reciver, const char* method){
        BlockController::connect(_sender, _signal, reciver, method);
        BlockController::connect(reciver, &R::agree, this, &BlockController::agree);
        BlockController::connect(reciver, &R::refuse, this, &BlockController::refuse);
        _count++;
    }

public slots:
    void run() override{
        //QObject* _sender;
        //_sender->thread()->wait()
        while(1){
            _mutex.lock();
            if(_agree + _refuse == _count){
                if(_refuse == 0)
                    emit pass();
                else
                    emit refused();
                _condition.wakeAll();
            }
            else{
                _condition.wait(&_mutex);
            }
            _mutex.unlock();
        }
    }

    void agree(){
        _agree++;
    }

    void refuse(){
        _refuse++;
    }

signals:
    void pass();
    void refused();
};

#endif // BLOCKCONTROLLER_H
