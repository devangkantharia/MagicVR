#ifndef MAGICVR_MAGICVRDESKTOPGLUTFRAMEWORK_HPP
#define MAGICVR_MAGICVRDESKTOPGLUTFRAMEWORK_HPP

#include "glutFramework/GlutFramework.hpp"
#include <OpenSG/OSGSimpleSceneManager.h>
#include <Scene.hpp>

class MagicVrDesktopGlutFramework : public glutFramework::GlutFramework {
    OSG::SimpleSceneManagerRefPtr mgr; // gets created in createWindow
    Scene &scene;
public:
    MagicVrDesktopGlutFramework(Scene &scene);

    int createWindow() override;

    void keyboardDown(unsigned char key, int x, int y) override;

    OSG::Node *root();

    void mouseButtonPress(int button, int state, int x, int y) override;

    void mouseMove(int x, int y) override;

    void display(float dTime) override;

    void reshape(int width, int height) override;

    void loadBackground();
};


#endif //MAGICVR_MAGICVRDESKTOPGLUTFRAMEWORK_HPP
