//
// Created by DarkSouls on 2018/4/15.
//
#include "ndk_deerclops_com_ndksample_HiNdk.h"
#include <android/log.h>
#include "test_add.h"
#include "fun/add_two.h"
#include <stdbool.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "from C", __VA_ARGS__))

JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_HiNdk_getStrFromC
        (JNIEnv *env, jclass jclass1) {
    LOGI("test log on c");
    jstring str_test = (*env)->NewStringUTF(env, "ha ha I am C");

    jclass class_hello_ndk = (*env)->FindClass(env, "ndk/deerclops/com/ndksample/HelloNdk");
    jmethodID method_log_msg = (*env)->GetStaticMethodID(env, class_hello_ndk, "logMsg",
                                                         "(Ljava/lang/String;)V");
    (*env)->CallStaticVoidMethod(env, class_hello_ndk, method_log_msg, str_test);

    jint int_result = add(3, 5);
    LOGI("add result is %d", int_result);

    jint int_result2 = add_two(4);
    LOGI("after add 2, the result is %d", int_result2);

    return str_test;
}

typedef struct Sample {
    char str[30];
    int i;
    bool signal;
    char c;
} SampleStruct;

//const SampleStruct s1 = {"s1", 11, false, 'f'};
//const SampleStruct s2 = {"s2", 44, true, 'H'};
//const SampleStruct s3 = {"s3", 77, false, 'U'};

#define ARRAY_LENGTH 3

SampleStruct *create_several_samples() {
    SampleStruct array_sample[ARRAY_LENGTH] = {{"s1", 11, false, 'f'},
                                               {"s2", 44, true,  'H'},
                                               {"s3", 77, false, 'U'}};
    SampleStruct *point_sample = array_sample;
    return point_sample;
}

jobject get_obj_from_struct(JNIEnv *env, SampleStruct *s) {
    jclass class_sample = (*env)->FindClass(env, "ndk/deerclops/com/ndksample/entity/SampleEntity");
    jmethodID method_id_sample_construct = (*env)->GetMethodID(env, class_sample, "<init>",
                                                               "(Ljava/lang/String;IZC)V");

    jstring arg_str = (*env)->NewStringUTF(env, (*s).str);
    jint arg_integer = (*s).i;
    jboolean arg_boolean = (*s).signal ? true : false;

    return (*env)->NewObject(env, class_sample, method_id_sample_construct, arg_str, (*s).i,
                             (*s).signal, (*s).c);
}

void print_struct(SampleStruct ss) {
    LOGI("String:%s, int:%d, bool:%d , char:%c", ss.str, ss.i, ss.signal, ss.c);
}

JNIEXPORT jobject JNICALL Java_ndk_deerclops_com_ndksample_HiNdk_transferFromStruct
        (JNIEnv *env, jclass jclass1) {
    SampleStruct sample = {
            "this is a str",
            120,
            true,
            'x'
    };
    print_struct(sample);
    return get_obj_from_struct(env, &sample);
}

JNIEXPORT jobject JNICALL Java_ndk_deerclops_com_ndksample_HiNdk_getSampleArrayList
        (JNIEnv *env, jclass jclass1) {
    SampleStruct *point = create_several_samples();

    jclass class_array_list = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID method_id_construct = (*env)->GetMethodID(env, class_array_list, "<init>", "()V");
    jobject array_list = (*env)->NewObject(env, class_array_list, method_id_construct);
    jmethodID method_id_add = (*env)->GetMethodID(env, class_array_list, "add",
                                                  "(Ljava/lang/Object;)Z");

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        LOGI("loop i==%d", i);
        jobject element = get_obj_from_struct(env, (SampleStruct *) (point + i));
        (*env)->CallBooleanMethod(env, array_list, method_id_add, element);
    }

    return array_list;
}

JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HiNdk_printStruct
        (JNIEnv *env, jclass jclass1) {
    SampleStruct *point = create_several_samples();

//    print_struct(point[0]);
//    print_struct(point[1]);
//    print_struct(point[2]);

    LOGI("String:%s", point[0].str);
    LOGI("String:%s", point[1].str);
    LOGI("String:%s", point[2].str);

//    LOGI("String:%s, int:%d, bool:%d , char:%c", point[0].str, point[0].i, point[0].signal, point[0].c);
//    LOGI("String:%s, int:%d, bool:%d , char:%c", point[1].str, point[1].i, point[1].signal, point[1].c);
//    LOGI("String:%s, int:%d, bool:%d , char:%c", point[2].str, point[2].i, point[2].signal, point[2].c);

//    for (int i = 0; i < ARRAY_LENGTH; ++i) {
//        print_struct(&(point[i]));
//    }
}

