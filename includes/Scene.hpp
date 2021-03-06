#ifndef MYPROJECT_BASESCENE_H
#define MYPROJECT_BASESCENE_H


#include <OpenSG/OSGGL.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGComponentTransformBase.h>
#include <OpenSG/OSGComponentTransformFields.h>
#include <magicvr/animation/ParallelAnimation.hpp>
#include <magicvr/ComponentTransformNode.hpp>
#include <magicvr/node/TrajectoryContainerNode.hpp>
#include <input/Tracker.hpp>
#include <magicvr/node/MovableNode.hpp>
#include <magicvr/animation/Animation.hpp>
#include <magicvr/animation/BubblesAnimationNode.hpp>
#include <magicvr/animation/FireAnimationNode.hpp>
#include <magicvr/ranges/view/range.hpp>
#include <magicvr/animation/AnimationChildNode.hpp>
#include <magicvr/animation/BezierCurve.hpp>
#include "PathSettings.hpp"

OSG_USING_NAMESPACE

class Scene {
public:
    using AnimationPtr = std::shared_ptr<Animation>;
    using AnimationStopCallback = std::function<void(std::shared_ptr<Animation>)>;
    using Path = const Char8 *;

private:
    const NodeRecPtr _root;

    magicvr::node::TrajectoryContainerNode _inputTrajectoryNode;
    magicvr::node::TrajectoryContainerNode _preprocessedInputTrajectoryNode;
    magicvr::node::TrajectoryContainerNode _patternTrajectoryNode;

    OSG::NodeRecPtr _stonehenge;
    OSG::NodeRecPtr _realWorldScale;

    ComponentTransformNode _fireElementalStone;
    ComponentTransformNode _waterElementalStone;
    ComponentTransformNode _thunderElementalStone;
    ComponentTransformNode _windElementalStone;

//    const ComponentTransformRecPtr earthUnlockedCT;
//    const ComponentTransformRecPtr fireUnlockedCT;
//    const ComponentTransformRecPtr waterUnlockedCT;
//    const ComponentTransformRecPtr thunderUnlockedCT;

    magicvr::animation::FireAnimationNode _fire;

    AnimationPtr _fireBubbles;
    AnimationPtr _waterBubbles;
    AnimationPtr _thunderBubbles;
    AnimationPtr _windBubbles;




    ParallelAnimation _animations;

    void build();

    const NodeTransitPtr buildStonehenge() const;

//    const NodeTransitPtr buildElement(const ComponentTransformRecPtr trans,
//                                      const char *modelName) const;

//    const NodeTransitPtr buildEarthElement() const;

    static ComponentTransformNode
    createElementalStone(Path modelPath, float rotationAngle);

//    const NodeTransitPtr buildFireElement() const;

//    const NodeTransitPtr buildWaterElement() const;

//    const NodeTransitPtr buildThunderElement() const;

    const NodeTransitPtr buildBackLeftPedestal() const;

    const NodeTransitPtr buildBackRightPedestal() const;

    const NodeTransitPtr buildFrontLeftPedestal() const;

    const NodeTransitPtr buildFrontRightPedestal() const;

    const NodeRecPtr buildRealWorldScale();

    ComponentTransformNode buildLightBubble() const;

    const NodeTransitPtr buildPedestal() const;

public:

    Scene();

//    void unlockEarth();
//
//    void unlockFire();
//
//    void unlockWater();
//

    void update(OSG::Time dTime);

    const NodeRecPtr &root() const;

    magicvr::animation::FireAnimationNode& fire();

//    void unlockThunder();

    NodeTransitPtr buildBezierCurve() const;


//    const NodeTransitPtr buildBubble() const;

    void animateFire();

    void animateFireBubbles();

    void animateWaterBubbles();

    void animateThunderBubbles();

    void animateWindBubbles();

    void stopAnimateBubbles(Scene::AnimationPtr &bubbles);

    void stopAnimateFireBubbles();

    void stopAnimateWaterBubbles();

    void stopAnimateThunderBubbles();

    void stopAnimateWindBubbles();

    const NodeTransitPtr buildKapelle() const;


    const NodeTransitPtr buildLantern() const;

    NodeTransitPtr buildSpiral() const;

    void shootLight(const BezierCurve<> &curve, AnimationStopCallback callback);

    void shootWater(const BezierCurve<> &curve, AnimationStopCallback callback);

    void shootFire(const BezierCurve<> &curve, AnimationStopCallback callback);

    const NodeTransitPtr buildScenesModels();

    void showInputTrajectory(std::vector<OSG::Vec3f> &&trajectory);

    void showPreprocessedInputTrajectory(std::vector<OSG::Vec3f> &&trajectory);

    void showPatternTrajectory(std::vector<OSG::Vec3f> &&trajectory);

    static std::shared_ptr<magicvr::animation::BubblesAnimationNode>
    createBubblesAnimationNode(Path modelPath);

    static std::vector<float> getBubblesRange();

    void animateBubbles(AnimationPtr &bubbles, Path modelPath,
                        NodeTransitPtr elementalStone);

    bool areBubblesRunning(const AnimationPtr bubbles) const;

    ComponentTransformNode buildWaterBubble() const;

    ComponentTransformNode buildFireBubble() const;

    Vec3f getLanternPosition() const;
};


#endif //MYPROJECT_BASESCENE_H
