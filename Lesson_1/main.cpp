#include <iostream>
#include <cstdint>
#include <exception>

/*WELL DONE*/

class Power{
private:
    float a = 0.0f;
    float b = 0.0f;
public:
    void SetA(float aVal) {
        a = aVal;
    }

    void SetB(float bVal) {
        b = bVal;
    }

    float Calculate() const{
        if (b == 0){
            return 1.0f;
        }
        return pow(a,b);
    }

};

class RGBA{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
   explicit RGBA(uint8_t mRed, uint8_t mGreen, uint8_t mBlue, uint8_t mAlpha) : m_red(mRed), m_green(mGreen), m_blue(mBlue),
                                                                        m_alpha(mAlpha) {}

    void Print() const{
        std::cout << "Red: " << m_red
                  << "Green: " << m_green
                  << "Blue: " << m_blue
                  << "Alpha: " << m_alpha << std::endl;
        
        //https://stackoverflow.com/questions/19562103/uint8-t-cant-be-printed-with-cout
    }


};

class Stack{
private:
    int mas[10];
    int length = 0;
public:
    void Reset(){
        length = 0;
        for (int& m : mas) {
            m = 0;
        }
        
        //https://en.cppreference.com/w/cpp/string/byte/memset
    }

    bool Push(int val){
        if(length < 10){
            mas[length] = val;
            ++length;
            return true;
        }
        return false;
    }

    int Pop(){
        if (length == 0){
            throw std::out_of_range("Stack is empty");
        }
        else{
            return mas[--length];
        }
    }

    void Print() const{
        std::cout << "( ";
        for (int i = 0; i < length; ++i) {
            std::cout << mas[i] << ' ';
        }
        std::cout << " )" << std::endl;
    }
};

int main() {
    //Task1
    Power power;
    power.SetA(5.6f);
    power.SetB(3.8f);
    std::cout << power.Calculate() << std::endl;

    //Task2
    RGBA rgba(128, 128, 0, 100);
    rgba.Print();

    //Task3
    Stack stack;
    stack.Push(56);
    std::cout << stack.Pop() << std::endl;

    for (int i = 0; i < 10; ++i) {
        stack.Push(i*i);
    }

    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;

    stack.Print();

    stack.Reset();
    stack.Print();


    return 0;
}
