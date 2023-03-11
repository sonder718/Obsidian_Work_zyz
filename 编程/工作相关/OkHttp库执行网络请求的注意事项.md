- 使用`enqueue()`方法在**后台线程中**执行网络请求操作。
- 在网络请求成功后，我们使用`runOnUiThread()`方法在UI线程中更新UI界面，避免了在主线程中执行网络请求操作的问题。
	- `runOnUiThread()`方法可以在**后台线程中执行一个Runnable对象**，并在UI线程中更新UI界面。它是Activity类中的一个方法，因此只能在Activity中使用
```java
public class MyActivity extends AppCompatActivity {
    private TextView mResultTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mResultTextView = findViewById(R.id.result_text_view);

        // 创建OkHttpClient实例
        OkHttpClient client = new OkHttpClient();

        // 创建Request对象
        Request request = new Request.Builder()
                .url("http://www.example.com/api/data")
                .build();

        // 创建Call对象，并执行网络请求操作
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                // 处理网络请求失败的情况
            }

            @Override
            public void onResponse(Call call, Response response) throws IOException {
                // 处理网络请求成功的情况
                final String result = response.body().string();
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        // 在UI线程中更新UI界面
                        mResultTextView.setText(result);
                    }
                });
            }
        });
    }
}

```