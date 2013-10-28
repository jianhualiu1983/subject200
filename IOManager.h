#ifndef __IOMANAGER_H__
#define __IOMANAGER_H__

#include "cocos2d.h"

class GameManager;
class Cell;

class MapData
{
public:
    int height;
    int width;
    int bit;
};

class IOManager : public cocos2d::CCLayer
{
public:
    GameManager *gameManager;

    virtual ~IOManager() {}

    CREATE_FUNC(IOManager);

    Cell *selectedCell;

    virtual bool init();

    MapData *mapData;

    MapData *GetMapData();

    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent  *event) override;
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent  *event) override;
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent  *event) override;
};

#endif
