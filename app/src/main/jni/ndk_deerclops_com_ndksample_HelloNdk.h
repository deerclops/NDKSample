/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ndk_deerclops_com_ndksample_HelloNdk */

#ifndef _Included_ndk_deerclops_com_ndksample_HelloNdk
#define _Included_ndk_deerclops_com_ndksample_HelloNdk
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_sayHello
  (JNIEnv *, jclass);

/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    callStaticMethod
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__I
  (JNIEnv *, jclass, jint);

/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    callStaticMethod
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callStaticMethod__JLjava_lang_String_2
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    callIntanceMethod
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    callIntanceMethod
 * Signature: (Ljava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_callIntanceMethod__Ljava_lang_String_2J
  (JNIEnv *, jobject, jstring, jlong);

/*
 * Class:     ndk_deerclops_com_ndksample_HelloNdk
 * Method:    makeCrash
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ndk_deerclops_com_ndksample_HelloNdk_makeCrash
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
