#include <jni.h>
#include "fractional_util.h"

extern "C"
JNIEXPORT jstring JNICALL Java_com_rbodai_fractions_MainActivity_produceFractionalResult(JNIEnv *env, jobject thiz, jstring fractional)
{
    std::string input(env->GetStringUTFChars(fractional, 0));
    try
    {
        return env->NewStringUTF(produce_fractional_result(input).c_str());
    }
    catch(const invalid_argument& e)
    {
        jclass exceptionClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exceptionClass, e.what());
        return nullptr;
    }
    catch(const runtime_error& e)
    {
        jclass exceptionClass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(exceptionClass, e.what());
        return nullptr;
    }
}