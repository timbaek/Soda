#include <iostream>
using namespace std;					// direct access to std
#include "MPRNG.h"
#include <cstdlib>					// exit
#include "config.h"
#include "printer.h"

// global definition
MPRNG mprng;

void usage( char * argv[] ) {
    cerr << "Usage: " << argv[0]
	 << " [ config-file [ Seed ] ]" << endl;
    exit( EXIT_FAILURE );				// TERMINATE
} // usage

int main( int argc, char * argv[] ) {
    istream * infile = &cin;				// default value
    ostream * outfile = &cout;

    string configFile = "soda.config";
    int seed = getpid(),
        processors = 1;

    try {
        switch ( argc ) {
            case 3: 
                configFile = string( argv[2] );
            case 2: 
                seed = stoi( argv[1] );
                if ( seed <= 0 ) throw 1; 
            case 1:
                break;
            default: 					// wrong number of options
                throw 1;
        } // switch
    } catch (...) {
        usage(argv);
    } // try
    mprng.set_seed(seed);
    if ( 1 < processors ) {
        uProcessor p[processors - 1] __attribute__(( unused ));
    }

    ConfigParms config;
    processConfigFile( configFile.c_str(), config );

    Printer printer( config.numStudents, config.numVendingMachines, config.numCouriers );

    if ( infile != &cin ) delete infile;		// close file, do not delete cin!
    if ( outfile != &cout ) delete outfile;		// close file, do not delete cout!
} // main