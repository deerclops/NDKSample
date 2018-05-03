package ndk.deerclops.com.ndksample.entity;

/**
 * Created by Deerclops on 2018/4/16 with joy.
 */
public class SampleEntity {

    private String mStr;
    private int mInteger;
    private boolean mBoolean;
    private char mChar;

    public SampleEntity(String mStr, int mInteger, boolean mBoolean, char mChar) {
        this.mStr = mStr;
        this.mInteger = mInteger;
        this.mBoolean = mBoolean;
        this.mChar = mChar;
    }

    @Override
    public String toString() {
        return "str:" + mStr + "\ninteger:" + mInteger + "\nboolean:" + mBoolean + "\nchar" + mChar;
    }
}
