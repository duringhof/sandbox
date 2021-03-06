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

  //VectorXd x_pred = VectorXd(5);
  //MatrixXd P_pred = MatrixXd(5, 5);
  //ukf.PredictMeanAndCovariance(&x_pred, &P_pred);

  //VectorXd z_out = VectorXd(3);
  //MatrixXd S_out = MatrixXd(3, 3);
  //ukf.PredictRadarMeasurement(&z_out, &S_out);

  VectorXd x_out = VectorXd(5);
  MatrixXd P_out = MatrixXd(5, 5);
  ukf.UpdateState(&x_out, &P_out);

  // print result
  // std::cout << "Xsig = " << std::endl << Xsig << std::endl;
  // std::cout << "Xsig_aug = " << std::endl << Xsig_aug << std::endl;
  // std::cout << "Xsig_pred = " << std::endl << Xsig_pred << std::endl;
  // std::cout << "Predicted state" << std::endl;
  // std::cout << x_pred << std::endl;
  // std::cout << "Predicted covariance matrix" << std::endl;
  // std::cout << P_pred << std::endl;
  // std::cout << "z_pred: " << std::endl << z_out << std::endl;
  // std::cout << "S: " << std::endl << S_out << std::endl;

  std::cout << "Updated state x: " << std::endl << x_out << std::endl;
  std::cout << "Updated state covariance P: " << std::endl << P_out << std::endl;

  return 0;
}