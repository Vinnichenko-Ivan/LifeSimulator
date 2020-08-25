#ifndef CORDINATE_H
#define CORDINATE_H
struct Cordinate
{
    Cordinate(int xIn=0,int yIn=0)
    {
        x=xIn;
        y=yIn;
    }
    int x,y;
    int angel;
};
#endif // CORDINATE_H
