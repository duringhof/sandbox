#include <iostream>
#include "Eigen/Dense"
#include "ukf.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main() {

  // Create a UKF instance
  UKF ukf;

  //MatrixXd Xsig = MatrixXd(5, 11);
  //ukf.GenerateSigmaPoints(&Xsig);

  //MatrixXd Xsig_aug = MatrixXd(7, 15);
  //ukf.AugmentedSigmaPoints(&Xsig_aug);

  //MatrixXd Xsig_pred = MatrixXd(15, 5);
  //ukf.SigmaPointPrediction(&Xsig_pred);

  VectorXd x_pred = VectorXd(5);
  MatrixXd P_pred = MatrixXd(5, 5);
  ukf.PredictMeanAndCovariance(&x_pred, &P_pred);

  // print result
  // std::cout << "Xsig = " << std::endl << Xsig << std::endl;
  // std::cout << "Xsig_aug = " << std::endl << Xsig_aug << std::endl;
  // std::cout << "Xsig_pred = " << std::endl << Xsig_pred << std::endl;

  std::cout << "Predicted state" << std::endl;
  std::cout << x_pred << std::endl;
  std::cout << "Predicted covariance matrix" << std::endl;
  std::cout << P_pred << std::endl;

  return 0;
}