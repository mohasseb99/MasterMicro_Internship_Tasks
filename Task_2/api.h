//
// Created by Mohasseb on 5/14/2022.
//

#ifndef API_H
#define API_H

# include <iostream>
#include "topology.h"
class Api {
private:
    TopologyList allTopology;

public:
    bool readJSON(string FileName);

    bool writeJSON(string topologyID);

    TopologyList queryTopologies();

    bool deleteTopology(string topologyID);

    DeviceList queryDevices(string topologyID);

    DeviceList queryDevicesWithNetlistNode(string topologyID, nlohmann::json NetlistNodeID);
};
#endif //API_H
