class DiningPhilosophers {
private:
    mutex mtx;
    condition_variable cv[5];
    bool forkFree[5];

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            forkFree[i] = true;
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        unique_lock<mutex> lock(mtx);

        cv[philosopher].wait(lock, [&]() {
            return forkFree[left] && forkFree[right];
        });

        forkFree[left] = false;
        forkFree[right] = false;

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        forkFree[left] = true;
        forkFree[right] = true;

        cv[left].notify_one();
        cv[right].notify_one();
    }
};