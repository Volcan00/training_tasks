#ifndef DIGITAL_ROOT_H
#define DIGITAL_ROOT_H

int digitalRoot(int n)
{
    if (n < 10)
        return n;

    int result {};

    while(n > 0)
    {
        result += n % 10;
        n /= 10;
    }

    return digitalRoot(result);
}

#endif