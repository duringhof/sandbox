/** 
 * Write a function 'filter()' that implements a multi-
 *   dimensional Kalman Filter for the example given
 */

#include <iostream>
#include <vector>
#include "Eigen/Dense"

// Kalman Filter variables
Eigen::VectorXd x;	// object state
Eigen::MatrixXd P;	// object covariance matrix
Eigen::VectorXd u;	// external motion
Eigen::MatrixXd F; // state transition matrix
Eigen::MatrixXd H;	// measurement matrix
Eigen::MatrixXd R;	// measurement covariance matrix
Eigen::MatrixXd I; // Identity matrix
Eigen::MatrixXd Q;	// process covariance matrix

std::vector<Eigen::VectorXd> measurements;
void filter(Eigen::VectorXd &x, Eigen::MatrixXd &P);

int main() {

  // design the KF with 1D motion
  x = Eigen::VectorXd(2);
  x << 0, 0;

  P = Eigen::MatrixXd(2, 2);
  P << 1000, 0, 0, 1000;

  u = Eigen::VectorXd(2);
  u << 0, 0;

  F = Eigen::MatrixXd(2, 2);
  F << 1, 1, 0, 1;

  H = Eigen::MatrixXd(1, 2);
  H << 1, 0;

  R = Eigen::MatrixXd(1, 1);
  R << 1;

  I = Eigen::MatrixXd::Identity(2, 2);

  Q = Eigen::MatrixXd(2, 2);
  Q << 0, 0, 0, 0;
  
  // create a list of measurements
  Eigen::VectorXd single_meas(1);
  single_meas << 1;
  measurements.push_back(single_meas);
  single_meas << 2;
  measurements.push_back(single_meas);
  single_meas << 3;
  measurements.push_back(single_meas);

  // call Kalman filter algorithm
  filter(x, P);

  return 0;
}

void filter(Eigen::VectorXd &x, Eigen::MatrixXd &P) {

  for (unsigned int n = 0; n < measurements.size(); ++n) {

    Eigen::VectorXd z = measurements[n];
    
    // KF Measurement update step
    Eigen::VectorXd y = z - (H * x);
    Eigen::MatrixXd S = H * P * H.transpose() + R;
    Eigen::MatrixXd K = P * H.transpose() * S.inverse();

    // new state
    x << x + (K * y);
    P << (I - (K * H)) * P;

    // KF Prediction step
    x << (F * x) + u;
    P << F * P * F.transpose();
		
    std::cout << "x=" << std::endl <<  x << std::endl;
    std::cout << "P=" << std::endl <<  P << std::endl;
  }
}