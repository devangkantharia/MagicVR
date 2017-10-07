#ifndef MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP
#define MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP


#include <magicvr/util/VectorConverter.hpp>
#include <magicvr/node/MovableNode.hpp>
#include <magicvr/node/TrajectoryContainerNode.hpp>
#include <input/RemoteManager.hpp>
#include <magicvr/node/WandNode.hpp>
#include "AppController.hpp"

namespace magicvr {
    class AppControllerWithWandSupport : public AppController {
        node::WandNode _wandNode;
        node::TrajectoryContainerNode _trajectoryNode;
        input::RemoteManager &_wand;

        magicvr::node::WandBulb _selectedWandBulb;
        int _bulbCount;

        int bulbCount() const;

        void bulbCount(int count);

        void shootBulb();

        void showBulb(magicvr::node::WandBulb bulb);

    public:
        explicit AppControllerWithWandSupport(input::RemoteManager &wand);

        void display(OSG::Time dTime) override;

        void keyboardDown(unsigned char key, int x, int y) override;

        void shootLight();

        void shootWater();

        void shootFire();
    };
}

#endif //MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP
