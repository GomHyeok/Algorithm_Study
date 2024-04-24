#include <iostream>

using namespace std;

class Rectangle {
    private :
        int a;

    protected:
        int b;
    public:
        Rectangle() : a(20), b(10) {
            
        }

        Rectangle(int a) : a(a){}

        virtual int c() const {
            return 0;
        }
};

class B : public Rectangle {
    private :
        int b;
    public :
        B() : b(15) {

        }

        B(int a) : b(a) {

        }

        B(int a, int b) : Rectangle(a), b(b) {}

        virtual int c() const {
            return b;
        }
};

int main() {
    B re;

    int a = re.c();
    cout<<a<<endl;
}