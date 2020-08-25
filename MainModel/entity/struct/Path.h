#ifndef PATH_H
#define PATH_H
struct Path
{
  double path;
  double angle;
  Path(double pathIn,double angleIn)
  {
      path=pathIn;
      angle=(int)angleIn%360;
  }
};
#endif // PATH_H
