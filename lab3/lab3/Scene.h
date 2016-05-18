#ifndef SCENE_H
#define SCENE_H
#include <SceneObjects.h>
#include <vector>
#include <QGraphicsScene>
//синглтон
class Scene {
public:
    QGraphicsScene *scene;
    Scene();
    Scene(const Scene &obj)
        {
            scene = obj.scene;
        }

    void addElement(SceneObject *param);
    std::vector <SceneObject*> obj;
};
#endif // SCENE_H
