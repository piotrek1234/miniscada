#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color();
    void setRGB(char R, char G, char B);
    char getR();
    char getG();
    char getB();
    void setAlpha(char alpha);
    char getAlpha();
private:
    char R;
    char G;
    char B;
    char alpha;
};

#endif // COLOR_H
