#include <bits/stdc++.h>
using namespace std;



class FooBar {
public:
    int n;
public:
    FooBar(int n) {
        this->n = n;
    }
    void foo() {
        for (int i = 0; i < n; i++) {
            cout << "foo";
        }
    }
    void bar() {
        for (int i = 0; i < n; i++) {
            cout << "bar";
        }
    }
    
};

int main() {
    FooBar* obj = new FooBar(5);
    thread thread1(bind(&FooBar::foo, &obj));
    thread thread2(bind(&FooBar::bar, &obj));
    thread1.join();
    thread2.join();
    return 0;
}