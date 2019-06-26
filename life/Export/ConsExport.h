#ifndef LIFE_CONSEXPORT_H
#define LIFE_CONSEXPORT_H

#include "../Game/Condition.h"

namespace LifeGame{
    class ConsExport{
    protected:
        Condition cond;
        static const int LIVE = 1;
    public:
        ConsExport();
        ConsExport(const ConsExport& other);
        ConsExport& operator=(const ConsExport& other);
        ConsExport(Condition finish);
        virtual ~ConsExport();
        void consOut();
    };
}

#endif //LIFE_CONSEXPORT_H
