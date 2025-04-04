#include "Account.h"




int main() {

    // Account a(); // The most vexing parse. Tries to declare a function a that returns Account.
    Account a;

    a.withdraw(50);

    Account b("Janne", 9142221);

    Account c(b);

    return 0;
}