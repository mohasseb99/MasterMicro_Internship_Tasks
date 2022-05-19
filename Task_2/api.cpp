#include "api.h"
#include <fstream>

using json = nlohmann::json;

bool Api::readJSON(string FileName){
    // read json file in json object
    ifstream file(FileName);
    // checking if file read correctly or not
    if(file){
        json jsonFile = json::parse(file);
        // make topology object to store json object in it
        Topology topology;
        topology.setId(jsonFile["id"]);

        // iterate through every component in components (every component is json object)
        for(auto comp:jsonFile["components"]){
            Component device;
            device.setType(comp["type"]);
            device.setId(comp["id"]);
            // default, min and max are in internal object. every component has different name of object so we check on name of it first
            if(comp["type"] == "resistor") {
                device.setDefaultValue(comp["resistance"]["default"]);
                device.setMinValue(comp["resistance"]["min"]);
                device.setMaxValue(comp["resistance"]["max"]);
            }
            else if(comp["type"] == "nmos") {
                device.setDefaultValue(comp["m(l)"]["default"]);
                device.setMinValue(comp["m(l)"]["min"]);
                device.setMaxValue(comp["m(l)"]["max"]);
            }
            device.setNetlist(comp["netlist"]);
            topology.addDevice(device);
        }
        // push this topology in topologies list
        allTopology.push_back(topology);
        return true;
    }
    else{
        // if file is not opened successfully it return false
        return false;
    }
}

bool Api::writeJSON(string topologyID){
    Topology topology;

    bool found = false;
    for(auto &top:allTopology) {
        if (top.getId() == topologyID) {
            topology = top;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "This topology id is not in my list" << endl;
        return false;
    }


    json jsonFile;
    jsonFile["id"] = topology.getId();
    for(int i = 0; i < topology.getDevices().size(); i++){
        Component device = topology.getDevices()[i];
        jsonFile["components"][i]["type"] = device.getType();
        jsonFile["components"][i]["id"] = device.getId();
        if(device.getType() == "resistor") {
            jsonFile["components"][i]["resistance"]["default"] = device.getDefaultValue();
            jsonFile["components"][i]["resistance"]["min"] = device.getMinValue();
            jsonFile["components"][i]["resistance"]["max"] = device.getMaxValue();
        }
        else if(device.getType() == "nmos") {
            jsonFile["components"][i]["m(l)"]["default"] = device.getDefaultValue();
            jsonFile["components"][i]["m(l)"]["min"] = device.getMinValue();
            jsonFile["components"][i]["m(l)"]["max"] = device.getMaxValue();
        }
        jsonFile["components"][i]["netlist"] = device.getNetlist();
    }

    ofstream file("written_Json_file.json");
    file << jsonFile << "\n";
    return true;
}

TopologyList Api::queryTopologies(){
    return this->allTopology;
}

bool Api::deleteTopology(string topologyID){
    for(auto it = allTopology.begin(); it != allTopology.end(); it++){
        if(it->getId() == topologyID){
            allTopology.erase(it);
            return true;
        }
    }
    return false;
}

DeviceList Api::queryDevices(string topologyID){
    for(auto it = allTopology.begin(); it != allTopology.end(); it++){
        if(it->getId() == topologyID){
            return it->getDevices();
        }
    }
    return {};
}

DeviceList Api::queryDevicesWithNetlistNode(string topologyID, json NetlistNodeID){
    DeviceList devicesWithNode = {};
    for(int i=0; i < allTopology.size(); i++){

        if(allTopology[i].getId() == topologyID){
            Topology topo = allTopology[i];

            for(int j = 0; j < topo.getDevices().size(); j++){
                Component device = topo.getDevices()[j];
                json nets = device.getNetlist();

                for(auto &net : nets.items()){
                    if(net.key() == NetlistNodeID.items().begin().key() && net.value() == NetlistNodeID.items().begin().value()){
                        devicesWithNode.push_back(device);
                    }
                }

            }

        }

    }
    return devicesWithNode;
}