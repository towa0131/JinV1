#pragma once
#include "MapTranslator.h"

bool MapTranslator::registerClass(const char* searge, const char* cls) {
    if (this->classMapping.find(std::string(cls)) == this->classMapping.end()) {
        this->classMapping.insert(std::make_pair(std::string(cls), std::string(searge)));
        return true;
    }
    return false;
}

bool MapTranslator::registerMethod(const char* searge, const char* method, const char* desc) {
    if (this->methodMapping.find(std::string(method)) == this->methodMapping.end()) {
        this->methodMapping.insert(std::make_pair(std::string(method), std::make_pair(searge, desc)));
        return true;
    }
    return false;
}

bool MapTranslator::registerField(const char* searge, const char* field, const char* desc) {
    if (this->fieldMapping.find(std::string(field)) == this->fieldMapping.end()) {
        this->fieldMapping.insert(std::make_pair(std::string(field), std::make_pair(searge, desc)));
        return true;
    }
    return false;
}

const char* MapTranslator::getClass(const char* cls) {
    if (this->classMapping.find(std::string(cls)) == this->classMapping.end()) {
        return cls;
    }
    return this->classMapping.at(std::string(cls)).c_str();
}

std::pair<const char*, const char*> MapTranslator::getMethod(const char* method) {
    return this->methodMapping.at(std::string(method));
}

std::pair<const char*, const char*> MapTranslator::getField(const char* field) {
    return this->fieldMapping.at(std::string(field));
}