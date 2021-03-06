#ifndef SCENEOBJECTS_H
#define SCENEOBJECTS_H
#include <string>
#include <vector>
using namespace std;
class SceneObject {
public:
    virtual string whatIsIt() { return "Scene"; }
    bool enable;
};
class VisibleObject : public SceneObject {
public:
    virtual string whatIsIt() { return "VisibleObject"; }
};
class InvisibleObjects : public SceneObject {
public:
    virtual string whatIsIt() { return "InvisibleObject"; }
};
//камеры
class PrototypeCamera : public InvisibleObjects {
public:
    double x, y, z; //координаты камеры
    virtual string whatIsIt() { return "PrototypeCamera"; }
};

class ConcreteCamera1 : public PrototypeCamera {
public:
    double fx, fy, fz;
    virtual string whatIsIt() { return "ConcreteCamera1"; }
    string test(){return "lol";}
};

//прототипы
class PrototypeModel : public VisibleObject {
public:
    PrototypeModel();
    virtual string whatIsIt() { return "PrototypeModel"; }
    int vertices;
    int* links;
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
    bool full = false;
};

class ConcreteModel1 : public PrototypeModel {
public:
    ConcreteModel1();
    virtual string whatIsIt() { return "ConcreteModel1"; }
    int edge_num;
    double* x;
    double* y;
    double* z;
};
class Composite : public SceneObject {
public:
    std::vector<SceneObject*> vect;
    virtual string whatIsIt() { return "Composite"; }
};

#endif // SCENEOBJECTS_H
