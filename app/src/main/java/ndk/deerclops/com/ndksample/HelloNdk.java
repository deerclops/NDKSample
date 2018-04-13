package ndk.deerclops.com.ndksample;

/**
 * Created by Deerclops on 2018/4/13 with joy.
 */
public class HelloNdk {

    static {
        System.loadLibrary("hello");
    }

    public static native String sayHello();
}
