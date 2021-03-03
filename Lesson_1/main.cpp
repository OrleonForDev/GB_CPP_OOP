#include <iostream>
#include <cstdint>

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
    }


};
int main() {
    Power power;
    power.SetA(5.6f);
    power.SetB(3.8f);

    std::cout << power.Calculate() << std::endl;

    RGBA rgba(128, 128, 0, 100);
    rgba.Print();


    return 0;
}
