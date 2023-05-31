class ParkingSystem {
private:
	int big;
	int medium;
	int small;
	int countB;
	int countM;
	int countS;

public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
		this->medium = medium;
		this->small = small;
		this->countB = 0;
		this->countM = 0;
		this->countS = 0;
    }

    bool addCar(int carType) {
        switch(carType) {
			case 1:
				if (countB < big) {
					countB++;
					return true;
				} else {
					return false;
				}
			case 2:
				if (countM < medium) {
					countM++;
					return true;
				} else {
					return false;
				}
			case 3:
				if (countS < small) {
					countS++;
					return true;
				} else {
					return false;
				}
		}
		return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
