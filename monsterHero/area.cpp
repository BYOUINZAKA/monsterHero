#include "area.h"
#include "base_monster.h"
#include "interfaces.h"

base_area::~base_area(){
#ifdef ISDEBUGING
    qDebug() << "~base_area()";
#endif
}
