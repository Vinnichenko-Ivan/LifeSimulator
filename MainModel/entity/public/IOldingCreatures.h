#pragma once

class IOldingCreatures
{
public:
    virtual void update()=0;
    virtual bool is_dead() const=0;
    virtual ~IOldingCreatures(){}
};
