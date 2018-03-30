#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Incident Storage Test
#include <boost/test/included/unit_test.hpp>

#include "../../json.hpp"
#include "../../incident.h"
#include "../../incident_storage.h"
Incident TEST_INCIDENT = Incident("europe_CLUSTER_11_-1540737434", "", "", "", 518277.0,
                         6852207.0, 9, 1, 1620, -1);

BOOST_AUTO_TEST_CASE( Test_StoreIncidents )
{
  IncidentStorage IS = IncidentStorage();
}
