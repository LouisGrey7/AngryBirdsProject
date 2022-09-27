#pragma once
#include <iostream>

#include "Object.h"
class Enemy :
    public Object
{
private:




public:
    int m_health = 3;
    using Object::Object;

    void TakeDamage();
    void Destroy();

    void StartContact(Object* other) override;
    void EndContact(Object* other) override;

};

