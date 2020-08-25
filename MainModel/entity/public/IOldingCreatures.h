#pragma once

class IOldingCreatures
{
public:
    virtual void update()=0;
    virtual bool isDead() const=0;
    virtual ~IOldingCreatures(){}
};
