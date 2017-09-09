#include "tomtom_api.h"
#include "pull_updates.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
    if(argc != 1){
        cout<<"Error: no additional parmeter functionality has been defined."<<endl;
        cout<<argv<<endl;
    }

    // First initalization of curl, only needs to be done once
    curl_global_init(CURL_GLOBAL_ALL);

    PullUpdates* P = new PullUpdates();
    TomTomAPI* T = new TomTomAPI("8274p6y8umxn4tey9jrr6tqh");

    P->load_api(T);
    P->pull_updates();
    P->print_updates();


    return 0;
}