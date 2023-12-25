#ifndef LOCATION_H
#define LOCATION_H
#include <math.h>
class Location {
    private :
        double lat;
        double lon;
    public :
        Location(double lat,double lon){ this->lat = lat; this->lon = lon; }
        double getLat(){ return lat; }
        double getLon(){ return lon; }
        double oklid(Location *l){
            return sqrt(pow(lat - l->getLat(),2) + pow(lon - l->getLon(),2));
        }
};
#endif