#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include "component.h"

class Topology {
private:
    string id;
    DeviceList devices;

public:
    Topology();
    Topology(string id);

    void setId(string newId);
    void addDevice(Component newDevices);

    string getId();
    DeviceList getDevices();

    // Destructor
    ~Topology();
};

typedef vector<Topology> TopologyList;

#endif //TOPOLOGY_H