//
// Created by DarkSouls on 2018/4/13.
//
#include "ndk_deerclops_com_ndksample_HelloNdk.h"

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_sayHello(JNIEnv * env, jclass jclass1){
    return env->NewStringUTF("Hello Ndk!");
}

