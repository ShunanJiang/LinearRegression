#ifndef REGRESSION_H
#define REGRESSION_H
#include "csvreader.h"
#include <armadillo>
#include <sstream>

class regression
{
public:
    regression();
    regression(csvReader read);
    bool setDataSource(csvReader read);

    bool set(std::vector<int> listOfSelected,int y);

    arma::mat CookMeasure();
    std::string getSummary();
    std::string getWarning();
    arma::mat getX();
    arma::mat getY();
    arma::mat getHat();
    arma::mat getbetaHat();
    arma::mat getYHat();
    arma::mat getResidual();
    csvReader getReader();
    int getN();
    int getK();
    double getRSquare();
    double getRadjSquare();
    virtual bool solve() = 0;
    std::stringstream printSummary();

protected:
    csvReader reader;
    arma::mat data;
    arma::mat X,Y;
    arma::mat betaHat, Hat, YHat, residual, CookResiduals;
    int n,k;
    double SSR,SSres,MSres,SStotal,meanY,RSquare,RadjSquare;
    std::string warning;
};

#endif // REGRESSION_H