#include <iostream>
using namespace std;

template <class T = char, int N = 8>
class Comunl {
    T bloque[N]; 
public:
    void set(int num, T tval); 
    T get(int num); 
};

template <class T, int N>
void Comunl<T, N>::set(int num, T tval) {
    bloque[num] = tval; 
}

template <class T, int N>
T Comunl<T, N>::get(int num) {
    return bloque[num]; 
}

int main() {
    Comunl<int, 5> objInt; 
    Comunl<double, 5> objFloat; 
    Comunl<> obj;

    objInt.set(0, 10); 
    objFloat.set(2, 3.1); 

    cout << objInt.get(0) << endl; 
    cout << objFloat.get(2) << endl; 
    cout << obj.get(4) << endl; 

    return 0;
}
