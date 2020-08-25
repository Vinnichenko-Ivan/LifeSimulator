#ifndef CORDINATE_H
#define CORDINATE_H
struct Cordinate
{
    Cordinate(double xIn=0,double yIn=0)
    {
        x=xIn;
        y=yIn;
    }
    double x,y;
    double angel;
};
#endif // CORDINATE_H
