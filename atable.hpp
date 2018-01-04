#ifndef _ATABLE_HPP_
#define _ATABLE_HPP_
#include <cstring>

class atable {
protected:
  struct wezel{
    wezel* naprzod;
    char* klucz;
    int wartosc;
    wezel(const char* nowy_klucz)
    {
      naprzod = NULL;
      klucz = new char[strlen(nowy_klucz)+1];
      strcpy(klucz,nowy_klucz);
    }
    wezel(const wezel& w){
      if(w.naprzod==NULL) naprzod=NULL;
      else{
        klucz=new char[strlen(w.klucz)+1];
        strcpy(w.klucz,klucz);
      }
      wartosc = w.wartosc;
    }
    ~wezel()
    {
      delete[] klucz;
    }
  };
  wezel* start;
  int& znajdz(const char*, bool);
private:
  void wstaw(const char*, int);
  void wyczysc();
  void kopiuj(const atable&);
public:
  atable();
  atable(const atable&);
  ~atable();
  atable& operator= (const atable&);
  int& operator[](const char*);
};

class atableNNW: public atable
{
public:
  atableNNW(): atable() {}
  atableNNW(const atable& tablica): atable(tablica) {}
  int& operator[](const char*);
};

#endif
