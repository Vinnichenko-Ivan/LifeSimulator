#ifndef ICREATUREGENERATOR_H
#define ICREATUREGENERATOR_H
#include <string>
#include <vector>
class ICreatureGenerator
{
    public:
        virtual std::vector<std::pair<std::string,int>>getCultureCreatures()=0;
        virtual std::pair<std::string,int> getSetCultureCreatures()=0;
        virtual void setCultureCreatures(int i)=0;
};
#endif // ICREATUREGENERATOR_H
