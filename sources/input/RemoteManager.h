#ifndef MYPROJECT_REMOTEMANAGER_H
#define MYPROJECT_REMOTEMANAGER_H


#include <vrpn_Analog.h>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <OSGCSM/OSGCAVEConfig.h>
#include <input/Tracker.h>

namespace input {
    class RemoteManager {
        OSGCSM::CAVEConfig &cfg;
        vrpn_Tracker_Remote* tracker =  nullptr;
        vrpn_Button_Remote* button = nullptr;
        vrpn_Analog_Remote* analog = nullptr;

    public:
        Tracker wand;
        Tracker head;
        Vec3f analog_values;

        RemoteManager(OSGCSM::CAVEConfig &cfg);
        virtual ~RemoteManager();

        void check_tracker();

        template<typename T>
        T scale_tracker2cm(const T &value);

        void print_tracker();

        void onHeadTrackerChange(const vrpn_TRACKERCB tracker);

        void onWandTrackerChange(const vrpn_TRACKERCB tracker);

        void onAnalogChange(const vrpn_ANALOGCB analog);

        void onButtonChange(const vrpn_BUTTONCB button);
    };
}


#endif //MYPROJECT_REMOTEMANAGER_H