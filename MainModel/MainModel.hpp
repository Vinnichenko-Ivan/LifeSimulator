#include "public/IOldingCreatures.hpp"
#include "entity/Creature.hpp"
class MainModel:public QObject
{
    private:

    public:
        std::vector<IOldingCreatures *> creatures;
        void update()
        {
           qDebug() << "C++ Style Debug Message";
        }
};
