#pragma once
#include "Object.h"
class Enemy :
    public Object
{
private:

    int m_health = 3;



public:
    using Object::Object;

    void TakeDamage();
    void Destroy();

    void StartContact(Object* other) override;
    void EndContact(Object* other) override;

};

