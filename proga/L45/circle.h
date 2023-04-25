#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
public:
    Circle();
    Circle(int x, int y, int r=120, int n_inter=0);

    int getX() const;
    void setX(int value);

    int getY();
    void setY(int value);

    int getR();

private:
    int x,y,r,n_inter;
};

#endif // CIRCLE_H
