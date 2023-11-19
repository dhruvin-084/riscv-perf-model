#include "sparta/utils/SpartaAssert.hpp"
#include "sparta/utils/LogUtils.hpp"

#include "Switch.hpp"

namespace olympia_mss
{
    const char Switch::name[] = "Switch";

    Switch::Switch(sparta::TreeNode *node, const SwitchParameterSet* p) :
        sparta::Unit(node)
    {

        ILOG("Switch construct: #" << node->getGroupIdx());
    }
}