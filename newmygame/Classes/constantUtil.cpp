//
//  constantUtil.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-07.
//
//

#include "constantUtil.h"

#include <stdio.h>
static Constant* sharedConst = NULL;

Constant * Constant::getInstance(){
    if (sharedConst == NULL){
        sharedConst = new Constant;
    }
    return sharedConst;
}

Constant::Constant()
{
    sharedConst = this;
    level = 0;
    ppt=0;
    lecture=0;
    lectureNo=0;
    extendEffect=0;
    extendEffectNo=0;
    machineID=0;
}

Constant::~Constant()
{
    sharedConst = NULL;
}

