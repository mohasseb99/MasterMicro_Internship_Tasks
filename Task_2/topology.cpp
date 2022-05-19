#include "topology.h"

Topology::Topology(){}

Topology::Topology(string id){this->id = id;}

void Topology::setId(string newId){this->id = newId;}

void Topology::addDevice(Component newDevice){this->devices.push_back(newDevice);}

string Topology::getId(){return this->id;}

DeviceList Topology::getDevices(){return this->devices;}

// Destructor
Topology::~Topology(){}