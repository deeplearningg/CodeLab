#include <cstddef> // NULL
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

class gps_position
{
    friend std::ostream & operator<<(std::ostream &os, const gps_position &gp);
    friend class boost::serialization::access;
    int degrees;
    int minutes;
    float seconds;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
        ar & degrees & minutes & seconds;
    }
public:
    // every serializable class needs a constructor
    gps_position(){};
    gps_position(int _d, int _m, float _s) :
        degrees(_d), minutes(_m), seconds(_s)
    {}
    void display_gps() const{
        std::cout << degrees << "\t" << minutes << "\t" << seconds << std::endl;
    }
};
std::ostream & operator<<(std::ostream &os, const gps_position &gp)
{
    return os << ' ' << gp.degrees << (unsigned char)186 << gp.minutes << '\'' << gp.seconds << '"';
}
int main() {
    // create and open a character archive for output
    std::ofstream ofs("filename");

    // create class instance
    const gps_position g(35, 59, 24.567f);

    // save data to archive
    {
        boost::archive::text_oarchive oa(ofs);
        // write class instance to archive
        oa << g;
    	// archive and stream closed when destructors are called
    }

    // ... some time later restore the class instance to its orginal state
    gps_position newg;
    {
        // create and open an archive for input
        std::ifstream ifs("filename");
        boost::archive::text_iarchive ia(ifs);
        // read class state from archive
        ia >> newg;
        // archive and stream closed when destructors are called
    }
    g.display_gps();
    newg.display_gps();
    return 0;
}
