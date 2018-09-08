# ride-sharing-crp

Changes that need to be made:
1) Need to find a way to access the data structure of the road network
2) Need to improve the incident handling
3) Write unit tests for all modules
4) Write logic to find affected edges after an incident is acquired
5) Find a way to update the road network


Dependencies:
1) OSRM
2) Curl
3) Boost 1.59

How to build:
1) Build OSRM from source, see documentation site.
2) Build dependencies and libraries.
3) cd cmake
4) Run the command 'cmake ..'
5) Run the command 'make'
6) Run the program by the command './Ride-Sharing <configuration file path>'


----------------------------- Configuration File ----------------------------------
In order to run the simulation, the program must be passed a configuration file when run.

There needs to be several variables defined in the configuration file.  A variable is defined by a line having an '='.  Note that all variables are on there own line, and there is no way to have a multi-line variable.  Each variable should have a name (left side) and a value (right side).  Note that everything before the '=' sign on a line is a variable name, and everything after the '=' on a line is the value.  Qoutations should not be included unless the user want to include them in a variable name or value.  Note that spaces or other values are not discarded in assigning the variable name or value.

Variable Example:
VariableName=Value

The following is a list of the required variables to be present.

Required Variables:
TomTomAPI=Value

---------------------------- Processing Data ----------------------------------
Link for reference: https://github.com/Project-OSRM/osrm-backend/wiki/Running-OSRM

In order to run the simulation, first a road network must be downloaded then processed.
Download a map from http://download.geofabrik.de, then run the following commands.  The commands are used for the MLD (Multi-Level Dijkstra) configuration which improves performance in the event where continuous traffic updates are nesscary to represent the road network.
1) osrm-extract -p <path to car.lua> data.osm.pbf
2) osrm-partition data.osrm
3) osrm-customize data.osrm


------------------------- Unit Testing -------------------------------------------
Included in the UnitTest folder are a number of tests that can be used to debug and test portions of the program.  The following is a list of instructions for running the unit tests.
1) cd UnitTest
2) mkdir build
3) cd build
4) cmake ..
5) make
6) make test
