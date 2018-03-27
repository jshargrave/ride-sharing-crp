#include <stdexcept>
#include <string>

using namespace std;

// ------------------------ incident_storage Exceptions ---------------------
class IncIDDoesNotExist: public std::runtime_error
{
  public:
    IncIDDoesNotExist(string const& msg): runtime_error(msg){}
};
