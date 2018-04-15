package ndk.deerclops.com.ndksample;

/**
 * Created by Deerclops on 2018/4/15 with joy.
 */
public class HiNdk {

    static {
        System.loadLibrary("hi");
    }

    public static native String getStrFromC();
}
