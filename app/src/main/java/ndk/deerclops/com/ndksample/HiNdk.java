package ndk.deerclops.com.ndksample;

import java.util.ArrayList;

import ndk.deerclops.com.ndksample.entity.SampleEntity;

/**
 * Created by Deerclops on 2018/4/15 with joy.
 */
public class HiNdk {

    static {
        System.loadLibrary("hi");
    }

    public static native String getStrFromC();

    public static native SampleEntity transferFromStruct();

    public static native ArrayList<SampleEntity> getSampleArrayList();

    public static native void printStruct();
}
