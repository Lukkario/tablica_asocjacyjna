#include "atable.hpp"
#include <iostream>
#include <cstring>
using namespace std;


atable::atable()
{
  start = NULL;
  //wezel();
}

atable::atable(const atable& tablica)
{
  kopiuj(tablica);
}

atable::~atable()
{
  wyczysc();
}

void atable::wyczysc()
{
  if(start != NULL)
  {
    wezel* obecny,*nastepny;
    obecny = start;
    while(obecny != NULL)
    {
      nastepny = obecny->naprzod;
      delete obecny;
      obecny = nastepny;
    }
  }
}

void atable::wstaw(const char* klucz, int wartosc)
{
  wezel* nowy = new wezel(klucz);
  nowy->naprzod = start;
  nowy->wartosc = wartosc;
  start = nowy;
}

int& atable::znajdz(const char* klucz, bool wielkoscliter)
{
  wezel* pomoc = start;
  if(wielkoscliter)
  {
    while(pomoc)
    {
      if(!strcmp(klucz, pomoc->klucz))
        break;
      pomoc = pomoc->naprzod;
    }
  }
  else
  {
    while(pomoc)
    {
      if(!strcasecmp(klucz, pomoc->klucz))
        break;
      pomoc = pomoc->naprzod;
    }
  }
  if(!pomoc)
  {
    wstaw(klucz,0);
    pomoc = start;
  }
  return pomoc->wartosc;
}

void atable::kopiuj(const atable& tablica)
{
  wezel *zrodlo;
  wezel *cel;
  zrodlo = tablica.start;
  cel = new wezel(*zrodlo);
  start = cel;
  while(zrodlo)
  {
    zrodlo = zrodlo->naprzod;
    if(zrodlo == NULL)
    {
      cel->naprzod = NULL;
      break;
    }
    cel->naprzod = new wezel(*zrodlo);
    cel = cel->naprzod;
  }
}

atable& atable::operator= (const atable& tablica)
{
  if(this != &tablica)
  {
    wyczysc();
    kopiuj(tablica);
  }
  return *this;
}

int& atable::operator[](const char* klucz)
{
  return znajdz(klucz, true);
}

int& atableNNW::operator[](const char* klucz)
{
  return znajdz(klucz, false);
}
