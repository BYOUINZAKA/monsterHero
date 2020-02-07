#-------------------------------------------------
#
# Project created by QtCreator 2019-12-25T10:34:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monsterHero
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    base_monster.cpp \
    type.cpp \
    base_ability.cpp \
    area.cpp \
    books.cpp \
    monster_slots.cpp \
    base_skill.cpp \
    binding.cpp \
    values.cpp \
    message_queue.cpp \
    blockcontroller.cpp

HEADERS += \
        mainwindow.h \
    base_monster.h \
    type.h \
    classes_tree.h \
    base_ability.h \
    area.h \
    tuple.h \
    books.h \
    base_skill.h \
    test.h \
    interfaces.h \
    status.h \
    middle_skill.h \
    message_queue.h \
    blockcontroller.h

FORMS += \
        mainwindow.ui
