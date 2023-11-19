#pragma once

#include <memory>
#include <string>
#include <vector>

#include "sparta/simulation/ResourceFactory.hpp"
#include "sparta/simulation/RootTreeNode.hpp"
#include "sparta/simulation/ResourceTreeNode.hpp"
#include "sparta/simulation/TreeNodeExtensions.hpp"

#include "BIUFactory.hpp"

namespace olympia_mss {
    class BIUTopology{
    public:
    //! \brief Structure to represent a resource unit in device tree
        struct UnitInfo{

            //! ResourceTreeNode name
            std::string name;

            //! ResourceTreeNode parent name
            std::string parent_name;

            //! ResourceTreeNode human-readable name
            std::string human_name;

            //! TreeNode group name required for multiple execution units
            std::string group_name;

            //! TreeNode group id required for multiple execution units
            uint32_t group_id;

            //! Factory required to create this particular resource
            sparta::ResourceFactoryBase* factory;

            //! Flag to tell whether this node should be private to its parent
            bool is_private_subtree;

            /**
             * @brief Constructor for UnitInfo
             */
            UnitInfo(const std::string& name,
                     const std::string& parent_name,
                     const std::string& human_name,
                     const std::string&  group_name,
                     const uint32_t group_id,
                     sparta::ResourceFactoryBase* factory,
                     bool is_private_subtree = false) :
                name{name},
                parent_name{parent_name},
                human_name{human_name},
                group_name{group_name},
                group_id{group_id},
                factory{factory},
                is_private_subtree{is_private_subtree}{}
        };
        //! \brief Structure to represent a port binding between units in device tree
        struct PortConnectionInfo{

            //! Out port name of unit
            std::string output_port_name;

            //! In port name of next unit, unit_2
            std::string input_port_name;

            /**
             * @brief Constructor for PortConnectionInfo
             */
            PortConnectionInfo(const std::string& output_port_name,
                               const std::string& input_port_name) :
                output_port_name{output_port_name},
                input_port_name{input_port_name}{}
        }; 

        BIUTopology();


        /**
         * @brief Set the name for this topoplogy
         */
        auto setName(const std::string& topology) -> void{
            topology_name = topology;
        }

        /**
         * @brief Static method to allocate memory for topology
         */
        static std::unique_ptr<BIUTopology> allocateTopology(const std::string& topology);

        //! Post binding/final setup specific to a topology
        virtual void bindTree(sparta::RootTreeNode* root_node) {}
        //! Public members used by BIUFactory to build and bind tree
        std::unique_ptr<BIUFactory> factory;
        std::string topology_name;
        std::vector<UnitInfo> units;
        std::vector<PortConnectionInfo> port_connections;
    };
}