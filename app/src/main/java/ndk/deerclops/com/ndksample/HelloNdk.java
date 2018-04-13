package ndk.deerclops.com.ndksample;

import android.util.Log;

/**
 * Created by Deerclops on 2018/4/13 with joy.
 */
public class HelloNdk {

    static {
        System.loadLibrary("hello");
    }

    public static native String sayHello();

    public static void logMsg(String data) {
        Log.d("nate", data);
    }

    public static void staticMethod(String data) {
        logMsg(data);
    }

    public static native void callStaticMethod(int i);

    public static native void callStaticMethod(long l, String str);

    public native void callIntanceMethod(int i);

    public native void callIntanceMethod(String str, long i);
}
