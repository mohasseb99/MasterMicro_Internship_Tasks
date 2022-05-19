#include "topology.h"
#include "api.h"

Api api;

void Testing_readJson();
void Testing_writeJSON();
void Testing_queryDevices();
void Testing_queryDevicesWithNetlistNode();
void Testing_deleteTopology();

int main(){
    Testing_readJson();
    Testing_writeJSON();
    Testing_queryDevices();
    Testing_queryDevicesWithNetlistNode();
    Testing_deleteTopology();
}

void Testing_readJson(){
    string FileName = "C:/Users/Mohasseb/Desktop/MasterMicro_Internship/Task_2/topology.json";
    // here we check if readJSON return true
    // if returned true that means JSON is read successfully
    if(api.readJSON(FileName)){
        cout << "read JSON file successfully passed" << endl;
    }
    else{
        cout << "JSON File is not load successfully" << endl;
        cout << "Please check that if file path is correct or not" << endl;
    }
}

void Testing_writeJSON(){
    // here we check whether json file wrote successfully or not
    if(api.writeJSON("top1")){
        cout << "JSON file is written successfully" << endl;
    }
    else{
        cout << "JSON file is not written successfully" << endl;
    }
}

void Testing_queryDevices(){
    DeviceList devices = api.queryDevices("top1");
    if(devices.size() == 2 && devices[0].getId() == "res1" && devices[1].getId() == "m1"){
        cout << "queryDevices() is passed successfully" << endl;
    }
    else{
        cout << "queryDevices() is not passed successfully" << endl;
    }
}

void Testing_queryDevicesWithNetlistNode(){
    nlohmann::json jsonNode;
    jsonNode["drain"] = "n1";
    DeviceList  devicesWithNode = api.queryDevicesWithNetlistNode("top1", jsonNode);
    if(devicesWithNode[0].getId() == "m1"){
        cout << "queryDevicesWithNetlistNode is passed successfully" << endl;
    }
    else{
        cout << "queryDevicesWithNetlistNode is not passed successfully" << endl;
    }
}

void Testing_deleteTopology(){
    if(api.deleteTopology("top1") && api.queryTopologies().size() == 0){
        cout << "deleteTopology() is passed successfully" << endl;
    }
    else{
        cout << "deleteTopology() is not passed successfully" << endl;
    }
}