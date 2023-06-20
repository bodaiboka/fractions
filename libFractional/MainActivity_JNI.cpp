#include <jni.h>
#include "fractional_util.h"

extern "C"
JNIEXPORT jstring JNICALL Java_com_rbodai_fractions_MainActivity_produceFractionalResult(JNIEnv *env, jobject thiz, jstring fractional)
{
    std::string input(env->GetStringUTFChars(fractional, 0));
    return env->NewStringUTF(produce_fractional_result(input).c_str());
}