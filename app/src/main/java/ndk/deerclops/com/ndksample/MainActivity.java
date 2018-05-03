package ndk.deerclops.com.ndksample;

import android.content.Intent;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import java.util.ArrayList;

import butterknife.ButterKnife;
import butterknife.OnClick;
import ndk.deerclops.com.ndksample.entity.SampleEntity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
    }

    private void toast(String str) {
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }

    @OnClick(R.id.tv)
    public void testNdkOfCPlusPlus() {
        HelloNdk.callStaticMethod(777);

        new HelloNdk().callIntanceMethod(222);
        toast(HelloNdk.sayHello());
    }

    @OnClick(R.id.tv_make_crash)
    public void makeCrashOfCPlusPlus() {
        HelloNdk.makeCrash();
    }

    @OnClick(R.id.tv_hi_c)
    public void testNdkOfC() {
        toast(HiNdk.getStrFromC());
    }

    @OnClick(R.id.btn_jump)
    public void jump() {
        ActivityCompat.startActivity(this, new Intent(this, EncryptActivity.class), null);
    }

    @OnClick(R.id.btn_struct)
    public void testStruct() {
        SampleEntity sampleEntity = HiNdk.transferFromStruct();
        if (sampleEntity == null) {
            Log.d("nate", "return a null obj");
        } else {
            Log.d("nate", sampleEntity.toString());
        }
    }

    @OnClick(R.id.btn_struct_2_array)
    public void testStruct2ArrayList() {
        ArrayList<SampleEntity> sampleArrayList = HiNdk.getSampleArrayList();
        if (sampleArrayList != null && !sampleArrayList.isEmpty()) {
            Log.d("nate", "result arraylist is not empty!!!");
            Log.d("nate", sampleArrayList.toString());
        }
    }

    @OnClick(R.id.btn_print_struct)
    public void printStruct() {
        HiNdk.printStruct();
    }
}
