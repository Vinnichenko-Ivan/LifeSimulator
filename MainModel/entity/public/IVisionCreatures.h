#ifndef IVISIONCREATURES_H
#define IVISIONCREATURES_H
#include<vector>
class VisiableEntity;
class IVisionCreatures
{
    public:
        virtual void visionCreaturesUpdate(std::vector<VisiableEntity>visionCreaturesIn)=0;
        virtual void visionFoodsUpdate(std::vector<VisiableEntity>visionFoodsIn)=0;
};
#endif // IVISIONCREATURES_H
