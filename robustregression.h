#ifndef ROBUSTREGRESSION_H
#define ROBUSTREGRESSION_H
#include "csvreader.h"
#include <armadillo>
#include "lsregression.h"
#include "regression.h"

class robustregression: public regression
{
public:
    robustregression();
    robustregression(csvReader read);
    robustregression(LSregression LSR);
    void setLSR(LSregression LSR);
    bool setT(double t);
    bool solve();
    LSregression* getInitial();

private:
    LSregression initial;
    double t = 2;
    arma::mat generateW(arma::mat beta, double t );
};

#endif // ROBUSTREGRESSION_H
