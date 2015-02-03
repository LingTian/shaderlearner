//
//  constantUtil.h
//  mygame
//
//  Created by WU XIAO on 2014-12-07.
//
//

#ifndef mygame_constantUtil_h
#define mygame_constantUtil_h
#include "cocos2d.h"

#include <iostream>
class Constant
{
    
public:
    Constant();
    ~Constant();
    
public:
    int level;
    int ppt;
    int lecture;
    int lectureNo;
    int extendEffect;
    int extendEffectNo;
    int machineID;
    //machineID 0: iPadMini
    //machineID 1: iPhone5/5s
    //machineID 2: iPhone4/4s
    //machineID 3: iPhone6
    //machineID 4: iPhone6p
    
public:
    static Constant * getInstance(void);
};

#endif
