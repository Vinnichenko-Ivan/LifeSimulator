#ifndef IVISIONCREATURES_H
#define IVISIONCREATURES_H
#include<vector>
class VisiableEntity;
class IVisionCreatures
{
    public:
        virtual void visionUpdate(std::vector<VisiableEntity> visionIn)=0;
};
#endif // IVISIONCREATURES_H
