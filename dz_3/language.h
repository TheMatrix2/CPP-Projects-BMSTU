#ifndef DZ_3_LANGUAGE_H
#define DZ_3_LANGUAGE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Language {
public:
    virtual void compile();
};


class Python : public Language{
    string filename;

public:
    Python(string filename);
    ~Python();
    void compile() override;
};

class C: public Language{
    string filename;

public:
    C(string filename);
    ~C();
    void compile();
};

#endif
