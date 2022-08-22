#include "movingborder.h"

auto constexpr borderlength = 10;

movingborder::movingborder()
{
    _borderheight = 26;
    _borderwidth = 26;
    _position = borderlength;
    addborder();
}

// OOP_3
movingborder::movingborder(int height, int width) 
    : _borderheight(height),
      _borderwidth(width){
    _position = borderlength;
    addborder();
}

movingborder::~movingborder()
{
}

movingborder::movingborder(const movingborder &source){
    _borderheight = source._borderheight;
    _borderwidth = source._borderwidth;
    _position = source._position;
    _speed = source._speed;
    _direction = source._direction;
    addborder();
}

movingborder::movingborder(movingborder &&source){
    _borderheight = source._borderheight;
    _borderwidth = source._borderwidth;
    _position = source._position;
    _speed = source._speed;
    _direction = source._direction;
    addborder();

    source._borderheight = 0;
    source._borderwidth = 0;
    source._position = 0;
    source._speed = 0;
    source._direction = Direction::kUp;
}

movingborder& movingborder::operator=(movingborder &source){
    if(&source == this)
        return *this;

    _borderheight = source._borderheight;
    _borderwidth = source._borderwidth;
    _position = source._position;
    _speed = source._speed;
    _direction = source._direction;
    addborder();

    return *this;    
}

movingborder& movingborder::operator=(movingborder &&source){
    if(&source == this)
        return *this;

    _borderheight = source._borderheight;
    _borderwidth = source._borderwidth;
    _position = source._position;
    _speed = source._speed;
    _direction = source._direction;
    addborder();

    source._borderheight = 0;
    source._borderwidth = 0;
    source._position = 0;
    source._speed = 0;
    source._direction = Direction::kUp;

    return *this;    
}

void movingborder::addborder(){
    SDL_Point point;

    m_movingborder_left.clear();
    for(int i=_position; i<_position+10; ++i){
        point.x = 0;
        point.y = i;

        m_movingborder_left.push_back(point);
    }

    m_movingborder_right.clear();
    for(int i=_position; i<_position+10; ++i){
        point.x = _borderwidth-1;
        point.y = i;

        m_movingborder_right.push_back(point);
    }
}

void movingborder::moveborder(){
    SDL_Point point;

    if(_speed == 10){
        _speed = 0;
        if((_position < (_borderheight-borderlength)) && (_direction == Direction::kUp)){
            _position++;
        }
        else if((_position > 0) && (_direction == Direction::kDown) ){
            _position--;
        }
        else if((_position+borderlength) == _borderheight){
            _direction = Direction::kDown;
            _position--;
        }
        else{
            _direction = Direction::kUp;
            _position++;
        }

        // ** Since using rule of 5, no need of below code **
        //moveborder_left(_position);
        //moveborder_right(_position);
    }
    else{
        _speed++;
    }
}

#if 0
void movingborder::moveborder_left(int position){
    SDL_Point point;

    m_movingborder_left.clear();
    for(int i=position; i<position+borderlength; ++i){
        point.x = 0;
        point.y = i;

        m_movingborder_left.push_back(point);
    }
}

void movingborder::moveborder_right(int position){
    SDL_Point point;

    m_movingborder_right.clear();
    for(int i=position; i<position+borderlength; ++i){
        point.x = _borderwidth-1;
        point.y = i;

        m_movingborder_right.push_back(point);
    }
}
#endif
bool movingborder::isSnakeBorderCollide(int x, int y){
    for(auto const &point : m_movingborder_left){
        if ((x == point.x) && (y == point.y))
            return true;
    }

    for(auto const &point : m_movingborder_right){
        if ((x == point.x) && (y == point.y))
            return true;
    }
    return false;
}

bool movingborder::isFoodBorderCollide(int x, int y){
    for(auto i=0; i<_borderheight; ++i){
        if ((x == 0) && (y == i))
            return true;
    }

    for(auto i=0; i<_borderheight; ++i){
        if ((x == _borderwidth) && (y == i))
            return true;
    }

    return false;
}