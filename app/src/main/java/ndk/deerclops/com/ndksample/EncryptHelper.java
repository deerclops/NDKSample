package ndk.deerclops.com.ndksample;

/**
 * Created by Deerclops on 2018/4/15 with joy.
 */
public class EncryptHelper {

    static {
        System.loadLibrary("Encrypt");
    }

    public static native String encrypt(String str, long length);

    public static native String decrypt(String str, long length);

}
