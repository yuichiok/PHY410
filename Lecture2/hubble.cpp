#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int n = 24;   // number of galaxies in Table 1

double r[n] = {     // distances in Mpc
    0.032, 0.034, 0.214, 0.263, 0.275, 0.275, 0.45, 0.5, 0.5, 0.63, 0.8,
    0.9, 0.9, 0.9, 0.9, 1.0, 1.1, 1.1, 1.4, 1.7, 2.0, 2.0, 2.0, 2.0
};

double v[n] = {     // velocities in km/s
    +170, +290, -130, -70,  -185, -220, +200, +290, +270, +200, +300, -30,
    +650, +150, +500, +920, +450, +500, +500, +960, +500, +850, +800, +1090
};

double average(std::vector<double> *group){
    
    int size = 0;
    double sum,avg = 0;
    size = group->size();
    
    for (int n = 0; n < size; n++) {
        
        sum += group->at(n);
        
    }
    
    avg = sum / size;
    
    return avg;
    
}





int main() {
    
    std::vector<double> gr1,gr2,gr3,gr4,gr5,gr6,gr7,gr8,gr9;
    std::vector<double> gv1,gv2,gv3,gv4,gv5,gv6,gv7,gv8,gv9;
    std::vector<double> grR,grV;
    
    // declare and initialize various sums to be computed
    double s_x = 0, s_y = 0, s_xx = 0, s_xy = 0;
    int m = 0.;
    double sumr1 = 0, sumr2 = 0, sumr3 = 0;
    double sumv1 = 0, sumv2 = 0, sumv3 = 0;
    
    if ( n < 2 ) {
        cout << "Error! Need at least two data points!" << endl;
        return 0;
    }
    
    int temp1 =0, temp2 =0;
    
    
    // compute the sums
    for (int i = 0; i < n; i++) {
        
        if(r[i]<0.1){
            gr1.push_back(r[i]);
            gv1.push_back(v[i]);
        }else if(r[i]>0.1 && r[i]<0.22){
            gr2.push_back(r[i]);
            gv2.push_back(v[i]);
        }else if(r[i]>0.22 && r[i]<0.4){
            gr3.push_back(r[i]);
            gv3.push_back(v[i]);
        }else if(r[i]>0.4 && r[i]<0.6){
            gr4.push_back(r[i]);
            gv4.push_back(v[i]);
        }else if(r[i]>0.6 && r[i]<0.7){
            gr5.push_back(r[i]);
            gv5.push_back(v[i]);
        }else if(r[i]>0.7 && r[i]<=0.9){
            gr6.push_back(r[i]);
            gv6.push_back(v[i]);
        }else if(r[i]>0.9 && r[i]<=1.){
            gr7.push_back(r[i]);
            gv7.push_back(v[i]);
        }else if(r[i]>1. && r[i]<=1.5){
            gr8.push_back(r[i]);
            gv8.push_back(v[i]);
        }else if(r[i]>1.5 && r[i]<=2.0){
            gr9.push_back(r[i]);
            gv9.push_back(v[i]);
        }
        
        
        if(i<=11){
            sumr1 += r[i];
            sumv1 += v[i];
            temp1 += 1;
        }else if(i>11){
            sumr2 += r[i];
            sumv2 += v[i];
            temp2 += 1;
        }
        
        sumr3 += r[i];
        sumv3 += v[i];
        
        /*
        if(  ){
            s_x += r[i];
            s_y += v[i];
            s_xx += r[i] * r[i];
            s_xy += r[i] * v[i];
            m += 1;
        }
         */
    }
    
    
    //very domb way of writing code...
    grR.push_back(average(&gr1));
    grR.push_back(average(&gr2));
    grR.push_back(average(&gr3));
    grR.push_back(average(&gr4));
    grR.push_back(average(&gr5));
    grR.push_back(average(&gr6));
    grR.push_back(average(&gr7));
    grR.push_back(average(&gr8));
    grR.push_back(average(&gr9));
    //grR.push_back(sumr2/temp2);
    //grR.push_back(sumr3/24);
    
    grV.push_back(average(&gv1));
    grV.push_back(average(&gv2));
    grV.push_back(average(&gv3));
    grV.push_back(average(&gv4));
    grV.push_back(average(&gv5));
    grV.push_back(average(&gv6));
    grV.push_back(average(&gv7));
    grV.push_back(average(&gv8));
    grV.push_back(average(&gv9));
    //grV.push_back(sumv1/temp1);
    //grV.push_back(sumv3/24);

    for (int j=0; j < 9; j++) {
        
        std::cout << grR.at(j) << std::endl;
        
        s_x += grR.at(j);
        s_y += grV.at(j);
        s_xx += grR.at(j) * grR.at(j);
        s_xy += grR.at(j) * grV.at(j);
    }
    
    
    m = 9;
    
    
    
    cout << s_x << " " << s_y << " " << s_xx << " " << s_xy << endl;
    
    // evaluate least-squares fit forumlas
    double denom = m * s_xx - s_x * s_x;
    
    if ( fabs(denom) < 0.000001 ) {
        cout << "Error! Denominator is zero!" << endl;
        return 0;
    }
    
    double a = (s_xx * s_y - s_x * s_xy) / denom;
    double b = (m * s_xy - s_x * s_y) / denom;
    
    cout << denom << " " << a << " " << b << " " << m << endl;
    
    // estimate the variance in the data set
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double v_of_r_i = a + b * r[i];
        double error = v[i] - v_of_r_i;
        sum += error * error;
    }
    
    double sigma = (m > 2) ? sqrt(sum / (m - 2)) : 0;    // estimate of error bar in v
    
    // estimate errors in a and b
    double sigma_a = sqrt(sigma * sigma * s_xx / denom);
    double sigma_b = sqrt(sigma * sigma * m / denom);
    
    // print results
    cout.precision(4);
    cout << " Least-squares fit of " << m << " data points\n"
    << " -----------------------------------\n"
    << " Hubble's constant slope   b  =  " << b
    << " +- " << sigma_b << " km/s/Mpc\n"
    << " Intercept with r axis     a  =  " << a
    << " +- " << sigma_a << " km/s\n"
    << " Estimated v error bar sigma  =  " << sigma << " km/s" << endl;
}
