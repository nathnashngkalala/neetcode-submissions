class Solution {
public:
    /*
        you have positions and speed
        if we calcualte the time to get to target
        how does that work
        so if we know the time where a car can reach what does that mean
        if we sort by position in descending
        [4,1] [2,3] [2,0] -> target = 10
        if I know at the end of positioon and the net if the time for 
        the farther position < position - 1 then its a fleet 
        we then pop and push the next fleet if not we just push
        Now how do we find out the time? 
        time = target - position / speed -> do we know x
        
    */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        struct Car {
            Car(double t, int p, int s)
                :time(t),
                position(p),
                speed(s)
            {

            }
            double time;
            int position;
            int speed;
        };
        int n = position.size();
        vector<Car> cars;
        for(int i = 0 ; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back(Car(time, position[i], speed[i]));
        }   
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.position > b.position;
        });
        int res = 0;
        double curr = 0.0;
        for(int i = 0; i < n; ++i) {
            if(curr < cars[i].time) {
                //its a fleet 
                ++res;
                curr = cars[i].time;
            }
        }
        return res;
    }
};
