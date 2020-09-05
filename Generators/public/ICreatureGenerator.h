#ifndef ICREATUREGENERATOR_H
#define ICREATUREGENERATOR_H
#include <string>
#include <vector>
class ICreatureGenerator
{
    public:
        virtual std::vector<std::string>getCultureCreatures()=0;
        virtual std::string getSetCultureCreatures()=0;
        virtual void setCultureCreatures(std::string in)=0;
};
#endif // ICREATUREGENERATOR_H
