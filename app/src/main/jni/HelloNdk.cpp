//
// Created by DarkSouls on 2018/4/13.
//
#include "ndk_deerclops_com_ndksample_HelloNdk.h"
#include <stdio.h>
#include <stdlib.h>

#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "nate", __VA_ARGS__))

JNIEXPORT jstring JNICALL
Java_ndk_deerclops_com_ndksample_HelloNdk_sayHello(JNIEnv *env, jclass jclass1) {
    LOGI("this is from C");
    return env->NewStringUTF("Hello Ndk!");
}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__I
        (JNIEnv *env, jclass jclass1, jint i) {
    jclass cls_hello = env->FindClass("ndk/deerclops/com/ndksample/HelloNdk");
    if (cls_hello == NULL) {
        return;
    }
    LOGI("class found");
    jmethodID mth_static_method = env->GetStaticMethodID(cls_hello, "staticMethod",
                                                         "(Ljava/lang/String;)V");
    if (mth_static_method == NULL) {
        return;
    }
    LOGI("method found");

    jfieldID fld_name = env->GetStaticFieldID(cls_hello, "name", "Ljava/lang/String;");
    if (fld_name == NULL) {
        return;
    }
    jstring new_name = env->NewStringUTF("this is a new name");
    env->SetStaticObjectField(cls_hello, fld_name, new_name);
    LOGI("filed name is set a new value");

    jstring data = env->NewStringUTF("call static method");
    if (data == NULL) {
        return;
    }
    LOGI("str is created");
    env->CallStaticVoidMethod(cls_hello, mth_static_method, data);

    LOGI("method is called");
    // release
    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(data);
}

JNIEXPORT void JNICALL
Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__JLjava_lang_String_2
        (JNIEnv *env, jclass jclass1, jlong jlong1, jstring jstring1) {

}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__I
        (JNIEnv *env, jobject jobject1, jint jint1) {
    jclass cls_hello = env->FindClass("ndk/deerclops/com/ndksample/HelloNdk");
    if (cls_hello == NULL) {
        return;
    }
    jmethodID mtd_method = env->GetMethodID(cls_hello, "method", "(Ljava/lang/String;)V");
    if (mtd_method == NULL) {
        return;
    }

    // create Hello obj
    jmethodID mtd_construct = env->GetMethodID(cls_hello, "<init>", "()V");
    if (mtd_construct == NULL) {
        return;
    }
    jobject hello = env->NewObject(cls_hello, mtd_construct, NULL);
    if (hello == NULL) {
        return;
    }
//    jstring msg = env->NewStringUTF("call instance method");
//    env->CallVoidMethod(hello, mtd_method, msg);

    jfieldID fld_address = env->GetFieldID(cls_hello, "address", "Ljava/lang/String;");
    if (fld_address == NULL) {
        return;
    }
    env->SetObjectField(hello, fld_address, env->NewStringUTF("this is a new address"));

    env->CallVoidMethod(hello, mtd_method, env->GetObjectField(hello, fld_address));

//    env->DeleteLocalRef(msg);
    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(hello);
}

JNIEXPORT void JNICALL
Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__Ljava_lang_String_2J
        (JNIEnv *env, jobject jobject1, jstring jstring1, jlong jlong1) {

}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_makeCrash(JNIEnv * env, jclass jclass){
    env = NULL;
    env->NewStringUTF("here is a crash");
}

