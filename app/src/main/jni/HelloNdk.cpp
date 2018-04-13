//
// Created by DarkSouls on 2018/4/13.
//
#include "ndk_deerclops_com_ndksample_HelloNdk.h"
#include <android/log.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "nate", __VA_ARGS__))

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_sayHello(JNIEnv * env, jclass jclass1){
    LOGI("this is from C");
    return env->NewStringUTF("Hello Ndk!");
}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__I
        (JNIEnv * env, jclass jclass1, jint i){

}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__JLjava_lang_String_2
        (JNIEnv * env, jclass jclass1, jlong jlong1, jstring jstring1){

}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__I
        (JNIEnv * env, jobject jobject1, jint jint1){

}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__Ljava_lang_String_2J
        (JNIEnv * env, jobject jobject1, jstring jstring1, jlong jlong1){

}

