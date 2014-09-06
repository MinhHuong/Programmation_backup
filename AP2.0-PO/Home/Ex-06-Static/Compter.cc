#include "Compter.h"
#include <iostream>

using namespace std;

int Compter::_comp = 0;

Compter::Compter()
{
  _comp++;
}

Compter::~Compter()
{
  _comp--;
}

int Compter::getCompter()
{
  return _comp;
}
