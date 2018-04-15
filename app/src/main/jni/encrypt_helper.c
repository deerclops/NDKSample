//
// Created by DarkSouls on 2018/4/15.
//
#include <jni.h>
#include <string.h>
#include <malloc.h>
#include "ndk_deerclops_com_ndksample_EncryptHelper.h"

char *Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass class_string = (*env)->FindClass(env, "java/lang/String");
    jstring str_encode = (*env)->NewStringUTF(env, "GB2312");

    jmethodID method_get_bytes = (*env)->GetMethodID(env, class_string, "getBytes",
                                                     "(Ljava/lang/String;)[B");
    jbyteArray byte_array = (*env)->CallObjectMethod(env, jstr, method_get_bytes, str_encode);

    jsize array_length = (*env)->GetArrayLength(env, byte_array);
    jbyte *byte_address = (*env)->GetByteArrayElements(env, byte_array, JNI_FALSE);

    if (array_length > 0) {
        rtn = (char *) malloc(array_length + 1);
        memcpy(rtn, byte_address, array_length);
        rtn[array_length] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, byte_array, byte_address, 0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_EncryptHelper_encrypt
        (JNIEnv *env, jclass jclass1, jstring str, jlong length) {
    char *c_str = Jstring2CStr(env, str);
    for (int i = 0; i < length; ++i) {
        *(c_str + i) += 1;
    }
    return (*env)->NewStringUTF(env, c_str);
}

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_EncryptHelper_decrypt
        (JNIEnv *env, jclass jclass1, jstring str, jlong length) {
    char *c_str = Jstring2CStr(env, str);
    for (int i = 0; i < length; ++i) {
        *(c_str + i) -= 1;
    }
    return (*env)->NewStringUTF(env, c_str);
}



