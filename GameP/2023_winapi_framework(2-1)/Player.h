#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    virtual void Update() override;
    //virtual void Render(HDC _dc) override;
};
