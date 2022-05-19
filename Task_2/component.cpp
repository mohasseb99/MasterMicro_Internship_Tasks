#include "component.h"

// constructor
Component::Component() {}

Component::Component(string type, string id, float defaultValue, float minValue, float maxValue, nlohmann::json netlist){
    this->type = type;
    this->id = id;
    this->defaultValue = defaultValue;
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->netlist = netlist;
}

// setters methods
void Component::setType(string newType) {this->type = newType;}

void Component::setId(string newId) {this->id = newId;}

void Component::setDefaultValue(float newDefaultValue) {this->defaultValue = newDefaultValue;}

void Component::setMinValue(float newMinValue) {this->minValue = newMinValue;}

void Component::setMaxValue(float newMaxValue) {this->maxValue = newMaxValue;}

void Component::setNetlist(nlohmann::json netlist){this->netlist = netlist;}

// getters methods
string Component::getType() {return this->type;}

string Component::getId() {return this->id;}

float Component::getDefaultValue() {return this->defaultValue;}

float Component::getMinValue() {return this->minValue;}

float Component::getMaxValue() {return this->maxValue;}

nlohmann::json Component::getNetlist(){return this->netlist;}

// Destructors
Component::~Component(){}