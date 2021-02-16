# 多线程

## 线程类 thread



```cpp
void func1() {
    cout << "1" << endl;
}

void test() {
    //创建 一个线程
	thread* t = new thread(func1);
    //等待线程结束
	t->join();
}
```



