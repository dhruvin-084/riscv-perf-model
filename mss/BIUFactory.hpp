#pragma once

#include "sparta/simulation/ResourceFactory.hpp"
#include "Switch.hpp"


namespace olympia_mss
{
    struct BIUFactory{
        sparta::ResourceFactory<Switch, Switch::SwitchParameterSet> switch_rf;
    };
    
}