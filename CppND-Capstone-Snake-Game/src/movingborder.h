#ifndef MOVINGBORDER
#define MOVINGBORDER

#include "SDL.h"
#include "vector"

enum class Direction {kUp, kDown};

// LFIO_1
// OOP_1
class movingborder
{
// OOP_2
// OOP_5
private:
    /* data */
    int _borderheight;
    int _borderwidth;
    int _position;
    int _speed;
    Direction _direction;
    // LFIO_1
    void addborder();
    #if 0
    void moveborder_left(int position);
    void moveborder_right(int position);
    #endif

// OOP_2
public:
    // LFIO_1
    // OOP_7
    // MM_4
    movingborder(/* args */);
    movingborder(int height, int width);
    ~movingborder();
    movingborder(const movingborder &source);
    movingborder(movingborder &&source);
    movingborder& operator=(movingborder &source);
    movingborder& operator=(movingborder &&source);
    std::vector <SDL_Point> m_movingborder_left;
    std::vector <SDL_Point> m_movingborder_right;
    // LFIO_1
    // OOP_5
    bool isSnakeBorderCollide(int x, int y);
    bool isFoodBorderCollide(int x, int y);
    void moveborder();
};

#endif /*MOVINGBORDER*/