#ifndef __MAP_H__
#define __MAP_H__

#include "cocos2d.h"

#include "Cell.h"

class GameManager;
class MapData;

class Map : public cocos2d::CCLayer
{
public:
    virtual ~Map() {}

    virtual bool init();

    GameManager *gameManager;

    int GetHeight();
    int GetWidth();

    Cell ***cells;

    CREATE_FUNC(Map);

    /////////////////////////////////////////////////////////////
    // Neighbor cells on different directions
    //     _1_                              _4_
    //  6 /   \ 2 (windows form app)     5 /   \ 3 (phone app)
    //  5 \___/ 3                        6 \___/ 2
    //      4                                1
    /////////////////////////////////////////////////////////////
    Cell* Neighbor(const Cell &cell, const DIRECTION dir);

    bool isNeighbor(const Cell &cellA, const Cell &cellB);

    void Reset(const MapData &mapData);  

    static bool IsOdd(const int num);

    cocos2d::CCPoint GetCellOriginalPos(const Cell &cell);

    cocos2d::CCPoint GetCellOriginalPos(const int row, const int col);

    static cocos2d::CCPoint CalcCellPositionByIndex(const int row, const int cow);

    virtual void onEnter();

    void update(float dt);

    unsigned long GetTimer();

    static DIRECTION OppositeDirection(DIRECTION dir);

    void MarkResolvingInDirection(Cell *start, DIRECTION dir);
    void MarkResolvingWideInDirection(Cell *start, DIRECTION dir);
    void MarkResolvingSurrounding(Cell *center);
    void MarkResolvingColor(const GemColor color);

    void GetSurroundings(const Cell *center, Cell *(&surroundings)[6]);

    GemColor S5TargetColor;

private:
    int height;
    int width;

    unsigned int timer;

    Cell* N1(const Cell &cell);
    Cell* N2(const Cell &cell);
    Cell* N3(const Cell &cell);
    Cell* N4(const Cell &cell);
    Cell* N5(const Cell &cell);
    Cell* N6(const Cell &cell);

    void ReadMapData(const MapData &mapData);
    void InitializeMap(const MapData &mapData);
    void InitializeColor();
    void InitializeCellsPos();

    cocos2d::CCPoint ***pos; // position infomation
};

#endif