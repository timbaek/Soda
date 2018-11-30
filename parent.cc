#include "parent.h"
#include "printer.h"
#include "MPRNG.h"

using namespace std;

extern MPRNG mprng;

Parent::Parent( Printer & prt, Bank & bank, unsigned int numStudents, unsigned int parentalDelay )
        : printer(prt), bank(bank), numStudents(numStudents), parentalDelay(parentalDelay) {

}

Parent::~Parent() {

}

void Parent::main() {
    while (true) {
        _Accept( ~Parent ) {
            break;
        } _Else {
            unsigned int money = mprng(1, 3);
            unsigned int student = mprng( numStudents - 1 );

            yield( parentalDelay );

            bank.deposit( student, money );
        } // 
    } // while
}