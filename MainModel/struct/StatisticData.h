#ifndef STATISTICDATA_H
#define STATISTICDATA_H
#include <string>
#include <vector>
struct StatisticData
{
    int tickLives=0;
    int countLivesCreatures;
    int countLivesFood;
    int maxCountLivesCreatures=0;
    int maxCountLivesFood=0;
    int countCreateCreatures=0;
    int averageAge;
    std::vector<std::pair<std::string,int>> creaturesCultures;
};

#endif // STATISTICDATA_H
