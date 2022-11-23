//
// Created by chh3213 on 2022/11/23.
//

// osqp-eigen
#include "OsqpEigen/OsqpEigen.h"

// eigen
#include <Eigen/Dense>
#include <iostream>

int main()
{
    // allocate QP problem matrices and vectores
    Eigen::SparseMatrix<double> hessian(2, 2);      //P: n*n正定矩阵,必须为稀疏矩阵SparseMatrix
    Eigen::VectorXd gradient(2);                    //Q: n*1向量
    Eigen::SparseMatrix<double> linearMatrix(2, 2); //A: m*n矩阵,必须为稀疏矩阵SparseMatrix
    Eigen::VectorXd lowerBound(2);                  //L: m*1下限向量
    Eigen::VectorXd upperBound(2);                  //U: m*1上限向量

    hessian.insert(0, 0) = 2.0; //注意稀疏矩阵的初始化方式,无法使用<<初始化
    hessian.insert(1, 1) = 2.0;
    // std::cout << "hessian:" << std::endl
    //           << hessian << std::endl;
    gradient << -2, -2;
    linearMatrix.insert(0, 0) = 1.0; //注意稀疏矩阵的初始化方式,无法使用<<初始化
    linearMatrix.insert(1, 1) = 1.0;
    // std::cout << "linearMatrix:" << std::endl
    //           << linearMatrix << std::endl;
    lowerBound << 1, 1;
    upperBound << 1.5, 1.5;

    // instantiate the solver
    OsqpEigen::Solver solver;

    // settings
    solver.settings()->setVerbosity(false);
    solver.settings()->setWarmStart(true);

    // set the initial data of the QP solver
    solver.data()->setNumberOfVariables(2);   //变量数n
    solver.data()->setNumberOfConstraints(2); //约束数m
    if (!solver.data()->setHessianMatrix(hessian))
        return 1;
    if (!solver.data()->setGradient(gradient))
        return 1;
    if (!solver.data()->setLinearConstraintsMatrix(linearMatrix))
        return 1;
    if (!solver.data()->setLowerBound(lowerBound))
        return 1;
    if (!solver.data()->setUpperBound(upperBound))
        return 1;

    // instantiate the solver
    if (!solver.initSolver())
        return 1;

    Eigen::VectorXd QPSolution;

    // solve the QP problem
    if (!solver.solve())
    {
        return 1;
    }

    QPSolution = solver.getSolution();
    std::cout << "QPSolution" << std::endl
              << QPSolution << std::endl; //输出为m*1的向量
    return 0;
}
