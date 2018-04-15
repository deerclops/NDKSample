package ndk.deerclops.com.ndksample;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.AppCompatEditText;
import android.support.v7.widget.AppCompatTextView;
import android.text.TextUtils;
import android.widget.Toast;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

/**
 * Created by Deerclops on 2018/4/15 with joy.
 */
public class EncryptActivity extends AppCompatActivity {

    @BindView(R.id.et_str_not_encrypted)
    AppCompatEditText et;
    @BindView(R.id.tv)
    AppCompatTextView tv;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_encrypt);
        ButterKnife.bind(this);
    }

    private StringBuilder str = new StringBuilder();

    @OnClick(R.id.btn_encrypt)
    public void encryptStr() {
        str.delete(0, str.length());
        if (TextUtils.isEmpty(str.append(et.getText()))) {
            return;
        }
        String encrypt = EncryptHelper.encrypt(str.toString(), str.length());
        tv.append("加密后的字符串为：");
        tv.append(encrypt);
    }

    @OnClick(R.id.btn_decrypt)
    public void decryptStr() {
        if (str.length() == 0) {
            return;
        }
        Toast.makeText(this, EncryptHelper.decrypt(str.toString(), str.length()), Toast.LENGTH_SHORT).show();
    }
}
