#include <iostream>
#include <string>
using namespace std;

class Figure abstract {
protected:
    int geometry[4][4];
    int color[3];
    string name;

public:
    virtual ~Figure() {}

    virtual void SetGeometry(int geo[4][4]) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                geometry[i][j] = geo[i][j];
            }
        }
    }

    virtual void SetColor(int r, int g, int b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    virtual void SetName(string figureName) {
        name = figureName;
    }

    virtual void PrintInfo() {
        cout << "Figure: " << name << endl;
        cout << "Color (RGB): " << color[0] << ", " << color[1] << ", " << color[2] << endl;
        cout << "Geometry: " << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class O_Figure : public Figure {
public:
    O_Figure() {
        int geo[4][4] = {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(249, 255, 1);
        SetName("O_Figure");
    }
};

class I_Figure : public Figure {
public:
    I_Figure() {
        int geo[4][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(0, 229, 255);
        SetName("I_Figure");
    }
};

class S_Figure : public Figure {
public:
    S_Figure() {
        int geo[4][4] = {
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(246, 1, 0);
        SetName("S_Figure");
    }
};

class Z_Figure : public Figure {
public:
    Z_Figure() {
        int geo[4][4] = {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(104, 182, 36);
        SetName("Z_Figure");
    }
};

class L_Figure : public Figure {
public:
    L_Figure() {
        int geo[4][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(255, 140, 5);
        SetName("L_Figure");
    }
};

class J_Figure : public Figure {
public:
    J_Figure() {
        int geo[4][4] = {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(254, 81, 188);
        SetName("J_Figure");
    }
};

class T_Figure : public Figure {
public:
    T_Figure() {
        int geo[4][4] = {
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(geo);
        SetColor(159, 0, 152);
        SetName("T_Figure");
    }
};


class Creator abstract {
public:
    virtual Figure* Create() = 0;
};

class O_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new O_Figure;
    }
};

class I_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new I_Figure;
    }
};

class S_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new S_Figure;
    }
};

class Z_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new Z_Figure;
    }
};

class L_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new L_Figure;
    }
};

class J_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new J_Figure;
    }
};

class T_FigureCreator : public Creator {
public:
    Figure* Create() override {
        return new T_Figure;
    }
};


Figure* Client(Creator* pDev) {
    return pDev->Create();
}


int main() {
    Creator* pDev = new O_FigureCreator();
    Figure* pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new I_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new S_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new Z_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new L_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new J_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new T_FigureCreator();
    pHouse = Client(pDev);
    pHouse->PrintInfo();
    delete pHouse;
    delete pDev;

    return 0;
}