#ifndef SAP_H
#define SAP_H

#include <vector>
using namespace std;

class SAP
{
    public:
        SAP(vector<int>, vector<int>, int);
        virtual ~SAP();
        void takeStep ();
    protected:
    private:
        vector<int> locXs; // lijst met alle x-waardes waar hij is geweest
        vector<int> locYs; // lijst met alle y-waardes waar hij is geweest
        int n; // hoe lang de SAP nog mag zijn
};

#endif // SAP_H
