#pragma once

#include "sparta/ports/PortSet.hpp"
#include "sparta/ports/SignalPort.hpp"
#include "sparta/ports/DataPort.hpp"
#include "sparta/events/EventSet.hpp"
#include "sparta/events/UniqueEvent.hpp"
#include "sparta/simulation/Unit.hpp"
#include "sparta/simulation/ParameterSet.hpp"
#include "sparta/simulation/TreeNode.hpp"
#include "sparta/collection/Collectable.hpp"
#include "sparta/events/StartupEvent.hpp"

#include "Inst.hpp"
#include "CoreTypes.hpp"
#include "FlushManager.hpp"

// UPDATE
#include "sparta/ports/SyncPort.hpp"
#include "sparta/resources/Pipe.hpp"

namespace olympia_mss
{
    class Switch : public sparta::Unit
    {
    public:
        // Parameter set for Switch
        class SwitchParameterSet : public sparta::ParameterSet
        {
        public:
            SwitchParameterSet(sparta::TreeNode* n):
                sparta::ParameterSet(n)
            { }
            PARAMETER(uint32_t, switch_req_queue_size, 16, "Switch request queue size")
            PARAMETER(uint32_t, switch_latency, 1, "Send bus request latency")

        };
        
        // Constructor for Switch
        // node parameter is the node that represent the Switch and p is the BIU parameter set
        Switch(sparta::TreeNode* node, const SwitchParameterSet* p);

        static const char name[];

    private:
        ////////////////////////////////////////////////////////////////////////////////
        // Input Ports
        ////////////////////////////////////////////////////////////////////////////////
        sparta::DataInPort<olympia::InstPtr> in_switch_e_
            {&unit_port_set_, "in_switch_e", 1};

        sparta::DataInPort<olympia::InstPtr> in_switch_n_
            {&unit_port_set_, "in_switch_n", 1};

        sparta::DataInPort<olympia::InstPtr> in_switch_w_
            {&unit_port_set_, "in_switch_w", 1};

        sparta::DataInPort<olympia::InstPtr> in_switch_s_
            {&unit_port_set_, "in_switch_s", 1};
            
        ////////////////////////////////////////////////////////////////////////////////
        // Output Ports
        ////////////////////////////////////////////////////////////////////////////////
        sparta::DataInPort<olympia::InstPtr> out_switch_e_
            {&unit_port_set_, "out_switch_e", 1};

        sparta::DataInPort<olympia::InstPtr> out_switch_n_
            {&unit_port_set_, "out_switch_n", 1};
        
        sparta::DataInPort<olympia::InstPtr> out_switch_w_
            {&unit_port_set_, "out_switch_w", 1};

        sparta::DataInPort<olympia::InstPtr> out_switch_s_
            {&unit_port_set_, "out_switch_s", 1};

        ////////////////////////////////////////////////////////////////////////////////
        // Internal States
        ////////////////////////////////////////////////////////////////////////////////
        using BusRequestQueue = std::list<olympia::InstPtr>;
        BusRequestQueue switch_req_queue_;

        const uint32_t switch_req_queue_size_ = 10;
        const uint32_t switch_latency_ = 1;

        bool switch_busy_ = false;

        ////////////////////////////////////////////////////////////////////////////////
        // Event Handlers
        ////////////////////////////////////////////////////////////////////////////////
        sparta::UniqueEvent<> ev_handle_in_req_
            {&unit_event_set_, "handle_switch_in_req", CREATE_SPARTA_HANDLER(Switch, handle_Input_Req_)};
        
        ////////////////////////////////////////////////////////////////////////////////
        // Callbacks
        ////////////////////////////////////////////////////////////////////////////////
        void handleInputReq(const olympia::InstPtr &);
        void handle_Input_Req_();
    };
}
