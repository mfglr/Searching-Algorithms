#ifndef LOCATION_H
#define LOCATION_H
namespace searching_algorithms{
    class Location {
        private :
            double lat;
            double lon;
        public :
            Location(double lat,double lon){ this->lat = lat; this->lon = lon; }
            double getLat(){ return lat; }
            double getLon(){ return lon; }
            static double oklid(Location *a,Location *b);
    };
}

#endif