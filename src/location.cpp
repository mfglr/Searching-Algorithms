#include <math.h>
#include "location.h"

double searching_algorithms::Location::oklid(searching_algorithms::Location *a,searching_algorithms::Location *b){
    return sqrt( pow( a->getLat() - b->getLat(), 2 ) + pow( a->getLon() - b->getLon(),2 ) );
}