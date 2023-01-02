class Sport {
public:
    Sport(string name) {
        m_name = name;
    }

    virtual ~Sport() {
    }

    string name() const {
        return m_name;
    }

    virtual bool isOutdoor() const = 0;

    virtual string icon() const = 0;

private:
    string m_name;
};

class Snowboarding : public Sport {
public:
    Snowboarding(string name)
        : Sport(name) {
    }

    virtual ~Snowboarding() {
        cout << "Destroying the Snowboarding object named " << name() << "." << endl;
    }

    virtual bool isOutdoor() const {
        return true;
    }

    virtual string icon() const {
        return "a descending snowboarder";
    }

};

class Biathlon : public Sport {
public:
    Biathlon(string name, double distance)
        : Sport(name), m_distance(distance) {
    }

    virtual ~Biathlon() {
        cout << "Destroying the Biathlon object named " << name() << "." << endl;
    }

    virtual bool isOutdoor() const {
        return true;
    }

    virtual string icon() const {
        return "showing a skier with a rifle";
    }
private:
    double m_distance;
};

class FigureSkating : public Sport {
public:
    FigureSkating(string name) : Sport(name) {
    }

    ~FigureSkating() {
        cout << "Destroying the FigureSkating object named " << name() << "." << endl;
    }

    virtual bool isOutdoor() const {
        return false;
    }

    virtual string icon() const {
        return "a skater in the Biellmann position";
    }
};