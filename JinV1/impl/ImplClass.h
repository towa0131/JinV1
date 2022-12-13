#pragma once
#include "../Core.h"
#include <iostream>

class ImplClass {
public:
    Core* core;
    jclass cls;

    ImplClass(Core *core, const char *className) {
        this->core = core;
        this->cls = getClass(className);

        if (this->cls == NULL) {
            std::cout << "[Error] Class Not Found : " << className << std::endl;
        } else {
            std::cout << "[Debug] Class : " << className << std::endl;
        }
    }

    jobject getClassLoader() {
        jclass launch = core->getEnv()->FindClass("net/minecraft/launchwrapper/Launch");
        jfieldID sfid = core->getEnv()->GetStaticFieldID(launch, "classLoader", "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
        jobject classLoader = core->getEnv()->GetStaticObjectField(launch, sfid);

        return classLoader;
    }

    jclass getClass(const char *clsName) {
        jstring name = core->getEnv()->NewStringUTF(clsName);
        std::cout << "[Debug] Loading class loader... ";
        jobject classLoader = getClassLoader();
        std::cout << "Loaded!" << std::endl;
        jmethodID mid = core->getEnv()->GetMethodID(core->getEnv()->GetObjectClass(classLoader), "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
        return (jclass)core->getEnv()->CallObjectMethod(classLoader, mid, name);
    }

    jmethodID getMethodID(const char *name, const char *sig) {
        return this->core->getEnv()->GetMethodID(this->cls, name, sig);
    }

    jmethodID getStaticMethodID(const char *name, const char *sig) {
        return this->core->getEnv()->GetStaticMethodID(this->cls, name, sig);
    }

    jfieldID getFieldID(const char* name, const char* sig) {
        return this->core->getEnv()->GetFieldID(this->cls, name, sig);
    }

    jfieldID getStaticFieldID(const char* name, const char* sig) {
        return this->core->getEnv()->GetStaticFieldID(this->cls, name, sig);
    }

    template <class T> jboolean getBoolean(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallBooleanMethod(parent, method, values); }
    template <class T> jboolean getBoolean(jmethodID method, T values...) { return this->core->getEnv()->CallStaticBooleanMethod(cls, method, values); }
    jboolean getBoolean(jobject parent, jmethodID method) { return this->core->getEnv()->CallBooleanMethod(parent, method); }
    jboolean getBoolean(jmethodID method) { return this->core->getEnv()->CallStaticBooleanMethod(cls, method); }
    jboolean getBoolean(jobject parent, jfieldID field) { return this->core->getEnv()->GetBooleanField(parent, field); }
    jboolean getBoolean(jfieldID field) { return this->core->getEnv()->GetStaticBooleanField(cls, field); }

    template <class T> jbyte getByte(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallByteMethod(parent, method, values); }
    template <class T> jbyte getByte(jmethodID method, T values...) { return this->core->getEnv()->CallStaticByteMethod(cls, method, values); }
    jbyte getByte(jobject parent, jmethodID method) { return this->core->getEnv()->CallByteMethod(parent, method); }
    jbyte getByte(jmethodID method) { return this->core->getEnv()->CallStaticByteMethod(cls, method); }
    jbyte getByte(jobject parent, jfieldID field) { return this->core->getEnv()->GetByteField(parent, field); }
    jbyte getByte(jfieldID field) { return this->core->getEnv()->GetStaticByteField(cls, field); }

    template <class T> jchar getChar(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallCharMethod(parent, method, values); }
    template <class T> jchar getChar(jmethodID method, T values...) { return this->core->getEnv()->CallStaticCharMethod(cls, method, values); }
    jchar getChar(jobject parent, jmethodID method) { return this->core->getEnv()->CallCharMethod(parent, method); }
    jchar getChar(jmethodID method) { return this->core->getEnv()->CallStaticCharMethod(cls, method); }
    jchar getChar(jobject parent, jfieldID field) { return this->core->getEnv()->GetCharField(parent, field); }
    jchar getChar(jfieldID field) { return this->core->getEnv()->GetStaticCharField(cls, field); }

    template <class T> jshort getShort(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallShortMethod(parent, method, values); }
    template <class T> jshort getShort(jmethodID method, T values...) { return this->core->getEnv()->CallStaticShortMethod(cls, method, values); }
    jshort getShort(jobject parent, jmethodID method) { return this->core->getEnv()->CallShortMethod(parent, method); }
    jshort getShort(jmethodID method) { return this->core->getEnv()->CallStaticShortMethod(cls, method); }
    jshort getShort(jobject parent, jfieldID field) { return this->core->getEnv()->GetShortField(parent, field); }
    jshort getShort(jfieldID field) { return this->core->getEnv()->GetStaticShortField(cls, field); }

    template <class T> jint getInt(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallIntMethod(parent, method, values); }
    template <class T> jint getInt(jmethodID method, T values...) { return this->core->getEnv()->CallStaticIntMethod(cls, method, values); }
    jint getInt(jobject parent, jmethodID method) { return this->core->getEnv()->CallIntMethod(parent, method); }
    jint getInt(jmethodID method) { return this->core->getEnv()->CallStaticIntMethod(cls, method); }
    jint getInt(jobject parent, jfieldID field) { return this->core->getEnv()->GetIntField(parent, field); }
    jint getInt(jfieldID field) { return this->core->getEnv()->GetStaticIntField(cls, field); }

    template <class T> jlong getLong(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallLongMethod(parent, method, values); }
    template <class T> jlong getLong(jmethodID method, T values...) { return this->core->getEnv()->CallStaticLongMethod(cls, method, values); }
    jlong getLong(jobject parent, jmethodID method) { return this->core->getEnv()->CallLongMethod(parent, method); }
    jlong getLong(jmethodID method) { return this->core->getEnv()->CallStaticLongMethod(cls, method); }
    jlong getLong(jobject parent, jfieldID field) { return this->core->getEnv()->GetLongField(parent, field); }
    jlong getLong(jfieldID field) { return this->core->getEnv()->GetStaticLongField(cls, field); }

    template <class T> jfloat getFloat(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallFloatMethod(parent, method, values); }
    template <class T> jfloat getFloat(jmethodID method, T values...) { return this->core->getEnv()->CallStaticFloatMethod(cls, method, values); }
    jfloat getFloat(jobject parent, jmethodID method) { return this->core->getEnv()->CallFloatMethod(parent, method); }
    jfloat getFloat(jmethodID method) { return this->core->getEnv()->CallStaticFloatMethod(cls, method); }
    jfloat getFloat(jobject parent, jfieldID field) { return this->core->getEnv()->GetFloatField(parent, field); }
    jfloat getFloat(jfieldID field) { return this->core->getEnv()->GetStaticFloatField(cls, field); }

    template <class T> jdouble getDouble(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallDoubleMethod(parent, method, values); }
    template <class T> jdouble getDouble(jmethodID method, T values...) { return this->core->getEnv()->CallStaticDoubleMethod(cls, method, values); }
    jdouble getDouble(jobject parent, jmethodID method) { return this->core->getEnv()->CallDoubleMethod(parent, method); }
    jdouble getDouble(jmethodID method) { return this->core->getEnv()->CallStaticDoubleMethod(cls, method); }
    jdouble getDouble(jobject parent, jfieldID field) { return this->core->getEnv()->GetDoubleField(parent, field); }
    jdouble getDouble(jfieldID field) { return this->core->getEnv()->GetStaticDoubleField(cls, field); }

    template <class T> jobject getObject(jobject parent, jmethodID method, T values...) { return this->core->getEnv()->CallObjectMethod(parent, method, values); }
    template <class T> jobject getObject(jmethodID method, T values...) { return this->core->getEnv()->CallStaticObjectMethod(cls, method, values); }
    jobject getObject(jobject parent, jmethodID method) { return this->core->getEnv()->CallObjectMethod(parent, method); }
    jobject getObject(jmethodID method) { return this->core->getEnv()->CallStaticObjectMethod(cls, method); }
    jobject getObject(jobject parent, jfieldID field) { return this->core->getEnv()->GetObjectField(parent, field); }
    jobject getObject(jfieldID field) { return this->core->getEnv()->GetStaticObjectField(cls, field); }

    void setBoolean(jobject parent, jfieldID field, jboolean value) { this->core->getEnv()->SetBooleanField(parent, field, value); }
    void setBoolean(jfieldID field, jboolean value) { this->core->getEnv()->SetStaticBooleanField(cls, field, value); }

    void setByte(jobject parent, jfieldID field, jbyte value) { this->core->getEnv()->SetByteField(parent, field, value); }
    void setByte(jfieldID field, jbyte value) { this->core->getEnv()->SetStaticByteField(cls, field, value); }

    void setChar(jobject parent, jfieldID field, jchar value) { this->core->getEnv()->SetCharField(parent, field, value); }
    void setChar(jfieldID field, jchar value) { this->core->getEnv()->SetStaticCharField(cls, field, value); }

    void setShort(jobject parent, jfieldID field, jshort value) { this->core->getEnv()->SetShortField(parent, field, value); }
    void setShort(jfieldID field, jshort value) { this->core->getEnv()->SetStaticShortField(cls, field, value); }

    void setInt(jobject parent, jfieldID field, jint value) { this->core->getEnv()->SetIntField(parent, field, value); }
    void setInt(jfieldID field, jint value) { this->core->getEnv()->SetStaticIntField(cls, field, value); }

    void setLong(jobject parent, jfieldID field, jlong value) { this->core->getEnv()->SetLongField(parent, field, value); }
    void setLong(jfieldID field, jlong value) { this->core->getEnv()->SetStaticLongField(cls, field, value); }

    void setFloat(jobject parent, jfieldID field, jfloat value) { this->core->getEnv()->SetFloatField(parent, field, value); }
    void setFloat(jfieldID field, jfloat value) { this->core->getEnv()->SetStaticFloatField(cls, field, value); }

    void setDouble(jobject parent, jfieldID field, jdouble value) { this->core->getEnv()->SetDoubleField(parent, field, value); }
    void setDouble(jfieldID field, jdouble value) { this->core->getEnv()->SetStaticDoubleField(cls, field, value); }

    void setObject(jobject parent, jfieldID field, jobject value) { this->core->getEnv()->SetObjectField(parent, field, value); }
    void setObject(jfieldID field, jobject value) { this->core->getEnv()->SetStaticObjectField(cls, field, value); }
};