#include <iostream>
#include <iomanip>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    void tick() {
        ++second;

        if (second >= 60) {
            second = 0;
            ++minute;

            if (minute >= 60) {
                minute = 0;
                ++hour;

                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << std::setfill('0') << std::setw(2) << time.hour << ":"
           << std::setw(2) << time.minute << ":" << std::setw(2) << time.second;
        return os;
    }
};

int main() {
    Time time(23, 59, 59);

    for (int i = 0; i < 5; ++i) {
        time.tick();
        std::cout << "Current time: " << time << std::endl;
    }

    return 0;
}
