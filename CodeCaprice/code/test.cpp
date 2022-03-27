#include<bits/stdc++.h>
using namespace std;

class A {
  public:
    virtual int get_v() {return v;}

  private:
    int v = 10;
};

int main() {
    A* a = new A();
    memset(a, 0, sizeof(A));
    cout << a->get_v() << endl;
    delete a;
}; 