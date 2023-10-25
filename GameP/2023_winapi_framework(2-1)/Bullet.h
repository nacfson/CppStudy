#pragma once
#include "Object.h"
class Bullet :
    public Object
{
public :
    virtual void Update() override;
private:
    float m_fSpeed;
    float m_fDir;
    float m_fXScale;
    float m_fYScale;
};

