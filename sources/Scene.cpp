#include "Scene.hpp"
#include <OpenSG/OSGSceneFileHandler.h>
#include <magicvr/ComponentTransformNode.hpp>

void Scene::build() {
    /*Water*/
    const auto waterTrans =
            ComponentTransformNode()
                    .translate(0, 1, 0)
                    .scale(2, 1, 2)
                    .rotate(Quaternion(Vec3f(0, 1, 0), osgDegree2Rad(30)))
                    .addChild(SceneFileHandler::the()->read("models/Water.obj"))
                    .addChild(buildWaterElementalStone())
                    .node();



    /*SockelVorneLinks*/
    const auto sockelVorneLinksTrans =
            ComponentTransformNode()
                    .translate(-1, 0, -1)
                    .rotate(Quaternion(Vec3f(1, 0, 0), osgDegree2Rad(0)))
                    .scale(0.5, 1, 0.5)
                    .addChild(SceneFileHandler::the()->read("models/Sockel.obj"))
                    .addChild(waterTrans)
                    .node();

    /*realWorldScale
     *
     * Modelle, die mit Blender erstellt wurden werden vom
     * OSGFileHandler um den Faktor 100 zu klein interpretiert.
     *
     * -> Die gesamt Szene auf 100 hochskalieren
     *
     * => künftig Translation 1 = 1m
     * => künftig Scale 1 = 100% */
    const NodeRecPtr realWorldScaleTrans =
            ComponentTransformNode()
                    .scale(100)
                    .addChild(sockelVorneLinksTrans)
                    .node();

    root()->addChild(realWorldScaleTrans);
}

const NodeTransitPtr Scene::buildWaterElementalStone() const {
    return ComponentTransformNode(waterUnlockedCT)
            .rotate(Quaternion(Vec3f(1, 0, 0), osgDegree2Rad(-90)))
            .addChild(SingletonHolder<SceneFileHandlerBase>::the()->read("models/WaterUnlocked.obj"))
            .node();
}

void Scene::update() {
}

Scene::Scene() : _root(makeNodeFor(Group::create())), waterUnlockedCT(ComponentTransformBase::create()) {
    build();
    update();
}

const NodeRecPtr &Scene::root() const {
    return _root;
}
