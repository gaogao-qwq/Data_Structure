/* https://leetcode.cn/problems/design-parking-system/ */
#include "LC.h"

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(big == 0) return false;
            big--;
            return true;
        }
        if(carType == 2) {
            if(medium == 0) return false;
            medium--;
            return true;
        }
        if(carType == 3) {
            if(small == 0) return false;
            small--;
            return true;
        }
        return false;
    }
    private:
    int big;
    int medium;
    int small;
};

int main(void) {
    int big = 1, medium = 1, small = 0;
    int carType[5] = {1,2,3,3,3};
    ParkingSystem* obj = new ParkingSystem(big, medium, small);
    for(auto i : carType) {
        cout << obj->addCar(i);
    }
    return 0;
}