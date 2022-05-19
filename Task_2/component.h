#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <map>
#include <vector>
#include "json.hpp"

using namespace std;

class Component{
private:
    string type;
    string id;

    float defaultValue;
    float minValue;
    float maxValue;

    nlohmann::json netlist;

public:
    // constructor
    Component();
    Component(string type, string id, float defaultValue, float minValue, float maxValue, nlohmann::json netlist);

    // setters methods
    void setType(string newType);
    void setId(string newId);
    void setDefaultValue(float newDefaultValue);
    void setMinValue(float newMinValue);
    void setMaxValue(float newMaxValue);
    void setNetlist(nlohmann::json netlist);

    // getters methods
    string getType();
    string getId();
    float getDefaultValue();
    float getMinValue();
    float getMaxValue();
    nlohmann::json getNetlist();

    // Destructor
    ~Component();
};

typedef vector<Component> DeviceList;

#endif //COMPONENT_H
