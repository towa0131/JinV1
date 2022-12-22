#pragma once
#include <map>
#include <string>

class MapTranslator {
public:
    bool registerClass(const char* searge, const char* cls);

    bool registerMethod(const char* searge, const char* method, const char* desc);

    bool registerField(const char* searge, const char* field, const char* desc);

    const char *getClass(const char* cls);

    std::pair<const char*, const char*> getMethod(const char* method);

    std::pair<const char*, const char*> getField(const char* field);

private:
    std::map<std::string, std::string> classMapping;
    std::map<std::string, std::pair<const char*, const char*>> methodMapping;
    std::map<std::string, std::pair<const char*, const char*>> fieldMapping;
};