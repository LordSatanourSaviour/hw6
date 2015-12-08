#include <iostream>
#include <fstream>

using namespace std;


void Kvalues( double* K, double* y,double const a, double const b, double const c); // function to evaluate K_i


int main(){
    
   
    
    int const N = 1000000;
    double const dt = 0.0001;
    
    const string t = to_string(dt);
    const string filename = "data_lorenz" "_" + t + ".txt";
    ofstream out(filename.c_str());
    
    double K1[3]; // make K_i
    double K2[3];
    double K3[3];
    double K4[3];
    double r[3], temp[3];
    
    double const a = 10;
    double const b = 28;
    double const c = 8/3;
    
    r[0] = 1; // initial conditions
    r[1] = 1;
    r[2] = 1;

    for (int i=0; i<N; i++) {
    
        out << i*dt << "\t" << r[0] << "\t" << r[1] << "\t" << r[2] << endl;

    
        Kvalues( K1, r, a, b, c);
        
        temp[0] = r[0] + (dt/2)* K1[0]; // new input for K_i is calculated
        temp[1] = r[1] + (dt/2)* K1[1];
        temp[2] = r[2] + (dt/2)* K1[2];
        
        Kvalues( K2, temp, a, b, c);
        
        temp[0] = r[0] + (dt/2)* K2[0];
        temp[1] = r[1] + (dt/2)* K2[1];
        temp[2] = r[2] + (dt/2)* K2[2];
        
        Kvalues( K3, temp, a, b, c);
        
        temp[0] = r[0] + dt* K3[0];
        temp[1] = r[1] + dt* K3[1];
        temp[2] = r[2] + dt* K3[2];
        
        Kvalues( K4, temp, a, b, c);
        
        r[0] = r[0] + (dt/6.0)*(K1[0] + 2*K2[0] + 2*K3[0] + K4[0]); // trajectories
        r[1] = r[1] + (dt/6.0)*(K1[1] + 2*K2[1] + 2*K3[1] + K4[1]);
        r[2] = r[2] + (dt/6.0)*(K1[2] + 2*K2[2] + 2*K3[2] + K4[2]);
    
}
    
    out.close();
    return 0;
}






void Kvalues(double* K, double* y, double const a, double const b, double const c){
   
    K[0] = a*(y[1]-y[0]);
    K[1] = y[0]*(b-y[2]) - y[1];
    K[2] = y[0]*y[1] - c*y[2];
    
    
    
    
}