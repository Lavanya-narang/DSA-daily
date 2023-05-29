class ParkingSystem {
public:
int a[3];
    ParkingSystem(int big, int medium, int small) 
    {
        a[0]=big;
        a[1]=medium;
        a[2]=small;
    }
    
    bool addCar(int carType) 
    {
        carType--;
        if(a[carType]>0)
        {
            a[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
