#include "BIUTopology.hpp"
#include "BIUFactory.hpp"
#include "sparta/utils/SpartaException.hpp"

namespace olympia_mss
{
    BIUTopology::BIUTopology(): factory{new BIUFactory()}
    {
        units = {
            {
                "switch00",
                "cpu.biu",
                "switch00",
                sparta::TreeNode::GROUP_NAME_NONE,
                sparta::TreeNode::GROUP_IDX_NONE,
                &factory->switch_rf
            },
            {
                "switch01",
                "cpu.biu",
                "switch01",
                sparta::TreeNode::GROUP_NAME_NONE,
                sparta::TreeNode::GROUP_IDX_NONE,
                &factory->switch_rf
            },
            {
                "switch10",
                "cpu.biu",
                "switch10",
                sparta::TreeNode::GROUP_NAME_NONE,
                sparta::TreeNode::GROUP_IDX_NONE,
                &factory->switch_rf
            },
            {
                "switch11",
                "cpu.biu",
                "switch11",
                sparta::TreeNode::GROUP_NAME_NONE,
                sparta::TreeNode::GROUP_IDX_NONE,
                &factory->switch_rf
            }
        };

        port_connections = {

        };
    }
} // namespace olympia_mss
