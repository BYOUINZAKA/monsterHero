#include "base_monster.h"

void base_monster::connect_all()
{
    connect(this,
            SIGNAL(hited(base_monster *, base_skill *, int)),
            this,
            SLOT(hited_slot(base_monster *, base_skill *, int)));
}
