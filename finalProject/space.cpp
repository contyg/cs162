//TODO: description
#include "space.hpp"
#include <iostream>

Space::Space()
{
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    type = "";
}

Space* Space::getTop()
{
    return top;
}

Space* Space::getBottom()
{
    return bottom;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getRight()
{
    return right;
}

string Space::getType()
{
    return type;
}

void Space::setType(string t)
{
    type = t;
}

void Space::setLinkedSpaces(Space* T, Space* B, Space* L, Space* R)
{
    top = T;
    bottom = B;
    left = L;
    right = R;
}
