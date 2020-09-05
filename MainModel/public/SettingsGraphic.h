#ifndef SETTINGSGRAPHIC_H
#define SETTINGSGRAPHIC_H
class SettingsGraphic
{
    public:
        virtual void setLimitCreatures(bool i)=0;
        virtual void setLimitFood(bool i)=0;
        virtual void setCountLimitCreatures(int i)=0;
        virtual void setCountLimitFood(int i)=0;
        virtual void stopReproductIfMax(bool i)=0;
};
#endif // SETTINGSGRAPHIC_H
