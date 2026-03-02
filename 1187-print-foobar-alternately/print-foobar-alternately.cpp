class FooBar {
private:
    int n;
    bool state;
    mutex mtx;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        this->state = false;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return state== false;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return state== true;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state = false;
            cv.notify_all();
        }
    }
};