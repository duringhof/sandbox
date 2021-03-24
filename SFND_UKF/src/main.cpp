#include <iostream>
#include "Eigen/Dense"
#include "ukf.h"

using Eigen::MatrixXd;

int main() {

  // Create a UKF instance
  UKF ukf;

  //MatrixXd Xsig = MatrixXd(5, 11);
  //ukf.GenerateSigmaPoints(&Xsig);

  //MatrixXd Xsig_aug = MatrixXd(7, 15);
  //ukf.AugmentedSigmaPoints(&Xsig_aug);

  MatrixXd Xsig_pred = MatrixXd(15, 5);
  ukf.SigmaPointPrediction(&Xsig_pred);

  // print result
  // std::cout << "Xsig = " << std::endl << Xsig << std::endl;
  // std::cout << "Xsig_aug = " << std::endl << Xsig_aug << std::endl;
  std::cout << "Xsig_pred = " << std::endl << Xsig_pred << std::endl;

  return 0;
}