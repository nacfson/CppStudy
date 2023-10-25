#pragma once
#include "Object.h"
class Monster :
    public Object
{
public:
    void Update() override;
public:
        Monster();
        ~Monster();
public:
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMaxDis(float _f) { m_fMaxDis = _f; }
    const float& GetSpeed() const { return m_fSpeed; }
private:
    int m_hp;//체력
    Vec2 m_vCenterPos; //중심 위치
    float m_fMaxDis; //최대 거리
    float m_fSpeed; //스피드
    float m_fDir; //방향 (-1: left, 1: right)
};

