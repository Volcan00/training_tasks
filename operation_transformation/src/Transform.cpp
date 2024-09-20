#include "Transform.h"

int Transform::operation(int a, int b)
{
    return a == b ? 0 : 1 + operation(a > b ? a >> 1 : a, a > b ? b : b >> 1);
}