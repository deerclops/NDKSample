//
// Created by DarkSouls on 2018/4/15.
//
#include "ndk_deerclops_com_ndksample_HiNdk.h"
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "from C", __VA_ARGS__))

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_HiNdk_getStrFromC
        (JNIEnv *env, jclass jclass1) {
    LOGI("test log on c");
    jstring str_test = (*env)->NewStringUTF(env, "ha ha I am C");

    jclass class_hello_ndk = (*env)->FindClass(env, "ndk/deerclops/com/ndksample/HelloNdk");
    jmethodID method_log_msg = (*env)->GetStaticMethodID(env, class_hello_ndk, "logMsg",
                                                         "(Ljava/lang/String;)V");
    (*env)->CallStaticVoidMethod(env, class_hello_ndk, method_log_msg, str_test);

    return str_test;
}
