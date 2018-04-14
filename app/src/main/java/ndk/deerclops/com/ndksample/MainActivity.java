package ndk.deerclops.com.ndksample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        findViewById(R.id.tv).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                HelloNdk.callStaticMethod(777);

                new HelloNdk().callIntanceMethod(222);

                Toast.makeText(MainActivity.this, HelloNdk.sayHello(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}
