#ifndef DZ_3_LANGUAGE_H
#define DZ_3_LANGUAGE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Language {
    string code;
public:
    virtual void compile();
    void add_line(string line);
};


class Python : public Language{
    string code;

public:
    Python(string & code);
    ~Python();
    void compile() override;
};

class C: public Language{
    string code;

public:
    C(string & code);
    ~C();
    void compile();
};

class Kotlin : public Language {
    string code;

public:
    Kotlin(string & code);
    ~Kotlin();
    void compile() override;
};

#endif
